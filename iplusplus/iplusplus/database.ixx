export module iplusplus:database;

import :core;
import :windows;

import std.core;

using namespace standard;
using namespace iplusplus;

namespace database
{
    struct node
    {
        long long left;
        long long right;
        long long parent;
        long long balance;
        long long key;

        node()
        {
            left = 0;
            right = 0;
            parent = 0;
            balance = state::header;
            key = 0;
        }

        node(long long p)
        {
            left = 0;
            right = 0;
            parent = p;
            balance = state::balanced;
            key = 0;
        }

        bool is_header() { return balance == state::header; }
    };

    struct file_exception
    {
        string description;

        file_exception(const string& s)
            : description(s) {}
    };

    inline bool handle_less(const handle& ha, const handle& hb)
    {
        return ha < hb;
    }

    dictionary<handle, long long> file_reference(handle_less);

    inline string get_last_error_string()
    {
        unsigned error = get_last_error();

        character* messageBuffer = nullptr;

        size_t size = format_message(format_message_flag::allocate_buffer |
            format_message_flag::from_system |
            format_message_flag::ignore_inserts,
            0,
            error,
            make_language(language::neutral, sublanguage::_default),
            (character*)&messageBuffer,
            0,
            0);

        string message(messageBuffer);

        free_local_memory(messageBuffer);

        return message;
    }

    export struct file
    {
        void* hfile;
        string file_name;

        file() : hfile(0), file_name(L"nun")
        {
            try
            {
                long long count = file_reference[hfile];
                count++;
                file_reference[hfile] = count;
            }
            catch (entry_not_found_exception)
            {
                file_reference[hfile] = 1;
            }
        }

        file(const string& file_name_set,
            unsigned access,
            unsigned share_nnode,
            const security_attributes* security = 0,
            unsigned disposition = file_action::open_existing,
            unsigned flags_and_attributes = 0,
            handle template_file = 0)
            : file_name(file_name_set)
        {
            hfile = create_file((const wchar_t*)file_name,
                access,
                share_nnode,
                security,
                disposition,
                flags_and_attributes,
                template_file);

            if (hfile == (void*)-1)
            {
                string estring = string(L"error opening file: ") + file_name + string(L" error: ") + get_last_error_string();
                throw file_exception(estring);
            }

            file_reference[hfile] = 1;
        }

        file(const file& p)
        {
            hfile = p.hfile;
            file_name = p.file_name;
            long long count = file_reference[hfile];
            count++;
            file_reference[hfile] = count;
        }

        ~file()
        {
            long long count = file_reference[hfile];
            count--;
            if (count == 0)
            {
                if (hfile != 0)
                {
                    bool success = close_handle(hfile);

                    if (!success)
                    {
                        string estring = string(L"error closing handle: ") + file_name + string(L"  error: ") + get_last_error_string();
                        throw file_exception(estring);
                    }
                }
                file_reference >> hfile;
            }
            else
            {
                file_reference[hfile] = count;
            }
        }

        void destroy()
        {
            long long count = file_reference[hfile];
            count--;
            if (count == 0)
            {
                if (hfile != 0)
                {
                    bool success = close_handle(hfile);

                    if (!success)
                    {
                        string estring = string(L"error closeing handle: ") + file_name + string(L"  error: ") + get_last_error_string();
                        throw file_exception(estring);
                    }
                }
                file_reference >> hfile;
            }
            else
            {
                file_reference[hfile] = count;
            }
        }

        file& operator=(const file& p)
        {
            destroy();

            hfile = p.hfile;
            file_name = p.file_name;

            long long count = file_reference[hfile];
            count++;
            file_reference[hfile] = count;
            return *this;
        }

        unsigned write(const void* buffer,
            unsigned count)
        {
            unsigned written;

            bool success = write_file(hfile,
                (void*)buffer,
                count,
                &written,
                0);

            if (!success)
            {
                string estring = string(L"error writing to file: ") + file_name + string(L"  error: ") + get_last_error_string();
                throw file_exception(estring);
            }


            return written;
        }

        unsigned read(void* buffer,
            unsigned count) const
        {
            unsigned read;

            bool success = read_file(hfile,
                buffer,
                count,
                &read,
                0);

            if (!success)
            {
                string estring = string(L"error reading file: ") + file_name + string(L"  error: ") + get_last_error_string();
                throw file_exception(estring);
            }

            return read;
        }

        long long size() const
        {
            return get_file_length(hfile);
        }

        void end_of_file()
        {
            bool success = set_end_of_file(hfile);

            if (!success)
            {
                string estring = string(L"error setting end of file: ") + file_name + string(L"  error: ") + get_last_error_string();
                throw file_exception(estring);
            }
        }

        long long set_pointer(long long offset, unsigned method)
        {
            return set_file_ptr(hfile, offset, method);
        }

        void flush()
        {
            bool success = flush_file_buffers(hfile);
            if (!success)
            {
                string estring = string(L"error flushing file: ") + file_name + string(L"  error: ") + get_last_error_string();
                throw file_exception(estring);
            }

        }

    };

    struct heap_entry
    {
        long long address;
        long long size;

        heap_entry(long long slot_size,
            long long slot_address)
        {
            size = slot_size;
            address = slot_address;
        }
    };

    struct node_stack
    {
        file _node_stack;

        node_stack() {}

        node_stack(string name, bool f_create)
        {
            if (f_create)
            {
                _node_stack = file(name,
                    access_type::generic_read | access_type::generic_write,
                    share_file::write | share_file::read,
                    (const security_attributes*)0,
                    file_action::create_new,
                    file_flag::random_file,
                    (handle)0);
                long long zero = 0;
                _node_stack.set_pointer(0, file_position::at_beginning);
                _node_stack.write(&zero, 8);
            }
            else
                _node_stack = file(name,
                    access_type::generic_read | access_type::generic_write,
                    share_file::write | share_file::read,
                    (const security_attributes*)0,
                    file_action::open_existing,
                    file_flag::random_file,
                    (handle)0);
        }

        void reset()
        {
            long long count = 0;
            _node_stack.set_pointer(0, file_position::at_beginning);
            _node_stack.write(&count, 8);
            _node_stack.end_of_file();
            _node_stack.flush();
        }

        long long get()
        {
            long long slot_address = 0;
            long long heap_count = 0;
            _node_stack.set_pointer(0, file_position::at_beginning);
            _node_stack.read(&heap_count, 8);
            if (heap_count != 0)
            {
                _node_stack.set_pointer((long long)(8 * heap_count), file_position::at_beginning);
                _node_stack.read(&slot_address, 8);
                _node_stack.set_pointer((long long)(8 * heap_count), file_position::at_beginning);
                _node_stack.end_of_file();
                heap_count--;
                _node_stack.set_pointer(0, file_position::at_beginning);
                _node_stack.write(&heap_count, 8);
                return slot_address;
            }

            return invalid();
        }

        void add(long long slot_address)
        {
            long long heap_count = 0;
            _node_stack.set_pointer(0, file_position::at_beginning);
            _node_stack.read(&heap_count, 8);
            _node_stack.set_pointer((long long)(8 * (1 + heap_count)), file_position::at_beginning);
            _node_stack.write(&slot_address, 8);
            heap_count++;
            _node_stack.set_pointer(0, file_position::at_beginning);
            _node_stack.write(&heap_count, 8);
        }

        long long invalid()
        {
            return -1;
        }

        void check_point()
        {
            _node_stack.flush();
        }
    };

    struct heap_node
    {
        long long left;
        long long right;
        long long parent;
        long long balance;
        long long key;
        long long address;

        heap_node()
        {
            left = 0;
            right = 0;
            parent = 0;
            balance = state::header;
            key = 0;
            address = 0;
        }

        heap_node(long long p, long long size, long long address_to_ad)
        {
            left = 0;
            right = 0;
            parent = p;
            balance = state::balanced;
            key = size;
            address = address_to_ad;
        }

        bool is_header() { return balance == state::header; }
    };

    dictionary<file*, long long> heap_references;

    struct heap
    {
        string node_filename;
        string heap_heapname;

        file* node_file;
        node_stack* _node_stack;

        heap()
            : node_file(0)
        {
            try
            {
                long long count = heap_references[node_file];
                count++;
                heap_references[node_file] = count;
            }
            catch (...)
            {
                heap_references[node_file] = 1;
            }
        }

        heap(const string& name,
             const string& directory)
        {
            node_filename = directory + string(L"\\") + name + string(L".a");
            heap_heapname = directory + string(L"\\") + name + string(L".b");

            if (!exists())
            {
                _node_stack = new node_stack(heap_heapname, true);

                node_file = new file(node_filename,
                    access_type::generic_read | access_type::generic_write,
                    share_file::write | share_file::read,
                    (const security_attributes*)0,
                    file_action::create_new,
                    file_flag::random_file,
                    (handle)0);

                reset();
            }
            heap_references[node_file] = 1;
        }

        ~heap()
        {
            long long count = heap_references[node_file];
            count--;
            if (count == 0)
            {
                if (node_file)
                {
                    delete node_file;
                    delete _node_stack;
                }
                heap_references.erase(node_file);
            }
            else
                heap_references[node_file] = count;
        }

        void destroy()
        {
            long long count = heap_references[node_file];
            count--;
            if (count == 0)
            {
                if (node_file)
                {
                    delete node_file;
                    delete _node_stack;
                }
                heap_references.erase(node_file);
            }
            else
                heap_references[node_file] = count;
        }


        heap(const heap& copee)
            : node_file(copee.node_file),
            _node_stack(copee._node_stack),
            node_filename(copee.node_filename),
            heap_heapname(copee.heap_heapname)
        {
            long long count = heap_references[node_file];
            count++;
            heap_references[node_file] = count;
        }

        heap& operator=(const heap& copee)
        {
            destroy();
            node_file = copee.node_file;
            _node_stack = copee._node_stack;
            node_filename = copee.node_filename;
            heap_heapname = copee.heap_heapname;
            long long count = heap_references[node_file];
            count++;
            heap_references[node_file] = count;
            return *this;
        }

        bool exists()
        {
            try
            {
                node_file = new file(node_filename,
                    access_type::generic_read | access_type::generic_write,
                    share_file::write | share_file::read,
                    (const security_attributes*)0,
                    file_action::open_existing,
                    file_flag::random_file,
                    (handle)0);
            }
            catch (file_exception)
            {
                return false;
            }

            _node_stack = new node_stack(heap_heapname, false);

            return true;
        }

        void reset()
        {
            node_file->set_pointer(0, file_position::at_beginning);
            node_file->end_of_file();
            add(heap_node());
            _node_stack->reset();
        }

        long long add(heap_node data)
        {
            long long slot_address = _node_stack->get();
            if (slot_address == invalid())
            {
                long long file_size = node_file->size();
                node_file->set_pointer(file_size, file_position::at_beginning);
                node_file->write(&data, sizeof(heap_node));
                return file_size;
            }
            else
            {
                node_file->set_pointer(slot_address, file_position::at_beginning);
                node_file->write(&data, sizeof(heap_node));
                return slot_address;
            }
        }

        void update(long long node_address, heap_node data)
        {
            node_file->set_pointer(node_address, file_position::at_beginning);
            node_file->write(&data, sizeof(heap_node));
        }

        heap_node get(long long node_address)
        {
            heap_node node_get;
            node_file->set_pointer(node_address, file_position::at_beginning);
            node_file->read(&node_get, sizeof(heap_node));
            return node_get;
        }

        void dispose(long long slot_address)
        {
            _node_stack->add(slot_address);
        }

        long long invalid()
        {
            return -1;
        }

        void check_point()
        {
            node_file->flush();
            _node_stack->check_point();
        }
    };

    long long rotate_left(heap& _heap, long long _node)
    {
        heap_node _heap_node = _heap.get(_node);
        long long parent = _heap_node.parent;
        long long x = _heap_node.right;
        heap_node _x = _heap.get(x);
        _heap_node.parent = x;
        _x.parent = parent;
        if (_x.left != 0)
        {
            heap_node x_left = _heap.get(_x.left);
            x_left.parent = _node;
            _heap.update(_x.left, x_left);
        }
        _heap_node.right = _x.left;
        _x.left = _node;
        _heap.update(_node, _heap_node);
        _heap.update(x, _x);
        return x;
    }

    long long rotate_right(heap& _heap, long long _node)
    {
        heap_node _heap_node = _heap.get(_node);
        long long parent = _heap_node.parent;
        long long x = _heap_node.left;
        heap_node _x = _heap.get(x);
        _heap_node.parent = x;
        _x.parent = parent;
        if (_x.right != 0)
        {
            heap_node x_right = _heap.get(_x.right);
            x_right.parent = _node;
            _heap.update(_x.right, x_right);
        }
        _heap_node.left = _x.right;
        _x.right = _node;
        _heap.update(_node, _heap_node);
        _heap.update(x, _x);
        return x;
    }

    long long balance_left(heap& _heap, long long _node)
    {
        long long new_heap_node = 0;

        heap_node _heap_node = _heap.get(_node);

        long long left = _heap_node.left;
        heap_node _left = _heap.get(left);

        switch (_left.balance)
        {
        case state::left_high:
            _heap_node.balance = state::balanced;
            _left.balance = state::balanced;
            _heap.update(_node, _heap_node);
            _heap.update(left, _left);
            new_heap_node = rotate_right(_heap, _node);
            break;

        case state::right_high:
        {
            long long sub_right = _left.right;
            heap_node _sub_right = _heap.get(sub_right);

            switch (_sub_right.balance)
            {
            case state::balanced:
                _heap_node.balance = state::balanced;
                _left.balance = state::balanced;
                _heap.update(_node, _heap_node);
                _heap.update(left, _left);
                break;

            case state::right_high:
                _heap_node.balance = state::balanced;
                _left.balance = state::left_high;
                _heap.update(_node, _heap_node);
                _heap.update(left, _left);
                break;

            case state::left_high:
                _heap_node.balance = state::right_high;
                _left.balance = state::balanced;
                _heap.update(_node, _heap_node);
                _heap.update(left, _left);
                break;
            }
            _sub_right.balance = state::balanced;
            _heap.update(sub_right, _sub_right);
            _heap_node.left = rotate_left(_heap, left);
            _heap.update(_node, _heap_node);
            new_heap_node = rotate_right(_heap, _node);
        }
        break;

        case state::balanced:
            _heap_node.balance = state::left_high;
            _left.balance = state::right_high;
            _heap.update(_node, _heap_node);
            _heap.update(left, _left);
            new_heap_node = rotate_right(_heap, _node);
            break;
        }

        return new_heap_node;
    }

    long long balance_right(heap& _heap, long long _node)
    {
        long long new_heap_node = 0;

        heap_node _heap_node = _heap.get(_node);

        long long right = _heap_node.right;
        heap_node _right = _heap.get(right);

        switch (_right.balance)
        {
        case state::right_high:
            _heap_node.balance = state::balanced;
            _right.balance = state::balanced;
            _heap.update(_node, _heap_node);
            _heap.update(right, _right);
            new_heap_node = rotate_left(_heap, _node);
            break;

        case state::left_high:
        {
            long long sub_left = _right.left;
            heap_node _sub_left = _heap.get(sub_left);

            switch (_sub_left.balance)
            {
            case state::balanced:
                _heap_node.balance = state::balanced;
                _right.balance = state::balanced;
                _heap.update(_node, _heap_node);
                _heap.update(right, _right);
                break;

            case state::left_high:
                _heap_node.balance = state::balanced;
                _right.balance = state::right_high;
                _heap.update(_node, _heap_node);
                _heap.update(right, _right);
                break;

            case state::right_high:
                _heap_node.balance = state::left_high;
                _right.balance = state::balanced;
                _heap.update(_node, _heap_node);
                _heap.update(right, _right);
                break;
            }
            _sub_left.balance = state::balanced;
            _heap.update(sub_left, _sub_left);
            _heap_node.right = rotate_right(_heap, right);
            _heap.update(_node, _heap_node);
            new_heap_node = rotate_left(_heap, _node);
        }
        break;

        case state::balanced:
            _heap_node.balance = state::right_high;
            _right.balance = state::left_high;
            _heap.update(_node, _heap_node);
            _heap.update(right, _right);
            new_heap_node = rotate_left(_heap, _node);
            break;
        }

        return new_heap_node;
    }

    void balance_tree(heap& _heap, long long _node, long long from)
    {
        bool taller = true;

        while (taller)
        {
            heap_node _heap_node = _heap.get(_node);

            long long parent = _heap_node.parent;
            heap_node _parent = _heap.get(parent);

            long long next_from = (_parent.left == _node) ? direction::from_left : direction::from_right;

            if (from == direction::from_left)
            {
                switch (_heap_node.balance)
                {
                case state::left_high:
                    if (_parent.is_header())
                        _parent.parent = balance_left(_heap, _node);
                    else if (_parent.left == _node)
                        _parent.left = balance_left(_heap, _node);
                    else
                        _parent.right = balance_left(_heap, _node);
                    _heap.update(parent, _parent);
                    taller = false;
                    break;

                case state::balanced:
                    _heap_node.balance = state::left_high;
                    _heap.update(_node, _heap_node);
                    taller = true;
                    break;

                case state::right_high:
                    _heap_node.balance = state::balanced;
                    _heap.update(_node, _heap_node);
                    taller = false;
                    break;
                }
            }
            else
            {
                switch (_heap_node.balance)
                {
                case state::left_high:
                    _heap_node.balance = state::balanced;
                    _heap.update(_node, _heap_node);
                    taller = false;
                    break;

                case state::balanced:
                    _heap_node.balance = state::right_high;
                    _heap.update(_node, _heap_node);
                    taller = true;
                    break;

                case state::right_high:
                    if (_parent.is_header())
                        _parent.parent = balance_right(_heap, _node);
                    else if (_parent.left == _node)
                        _parent.left = balance_right(_heap, _node);
                    else
                        _parent.right = balance_right(_heap, _node);
                    _heap.update(parent, _parent);
                    taller = false;
                    break;
                }
            }

            if (taller) // skip up a level
            {
                if (_parent.is_header())
                    return;
                else
                {
                    _node = parent;
                    from = next_from;
                }
            }
        }
    }

    void balance_tree_remove(heap& _heap, long long _node, long long from)
    {
        bool shorter = true;

        while (shorter)
        {
            heap_node _heap_node = _heap.get(_node);

            long long parent = _heap_node.parent;
            heap_node _parent = _heap.get(parent);

            long long next_from = (_parent.left == _node) ? direction::from_left : direction::from_right;

            if (from == direction::from_left)
            {
                switch (_heap_node.balance)
                {
                case state::left_high:
                    _heap_node.balance = state::balanced;
                    _heap.update(_node, _heap_node);
                    shorter = true;
                    break;

                case state::balanced:
                    _heap_node.balance = state::right_high;
                    _heap.update(_node, _heap_node);
                    shorter = false;
                    break;

                case state::right_high:
                {
                    heap_node right = _heap.get(_heap_node.right);

                    if (right.balance == state::balanced)
                        shorter = false;
                    else
                        shorter = true;

                    if (_parent.is_header())
                        _parent.parent = balance_right(_heap, _node);
                    else if (_parent.left == _node)
                        _parent.left = balance_right(_heap, _node);
                    else
                        _parent.right = balance_right(_heap, _node);

                    _heap.update(parent, _parent);
                }
                break;
                }
            }
            else
            {
                switch (_heap_node.balance)
                {
                case state::right_high:
                    _heap_node.balance = state::balanced;
                    _heap.update(_node, _heap_node);
                    shorter = true;
                    break;

                case state::balanced:
                    _heap_node.balance = state::left_high;
                    _heap.update(_node, _heap_node);
                    shorter = false;
                    break;

                case state::left_high:
                {
                    heap_node left = _heap.get(_heap_node.left);

                    if (left.balance == state::balanced)
                        shorter = false;
                    else
                        shorter = true;

                    if (_parent.is_header())
                        _parent.parent = balance_left(_heap, _node);
                    else if (_parent.left == _node)
                        _parent.left = balance_left(_heap, _node);
                    else
                        _parent.right = balance_left(_heap, _node);

                    _heap.update(parent, _parent);
                }
                break;
                }
            }

            if (shorter)
            {
                if (_parent.is_header())
                    return;
                else
                {
                    from = next_from;
                    _node = parent;
                }
            }
        }
    }

    void swap_long(long long* phurst, long long* second)
    {
        long long temporary = *phurst; *phurst = *second; *second = temporary;
    }

    void swap_heap_nodes(heap& heap, long long a, long long b)
    {
        heap_node _a = heap.get(a);
        heap_node _b = heap.get(b);
        swap_long(&_a.key, &_b.key);
        swap_long(&_a.address, &_b.address);
        heap.update(a, _a);
        heap.update(b, _b);
    }

    long long previous_slot(heap& heap, long long slot)
    {
        heap_node _slot = heap.get(slot);

        if (slot == 0)
            return _slot.right;
        else
        {
            if (_slot.left != 0)
            {
                slot = _slot.left;
                _slot = heap.get(slot);

                while (_slot.right != 0)
                {
                    slot = _slot.right;
                    _slot = heap.get(slot);
                }
            }
            else
            {
                long long y = _slot.parent;

                if (y == 0)
                    return 0;
                else
                {
                    heap_node _y = heap.get(y);

                    while (slot == _y.left)
                    {
                        slot = y;
                        y = _y.parent;
                        if (y == 0) break;
                        _y = heap.get(y);
                    }

                    slot = y;
                }
            }

            return slot;
        }
    }

    long long next_slot(heap heap, long long slot)
    {
        heap_node _slot = heap.get(slot);

        if (slot == 0)
            return _slot.left;
        else
        {
            if (_slot.right != 0)
            {
                slot = _slot.right;
                _slot = heap.get(slot);

                while (_slot.left != 0)
                {
                    slot = _slot.left;
                    _slot = heap.get(slot);
                }
            }
            else
            {
                long long y = _slot.parent;

                if (y == 0)
                    return y;
                else
                {
                    heap_node _y = heap.get(y);

                    while (slot == _y.right)
                    {
                        slot = y;
                        y = _y.parent;
                        if (y == 0) break;
                        _y = heap.get(y);
                    }

                    slot = y;
                }
            }

            return slot;
        }
    }

    dictionary<heap*, long long> heap_reference_counter;

    struct heap_bag
    {
        heap_node header;
        heap* _heap;

        heap_bag()
            : _heap(0)
        {
            try
            {
                long long count = heap_reference_counter[_heap];
                count++;
                heap_reference_counter[_heap] = count;
            }
            catch (...)
            {
                heap_reference_counter[_heap] = 1;
            }
        }

        heap_bag(string name,
            string directory)
        {
            _heap = new heap(name, directory);
            heap_reference_counter[_heap] = 1;
        }

        heap_bag(const heap_bag& hb)
            : header(hb.header),
            _heap(hb._heap)
        {
            long long count = heap_reference_counter[_heap];
            count++;
            heap_reference_counter[_heap] = count;
        }

        ~heap_bag()
        {
            long long count = heap_reference_counter[_heap];
            count--;
            if (count == 0)
            {
                if (_heap) delete _heap;
                heap_reference_counter.erase(_heap);
            }
            else
                heap_reference_counter[_heap] = count;
        }

        void destroy()
        {
            long long count = heap_reference_counter[_heap];
            count--;
            if (count == 0)
            {
                if (_heap) delete _heap;
                heap_reference_counter.erase(_heap);
            }
            else
                heap_reference_counter[_heap] = count;
        }

        heap_bag& operator=(const heap_bag& hb)
        {
            destroy();

            header = hb.header;
            _heap = hb._heap;

            try
            {
                long long count = heap_reference_counter[_heap];
                count++;
                heap_reference_counter[_heap] = count;
            }
            catch (...)
            {
                heap_reference_counter[_heap] = 1;
            }
            return *this;
        }

        void check_point()
        {
            _heap->check_point();
        }

        void reset()
        {
            _heap->reset();
        }

        long long get(long long size)
        {
            get_header();

            if (header.parent == 0)
                throw entry_not_found_exception();

            else
            {
                long long search = header.parent;

                heap_node _search = _heap->get(search);

                do
                {

                    if (size < _search.key)
                    {
                        search = _search.left;
                        if (search != 0) _search = _heap->get(search);
                    }

                    else if (size > _search.key)
                    {
                        search = _search.right;
                        if (search != 0) _search = _heap->get(search);
                    }

                    else break;

                } while (search != 0);

                if (search == 0)
                    throw entry_not_found_exception();
                else
                {
                    long long l_return = _search.address;
                    remove(search);
                    return l_return;
                }

            }
        }

        void add(long long l_size, long long l_address)
        {
            get_header();

            long long node = header.parent;

            if (node == 0)
            {
                header.parent = _heap->add(heap_node(0, l_size, l_address));
                header.left = header.parent;
                header.right = header.parent;
                put_header();
            }
            else
            {
                for (; ; )
                {
                    heap_node _node = _heap->get(node);

                    if (l_size < _node.key)
                    {
                        if (_node.left != 0)
                            node = _node.left;
                        else
                        {
                            long long new_node = _heap->add(heap_node(node, l_size, l_address));
                            _node.left = new_node;
                            _heap->update(node, _node);
                            if (header.left == node)
                            {
                                header.left = new_node;
                                put_header();
                            }
                            balance_tree(*_heap, node, direction::from_left);
                            return;
                        }
                    }

                    else
                    {
                        if (_node.right != 0)
                            node = _node.right;
                        else
                        {
                            long long new_node = _heap->add(heap_node(node, l_size, l_address));
                            _node.right = new_node;
                            _heap->update(node, _node);
                            if (header.right == node)
                            {
                                header.right = new_node;
                                put_header();
                            }
                            balance_tree(*_heap, node, direction::from_right);
                            return;
                        }
                    }
                }
            }
        }

        void get_header()
        {
            header = _heap->get(0);
        }

        void put_header()
        {
            _heap->update(0, header);
        }

        void remove(long long node_in)
        {
            long long node = node_in;

            heap_node _node = _heap->get(node);

            if (_node.left != 0 && _node.right != 0)
            {
                long long replace = _node.left;
                heap_node _replace = _heap->get(replace);

                while (_replace.right != 0)
                {
                    replace = _replace.right;
                    _replace = _heap->get(replace);
                }

                swap_heap_nodes(*_heap, node, replace);

                node = replace;
                _node = _heap->get(node);
            }

            long long parent = _node.parent;
            heap_node _parent = _heap->get(parent);

            long long from = (_parent.left == node) ? direction::from_left : direction::from_right;

            if (header.left == node)
            {
                long long n = next_slot(*_heap, node);

                if (n == 0)
                {
                    header.left = 0;
                    header.right = 0;
                }
                else
                    header.left = n;

                put_header();
            }
            else if (header.right == node)
            {
                long long p = previous_slot(*_heap, node);

                if (p == 0)
                {
                    header.left = 0;
                    header.right = 0;
                }
                else
                    header.right = p;

                put_header();
            }

            if (_node.left == 0)
            {
                if (parent == 0)
                {
                    header.parent = _node.right;
                    put_header();
                }
                else if (_parent.left == node)
                {
                    _parent.left = _node.right;
                    _heap->update(parent, _parent);
                }
                else
                {
                    _parent.right = _node.right;
                    _heap->update(parent, _parent);
                }

                if (_node.right != 0)
                {
                    heap_node right = _heap->get(_node.right);
                    right.parent = parent;
                    _heap->update(_node.right, right);
                }
            }
            else
            {
                if (parent == 0)
                {
                    header.parent = _node.left;
                    put_header();
                }
                else if (_parent.left == node)
                {
                    _parent.left = _node.left;
                    _heap->update(parent, _parent);
                }
                else
                {
                    _parent.right = _node.left;
                    _heap->update(parent, _parent);
                }

                if (_node.left != 0)
                {
                    heap_node left = _heap->get(_node.left);
                    left.parent = parent;
                    _heap->update(_node.left, left);
                }
            }

            if (parent != 0) balance_tree_remove(*_heap, parent, from);
            _heap->dispose(node);
        }
    };

    struct node_plus_address
    {
        long long address;
        node _node;

        node_plus_address() {}

        node_plus_address(long long l_address, const node& n_node) : _node(n_node), address(l_address) {}
    };

    struct log_file
    {
        file _log_file;
        file* _node_file;
        bool back_out;

        log_file(const string& name,
            file* node_file_set)
        {
            _node_file = node_file_set;

            _log_file = file(name,
                access_type::generic_read | access_type::generic_write,
                share_file::write | share_file::read,
                (const security_attributes*)0,
                file_action::always_open,
                file_flag::random_file | file_flag::write_through_file,
                (void*)0);

            recover();
        }

        bool recovered() { return back_out; }

        void write(long long address, const node& node)
        {
            node_plus_address to_right(address, node);
            long long file_size = _log_file.size();
            _log_file.set_pointer(file_size, (unsigned)file_position::at_beginning);
            _log_file.write((void*)&to_right, sizeof(node_plus_address));
        }

        void reset()
        {
            _log_file.set_pointer(0, (unsigned)file_position::at_beginning);
            _log_file.end_of_file();
        }

        void recover()
        {
            long long file_size = _log_file.size();

            if (file_size != 0)
            {
                back_out = true;

                long long l_record_offset = file_size - sizeof(node_plus_address);

                while (l_record_offset > 0)
                {
                    node_plus_address to_read;
                    _log_file.set_pointer(l_record_offset, (unsigned)file_position::at_beginning);
                    _log_file.read(&to_read, sizeof(node_plus_address));
                    _node_file->set_pointer(to_read.address, file_position::at_beginning);
                    _node_file->write((void*)&to_read._node, sizeof(node));
                    l_record_offset -= sizeof(node_plus_address);
                }

                _node_file->flush();
                reset();
            }
            else back_out = false;

        }
    };

    export class iplusplus_data_environment_variable_not_set_exception {};

    struct node_file
    {
        string node_filename;
        string node_stack_filename;
        string log_filename;

        file _node_file;
        node_stack* _node_stack;
        log_file* _log_file;

        node_file(string name)
        {
            string string_iplusplus;

            character buffer[1024];
            unsigned read = get_environment_variable(L"db", buffer, 1024);
            if (read == 0) throw iplusplus_data_environment_variable_not_set_exception();
            string_iplusplus = string(buffer);

            node_filename = string_iplusplus + L"\\" + name + L".n";
            node_stack_filename = string_iplusplus + L"\\" + name + L".m";
            log_filename = string_iplusplus + L"\\" + name + L".l";

            if (!contains())
            {
                _node_stack = new node_stack(node_stack_filename, true);

                _node_file = file(node_filename,
                    access_type::generic_read | access_type::generic_write,
                    share_file::write | share_file::read,
                    (security_attributes*)0,
                    file_action::create_new,
                    file_flag::random_file,
                    (handle)0);

                _log_file = new log_file(log_filename, &_node_file);
                reset();
                long long slot_count = 0;
                _node_stack->_node_stack.write(&slot_count, 8);
            }
            else
                _log_file = new log_file(log_filename, &_node_file);
        }

        node_file(string name,
            string directory)
        {
            node_filename = directory + string(L"\\") + name + L".n";
            node_stack_filename = directory + string(L"\\") + name + L".m";
            log_filename = directory + L"\\" + name + L".l";

            if (!contains())
            {
                _node_stack = new node_stack(node_stack_filename, true);

                _node_file = file(node_filename,
                    access_type::generic_read | access_type::generic_write,
                    share_file::write | share_file::read,
                    (security_attributes*)0,
                    file_action::create_new,
                    file_flag::random_file,
                    (handle)0);

                _log_file = new log_file(log_filename, &_node_file);
                reset();
                long long slot_count = 0;
                _node_stack->_node_stack.write(&slot_count, 8);
            }
            else
                _log_file = new log_file(log_filename, &_node_file);
        }

        ~node_file() { delete _node_stack; delete _log_file; }

        void reset()
        {
            _node_file.set_pointer(0, file_position::at_beginning);
            _node_file.end_of_file();
            add(node());
            _node_stack->reset();
            _log_file->reset();
        }

        long long add(node data)
        {
            long long slot_address = _node_stack->get();
            if (slot_address == invalid())
            {
                long long file_size = _node_file.size();
                _log_file->write(file_size, data);
                _node_file.set_pointer(file_size, file_position::at_beginning);
                _node_file.write(&data, sizeof(node));
                return file_size;
            }
            else
            {
                _node_file.set_pointer(slot_address, file_position::at_beginning);
                _log_file->write(slot_address, data);
                _node_file.write(&data, sizeof(node));
                return slot_address;
            }
        }

        void update(long long node_address, node data)
        {
            _node_file.set_pointer(node_address, file_position::at_beginning);
            _node_file.write(&data, sizeof(node));
        }

        node get(long long node_address)
        {
            node node_get;
            _node_file.set_pointer(node_address, file_position::at_beginning);
            _node_file.read(&node_get, sizeof(node));
            return node_get;
        }

        void dispose(long long slot_address)
        {
            _node_stack->add(slot_address);
        }

        bool contains()
        {
            try
            {
                _node_file = file(node_filename,
                    access_type::generic_read | access_type::generic_write,
                    share_file::write | share_file::read,
                    (const security_attributes*)0,
                    file_action::open_existing,
                    file_flag::random_file,
                    (handle)0);
            }
            catch (file_exception fe)
            {
                return false;
            }

            _node_stack = new node_stack(node_stack_filename, false);

            return true;
        }

        long long invalid()
        {
            return -1;
        }

        void check_point()
        {
            _node_file.flush();
            _log_file->reset();
        }
    };

    inline long long rotate_left(node_file& np, long long __node)
    {
        node _node = np.get(__node);
        long long parent = _node.parent;
        long long x = _node.right;
        node _x = np.get(x);
        _node.parent = x;
        _x.parent = parent;
        if (_x.left != 0)
        {
            node x_left = np.get(_x.left);
            x_left.parent = __node;
            np.update(_x.left, x_left);
        }
        _node.right = _x.left;
        _x.left = __node;
        np.update(__node, _node);
        np.update(x, _x);
        return x;
    }

    inline long long rotate_right(node_file& np, long long __node)
    {
        node _node = np.get(__node);
        long long parent = _node.parent;
        long long x = _node.left;
        node _x = np.get(x);
        _node.parent = x;
        _x.parent = parent;
        if (_x.right != 0)
        {
            node x_right = np.get(_x.right);
            x_right.parent = __node;
            np.update(_x.right, x_right);
        }
        _node.left = _x.right;
        _x.right = __node;
        np.update(__node, _node);
        np.update(x, _x);
        return x;
    }

    inline long long balance_left(node_file& np, long long __node)
    {
        long long new_node = 0;

        node _node = np.get(__node);

        long long left = _node.left;
        node _left = np.get(left);

        switch (_left.balance)
        {
        case state::left_high:
            _node.balance = state::balanced;
            _left.balance = state::balanced;
            np.update(__node, _node);
            np.update(left, _left);
            new_node = rotate_right(np, __node);
            break;

        case state::right_high:
        {
            long long sub_right = _left.right;
            node _sub_right = np.get(sub_right);

            switch (_sub_right.balance)
            {
            case state::balanced:
                _node.balance = state::balanced;
                _left.balance = state::balanced;
                np.update(__node, _node);
                np.update(left, _left);
                break;

            case state::right_high:
                _node.balance = state::balanced;
                _left.balance = state::left_high;
                np.update(__node, _node);
                np.update(left, _left);
                break;

            case state::left_high:
                _node.balance = state::right_high;
                _left.balance = state::balanced;
                np.update(__node, _node);
                np.update(left, _left);
                break;
            }
            _sub_right.balance = state::balanced;
            np.update(sub_right, _sub_right);
            _node.left = rotate_left(np, left);
            np.update(__node, _node);
            new_node = rotate_right(np, __node);
        }
        break;

        case state::balanced:
            _node.balance = state::left_high;
            _left.balance = state::right_high;
            np.update(__node, _node);
            np.update(left, _left);
            new_node = rotate_right(np, __node);
            break;
        }

        return new_node;
    }

    inline long long balance_right(node_file& np, long long __node)
    {
        long long new_node = 0;

        node _node = np.get(__node);

        long long right = _node.right;
        node _right = np.get(right);

        switch (_right.balance)
        {
        case state::right_high:
            _node.balance = state::balanced;
            _right.balance = state::balanced;
            np.update(__node, _node);
            np.update(right, _right);
            new_node = rotate_left(np, __node);
            break;

        case state::left_high:
        {
            long long sub_left = _right.left;
            node _sub_left = np.get(sub_left);

            switch (_sub_left.balance)
            {
            case state::balanced:
                _node.balance = state::balanced;
                _right.balance = state::balanced;
                np.update(__node, _node);
                np.update(right, _right);
                break;

            case state::left_high:
                _node.balance = state::balanced;
                _right.balance = state::right_high;
                np.update(__node, _node);
                np.update(right, _right);
                break;

            case state::right_high:
                _node.balance = state::left_high;
                _right.balance = state::balanced;
                np.update(__node, _node);
                np.update(right, _right);
                break;
            }
            _sub_left.balance = state::balanced;
            np.update(sub_left, _sub_left);
            _node.right = rotate_right(np, right);
            np.update(__node, _node);
            new_node = rotate_left(np, __node);
        }
        break;

        case state::balanced:
            _node.balance = state::right_high;
            _right.balance = state::left_high;
            np.update(__node, _node);
            np.update(right, _right);
            new_node = rotate_left(np, __node);
            break;
        }


        return new_node;
    }

    inline void balance_tree(node_file& np, long long __node, long long from)
    {
        bool taller = true;

        while (taller)
        {
            node _node = np.get(__node);

            long long parent = _node.parent;
            node _parent = np.get(parent);

            long long next_from = (_parent.left == __node) ? direction::from_left : direction::from_right;

            if (from == direction::from_left)
            {
                switch (_node.balance)
                {
                case state::left_high:
                    if (_parent.is_header())
                        _parent.parent = balance_left(np, __node);
                    else if (_parent.left == __node)
                        _parent.left = balance_left(np, __node);
                    else
                        _parent.right = balance_left(np, __node);
                    np.update(parent, _parent);
                    taller = false;
                    break;

                case state::balanced:
                    _node.balance = state::left_high;
                    np.update(__node, _node);
                    taller = true;
                    break;

                case state::right_high:
                    _node.balance = state::balanced;
                    np.update(__node, _node);
                    taller = false;
                    break;
                }
            }
            else
            {
                switch (_node.balance)
                {
                case state::left_high:
                    _node.balance = state::balanced;
                    np.update(__node, _node);
                    taller = false;
                    break;

                case state::balanced:
                    _node.balance = state::right_high;
                    np.update(__node, _node);
                    taller = true;
                    break;

                case state::right_high:
                    if (_parent.is_header())
                        _parent.parent = balance_right(np, __node);
                    else if (_parent.left == __node)
                        _parent.left = balance_right(np, __node);
                    else
                        _parent.right = balance_right(np, __node);
                    np.update(parent, _parent);
                    taller = false;
                    break;
                }
            }

            if (taller) // skip up a level
            {
                if (_parent.is_header())
                    return;
                else
                {
                    __node = parent;
                    from = next_from;
                }
            }
        }
    }

    inline void balance_tree_remove(node_file& np, long long __node, long long from)
    {
        //if (node == 0) return;

        bool shorter = true;

        while (shorter)
        {
            node _node = np.get(__node);

            long long parent = _node.parent;
            node _parent = np.get(parent);

            long long next_from = (_parent.left == __node) ? direction::from_left : direction::from_right;

            if (from == direction::from_left)
            {
                switch (_node.balance)
                {
                case state::left_high:
                    _node.balance = state::balanced;
                    np.update(__node, _node);
                    shorter = true;
                    break;

                case state::balanced:
                    _node.balance = state::right_high;
                    np.update(__node, _node);
                    shorter = false;
                    break;

                case state::right_high:
                {
                    node right = np.get(_node.right);

                    if (right.balance == state::balanced)
                        shorter = false;
                    else
                        shorter = true;

                    if (_parent.is_header())
                        _parent.parent = balance_right(np, __node);
                    else if (_parent.left == __node)
                        _parent.left = balance_right(np, __node);
                    else
                        _parent.right = balance_right(np, __node);

                    np.update(parent, _parent);
                }
                break;
                }
            }
            else
            {
                switch (_node.balance)
                {
                case state::right_high:
                    _node.balance = state::balanced;
                    np.update(__node, _node);
                    shorter = true;
                    break;

                case state::balanced:
                    _node.balance = state::left_high;
                    np.update(__node, _node);
                    shorter = false;
                    break;

                case state::left_high:
                {
                    node left = np.get(_node.left);

                    if (left.balance == state::balanced)
                        shorter = false;
                    else
                        shorter = true;

                    if (_parent.is_header())
                        _parent.parent = balance_left(np, __node);
                    else if (_parent.left == __node)
                        _parent.left = balance_left(np, __node);
                    else
                        _parent.right = balance_left(np, __node);

                    np.update(parent, _parent);
                }
                break;
                }
            }

            if (shorter)
            {
                if (_parent.is_header())
                    return;
                else
                {
                    from = next_from;
                    __node = parent;
                }
            }
        }
    }

    inline long long previous_slot(node_file& np, long long slot)
    {
        node _slot = np.get(slot);

        if (slot == 0)
            return _slot.right;
        else
        {
            if (_slot.left != 0)
            {
                slot = _slot.left;
                _slot = np.get(slot);

                while (_slot.right != 0)
                {
                    slot = _slot.right;
                    _slot = np.get(slot);
                }
            }
            else
            {
                long long y = _slot.parent;

                if (y == 0)
                    return 0;
                else
                {
                    node _y = np.get(y);

                    while (slot == _y.left)
                    {
                        slot = y;
                        y = _y.parent;
                        if (y == 0) break;
                        _y = np.get(y);
                    }

                    slot = y;
                }
            }

            return slot;
        }
    }

    inline long long next_slot(node_file& np, long long slot)
    {
        node _slot = np.get(slot);

        if (slot == 0)
            return _slot.left;
        else
        {
            if (_slot.right != 0)
            {
                slot = _slot.right;
                _slot = np.get(slot);

                while (_slot.left != 0)
                {
                    slot = _slot.left;
                    _slot = np.get(slot);
                }
            }
            else
            {
                long long y = _slot.parent;

                if (y == 0)
                    return y;
                else
                {
                    node _y = np.get(y);

                    while (slot == _y.right)
                    {
                        slot = y;
                        y = _y.parent;
                        if (y == 0) break;
                        _y = np.get(y);
                    }

                    slot = y;
                }
            }

            return slot;
        }
    }

    inline void swap_nodes(node_file& np, long long a, long long b)
    {
        node _a = np.get(a);
        node _b = np.get(b);
        swap_long(&_a.key, &_b.key);
        np.update(a, _a);
        np.update(b, _b);
    }

    inline long long depth(node_file& np, long long __node)
    {
        if (__node != 0)
        {
            node n = np.get(__node);
            long long left = n.left != 0 ? depth(np, n.left) : 0;
            long long right = n.right != 0 ? depth(np, n.right) : 0;
            return left < right ? right + 1 : left + 1;
        }
        else
            return 0;
    }

    inline long long count(node_file& np, long long __node)
    {
        if (__node != 0)
        {
            node n = np.get(__node);
            long long left = n.left != 0 ? count(np, n.left) : 0;
            long long right = n.right != 0 ? count(np, n.right) : 0;
            return left + right + 1;
        }
        else
            return 0;
    }

    template <class t>
    struct slot_file
    {
        string slot_file_name;
        string heap_file_name;
        file slot_file_instance;
        heap_bag* heap_file_instance;
        string directory;
        string name;

        void check_point()
        {
            heap_file_instance->check_point();
        }

        slot_file(const string& name_set)
        {
            name = name_set;
            string iplusplus_string;

            character buffer[4096];
            unsigned length = get_environment_variable(L"db", buffer, 4096);
            if (length == 0) throw new iplusplus_data_environment_variable_not_set_exception();

            iplusplus_string = string(buffer);

            directory = iplusplus_string;

            slot_file_name = directory + L"\\" + name + L".s";
            heap_file_name = directory + L"\\" + name + L".h";


            if (!exists())
            {
                heap_file_instance = new heap_bag(name, directory);

                slot_file_instance = file(slot_file_name,
                    access_type::generic_read | access_type::generic_write,
                    share_file::write | share_file::read,
                    (security_attributes*)0,
                    file_action::create_new,
                    file_flag::random_file | file_flag::write_through_file,
                    (handle)0);
            }
        }

        slot_file(const string& name_set,
            const string& directory_set)
        {
            name = name_set;
            directory = directory_set;

            slot_file_name = directory + L"\\" + name + L".s";
            heap_file_name = directory + L"\\" + name + L".h";

            if (!exists())
            {

                heap_file_instance = new heap_bag(name, directory);

                slot_file_instance = file(slot_file_name,
                    access_type::generic_read | access_type::generic_write,
                    share_file::write | share_file::read,
                    (security_attributes*)0,
                    file_action::create_new,
                    file_flag::random_file | file_flag::write_through_file,
                    (handle)0);
            }
        }

        ~slot_file() { delete heap_file_instance; }

        bool exists()
        {

            try
            {
                slot_file_instance = file(slot_file_name,
                    access_type::generic_read | access_type::generic_write,
                    share_file::write | share_file::read,
                    (security_attributes*)0,
                    file_action::open_existing,
                    file_flag::random_file | file_flag::write_through_file,
                    (handle)0);
            }
            catch (file_exception)
            {
                return false;
            }

            heap_file_instance = new heap_bag(name, directory);

            return true;
        }

        void reset()
        {
            heap_file_instance->reset();
            slot_file_instance.set_pointer(0, file_position::at_beginning);
            slot_file_instance.end_of_file();
        }

        long long add(t data)
        {
            oarchive oa;
            oa << data;
            long long added = add(oa);
            return added;
        }

        long long size(long long slot_address)
        {
            long long slot_size = 0;
            slot_file_instance.set_pointer(slot_address, file_position::at_beginning);
            slot_file_instance.read(&slot_size, 8);
            return slot_size;
        }

        long long add(void* buffer)
        {
            long long data_size = ((long long*)buffer)[0];
            try
            {
                long long slot_address = heap_file_instance->get(data_size);
                slot_file_instance.set_pointer(slot_address, file_position::at_beginning);
                slot_file_instance.write(buffer, data_size);
                delete[] buffer;
                return slot_address;
            }
            catch (entry_not_found_exception)
            {
                long long file_size = slot_file_instance.size();
                slot_file_instance.set_pointer(file_size, file_position::at_beginning);
                slot_file_instance.write(buffer, data_size);
                delete[] buffer;
                return file_size;
            }
        }

        t get(long long slot_address)
        {
            long long slot_size;
            slot_file_instance.set_pointer(slot_address, file_position::at_beginning);
            slot_file_instance.read(&slot_size, 8);
            char* buffer = new char[slot_size];
            slot_file_instance.set_pointer(slot_address, file_position::at_beginning);
            slot_file_instance.read(buffer, slot_size);
            iarchive ia(buffer);
            t _out;
            ia >> _out;
            delete[] buffer;
            return _out;
        }

        void dispose(long long slot_address)
        {
            heap_file_instance->add(size(slot_address), slot_address);
        }

        long long invalid()
        {
            return -1;
        }
    };

    dictionary<node_file*, long long> data_reference_count;

    template <class t>
    struct data_file
    {
        slot_file<t>* _slot_file;
        node_file* _node_file;

        data_file()
        {
            _slot_file = 0;
            _node_file = 0;
            try
            {
                long long count = data_reference_count[_node_file];
                count++;
                data_reference_count[_node_file] = count;
            }
            catch (...)
            {
                data_reference_count[_node_file] = 1;
            }
        }

        data_file(const string& name)
        {
            _slot_file = new slot_file<t>(name);
            _node_file = new node_file(name);

            if (_node_file->_log_file->recovered())
            {
                _slot_file->heap_file_instance->reset();
                _node_file->_node_stack->reset();
            }

            data_reference_count[_node_file] = 1;
        }

        data_file(const string& name,
            const string& directory)
        {
            _slot_file = new slot_file<t>(name, directory);
            _node_file = new node_file(name, directory);

            if (_node_file->_log_file->recovered())
            {
                _slot_file->heap_file_instance->rReset();
                _node_file->_node_stack->reset();
            }

            data_reference_count[_node_file] = 1;
        }

        ~data_file()
        {
            long long count = data_reference_count[_node_file];
            count--;
            if (count == 0)
            {
                if (_node_file)
                {
                    delete _slot_file;
                    delete _node_file;
                }
                data_reference_count.erase(_node_file);
            }
            else
                data_reference_count[_node_file] = count;
        }

        data_file(const data_file& dp)
            : _slot_file(dp._slot_file),
            _node_file(dp._node_file)
        {
            long long count = data_reference_count[_node_file];
            count++;
            data_reference_count[_node_file] = count;
        }

        data_file& operator=(const data_file& dp)
        {
            data_file::~data_file();
            _slot_file = dp._slot_file;
            _node_file = dp._node_file;
            try
            {
                long long count = data_reference_count[_node_file];
                count++;
                data_reference_count[_node_file] = count;
            }
            catch (...)
            {
                data_reference_count[_node_file] = 1;
            }
            return *this;
        }

        long long add(long long parent, t data)
        {
            node n(parent);
            n.key = _slot_file->add(data);
            long long new_node = _node_file->add(n);
            return new_node;
        }

        void update(long long previous, t data)
        {
            node n = _node_file->get(previous);
            long long old_key = n.key;
            n.key = _slot_file->add(data);
            _node_file->update(previous, n);
            _slot_file->dispose(old_key);
        }

        t get(long long address)
        {
            node n = _node_file->get(address);
            return _slot_file->get(n.key);
        }

        void reset()
        {
            _slot_file->reset();
            _node_file->reset();
        }

        void check_point()
        {
            _slot_file->check_point();
            _node_file->check_point();
        }

        void recover()
        {
            _node_file->_log_file->recover();
            if (_node_file->_log_file->recovered())
            {
                _slot_file->heap_file_instance->reset();
                _node_file->_node_stack->reset();
            }
        }
    };

    dictionary<handle, long long> lock_reference(handle_less);

    struct lock
    {
        void* sem;
        string name;

        lock() : sem(0)
        {
            try
            {
                long long count = lock_reference[sem];
                count++;
                lock_reference[sem] = count;
            }
            catch (entry_not_found_exception)
            {
                lock_reference[sem] = 1;
            }
        }

        lock(const string& _file_name)
            : name(_file_name)
        {
            sem = create_exclusive((security_attributes*)0, false, (const wchar_t*)name);
            if (sem == (void*)0)
            {
                string estring = string(L"error opening semaphore: ") + name + string(L" error: ") + get_last_error_string();
                throw file_exception(estring);
            }

            lock_reference[sem] = 1;
        }

        ~lock()
        {
            long long count = lock_reference[sem];
            count--;
            if (count == 0)
            {
                if (sem != 0)
                {

                    bool success = close_handle(sem);

                    if (!success)
                    {
                        string estring = string(L"error closeing handle: ") + name + string(L"  error: ") + get_last_error_string();
                        throw file_exception((const character*)estring);
                    }

                }
                lock_reference >> sem;
            }
            else
            {
                lock_reference[sem] = count;
            }
        }

        void destroy()
        {
            long long count = lock_reference[sem];
            count--;
            if (count == 0)
            {
                if (sem != 0)
                {

                    bool success = close_handle(sem);

                    if (!success)
                    {
                        string estring = string(L"error closeing handle: ") + name + string(L"  error: ") + get_last_error_string();
                        throw file_exception(estring);
                    }

                }
                lock_reference >> sem;
            }
            else
            {
                lock_reference[sem] = count;
            }
        }

        lock& operator=(const lock& l)
        {
            destroy();
            sem = l.sem;
            name = l.name;
            long long count = lock_reference[sem];
            count++;
            lock_reference[sem] = count;
            return *this;
        }

        void request()
        {
            wait_for_single_object(sem, -1);
        }

        void release()
        {
            bool success = release_exclusive(sem);

            if (!success)
            {
                string estring = string(L"error releaseing semaphore: ") + name + string(L"  error: ") + get_last_error_string();
                throw file_exception(estring);
            }
        }
    };

     export template <class t>
        struct set_iterator
    {
        long long slot_number;
        data_file<t>* dp;

        set_iterator() {}

        set_iterator(data_file<t>* df_set,
            long long n)
        {
            slot_number = n;
            dp = df_set;
        }

        set_iterator(const set_iterator<t>& i) : slot_number(i.slot_number), dp(i.dp) {}

        t operator*() const
        {
            return dp->get(slot_number);
        }

        set_iterator<t>& operator++()
        {
            slot_number = next_slot(*(dp->_node_file), slot_number);
            return *this;
        }

        set_iterator<t> operator++(int)
        {
            set_iterator<t> save = *this; ++* this; return save;
        }

        set_iterator<t>& operator--()
        {
            slot_number = previous_slot(*(dp->_node_file), slot_number);
            return *this;
        }

        set_iterator<t> operator--(int)
        {
            set_iterator<t> save = *this; --*this; return save;
        }

        bool operator==(const set_iterator<t>& y) const { return slot_number == y.slot_number; }

        bool operator!=(const set_iterator<t>& y) const { return slot_number != y.slot_number; }

        bool is_header() const { return slot_number == 0; }
    };

    export  template <class t>
        struct set
    {
        typedef bool (*is_less)(const t&, const t&);

        node header;
        is_less less;
        data_file<t>* dp;
        lock* semaphore;

        set(const char* name,
            is_less C = compare)
            : less(C)
        {
            semaphore = new lock(standard::string(name));
            request();
            try
            {
                dp = new data_file<t>(standard::string(name));
            }
            catch (...) { release(); throw; }
            release();
        }

        set(const char* name,
            const char* directory,
            is_less C = compare)
            : less(C)
        {
            semaphore = new lock(standard::string(name));
            request();
            try
            {
                dp = new data_file<t>(standard::string(name), standard::string(directory));
            }
            catch (...) { release(); throw; }
            release();
        }

        set(const wchar_t* name,
            is_less C = compare)
            : less(C)
        {
            semaphore = new lock(standard::string(name));
            request();
            try
            {
                dp = new data_file<t>(standard::string(name));
            }
            catch (...) { release(); throw; }
            release();
        }

        set(const wchar_t* name,
            const wchar_t* directory,
            is_less C = compare)
            : less(C)
        {
            semaphore = new lock(standard::string(name));
            request();
            try
            {
                dp = new data_file<t>(standard::string(name), standard::string(directory));
            }
            catch (...) { release(); throw; }
            release();
        }

        ~set()
        {
            delete semaphore;
            delete dp;
        }

        set_iterator<t> begin()
        {
            set_iterator<t> s(dp, 0);
            s++;
            return s;
        }

        set_iterator<t> end() { return set_iterator<t>(dp, 0); }

        void reorg()
        {
            request();
            set<t> r(name() + L"r");
            r.clear();
            for (t _t : *this) r << _t;
            clear();
            for (t _t : r) *this << _t;
            r.clear();
            release();
        }

        string name()
        {
            return dp->_slot_file->name;
        }

        string directory()
        {
            return dp->slot_file->directory;
        }

        void recover()
        {
            dp->recover();
            get_header();
        }

        t phurst()
        {
            t key;
            request();
            try
            {
                recover();
                if (header.parent == 0) throw entry_not_found_exception();
                key = dp->get(header.left);
            }
            catch (...) { release(); throw; }
            release();
            return key;
        }

        t last()
        {
            t key;
            request();
            try
            {
                recover();
                if (header.parent == 0) throw entry_not_found_exception();
                key = dp->get(header.right);
            }
            catch (...) { release(); throw; }
            release();
            return key;
        }

        long long depth()
        {
            long long d = 0;
            request();
            try
            {
                recover();
                d = depth(dp->_node_file, header.parent);
            }
            catch (...) { release(); throw; }
            release();
            return d;
        }

        long long count()
        {
            long long l = 0;
            request();
            try
            {
                recover();
                l = count(dp->_node_file, header.parent);
            }
            catch (...) { release(); throw; }
            release();
            return l;
        }

        bool contains(const t& key)
        {
            request();
            try
            {
                recover();

                if (header.parent == 0)
                {
                    release();
                    return false;
                }
                else
                {
                    long long search = header.parent;

                    node _search = dp->_node_file->get(search);

                    do
                    {
                        t _key = dp->_slot_file->get(_search.key);

                        bool less = less(key, _key);
                        bool greater = less(_key, key);

                        if (less)
                        {
                            search = _search.left;
                            if (search != 0) _search = dp->_node_file->get(search);
                        }

                        else if (greater)
                        {
                            search = _search.right;
                            if (search != 0) _search = dp->_node_file->get(search);
                        }

                        else break;

                    } while (search != 0);

                    release();

                    return search != 0;

                }
            }
            catch (...) { release(); throw; }
        }

        void update(const t& data)
        {
            request();
            try
            {
                recover();
                long long slot = search(data);
                if (slot != 0)
                {
                    node node = dp->_node_file->get(slot);
                    t previous = dp->slot_file->get(node.key);
                    dp->update(slot, data);
                    dp->check_point();
                }
                else
                    internal_addd(data);
            }
            catch (...) { release(); throw; }
            release();
        }

        set<t>& operator<<(const t& data)
        {
            add(data);
            return *this;
        }

        void add(const t& data)
        {
            request();
            try
            {
                recover();

                long long __node = header.parent;

                if (__node == 0)
                {
                    header.parent = dp->add(0, data);
                    header.left = header.parent;
                    header.right = header.parent;
                    put_header();
                    dp->check_point();
                    release();
                }
                else
                {
                    for (; ; )
                    {
                        node _node = dp->_node_file->get(__node);
                        t key = dp->_slot_file->get(_node.key);

                        bool _less = less(data, key);
                        bool _greater = less(key, data);

                        if (!_less && !_greater) throw entry_already_exists_exception();

                        else if (_less)
                        {
                            if (_node.left != 0)
                                __node = _node.left;
                            else
                            {
                                long long new_node = dp->add(__node, data);
                                _node.left = new_node;
                                dp->_node_file->update(__node, _node);
                                if (header.left == __node)
                                {
                                    header.left = new_node;
                                    put_header();
                                }
                                balance_tree(*(dp->_node_file), __node, direction::from_left);
                                dp->check_point();
                                release();
                                return;
                            }
                        }

                        else
                        {
                            if (_node.right != 0)
                                __node = _node.right;
                            else
                            {
                                long long new_node = dp->add(__node, data);
                                _node.right = new_node;
                                dp->_node_file->update(__node, _node);
                                if (header.right == __node)
                                {
                                    header.right = new_node;
                                    put_header();
                                }
                                balance_tree(*(dp->_node_file), __node, direction::from_right);
                                dp->check_point();
                                release();
                                return;
                            }
                        }
                    }
                }
            }
            catch (...) { release(); throw; }
        }

        void internal_add(const t& data)
        {
            long long __node = header.parent;

            if (__node == 0)
            {
                header.parent = dp->ad(0, data);
                header.left = header.parent;
                header.right = header.parent;
                put_header();
                dp->check_point();
            }
            else
            {
                for (; ; )
                {
                    node _node = dp->_node_file->get(__node);
                    t key = dp->slot_file.get(_node.key);

                    bool less = less(data, key);
                    bool greater = less(key, data);

                    if (!less && !greater) throw entry_already_exists_exception();

                    else if (less)
                    {
                        if (_node.left != 0)
                            __node = _node.left;
                        else
                        {
                            long long new_node = dp->ad(__node, data);
                            _node.left = new_node;
                            dp->_node_file->update(__node, _node);
                            if (header.left == __node)
                            {
                                header.left = new_node;
                                put_header();
                            }
                            balance_tree(dp->_node_file, __node, direction::from_left);
                            dp->check_point();
                            return;
                        }
                    }

                    else
                    {
                        if (_node.right != 0)
                            __node = _node.right;
                        else
                        {
                            long long new_node = dp->ad(__node, data);
                            _node.right = new_node;
                            dp->_node_file->update(__node, _node);
                            if (header.right == __node)
                            {
                                header.right = new_node;
                                put_header();
                            }
                            balance_tree(dp->_node_file, __node, direction::from_right);
                            dp->check_point();
                            return;
                        }
                    }
                }
            }
        }

        t find(const t& value)
        {
            t found;
            request();
            try
            {
                recover();
                long long slot_number = search(value);
                if (slot_number == 0)
                    throw entry_not_found_exception();

                found = dp->get(slot_number);
            }
            catch (...) { release(); throw; }
            release();
            return found;
        }

        void get_header()
        {
            header = dp->_node_file->get(0);
        }

        void put_header()
        {
            dp->_node_file->update(0, header);
        }

        void clear()
        {
            request();
            try
            {
                dp->reset();
            }
            catch (...) { release(); throw; }
            release();
        }

        set<t>& operator>>(t data)
        {
            remove(data);
            return *this;
        }


        void remove(const t& data)
        {
            request();
            try
            {
                recover();

                long long __node = header.parent;

                for (; ; )
                {

                    if (__node == 0) throw entry_not_found_exception();


                    node _node = dp->_node_file->get(__node);

                    t key = dp->_slot_file->get(_node.key);

                    bool _less = less(data, key);
                    bool _greater = less(key, data);

                    if (_less)
                        __node = _node.left;

                    else if (_greater)
                        __node = _node.right;

                    else
                    {
                        if (_node.left != 0 && _node.right != 0)
                        {
                            long long replace = _node.left;
                            node _replace = dp->_node_file->get(replace);

                            while (_replace.right != 0)
                            {
                                replace = _replace.right;
                                _replace = dp->_node_file->get(replace);
                            }

                            swap_nodes(*(dp->_node_file), __node, replace);

                            __node = replace;
                            _node = dp->_node_file->get(__node);
                        }

                        long long parent = _node.parent;
                        node _parent = dp->_node_file->get(parent);

                        long long from = (_parent.left == __node) ? direction::from_left : direction::from_right;

                        if (header.left == __node)
                        {
                            long long n = next_slot(*(dp->_node_file), __node);

                            if (n == 0)
                            {
                                header.left = 0;
                                header.right = 0;
                            }
                            else
                                header.left = n;

                            put_header();
                        }
                        else if (header.right == __node)
                        {
                            long long p = previous_slot(*(dp->_node_file), __node);

                            if (p == 0)
                            {
                                header.left = 0;
                                header.right = 0;
                            }
                            else
                                header.right = p;

                            put_header();
                        }

                        if (_node.left == 0)
                        {
                            if (parent == 0)
                            {
                                header.parent = _node.right;
                                put_header();
                            }
                            else if (_parent.left == __node)
                            {
                                _parent.left = _node.right;
                                dp->_node_file->update(parent, _parent);
                            }
                            else
                            {
                                _parent.right = _node.right;
                                dp->_node_file->update(parent, _parent);
                            }

                            if (_node.right != 0)
                            {
                                node right = dp->_node_file->get(_node.right);
                                right.parent = parent;
                                dp->_node_file->update(_node.right, right);
                            }
                        }
                        else
                        {
                            if (parent == 0)
                            {
                                header.parent = _node.left;
                                put_header();
                            }
                            else if (_parent.left == __node)
                            {
                                _parent.left = _node.left;
                                dp->_node_file->update(parent, _parent);
                            }
                            else
                            {
                                _parent.right = _node.left;
                                dp->_node_file->update(parent, _parent);
                            }

                            if (_node.left != 0)
                            {
                                node left = dp->_node_file->get(_node.left);
                                left.parent = parent;
                                dp->_node_file->update(_node.left, left);
                            }
                        }

                        if (parent != 0) balance_tree_remove(*(dp->_node_file), parent, from);

                        dp->_node_file->dispose(__node);
                        dp->_slot_file->dispose(_node.key);

                        dp->check_point();
                        break;
                    }
                }
            }
            catch (...) { release(); throw; }
            release();
        }

        void request() { semaphore->request(); }

        void release() { semaphore->release(); }

        long long above(const t& data)
        {
            long long y = 0;
            long long x = header.parent;

            while (x != 0)
            {
                node _x = dp->_node_file->get(x);
                t key = dp->slot_file.get(_x.key);

                if (less(data, key))
                {
                    y = x;
                    x = _x.left;
                }
                else
                    x = _x.right;
            }

            return y;
        }

        long long below(const t& data)
        {
            long long y = 0;
            long long x = header.parent;

            while (x != 0)
            {
                node _x = dp->_node_file->get(x);
                t key = dp->slot_file.get(_x.key);

                if (!less(key, data))
                    x = _x.left;
                else
                {
                    y = x; x = _x.right;
                }
            }

            return y;
        }

        long long search(const t& data)
        {
            if (header.parent == 0)
                return 0;
            else
            {
                long long search = header.parent;
                node _search = dp->_node_file->get(search);

                do
                {
                    t key = dp->_slot_file->get(_search.key);

                    bool _less = less(data, key);
                    bool _greater = less(key, data);

                    if (_less)
                    {
                        search = _search.left;
                        _search = dp->_node_file->get(search);
                    }

                    else if (_greater)
                    {
                        search = _search.right;
                        _search = dp->_node_file->get(search);
                    }

                    else break;

                } while (search != 0);

                return search;
            }
        }
    };

    export template<class t>
        std::stringstream& operator<<(std::stringstream& s, const set<t>& ouut)
    {
        for (t o : ouut) s << o;
        return s;
    }

    export template<class t>
        std::stringstream& operator>>(std::stringstream& s, set<t>& set_ouut)
    {
        set_ouut.clear();
        t t_in;
        s >> t_in;
        while (!s.bad())
        {
            set_ouut << t_in;
            s >> t_in;
        }
        return s;
    }

    export template <class k, class t>
        int compare_key(k a, t b)
    {
        if (a < b) return -1;
        if (!(a == b)) return 1;
        return 0;
    }

    export template <class k, class t>
        class tree
    {
    public:

        set<t> s;

        typedef int (*key_value_compare)(const k&, const t&);

        key_value_compare key_too_value;

        tree(const char* name, key_value_compare key, bool (*keycomparer)(const t&, const t&) = compare)
            : s(name, keycomparer), key_too_value(key) {}

        tree(const char* name, const char* directory, key_value_compare key, bool (*keycompareer)(const t&, const t&) = compare)
            : s(name, directory, keycompareer), key_too_value(key) {}

        tree(const wchar_t* name, key_value_compare key, bool (*keycomparer)(const t&, const t&) = compare)
            : s(name, keycomparer), key_too_value(key) {}

        tree(const wchar_t* name, const wchar_t* directory, key_value_compare key, bool (*keycompareer)(const t&, const t&) = compare)
            : s(name, directory, keycompareer), key_too_value(key) {}

        tree<k, t>& operator<<(const t& data)
        {
            s << data;
            return *this;
        }

        set_iterator<t> begin()
        {
            return s.begin();
        }

        set_iterator<t> end() { return s.end(); }

        void clear() { s.clear(); }

        void reorg() { s.reorg(); }

        t operator[](const k& key)
        {
            return get(key);
        }

        t get(const k& key)
        {
            t find;

            request();
            try
            {
                recover();

                if (s.header.parent == 0)
                    throw entry_not_found_exception();

                else
                {
                    long long search = s.header.parent;

                    node _search = s.dp->_node_file->get(search);

                    do
                    {
                        find = s.dp->_slot_file->get(_search.key);

                        int c = key_too_value(key, find);

                        if (c < 0)
                        {
                            search = _search.left;
                            if (search != 0) _search = s.dp->_node_file->get(search);
                        }

                        else if (c > 0)
                        {
                            search = _search.right;
                            if (search != 0) _search = s.dp->_node_file->get(search);
                        }

                        else break;

                    } while (search != 0);

                    if (search == 0) throw entry_not_found_exception();

                    release();

                    return find;
                }
            }
            catch (...) { release(); throw; }
        }

        void request() { s.request(); }
        void release() { s.release(); }
        void recover() { s.recover(); }

        void remove(const k& data)
        {
            request();
            try
            {
                recover();

                long long __node = s.header.parent;

                for (; ; )
                {
                    if (__node == 0) throw entry_not_found_exception();

                    node _node = s.dp->_node_file->get(__node);
                    t key = s.dp->_slot_file->get(_node.key);

                    int c = key_too_value(data, key);

                    if (c < 0)
                        __node = _node.left;

                    else if (c > 0)
                        __node = _node.right;

                    else
                    {
                        if (_node.left != 0 && _node.right != 0)
                        {
                            long long replace = _node.left;
                            node _replace = s.dp->_node_file->get(replace);

                            while (_replace.right != 0)
                            {
                                replace = _replace.right;
                                _replace = s.dp->_node_file->get(replace);
                            }

                            swap_nodes(*(s.dp->_node_file), __node, replace);

                            __node = replace;
                            _node = s.dp->_node_file->get(__node);
                        }

                        long long parent = _node.parent;
                        node _parent = s.dp->_node_file->get(parent);

                        long long from = (_parent.left == __node) ? direction::from_left : direction::from_right;

                        if (s.header.left == __node)
                        {
                            long long n = next_slot(*(s.dp->_node_file), __node);

                            if (n == 0)
                            {
                                s.header.left = 0;
                                s.header.right = 0;
                            }
                            else
                                s.header.left = n;

                            s.put_header();
                        }
                        else if (s.header.right == __node)
                        {
                            long long p = previous_slot(*(s.dp->_node_file), __node);

                            if (p == 0)
                            {
                                s.header.left = 0;
                                s.header.right = 0;
                            }
                            else
                                s.header.right = p;

                            s.put_header();
                        }

                        if (_node.left == 0)
                        {
                            if (parent == 0)
                            {
                                s.header.parent = _node.right;
                                s.put_header();
                            }
                            else if (_parent.left == __node)
                            {
                                _parent.left = _node.right;
                                s.dp->_node_file->update(parent, _parent);
                            }
                            else
                            {
                                _parent.right = _node.right;
                                s.dp->_node_file->update(parent, _parent);
                            }

                            if (_node.right != 0)
                            {
                                node right = s.dp->_node_file->get(_node.right);
                                right.parent = parent;
                                s.dp->_node_file->update(_node.right, right);
                            }
                        }
                        else
                        {
                            if (parent == 0)
                            {
                                s.header.parent = _node.left;
                                s.put_header();
                            }
                            else if (_parent.left == __node)
                            {
                                _parent.left = _node.left;
                                s.dp->_node_file->update(parent, _parent);
                            }
                            else
                            {
                                _parent.right = _node.left;
                                s.dp->_node_file->update(parent, _parent);
                            }

                            if (_node.left != 0)
                            {
                                node left = s.dp->_node_file->get(_node.left);
                                left.parent = parent;
                                s.dp->_node_file->update(_node.left, left);
                            }
                        }

                        if (parent != 0) balance_tree_remove(*(s.dp->_node_file), parent, from);

                        s.dp->_node_file->dispose(__node);
                        s.dp->_slot_file->dispose(_node.key);

                        s.dp->check_point();
                        break;
                    }
                }
            }
            catch (...) { release(); throw; }
            release();
        }

        bool contains(const k& data)
        {
            request();
            try
            {
                recover();

                long long __node = s.header.parent;

                for (; ; )
                {
                    if (__node == 0) return false;

                    node _node = s.dp->_node_file->get(__node);
                    t key = s.dp->_slot_file->get(_node.key);

                    int c = key_too_value(data, key);

                    if (c < 0)
                        __node = _node.left;

                    else if (c > 0)
                        __node = _node.right;

                    else return true;
                }
            }
            catch (...) { release(); return false; }
            release();
        }
    };

    export template<class k, class t>
        std::stringstream& operator<<(std::stringstream& s, const tree<k, t>& ouut)
    {
        for (t o : ouut.s) s << o;
        return s;
    }

    export template<class k, class t>
        std::stringstream& operator>>(std::stringstream& s, tree<k, t>& ouut)
    {
        ouut.s.clear();
        t t_in;
        s >> t_in;
        while (!s.bad())
        {
            ouut << t_in;
            s >> t_in;
        }
        return s;
    }

    export template <class c, class t>
        struct dictionary
    {
        set<key_value<c, t>> s;

        dictionary(const char* name)
            : s(name) {}

        dictionary(const char* name, const char* directory)
            : s(name, directory) {}


        dictionary(const wchar_t* name)
            : s(name) {}

        dictionary(const wchar_t* name, const wchar_t* directory)
            : s(name, directory) {}

        void add(c key, t value)
        {
            try { s >> key_value<c, t>(key, value); }
            catch (...) {}
            s << key_value<c, t>(key, value);
        }

        void erase(c key)
        {
            s >> key_value<c, t>(key);
        }

        t get(c key)
        {
            return s.find(key_value<c, t>(key)).value;
        }

        bool contains(c key)
        {
            try
            {
                s.find(key_value<c, t>(key));
                return true;
            }
            catch (...)
            {
                return false;
            }
        }

        void clear() { s.clear(); }

        set_iterator<key_value<c, t>> begin() { return s.begin(); }

        set_iterator<key_value<c, t>> end() { return s.end(); }

        const t& operator[](const c& key) const { return find(key).value(); }

        class reference
        {
        public:

            reference(dictionary<c, t>& dicSet, const c& keySet)
                : dic(&dicSet), key(&keySet) {}

            reference& operator=(const t& value)
            {
                dic->add(*key, value);
                return *this;
            }

            reference& operator=(const reference& reph)
            {
                dic->ad(*key, (t&)reph);
                return *this;
            }

            operator t () const
            {
                return dic->get(*key);
            }

            dictionary<c, t>* dic;
            const c* key;
        };

        reference operator[](const c& key) { return reference(*this, key); }

        dictionary<c, t>& operator>>(const c& key) { erase(key); return *this; }
    };

    export template<class k, class t>
        std::stringstream& operator<<(std::stringstream& s, const dictionary<k, t>& ouut)
    {
        for (t o : ouut.s) s << o;
        return s;
    }

    export template<class k, class t>
        std::stringstream& operator>>(std::stringstream& s, dictionary<k, t>& ouut)
    {
        ouut.s.clear();
        key_value<k, t> _in;
        s >> _in;
        while (!s.bad())
        {
            ouut << _in;
            s >> _in;
        }
        return s;
    }

    export template <class t>
        class bag
    {
    public:
        typedef bool (*is_less)(const t&, const t&);

        node header;
        is_less less;
        data_file<t>* dp;
        lock* semaphore;

        bag(const wchar_t* name,
            is_less C = compare)
            : less(C)
        {
            semaphore = new lock(standard::string(name));
            request();
            try
            {
                dp = new data_file<t>(standard::string(name));
            }
            catch (...) { release(); throw; }
            release();
        }

        bag(const wchar_t* name,
            const wchar_t* directory,
            is_less C = compare)
            : less(C)
        {
            semaphore = new lock(standard::string(name));
            request();
            try
            {
                dp = new data_file<t>(standard::string(name), standard::string(directory));
            }
            catch (...) { release(); throw; }
            release();
        }

        ~bag()
        {
            delete semaphore;
            delete dp;
        }

        set_iterator<t> begin()
        {
            set_iterator<t> s(dp, 0);
            s++;
            return s;
        }

        set_iterator<t> end() { return set_iterator<t>(dp, 0); }

        void reorg()
        {
            request();
            set<t> r(name() + "r");
            r.clear();
            for (t _t : *this) r << _t;
            clear();
            for (t _t : r) *this << _t;
            r.clear();
            release();
        }

        //*** properties ***

        string name()
        {
            return dp->_slot_file->name;
        }

        string directory()
        {
            return dp->slot_file->directory;
        }

        void recover()
        {
            dp->recover();
            get_header();
        }

        t phurst()
        {
            t key;
            request();
            try
            {
                recover();
                if (header.parent == 0) throw entry_not_found_exception();
                key = dp->get(header.left);
            }
            catch (...) { release(); throw; }
            release();
            return key;
        }

        t last()
        {
            t key;
            request();
            try
            {
                recover();
                if (header.parent == 0) throw entry_not_found_exception();
                key = dp->get(header.right);
            }
            catch (...) { release(); throw; }
            release();
            return key;
        }


        long long depth()
        {
            long long d = 0;
            request();
            try
            {
                recover();
                d = depth(dp->_node_file, header.parent);
            }
            catch (...) { release(); throw; }
            release();
            return d;
        }

        long long count()
        {
            long long l = 0;
            request();
            try
            {
                recover();
                l = count(dp->_node_file, header.parent);
            }
            catch (...) { release(); throw; }
            release();
            return l;
        }

        bool contains(t key)
        {
            request();
            try
            {
                recover();

                if (header.parent == 0)
                {
                    release();
                    return false;
                }
                else
                {
                    long long search = header.parent;

                    node _search = dp->_node_file->get(search);

                    do
                    {
                        t _key = dp->_slot_file->get(_search.key);

                        bool less = less(key, _key);
                        bool greater = less(_key, key);

                        if (less)
                        {
                            search = _search.left;
                            if (search != 0) _search = dp->_node_file->get(search);
                        }

                        else if (greater)
                        {
                            search = _search.right;
                            if (search != 0) _search = dp->_node_file->get(search);
                        }

                        else break;

                    } while (search != 0);

                    release();

                    return search != 0;

                }
            }
            catch (...) { release(); throw; }
        }

        //*** methods ***

        bag<t>& operator<<(t data)
        {
            ad(data);
            return *this;
        }

        void ad(t data)
        {
            request();
            try
            {
                recover();

                long long __node = header.parent;

                if (__node == 0)
                {
                    header.parent = dp->ad(0, data);
                    header.left = header.parent;
                    header.right = header.parent;
                    put_header();
                    dp->check_point();
                    release();
                }
                else
                {
                    for (; ; )
                    {
                        node _node = dp->_node_file->get(__node);
                        t key = dp->_slot_file->get(_node.key);

                        bool less = less(data, key);

                        if (less)
                        {
                            if (_node.left != 0)
                                __node = _node.left;
                            else
                            {
                                long long new_node = dp->ad(__node, data);
                                _node.left = new_node;
                                dp->_node_file->update(__node, _node);
                                if (header.left == __node)
                                {
                                    header.left = new_node;
                                    put_header();
                                }
                                balance_tree(*(dp->_node_file), __node, direction::from_left);
                                dp->check_point();
                                release();
                                return;
                            }
                        }

                        else
                        {
                            if (_node.right != 0)
                                __node = _node.right;
                            else
                            {
                                long long new_node = dp->ad(__node, data);
                                _node.right = new_node;
                                dp->_node_file->update(__node, _node);
                                if (header.right == __node)
                                {
                                    header.right = new_node;
                                    put_header();
                                }
                                balance_tree(*(dp->_node_file), __node, direction::from_right);
                                dp->check_point();
                                release();
                                return;
                            }
                        }
                    }
                }
            }
            catch (...) { release(); throw; }
        }

        void internal_add(t data)
        {
            long long __node = header.parent;

            if (__node == 0)
            {
                header.parent = dp->ad(0, data);
                header.left = header.parent;
                header.right = header.parent;
                put_header();
                dp->check_point();
            }
            else
            {
                for (; ; )
                {
                    node _node = dp->_node_file->get(__node);
                    t key = dp->slot_file.get(_node.key);

                    bool less = less(data, key);
                    bool greater = less(key, data);

                    if (!less && !greater) throw entry_already_exists_exception();

                    else if (less)
                    {
                        if (_node.left != 0)
                            __node = _node.left;
                        else
                        {
                            long long new_node = dp->ad(__node, data);
                            _node.left = new_node;
                            dp->_node_file->update(__node, _node);
                            if (header.left == __node)
                            {
                                header.left = new_node;
                                put_header();
                            }
                            balance_tree(dp->_node_file, __node, direction::from_left);
                            dp->check_point();
                            return;
                        }
                    }

                    else
                    {
                        if (_node.right != 0)
                            __node = _node.right;
                        else
                        {
                            long long new_node = dp->ad(__node, data);
                            _node.right = new_node;
                            dp->_node_file->update(__node, _node);
                            if (header.right == __node)
                            {
                                header.right = new_node;
                                put_header();
                            }
                            balance_tree(dp->_node_file, __node, direction::from_right);
                            dp->check_point();
                            return;
                        }
                    }
                }
            }
        }

        t find(t value)
        {
            t found;
            request();
            try
            {
                recover();
                long long slot_number = search(value);
                if (slot_number == 0)
                    throw entry_not_found_exception();

                found = dp->get(slot_number);
            }
            catch (...) { release(); throw; }
            release();
            return found;
        }

        void get_header()
        {
            header = dp->_node_file->get(0);
        }

        void put_header()
        {
            dp->_node_file->update(0, header);
        }

        void clear()
        {
            request();
            try
            {
                dp->reset();
            }
            catch (...) { release(); throw; }
            release();
        }

        set<t>& operator>>(t data)
        {
            remove(data);
            return *this;
        }

        void remove(t data)
        {
            request();
            try
            {
                recover();

                long long __node = header.parent;

                for (; ; )
                {
                    if (__node == 0) throw entry_not_found_exception();

                    node _node = dp->_node_file->get(__node);
                    t key = dp->_slot_file->get(_node.key);

                    bool less = less(data, key);
                    bool greater = less(key, data);

                    if (less)
                        __node = _node.left;

                    else if (greater)
                        __node = _node.right;

                    else
                    {
                        if (_node.left != 0 && _node.right != 0)
                        {
                            long long replace = _node.left;
                            node _replace = dp->_node_file->get(replace);

                            while (_replace.right != 0)
                            {
                                replace = _replace.right;
                                _replace = dp->_node_file->get(replace);
                            }

                            swap_nodes(*(dp->_node_file), __node, replace);

                            __node = replace;
                            _node = dp->_node_file->get(__node);
                        }

                        long long parent = _node.parent;
                        node _parent = dp->_node_file->get(parent);

                        long long from = (_parent.left == __node) ? direction::from_left : direction::from_right;

                        if (header.left == __node)
                        {
                            long long n = next_slot(*(dp->_node_file), __node);

                            if (n == 0)
                            {
                                header.left = 0;
                                header.right = 0;
                            }
                            else
                                header.left = n;

                            put_header();
                        }
                        else if (header.right == __node)
                        {
                            long long p = previous_slot(*(dp->_node_file), __node);

                            if (p == 0)
                            {
                                header.left = 0;
                                header.right = 0;
                            }
                            else
                                header.right = p;

                            put_header();
                        }

                        if (_node.left == 0)
                        {
                            if (parent == 0)
                            {
                                header.parent = _node.right;
                                put_header();
                            }
                            else if (_parent.left == __node)
                            {
                                _parent.left = _node.right;
                                dp->_node_file->update(parent, _parent);
                            }
                            else
                            {
                                _parent.right = _node.right;
                                dp->_node_file->update(parent, _parent);
                            }

                            if (_node.right != 0)
                            {
                                node right = dp->_node_file->get(_node.right);
                                right.parent = parent;
                                dp->_node_file->update(_node.right, right);
                            }
                        }
                        else
                        {
                            if (parent == 0)
                            {
                                header.parent = _node.left;
                                put_header();
                            }
                            else if (_parent.left == __node)
                            {
                                _parent.left = _node.left;
                                dp->_node_file->update(parent, _parent);
                            }
                            else
                            {
                                _parent.right = _node.left;
                                dp->_node_file->update(parent, _parent);
                            }

                            if (_node.left != 0)
                            {
                                node left = dp->_node_file->get(_node.left);
                                left.parent = parent;
                                dp->_node_file->update(_node.left, left);
                            }
                        }

                        if (parent != 0) balance_tree_remove(*(dp->_node_file), parent, from);

                        dp->_node_file->dispose(__node);
                        dp->_slot_file->dispose(_node.key);

                        dp->check_point();
                        break;
                    }
                }
            }
            catch (...) { release(); throw; }
            release();
        }

        void request() { semaphore->request(); }

        void release() { semaphore->release(); }

        //*** private methods ***

        long long above(t data)
        {
            long long y = 0;
            long long x = header.parent;

            while (x != 0)
            {
                node _x = dp->_node_file->get(x);
                t key = dp->slot_file.get(_x.key);

                if (less(data, key))
                {
                    y = x;
                    x = _x.left;
                }
                else
                    x = _x.right;
            }

            return y;
        }

        long long below(t data)
        {
            long long y = 0;
            long long x = header.parent;

            while (x != 0)
            {
                node _x = dp->_node_file->get(x);
                t key = dp->slot_file.get(_x.key);

                if (!less(key, data))
                    x = _x.left;
                else
                {
                    y = x; x = _x.right;
                }
            }

            return y;
        }

        long long search(t data)
        {
            if (header.parent == 0)
                return 0;
            else
            {
                long long search = header.parent;
                node _search = dp->_node_file->get(search);

                do
                {
                    t key = dp->_slot_file->get(_search.key);

                    bool less = less(data, key);
                    bool greater = less(key, data);

                    if (less)
                    {
                        search = _search.left;
                        _search = dp->_node_file->get(search);
                    }

                    else if (greater)
                    {
                        search = _search.right;
                        _search = dp->_node_file->get(search);
                    }

                    else break;

                } while (search != 0);

                return search;
            }
        }
    };


    export template<class T>
    std::ostream& operator<<(std::ostream& s, set<T>& o)
    {
        s << "{";
        set_iterator<T> e = o.end();
        set_iterator<T> l = e; --l;
        for (set_iterator<T> i = o.begin(); i != e; i++)
        {
            s << *i; if (i != l) s << ",";
        }
        s << "}";
        return s;
    }

    export template<class T>
    std::wostream& operator<<(std::wostream& s, set<T>& o)
    {
        s << L"{";
        set_iterator<T> e = o.end();
        set_iterator<T> l = e; --l;
        for (set_iterator<T> i = o.begin(); i != e; i++)
        {
            s << *i; if (i != l) s << L",";
        }
        s << L"}";
        return s;
    }


    export template<class K, class T>
        std::ostream& operator<<(std::ostream& s, dictionary<K, T>& o)
    {
        s << "{";
        set_iterator<key_value<K,T>> e = o.end();
        set_iterator<key_value<K, T>> l = e; --l;
        for (set_iterator<key_value<K, T>> i = o.begin(); i != e; i++)
        {
            s << *i; if (i != l) s << ",";
        }
        s << "}";
        return s;
    }

    export template<class K, class T>
        std::wostream& operator<<(std::wostream& s, dictionary<K, T>& o)
    {
        s << L"{";
        set_iterator<key_value<K, T>> e = o.end();
        set_iterator<key_value<K, T>> l = e; --l;
        for (set_iterator<key_value<K, T>> i = o.begin(); i != e; i++)
        {
            s << *i; if (i != l) s << L",";
        }
        s << L"}";
        return s;
    }
}