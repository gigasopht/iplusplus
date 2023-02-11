// Standard Kernel - Implements the Russian AVL Algorithm

export module iplusplus:core;

import std.core;
import :windows;

using namespace iplusplus;

namespace standard
{
    export typedef wchar_t character;

    export template <class character>
        inline int compare_strings(const character* p, const character* q)
    {
        while (*p && *p == *q) { p++; q++; }
        if (*p < *q) return -1;
        if (*q < *p) return 1;
        return 0;
    }

    export template <class character>
        inline character* copy_string(character* p, const character* q)
    {
        character* string = p;
        while (*q)
        {
            *p = *q;
            p++;
            q++;
        }
        *p = 0;
        return string;
    }

    export template <class character>
        inline character* concatenate_strings(character* p, const character* q)
    {
        character* string = p; while (*p) p++; while (*p++ = *q++); return string;
    }

    export template <class character>
        inline long long string_length(const character* string)
    {
        long long l = 0;
        while (*string)
        {
            l++;
            string++;
        }
        return l;
    }

    export template <class character>
        inline void reverse_string(character* to_reverse)
    {
        if (to_reverse)
        {
            character* start = to_reverse;
            character* end = start + (string_length(to_reverse) - 1);

            while (end - start > 0)
            {
                character c(*start);
                *start = *end;
                *end = c;
                start++; end--;
            }
        }
    }

    export template <class character>
        struct gsubstring
    {
        long long l;
        character* p;

        gsubstring() : l(0), p(0) {}

        gsubstring(character* c) : p(c), l(c ? string_length(c) : 0) {}

        gsubstring(character* pointer, long long length) : l(length), p(pointer) {}

        gsubstring(character* base, long long first, long long last)
            : l(first <= last ? last - first + 1 : first - last + 1),
            p(first <= last ? base + first : base + last) {}

        character& operator[](long long i)
        {
            return *(p + i);
        }

        long long length() const { return l; }

        operator const character* () const { return p; }

        operator character* () { return p; }

        gsubstring operator()(long long first, long long last) { return gsubstring(p, first, last); }

        gsubstring& operator=(character c)
        {
            long long index = 0;
            while (index < length())
            {
                p[index] = c;
                index++;
            }
            return *this;
        }

        gsubstring& operator=(const character* a)
        {
            long long i = 0;
            while (i < l && a[i])
            {
                p[i] = a[i]; i++;
            }
            while (i < l)
            {
                p[i] = '\0'; i++;
            }
            return *this;
        }

        gsubstring& operator=(const gsubstring& a)
        {
            if (this != &a)
            {
                if (a.length() && length())
                {
                    long long l_minimum = a.length() < length() ?
                        a.length() : length();

                    if (p + l_minimum < a.p ||
                        p - l_minimum > a.p)
                    {
                        long long uindex = l_minimum;
                        while (uindex--) p[uindex] = a.p[uindex];
                    }
                    else // overlapping
                    {
                        character* NewString = new character[l_minimum];
                        long long uindex = l_minimum;
                        while (uindex--) NewString[uindex] = a.p[uindex];
                        uindex = l_minimum;
                        while (uindex--) p[uindex] = NewString[uindex];
                        delete[] NewString;
                    }
                }
            }
            return *this;
        }

        gsubstring& operator<<(const gsubstring& c) { l = c.length(); p = c.p; return *this; }
    };

    export template <class character>
        struct gstring_iterator
    {
        const character* str;

        gstring_iterator(const character* i) : str(i) {}

        character operator*() const { return *str; }

        gstring_iterator operator++()
        {
            str++;
            return *this;
        }

        gstring_iterator& operator++(int)
        {
            str++;
            return *this;
        }

        bool operator==(const gstring_iterator& si)
        {
            return str == si.str;
        }

        bool operator!=(const gstring_iterator& si)
        {
            return str != si.str;
        }
    };

    export template <class character>
        struct gstring
    {
        character* s;

        gstring()
        {
            s = new character[1];
            *s = 0;
        }

        gstring(const char* copy)
        {
            s = (character*)0;
            if (copy)
            {
                int i = 0; while (copy[i]) i++;
                s = new character[i + 1];
                for (int j = 0; j < i; j++) s[j] = copy[j];
                s[i] = 0;
            }
        }

        gstring(const wchar_t* copy)
        {
            s = (character*)0;
            if (copy)
            {
                int i = 0; while (copy[i]) i++;
                s = new character[i + 1];
                for (int j = 0; j < i; j++) s[j] = copy[j];
                s[i] = 0;
            }
        }

        gstring(long long new_size) : s(new character[new_size + 1]) {}

        gstring(const gsubstring<character>& ss)
        {
            s = (character*)0;
            long long length = ss.length();
            if (length)
            {
                s = new character[length + 1];
                for (int i = 0; i < length; i++) s[i] = ss.p[i];
                s[length] = '\0';
            }
        }

        gstring(const gstring& c)
        {
            s = 0;
            if (c.s)
            {
                s = new character[string_length(c.s) + 1];
                copy_string(s, c.s);
            }
        }

        ~gstring() { if (s) delete[] s; }

        long long length() const { if (s) return string_length(s); else return 0; }

        gstring& operator=(const character* cs)
        {
            if (s) delete[] s;
            s = 0;
            if (cs)
            {
                s = new character[string_length(cs) + 1];
                copy_string(s, cs);
            }
            return *this;
        }

        gstring& operator=(long long n)
        {
            if (s) delete[] s;
            s = new character[n + 1];
            return *this;
        }

        gstring_iterator<character> begin()
        {
            return gstring_iterator<character>(s);
        }

        gstring_iterator<character> end()
        {
            character* e = s;
            while (*e) e++;
            return gstring_iterator<character>(e);
        }

        gstring_iterator<character> begin() const
        {
            return gstring_iterator<character>(s);
        }

        gstring_iterator<character> end() const
        {
            character* e = s;
            while (*e) e++;
            return gstring_iterator<character>(e);
        }

        long long count(character c) const
        {
            long long co = 0;
            character* t = s;
            while (*t) { if (*t == c) co++; t++; }
            return co;
        }

        void push(character c)
        {
            character ch[2];
            ch[0] = c;
            ch[1] = 0;
            *this += ch;
        }

        gstring& operator+=(const character* cs)
        {
            long long lcs = string_length(cs);

            if (!lcs) return *this;

            long long ls = s ? string_length(s) : 0;
            character* ns = new character[ls + lcs + 1];

            if (s)
            {
                copy_string(ns, s);
                concatenate_strings(ns, cs);
                delete[] s;
            }
            else
                copy_string(ns, cs);

            s = ns;
            return *this;
        }

        character& operator[](long long index) const
        {
            return *(s + index);
        }

        operator character* () const { return s; }

        gstring& operator=(const gstring& a)
        {
            if (this != &a) gstring::operator=((const character*)a);
            return *this;
        }

        void concat(const character* cs)
        {
            *this += cs;
        }

        void reverse()
        {
            reverse_string(s);
        }
    };

    export typedef gstring<wchar_t> string;

    export typedef gsubstring<wchar_t> substring;

    export typedef gsubstring<char> subseries;

    export typedef gstring<char> series;

    export template <class character>
        int compare_strings(const gstring<character>& a, const gstring<character>& b)
    {
        const character* p = a;
        const character* q = b;
        while (*p && *p == *q) { p++; q++; }
        if (*p < *q) return -1;
        if (*q < *p) return 1;
        return 0;
    }

    enum { less = -1, equals = 0, greater = 1 };


    export template<class character>
        inline bool operator==(const gstring<character>& a, const gstring<character>& b) { return (bool)(compare_strings(a, b) == 0); }

    export template<class character>
        inline bool operator!=(const gstring<character>& a, const gstring<character>& b) { return (bool)(compare_strings(a, b) != 0); }

    export inline bool operator<(const string& a, const string& b) { return (bool)(compare_strings(a, b) < 0); }

    export inline bool operator<=(const string& a, const string& b) { return (bool)(compare_strings(a, b) <= 0); }

    export inline bool operator>(const string& a, const string& b) { return (bool)(compare_strings(a, b) > 0); }

    export inline bool operator>=(const string& a, const string& b) { return (bool)(compare_strings(a, b) >= 0); }

    export inline bool operator<(const series& a, const series& b) { return (bool)(compare_strings(a, b) < 0); }

    export inline bool operator<=(const series& a, const series& b) { return (bool)(compare_strings(a, b) <= 0); }

    export inline bool operator>(const series& a, const series& b) { return (bool)(compare_strings(a, b) > 0); }

    export inline bool operator>=(const series& a, const series& b) { return (bool)(compare_strings(a, b) >= 0); }

    export template <class character>
        gstring<character> operator+(const character* a, const gstring<character>& b)
    {
        long long lb = b.length();
        gstring<character> result(string_length(a) + lb);
        copy_string(result.s, a);
        if (lb) concatenate_strings<character>(result.s, b);
        return result;
    }

    export template <class character>
        gstring<character> operator+(const gstring<character>& a, const character* b)
    {
        long long la = a.length();
        gstring<character> result(la + string_length(b));
        if (la)
        {
            copy_string(result.s, a.s);
            concatenate_strings<character>(result.s, b);
        }
        else
            copy_string(result.s, b);
        return result;
    }

    export template <class character>
        gstring<character> operator+(const gstring<character>& a, const gstring<character>& b)
    {
        long long la = a.length();
        long long lb = b.length();
        long long length = la + lb;
        if (length)
        {
            gstring<character> result(length);
            if (la)
            {
                copy_string(result.s, a.s);
                if (lb) concatenate_strings<character>(result.s, b.s);
            }
            else
                copy_string(result.s, b.s);
            return result;
        }
        else
            return gstring<character>((character*)"");
    }

    export class resource_string : public string
    {
    public:

        resource_string(uint resource,
            handle Module = 0)
        {
            handle loadhandle = Module ? Module : get_module_handle<character>();
            character buffer[256];
            load_string(loadhandle,
                resource,
                buffer,
                sizeof(buffer));
            unsigned size = string_length(buffer);
            s = new character[size + 1];
            copy_string(s, buffer);
        }
    };

    export struct standard_exception
    {
        string description;

        standard_exception(const string& sin) : description(sin) { }

        operator string() const { return (string)description; }
    };

    export struct month_is_invalid_exception : public standard_exception
    {
        month_is_invalid_exception() : standard_exception((const character*)L"Month is invalid.") {}
    };

    export struct day_of_month_is_invalid_exception : public standard_exception
    {
        day_of_month_is_invalid_exception() : standard_exception((const character*)L"Day of month is invalid.") {}
    };

    export struct julian_day_is_invalid_exception : public standard_exception
    {
        julian_day_is_invalid_exception() : standard_exception((const character*)L"Julian day is invalid.") {}
    };

    export struct allocation_failed_exception : public standard_exception
    {
        allocation_failed_exception() : standard_exception((const character*)L"Memory allocation failed.") {}
    };

    export struct free_failed_exception : public standard_exception
    {
        free_failed_exception() : standard_exception((const character*)L"Memory freeing failed.") {}
    };

    export struct entry_already_exists_exception : public standard_exception
    {
        entry_already_exists_exception() : standard_exception((const character*)L"Entry already exists.") {}
    };

    export struct entry_not_found_exception : public standard_exception
    {
        entry_not_found_exception() : standard_exception((const character*)L"Entry not found.") {}
    };

    export struct invalid_set_operation_exception : public standard_exception
    {
        invalid_set_operation_exception() : standard_exception((const character*)L"The specified set operation is invalid for the function.") {}
    };

    export struct invalid_bag_operation_exception : public standard_exception
    {
        invalid_bag_operation_exception() : standard_exception((const character*)"The specified bag operation is invalid for the function.") {}
    };

    export struct is_header_exception : public standard_exception
    {
        is_header_exception() : standard_exception((const character*)L"An invalid operation was atttempted on a header node.") {}
    };

    extern "C" long __cdecl _InterlockedCompareExchange(long volatile* Destination, long exchange, long comparand);

#pragma intrinsic(_InterlockedCompareExchange)

    class semaphore
    {
    public:

        semaphore() : busy(0), thread(0), reference(1) {}

        inline void request()
        {
            unsigned identity = iplusplus::get_current_thread_identity();

            for (;;)
                if (_InterlockedCompareExchange(&busy, 1, 0))
                {
                    if (identity == thread)
                    {
                        busy++;
                        break;
                    }
                    else
                    {
                        iplusplus::sleep(0);
                    }
                }
                else
                {
                    thread = identity;
                    break;
                }
        }

        inline bool release()
        {
            if (busy)
            {
                unsigned identity = iplusplus::get_current_thread_identity();
                if (identity == thread)
                {
                    if (busy == 1) thread = 0;
                    busy--;
                    return true;
                }
                else
                    return false;  // Not semaphore owner
            }
            else
                return false;  // semaphore Unowned
        }

        unsigned operator++() { return ++reference; }
        unsigned operator--() { if (reference) return --reference; else return 0; }

    private:
        long busy;
        unsigned thread;
        unsigned reference;
    };

    export struct wait
    {
        semaphore& S;

        wait(semaphore& S_In)
            : S(S_In)
        {
            S.request();
        }

        ~wait() { S.release(); }
    };

    export struct direction
    {
        enum { from_left, from_right };
    };

    export struct state
    {
        enum
        {
            header,
            balanced,
            left_high,
            right_high
        };
    };

    export struct node  // Base node class for all trees
    {
        node* left;
        node* right;
        node* parent;
        char balance;

        node()
        {
            balance = state::header;
            left = this;
            right = this;
            parent = 0;
        }

        node(node* parent_set)
        {
            balance = state::balanced;
            left = 0;
            right = 0;
            parent = parent_set;
        }

        bool is_header() const { return !balance; }
    };

    inline void swap_node_reference(node*& first, node*& second)
    {
        node* temporary = first; first = second; second = temporary;
    }

    inline void swap_nodes(node* A, node* B)
    {
        if (B == A->left)
        {
            if (B->left) B->left->parent = A;
            if (B->right) B->right->parent = A;

            if (A->right) A->right->parent = B;

            if (!A->parent->is_header())
            {
                if (A->parent->left == A)
                    A->parent->left = B;
                else
                    A->parent->right = B;
            }
            else A->parent->parent = B;

            B->parent = A->parent;
            A->parent = B;

            A->left = B->left;
            B->left = A;

            swap_node_reference(A->right, B->right);
        }
        else if (B == A->right)
        {
            if (B->right) B->right->parent = A;
            if (B->left) B->left->parent = A;

            if (A->left) A->left->parent = B;

            if (!A->parent->is_header())
            {
                if (A->parent->left == A)
                    A->parent->left = B;
                else
                    A->parent->right = B;
            }
            else A->parent->parent = B;

            B->parent = A->parent;
            A->parent = B;

            A->right = B->right;
            B->right = A;

            swap_node_reference(A->left, B->left);
        }
        else if (A == B->left)
        {
            if (A->left) A->left->parent = B;
            if (A->right) A->right->parent = B;

            if (B->right) B->right->parent = A;

            if (!B->parent->is_header())
            {
                if (B->parent->left == B)
                    B->parent->left = A;
                else
                    B->parent->right = A;
            }
            else B->parent->parent = A;

            A->parent = B->parent;
            B->parent = A;

            B->left = A->left;
            A->left = B;

            swap_node_reference(A->right, B->right);
        }
        else if (A == B->right)
        {
            if (A->right) A->right->parent = B;
            if (A->left) A->left->parent = B;

            if (B->left) B->left->parent = A;

            if (!B->parent->is_header())
            {
                if (B->parent->left == B)
                    B->parent->left = A;
                else
                    B->parent->right = A;
            }
            else B->parent->parent = A;

            A->parent = B->parent;
            B->parent = A;

            B->right = A->right;
            A->right = B;

            swap_node_reference(A->left, B->left);
        }
        else
        {
            if (A->parent == B->parent)
                swap_node_reference(A->parent->left, A->parent->right);
            else
            {
                if (!A->parent->is_header())
                {
                    if (A->parent->left == A)
                        A->parent->left = B;
                    else
                        A->parent->right = B;
                }
                else A->parent->parent = B;

                if (!B->parent->is_header())
                {
                    if (B->parent->left == B)
                        B->parent->left = A;
                    else
                        B->parent->right = A;
                }
                else B->parent->parent = A;
            }

            if (B->left)  B->left->parent = A;
            if (B->right) B->right->parent = A;

            if (A->left)  A->left->parent = B;
            if (A->right) A->right->parent = B;

            swap_node_reference(A->left, B->left);
            swap_node_reference(A->right, B->right);
            swap_node_reference(A->parent, B->parent);
        }

        unsigned balance = A->balance;
        A->balance = B->balance;
        B->balance = balance;
    }

    inline void rotate_left(node*& root)
    {
        node* parent = root->parent;
        node* x = root->right;

        root->parent = x;
        x->parent = parent;
        if (x->left) x->left->parent = root;

        root->right = x->left;
        x->left = root;
        root = x;
    }

    inline void rotate_right(node*& root)
    {
        node* parent = root->parent;
        node* x = root->left;

        root->parent = x;
        x->parent = parent;
        if (x->right) x->right->parent = root;

        root->left = x->right;
        x->right = root;
        root = x;
    }

    inline void balance_left(node*& root)
    {
        node* left = root->left; // left Subtree of root node

        switch (left->balance)
        {
        case state::left_high:
            root->balance = state::balanced;
            left->balance = state::balanced;
            rotate_right(root);
            break;

        case state::right_high:
        {
            node* subright = left->right;  // right subtree of left
            switch (subright->balance)
            {
            case state::balanced:
                root->balance = state::balanced;
                left->balance = state::balanced;
                break;

            case state::right_high:
                root->balance = state::balanced;
                left->balance = state::left_high;
                break;

            case state::left_high:
                root->balance = state::right_high;
                left->balance = state::balanced;
                break;
            }
            subright->balance = state::balanced;
            rotate_left(left);
            root->left = left;
            rotate_right(root);
        }
        break;

        case state::balanced:
            root->balance = state::left_high;
            left->balance = state::right_high;
            rotate_right(root);
            break;
        }
    }

    inline void balance_right(node*& root)
    {
        node* right = root->right; // right Subtree of root node

        switch (right->balance)
        {
        case state::right_high:
            root->balance = state::balanced;
            right->balance = state::balanced;
            rotate_left(root);
            break;

        case state::left_high:
        {
            node* subleft = right->left; // left Subtree of right
            switch (subleft->balance)
            {
            case state::balanced:
                root->balance = state::balanced;
                right->balance = state::balanced;
                break;

            case state::left_high:
                root->balance = state::balanced;
                right->balance = state::right_high;
                break;

            case state::right_high:
                root->balance = state::left_high;
                right->balance = state::balanced;
                break;
            }
            subleft->balance = state::balanced;
            rotate_right(right);
            root->right = right;
            rotate_left(root);
        }
        break;

        case state::balanced:
            root->balance = state::right_high;
            right->balance = state::left_high;
            rotate_left(root);
            break;
        }
    }

    inline void balance_tree(node* root, unsigned long long from)
    {
        bool taller = true;

        while (taller)
        {
            node* parent = root->parent;
            unsigned long long next_from = (parent->left == root) ? direction::from_left : direction::from_right;

            if (from == direction::from_left)
            {
                switch (root->balance)
                {
                case state::left_high:
                    if (parent->is_header())
                        balance_left(parent->parent);
                    else if (parent->left == root)
                        balance_left(parent->left);
                    else
                        balance_left(parent->right);
                    taller = false;
                    break;

                case state::balanced:
                    root->balance = state::left_high;
                    taller = true;
                    break;

                case state::right_high:
                    root->balance = state::balanced;
                    taller = false;
                    break;
                }
            }
            else
            {
                switch (root->balance)
                {
                case state::left_high:
                    root->balance = state::balanced;
                    taller = false;
                    break;

                case state::balanced:
                    root->balance = state::right_high;
                    taller = true;
                    break;

                case state::right_high:
                    if (parent->is_header())
                        balance_right(parent->parent);
                    else if (parent->left == root)
                        balance_right(parent->left);
                    else
                        balance_right(parent->right);
                    taller = false;
                    break;
                }
            }

            if (taller) // skip up a level
            {
                if (parent->is_header())
                    taller = false;
                else
                {
                    root = parent;
                    from = next_from;
                }
            }
        }
    }

    inline void balance_tree_remove(node* root, unsigned long long from)
    {
        if (root->is_header()) return;
        bool shorter = true;

        while (shorter)
        {
            node* parent = root->parent;
            unsigned long long next_from = (parent->left == root) ? direction::from_left : direction::from_right;

            if (from == direction::from_left)
            {
                switch (root->balance)
                {
                case state::left_high:
                    root->balance = state::balanced;
                    shorter = true;
                    break;

                case state::balanced:
                    root->balance = state::right_high;
                    shorter = false;
                    break;

                case state::right_high:
                    if (root->right->balance == state::balanced)
                        shorter = false;
                    else
                        shorter = true;
                    if (parent->is_header())
                        balance_right(parent->parent);
                    else if (parent->left == root)
                        balance_right(parent->left);
                    else
                        balance_right(parent->right);
                    break;
                }
            }
            else
            {
                switch (root->balance)
                {
                case state::right_high:
                    root->balance = state::balanced;
                    shorter = true;
                    break;

                case state::balanced:
                    root->balance = state::left_high;
                    shorter = false;
                    break;

                case state::left_high:
                    if (root->left->balance == state::balanced)
                        shorter = false;
                    else
                        shorter = true;
                    if (parent->is_header())
                        balance_left(parent->parent);
                    else if (parent->left == root)
                        balance_left(parent->left);
                    else
                        balance_left(parent->right);
                    break;
                }
            }

            if (shorter)
            {
                if (parent->is_header())
                    shorter = false;
                else
                {
                    from = next_from;
                    root = parent;
                }
            }
        }
    }

    export inline void adjust_add(node* root)
    {
        node* header = root->parent;
        while (!header->is_header()) header = header->parent;

        if (root->parent->left == root)
        {
            balance_tree(root->parent, direction::from_left);
            if (header->left == root->parent) header->left = root;
        }
        else
        {
            balance_tree(root->parent, direction::from_right);
            if (header->right == root->parent) header->right = root;
        }
    }

    inline node* minimum(node* node)
    {
        while (node->left) node = node->left;
        return node;
    }

    inline node* maximum(node* node)
    {
        while (node->right) node = node->right;
        return node;
    }

    export inline void adjust_remove(node* parent, unsigned long long direction)
    {
        balance_tree_remove(parent, direction);

        node* header = parent;
        while (!header->is_header()) header = header->parent;

        if (header->parent == 0)
        {
            header->left = header;
            header->right = header;
        }
        else
        {
            header->left = minimum(header->parent);
            header->right = maximum(header->parent);
        }
    }

    export inline unsigned long long depth(const node* root)
    {
        if (root)
        {
            unsigned long long left = root->left ? depth(root->left) : 0;
            unsigned long long right = root->right ? depth(root->right) : 0;
            return left < right ? right + 1 : left + 1;
        }
        else
            return 0;
    }

    export inline unsigned long long count(const node* root)
    {
        if (root)
        {
            unsigned long long left = root->left ? count(root->left) : 0;
            unsigned long long right = root->right ? count(root->right) : 0;
            return left + right + 1;
        }
        else
            return 0;
    }
    export inline node* previous_item(node* _node)
    {
        if (_node->is_header()) { return _node->right; }

        else if (_node->left != 0)
        {
            node* y = _node->left;
            while (y->right != 0) y = y->right;
            _node = y;
        }
        else
        {
            node* y = _node->parent;
            if (y->is_header()) return y;
            while (_node == y->left) { _node = y; y = y->parent; }
            _node = y;
        }
        return _node;
    }

    export inline node* next_item(node* _node)
    {
        if (_node->is_header()) return _node->left;

        if (_node->right != 0)
        {
            _node = _node->right;
            while (_node->left != 0) _node = _node->left;
        }
        else
        {
            node* y = _node->parent;
            if (y->is_header()) return y;
            while (_node == y->right) { _node = y; y = y->parent; }
            _node = y;
        }
        return _node;
    }


    export struct set_operation
    {
        enum
        {
            _union,
            intersection,
            symmetric_difference,
            difference,
        };
    };

    export template <class U>
        inline bool compare(const U& u, const U& v) { return u < v; }


    export template <class T>
        class array_value
    {
    public:

        long long c;
        T t;

        array_value(long long cIn, T tIn) : c(cIn), t(tIn) {}

        long long key() const { return c; }

        T value() const { return t; }
    };

    export template<class T>
        struct array_node : public node
    {
        long long key;
        T daata;

        array_node(long long keySet, const T& daataSet, node* parent)
            : node(parent), key(keySet), daata(daataSet) {}

        operator const long long& () const { return key; }

        operator T& () { return daata; }
    };

    export template <class T>
        struct array_iterator
    {
        node* _node;

        array_iterator() : _node(0) {}

        array_iterator(node* in) : _node(in) {}

        array_iterator(const array_iterator<T>& i) : _node(i._node) {}

        long long key() const
        {
            return ((array_node<T>*)_node)->key;
        }

        T& value() const
        {
            return ((array_node<T>*)_node)->daata;
        }

        T operator*() const
        {
            return value();
        }

        T* operator->() const
        {
            return &(((array_node<T>*)_node)->daata);
        }

        T* operator&() const
        {
            return &(((array_node<T>*)_node)->daata);
        }

        array_iterator<T>& operator++()
        {
            _node = next_item(_node); return *this;
        }

        array_iterator<T> operator++(int)
        {
            array_iterator<T> saau = *this; ++* this;return saau;
        }

        array_iterator<T>& operator+=(long long increment)
        {
            for (long long i = 0; i < increment; i++)++* this; return *this;
        }

        array_iterator<T> operator+(long long increment) const
        {
            array_iterator<T> result(*this);
            for (long long i = 0; i < increment; i++) ++result;
            return result;
        }

        array_iterator<T>& operator--()
        {
            _node = previous_item(_node); return *this;
        }

        array_iterator<T> operator--(int)
        {
            array_iterator<T> saau = *this; --* this;return saau;
        }

        array_iterator<T>& operator-=(long long decrement)
        {
            for (long long i = 0; i < decrement; i++)--* this; return *this;
        }

        array_iterator<T> operator-(long long decrement) const
        {
            array_iterator<T> result(*this);
            for (long long i = 0; i < decrement; i++) --result;
            return result;
        }

        bool operator==(const array_iterator<T>& y) const { return _node == y._node; }

        bool operator!=(const array_iterator<T>& y) const { return _node != y._node; }

        const T& operator[](long long i) const { return i >= 0 ? *(*this + i) : *(*this - -i); }

        long long operator-(array_iterator<T> iter) const
        {
            long long result = 0;
            while (iter++ != *this) { result++; }
            return result;
        }

        bool is_header() const { return _node->is_header(); }
    };

    export template<class T>
        struct const_array_iterator
    {
        const node* _node;

        const_array_iterator() : _node(0) {}

        const_array_iterator(const node* in) : _node(in) {}

        const_array_iterator(const array_iterator<T>& i) : _node(i._node) {}

        const_array_iterator(const const_array_iterator<T>& i) : _node(i._node) {}

        long long key() const
        {
            return ((array_node<T>*)_node)->key;
        }

        const T& value() const
        {
            return ((array_node<T>*)_node)->daata;
        }

        const T& operator*() const
        {
            return value();
        }

        const T* operator->() const
        {
            return &(((array_node<T>*)_node)->daata);
        }

        const T* operator&() const
        {
            return &(((array_node<T>*)_node)->daata);
        }

        const_array_iterator<T>& operator++()
        {
            _node = next_item((node*)_node); return *this;
        }

        const_array_iterator<T> operator++(int)
        {
            const_array_iterator<T> saau = *this; ++* this;return saau;
        }

        const_array_iterator<T>& operator+=(long long increment)
        {
            for (long long i = 0; i < increment; i++)++* this; return *this;
        }

        const_array_iterator<T> operator+(long long increment) const
        {
            const_array_iterator<T> result(*this);
            for (long long i = 0; i < increment; i++) ++result;
            return result;
        }

        const_array_iterator<T>& operator--()
        {
            _node = previous_item((node*)_node); return *this;
        }

        const_array_iterator<T> operator--(int)
        {
            array_iterator<T> saau = *this; --* this; return saau;
        }

        const_array_iterator<T>& operator-=(long long decrement)
        {
            for (long long i = 0; i < decrement; i++)--* this; return *this;
        }

        const_array_iterator<T> operator-(long long decrement) const
        {
            const_array_iterator<T> result(*this);
            for (long long i = 0; i < decrement; i++) --result;
            return result;
        }

        bool operator==(const const_array_iterator<T>& y) const { return _node == y._node; }

        bool operator!=(const const_array_iterator<T>& y) const { return _node != y._node; }

        const T& operator[](long long i) const { return i >= 0 ? *(*this + i) : *(*this - -i); }

        long long operator-(const_array_iterator<T> iter) const
        {
            long long result = 0;
            while (iter++ != *this) { result++; }
            return result;
        }

        bool is_header() const { return _node->is_header(); }
    };

    export template <class T>
        struct array : semaphore
    {
        node header;

        typedef array_iterator<T> iterator;

        typedef const_array_iterator<T> const_iterator;

        array() {}

        array(const array<T>& copy)
        {
            array<T>& c = (array<T>&)copy;
            wait uu(c);
            int s = c.length();
            for (int i = 0; i < s; i++) *this << c[i];
        }

        array(long long _count, const T* _values)
        {
            for (int i = 0; i < _count, i++; ) if (_values[i]) this << _values[i];
        }

        template<class I>
        array(I first, I last)
        {
            while (first != last) insert(*first++);
        }

        ~array()
        {
            wait uu(*this);
            destroy((array_node<T>*)header.parent);
        }

        array<T>& operator=(const array<T>& copy)
        {
            wait uu(*this);
            array<T>& c = (array<T>&)copy;
            erase();
            int s = c.length();
            for (int i = 0; i < s; i++) *this << c[i];
            return *this;
        }

        //    int size() const { return count(header.parent); }  // unsincroniisd

        array<T>& operator<<(const array<T>& a)
        {
            wait uu(*this);
            for (T _t : a) *this << _t;
            return *this;
        }

        int size() const { return count(header.parent); }

        long long length() const { return count(header.parent); }

        iterator begin() { return header.left; }

        iterator end() { return &header; }

        const_iterator begin() const { return header.left; }

        const_iterator end() const { return &header; }

        long long depth() const { wait uu(*this); return depth(header.parent); }

        iterator insert(const T& daata)
        {
            wait uu(*this);
            iterator Last = last();
            if (Last.is_header())
                return insert(0, daata);
            else
            {
                return insert(Last.key() + 1, daata);
            }
        }

        iterator insert(long long key,
            const T& daata)
        {
            wait uu(*this);

            node* root_node = header.parent;

            if (root_node == 0)
            {
                root_node = new array_node<T>(key, daata, &header);
                header.left = root_node;
                header.right = root_node;
                header.parent = root_node;
                return root_node;
            }

            else
            {
                for (; ; )
                {
                    bool less = compare(key, ((array_node<T>*)root_node)->key);
                    bool greater = compare(((array_node<T>*)root_node)->key, key);

                    if (!less && !greater)
                    {
                        ((array_node<T>*)root_node)->daata = daata;
                        return root_node;
                    }

                    else if (less)
                    {
                        if (root_node->left != 0)
                            root_node = root_node->left;
                        else
                        {
                            node* new_node = new array_node<T>(key, daata, root_node);
                            root_node->left = new_node;
                            adjust_add(new_node);
                            return new_node;
                        }
                    }

                    else
                    {
                        if (root_node->right != 0)
                            root_node = root_node->right;
                        else
                        {
                            node* new_node = new array_node<T>(key, daata, root_node);
                            root_node->right = new_node;
                            adjust_add(new_node);
                            return new_node;
                        }
                    }
                }
            }
        }

        void erase(long long key)
        {
            wait uu(*this);

            node* root_node = header.parent;

            for (; ; )
            {
                if (root_node == 0) throw entry_not_found_exception();

                bool less = compare(key, ((array_node<T>*)root_node)->key);
                bool greater = compare(((array_node<T>*)root_node)->key, key);

                if (less)
                    root_node = root_node->left;

                else if (greater)
                    root_node = root_node->right;

                else // Item is found
                {
                    if (root_node->left != 0 && root_node->right != 0)
                    {
                        node* replaas = root_node->left;
                        while (replaas->right != 0) replaas = replaas->right;
                        swap_nodes(root_node, replaas);
                    }

                    node* parent = root_node->parent;

                    long long from = (parent->left == root_node) ? direction::from_left : direction::from_right;

                    if (root_node->left == 0)
                    {
                        if (parent == &header)
                            header.parent = root_node->right;
                        else if (from == direction::from_left)
                            parent->left = root_node->right;
                        else
                            parent->right = root_node->right;

                        if (root_node->right != 0) root_node->right->parent = parent;
                    }
                    else
                    {
                        if (parent == &header)
                            header.parent = root_node->left;
                        else if (from == direction::from_left)
                            parent->left = root_node->left;
                        else
                            parent->right = root_node->left;

                        if (root_node->left != 0) root_node->left->parent = parent;
                    }

                    adjust_remove(parent, from);
                    delete (array_node<T>*)root_node;
                    break;
                }
            }
        }

        //const T operator[](long long key) { return find(key).value(); }

        class reference
        {
        public:

            reference(array<T>& ArraySet, long long keySet)
                : Array(&ArraySet), key(keySet) {}

            reference& operator=(const T& value)
            {
                Array->insert(key, value);
                return *this;
            }

            reference& operator=(const reference& Reference)
            {
                Array->insert(key, (T&)Reference);
                return *this;
            }

            operator T& () const
            {
                iterator i = Array->find(key);
                return i.value();
            }

            array<T>* Array;
            long long key;
        };

        reference operator[](long long key) { return reference(*this, key); }

        array<T>& operator>>(long long key) { erase(key); return *this; }

        iterator find(long long key)
        {
            wait uu(*this);

            if (!header.parent)
                throw entry_not_found_exception();
            else
            {
                const node* serch_node = header.parent;

                do
                {
                    bool less = compare(key, ((array_node<T>*)serch_node)->key);
                    bool greater = compare(((array_node<T>*)serch_node)->key, key);

                    if (less) serch_node = serch_node->left;

                    else if (greater) serch_node = serch_node->right;

                    else break;

                } while (serch_node);

                if (serch_node == 0) throw entry_not_found_exception();

                return (node*)serch_node;
            }
        }

        array<T>& operator<<(const T& t)
        {
            push(t);
            return *this;
        }

        void push_back(const T& t)
        {
            push(t);
        }

        array<T>& operator>>(T& t)
        {
            t = pop();
            return *this;
        }

        void push(const T& daata)
        {
            wait uu(*this);

            if (!header.parent)
                (*this)[0] = daata;
            else
            {
                array_iterator<T> ai(header.right);
                (*this)[ai.key() + 1] = daata;
            }
        }

        T pop()
        {
            wait uu(*this);

            if (!header.parent)
                throw entry_not_found_exception();
            else
            {
                array_iterator<T> ai(header.right);
                T r = ai.value();
                erase(ai.key());
                return r;
            }
        }

        bool exists(long long key) const
        {
            wait uu(*this);

            if (!header.parent)
                return false;
            else
            {
                const node* serch_node = header.parent;

                do
                {
                    int result = compare(key, ((array_node<T>*)serch_node)->key);

                    if (result < 0) serch_node = serch_node->left;

                    else if (result > 0) serch_node = serch_node->right;

                    else break;

                } while (serch_node);

                if (serch_node == 0) return false;

                return true;
            }
        }

        void erase()
        {
            wait uu(*this);
            destroy((array_node<T>*)header.parent);
            header.left = &header;
            header.right = &header;
            header.parent = 0;
        }

        iterator after(long long key) const
        {
            wait uu(*this);

            const node* y = &header;
            const node* x = header.parent;

            while (x != 0)
                if (compare(key, ((array_node<T>*)x)->key) < 0)
                {
                    y = x; x = x->left;
                }
                else
                    x = x->right;

            return (node*)y;
        }

        iterator after_equals(long long key) const
        {
            wait uu(*this);

            const node* y = &header;
            const node* x = header.parent;

            while (x != 0)
            {
                int c = compare(key, ((array_node<T>*)x)->key);
                if (c == 0)
                {
                    y = x; break;
                }
                else if (c < 0)
                {
                    y = x; x = x->left;
                }
                else
                    x = x->right;
            }

            return (node*)y;
        }

        iterator before(long long key) const
        {
            wait uu(*this);

            const node* y = &header;
            const node* x = header.parent;

            while (x != 0)
                if (compare(key, ((array_node<T>*)x)->key) <= 0)
                {
                    x = x->left;
                }
                else
                {
                    y = x; x = x->right;
                }

            return (node*)y;
        }

        iterator before_equals(long long key) const
        {
            wait uu(*this);

            const node* y = &header;
            const node* x = header.parent;

            while (x != 0)
            {
                int c = compare(key, ((array_node<T>*)x)->key);
                if (c == 0)
                {
                    y = x; break;
                }
                else if (c < 0)
                    x = x->left;
                else
                {
                    y = x; x = x->right;
                }
            }

            return (node*)y;
        }

        iterator last() { return header.right; }

        const_iterator last() const { return header.right; }

        bool contiguous() const
        {
            long long l = length();
            if (l == 0)
                return true;

            const_iterator i = last();
            long long k = i.key();
            return l == k + 1;
        }

        void copy(array_node<T>* Clone)
        {
            if (!header.parent) erase();
            if (Clone)
            {
                copy((array_node<T>*&)header.parent, Clone, &header);
                header.left = get_first();
                header.right = get_last();
            }
        }

        void copy(array_node<T>*& root_node,
            array_node<T>* n,
            node* parent)  // assumes root_node non-null
        {
            root_node = new array_node<T>(n->key, n->daata, parent);
            root_node->balans = n->balans;

            if (n->left)
                copy((array_node<T>*&)root_node->left, (array_node<T>*)n->left, root_node);
            else root_node->left = 0;

            if (n->right)
                copy((array_node<T>*&)root_node->right, (array_node<T>*)n->right, root_node);
            else root_node->right = 0;
        }

        node* get_first()
        {
            if (!header.parent)
                return &header;

            else
            {
                node* serch_node = header.parent;
                while (serch_node->left) serch_node = serch_node->left;
                return serch_node;
            }
        }

        node* get_last()
        {
            if (!header.parent)
                return &header;

            else
            {
                node* serch_node = header.parent;
                while (serch_node->right) serch_node = serch_node->right;
                return serch_node;
            }
        }

        void destroy(array_node<T>* root_node)
        {
            if (root_node)
            {
                if (root_node->left)
                    destroy((array_node<T>*)root_node->left);

                if (root_node->right)
                    destroy((array_node<T>*)root_node->right);

                delete root_node;
            }
        }
    };

    // binary serialization

    export struct entry
    {
        union
        {
            char _char;
            wchar_t _wchar_t;
            unsigned char _byte;
            short _short;
            unsigned short _ushort;
            int _int;
            unsigned _unsigned;
            float _float;
            double _double;
            long _long;
            unsigned long _ulong;
            long long _longlong;
            unsigned long long _ulonglong;
            bool _bool;
        } data;

        entry() {}

        entry(char c)
        {
            data._char = c;
        }

        entry(wchar_t c)
        {
            data._wchar_t = c;
        }

        entry(unsigned char uc)
        {
            data._byte = uc;
        }

        entry(short s)
        {
            data._short = s;
        }

        entry(unsigned short us)
        {
            data._ushort = us;
        }

        entry(int i)
        {
            data._int = i;
        }

        entry(unsigned u)
        {
            data._unsigned = u;
        }

        entry(float f)
        {
            data._float = f;
        }

        entry(double d)
        {
            data._double = d;
        }

        entry(long l)
        {
            data._long = l;
        }

        entry(unsigned long ul)
        {
            data._ulong = ul;
        }

        entry(long long l)
        {
            data._longlong = l;
        }

        entry(unsigned long long ul)
        {
            data._ulonglong = ul;
        }

        entry(bool b)
        {
            data._bool = b;
        }
    };

    export struct oarchive
    {
        array<entry> data;

        oarchive& operator<<(char c)
        {
            data.push(entry(c));
            return *this;
        }

        oarchive& operator<<(wchar_t c)
        {
            data.push(entry(c));
            return *this;
        }

        oarchive& operator<<(unsigned char uc)
        {
            data.push(entry(uc));
            return *this;
        }

        oarchive& operator<<(short s)
        {
            data.push(entry(s));
            return *this;
        }

        oarchive& operator<<(unsigned short us)
        {
            data.push(entry(us));
            return *this;
        }

        oarchive& operator<<(int i)
        {
            data.push(entry(i));
            return *this;
        }

        oarchive& operator<<(unsigned u)
        {
            data.push(entry(u));
            return *this;
        }

        oarchive& operator<<(float f)
        {
            data.push(entry(f));
            return *this;
        }

        oarchive& operator<<(double d)
        {
            data.push(entry(d));
            return *this;
        }

        oarchive& operator<<(long l)
        {
            data.push(entry(l));
            return *this;
        }

        oarchive& operator<<(unsigned long ul)
        {
            data.push(entry(ul));
            return *this;
        }

        oarchive& operator<<(long long l)
        {
            data.push(entry(l));
            return *this;
        }

        oarchive& operator<<(unsigned long long ul)
        {
            data.push(entry(ul));
            return *this;
        }

        oarchive& operator<<(bool b)
        {
            data.push(entry(b));
            return *this;
        }

        operator void* ()
        {
            long long size = data.size();
            entry* buffer = new entry[size + 1];
            buffer[0].data._longlong = (size + 1) * 8;
            for (long long l = 0; l < size; l++)
            {
                entry e = data[l];
                buffer[l + 1].data = e.data;
            }
            return buffer;
        }
    };

    export struct iarchive
    {
        entry* buffer;
        long long offset;

        iarchive(void* b) : buffer((entry*)b), offset(0) {}

        iarchive& operator>>(char& c)
        {
            c = buffer[offset + 1].data._char;
            offset++;
            return *this;
        }

        iarchive& operator>>(wchar_t& c)
        {
            c = buffer[offset + 1].data._wchar_t;
            offset++;
            return *this;
        }

        iarchive& operator>>(unsigned char& uc)
        {
            uc = buffer[offset + 1].data._byte;
            offset++;
            return *this;
        }

        iarchive& operator>>(short& s)
        {
            s = buffer[offset + 1].data._short;
            offset++;
            return *this;
        }

        iarchive& operator>>(unsigned short& us)
        {
            us = buffer[offset + 1].data._ushort;
            offset++;
            return *this;
        }

        iarchive& operator>>(int& i)
        {
            i = buffer[offset + 1].data._int;
            offset++;
            return *this;
        }

        iarchive& operator>>(unsigned& u)
        {
            u = buffer[offset + 1].data._unsigned;
            offset++;
            return *this;
        }

        iarchive& operator>>(float& f)
        {
            f = buffer[offset + 1].data._float;
            offset++;
            return *this;
        }

        iarchive& operator>>(double& d)
        {
            d = buffer[offset + 1].data._double;
            offset++;
            return *this;
        }

        iarchive& operator>>(long& l)
        {
            l = buffer[offset + 1].data._long;
            offset++;
            return *this;
        }

        iarchive& operator>>(unsigned long& ul)
        {
            ul = buffer[offset + 1].data._ulong;
            offset++;
            return *this;
        }

        iarchive& operator>>(long long& l)
        {
            l = buffer[offset + 1].data._longlong;
            offset++;
            return *this;
        }

        iarchive& operator>>(unsigned long long& ul)
        {
            ul = buffer[offset + 1].data._ulonglong;
            offset++;
            return *this;
        }

        iarchive& operator>>(bool& b)
        {
            b = buffer[offset + 1].data._bool;
            offset++;
            return *this;
        }

    };

     export template <class k, class t>
        struct key_value
    {
        k key;
        t value;

        key_value() {}

        key_value(k k_set) : key(k_set) {}

        key_value(k k_set, t t_set) : key(k_set), value(t_set) {}
    };

    export template <class k, class t>
        bool operator<(const key_value<k, t>& a, const key_value<k, t>& b)
    {
        return a.key < b.key;
    }

    export template <class c, class t>
        inline std::ostream& operator<<(std::ostream& s, const key_value<c, t>& cv)
    {
        s << "(" << cv.key << "," << cv.value << ")";
        return s;
    }

    export template<class K, class T>
        inline oarchive& operator<<(oarchive& s, const key_value<K, T>& o)
    {
        s << o.key;
        s << o.value;
        return s;
    }

    export template<class K, class T>
        iarchive& operator>>(iarchive& s, key_value<K, T>& o)
    {
        s >> o.key;
        s >> o.value;
        return s;
    }

    export template<class K, class T>
        inline oarchive& operator<<(oarchive& s, const std::pair<K, T>& o)
    {
        s << o.first;
        s << o.second;
        return s;
    }

    export template<class K, class T>
        iarchive& operator>>(iarchive& s, std::pair<K, T>& o)
    {
        s >> o.first;
        s >> o.second;
        return s;
    }

    export bool integer_to_ascii(long long convert,
        character* string,
        long long base)
    {
        if (base >= 36 || base < 2)
            return false;
        else
        {
            character digits[] = { '0','1','2','3','4','5','6','7','8','9',
                                  'a','b','c','d','e','f','g','h','i','j',
                                  'k','l','m','n','o','p','q','r','s','t',
                                  'u','v','w','x','y','z' };

            if (!convert)
            {
                *string = '0';
                *(string + 1) = '\0';
            }
            else
            {
                long long i = 0;

                if (base == 10 && convert < 0)
                {
                    string[i] = '-';
                    convert = -convert;
                    i++;
                }
                long long u = (long long)convert;
                while (u)
                {
                    long long remainder = u % base;

                    string[i] = digits[remainder];
                    u /= base;
                    i++;
                }
                string[i] = '\0';
                if (string[0] == '-')
                    reverse_string(string + 1);
                else
                    reverse_string(string);
            }
        }
        return true;
    }

    export template <class character>
    gstring<character> integer_to_string(long long convert, long long base=10)
    {
        character bupher[80];

        integer_to_ascii(convert,
            bupher,
            base);

        return (character*)bupher;
    }
        
    export template<class character>
    std::ostream& operator<<(std::ostream& s, const gstring<character>& o)
    {
        for (character c : o) s << (char)c;
        return s;
    }

    export template<class character>
    std::wostream& operator<<(std::wostream& s, const gstring<character>& o)
    {
        for (character c : o) s << (wchar_t)c;
        return s;
    }

    export template<class character>
        oarchive& operator<<(oarchive& oa, const gstring<character>& o)
    {
        long long l = o.length();
        oa << l;
        for (long long i = 0; i < l; i++)
            oa << o[i];
        return oa;
    }

    export template<class character>
        iarchive& operator>>(iarchive& ia, gstring<character>& o)
    {
        long long l;
        ia >> l;
        for (long long i = 0; i < l; i++)
        {
            character c;
            ia >> c;
            o.push(c);
        }
        return ia;
    }

    export template<class character>
        std::istream& operator>>(std::istream& s, gstring<character>& o)
    {
        gstring<character> t;
        char c;
        while (!s.eof())
        {
            s >> c;
            if (!s.eof()) t.push(c);
        }
        o = t;
        return s;
    }

    export template<class character>
    std::wistream& operator>>(std::wistream& s, gstring<character>& o)
    {
        gstring<character> t;
        wchar_t c;
        while (!s.eof())
        {
            s >> c;
            if (!s.eof()) t.push(c);
        }
        o = t;
        return s;
    }
    
    export template<class T, class Compare, class Allocator>
        oarchive& operator<<(oarchive& s, const std::set<T,Compare,Allocator>& o)
    {
        s << o.size();
        for (T t : o) s << t;
        return s;
    }

    export template<class T, class Compare, class Allocator>
        iarchive& operator>>(iarchive& s, std::set<T,Compare,Allocator>& o)
    {
        long long length;
        s >> length;
        for (long long i = 0; i < length; i++)
        {
            T t;
            s >> t;
            o.insert(t);
        }
        return s;
    }

    export template<class T, class Compare, class Allocator>
        oarchive& operator<<(oarchive& s, const std::multiset<T, Compare, Allocator>& o)
    {
        s << o.size();
        for (T t : o) s << t;
        return s;
    }

    export template<class T, class Compare, class Allocator>
        iarchive& operator>>(iarchive& s, std::multiset<T, Compare, Allocator>& o)
    {
        long long length;
        s >> length;
        for (long long i = 0; i < length; i++)
        {
            T t;
            s >> t;
            o.insert(t);
        }
        return s;
    }

    export template<class T, class Hash, class Equal, class Allocator>
        oarchive& operator<<(oarchive& s, const std::unordered_set<T, Hash, Equal, Allocator>& o)
    {
        s << o.size();
        for (T t : o) s << t;
        return s;
    }

    export template<class T, class Hash, class Equal, class Allocator>
        iarchive& operator>>(iarchive& s, std::unordered_set<T, Hash, Equal, Allocator>& o)
    {
        long long length;
        s >> length;
        for (long long i = 0; i < length; i++)
        {
            T t;
            s >> t;
            o.insert(t);
        }
        return s;
    }

    export template<class T, class Hash, class Equal, class Allocator>
        oarchive& operator<<(oarchive& s, const std::unordered_multiset<T, Hash, Equal, Allocator>& o)
    {
        s << o.size();
        for (T t : o) s << t;
        return s;
    }

    export template<class T, class Hash, class Equal, class Allocator>
        iarchive& operator>>(iarchive& s, std::unordered_multiset<T, Hash, Equal, Allocator>& o)
    {
        long long length;
        s >> length;
        for (long long i = 0; i < length; i++)
        {
            T t;
            s >> t;
            o.insert(t);
        }
        return s;
    }

    export oarchive& operator<<(oarchive& s, const std::string& o)
    {
        s << o.size();
        std::string::const_iterator e = o.end();
        std::string::const_iterator l = e - 1;
        for (std::string::const_iterator i = o.begin(); i != e; ++i)
        {
            s << *i;
        }
        return s;
    }

    export iarchive& operator>>(iarchive& s, std::string& o)
    {
        int length;
        s >> length;
        for (long long i = 0; i < length; i++)
        {
            char t;
            s >> t;
            o.push_back(t);
        }
        return s;
    }

    export template<class T, class Allocator>
        oarchive& operator<<(oarchive& s, const std::list<T,Allocator>& o)
    {
        s << o.size();
        for (T t : o) s << t;
        return s;
    }

    export template<class T, class Allocator>
        iarchive& operator>>(iarchive& s, std::list<T,Allocator>& o)
    {
        long long length;
        s >> length;
        for (long long i = 0; i < length; i++)
        {
            T t;
            s >> t;
            o.push_back(t);
        }
        return s;
    }

    export template<class T, class Allocator>
        oarchive& operator<<(oarchive& s, const std::forward_list<T,Allocator>& o)
    {
        s << o.size();
        for (T t : o) s << t;
        return s;
    }

    export template<class T, class Allocator>
        iarchive& operator>>(iarchive& s, std::forward_list<T,Allocator>& o)
    {
        long long length;
        s >> length;
        for (long long i = 0; i < length; i++)
        {
            T t;
            s >> t;
            o.push_back(t);
        }
        return s;
    }

    export template<class T, class Allocator>
        oarchive& operator<<(oarchive& s, const std::vector<T,Allocator>& o)
    {
        s << o.size();
        for (T t : o) s << t;
        return s;
    }

    export template<class T, class Allocator>
        iarchive& operator>>(iarchive& s, std::vector<T,Allocator>& o)
    {
        long long length;
        s >> length;
        for (long long i = 0; i < length; i++)
        {
            T t;
            s >> t;
            o.push_back(t);
        }
        return s;
    }

    export template<class T, class Allocator>
        oarchive& operator<<(oarchive& s, const std::deque<T,Allocator>& o)
    {
        s << o.size();
        for (T t : o) s << t;
        return s;
    }

    export template<class T, class Allocator>
        iarchive& operator>>(iarchive& s, std::deque<T,Allocator>& o)
    {
        long long length;
        s >> length;
        for (long long i = 0; i < length; i++)
        {
            T t;
            s >> t;
            o.push_back(t);
        }
        return s;
    }

    export template<class K, class T, class Compare, class Allocator>
        inline oarchive& operator<<(oarchive& s, const std::map<K, T, Compare, Allocator>& o)
    {
        s << o.size();
        for (std::pair<K, T> p : o) s << p;
        return s;
    }

    export template<class K, class T, class Compare, class Allocator>
        inline iarchive& operator>>(iarchive& s, std::map<K, T, Compare, Allocator>& o)
    {
        long long length;
        s >> length;
        for (long long i = 0; i < length; i++)
        {
            std::pair<K, T> t;
            s >> t;
            o[t.first] = t.second;
        }
        return s;
    }

    
    export template<class K, class T, class Hash, class Equal, class Allocator>
        inline oarchive& operator<<(oarchive& s, const std::unordered_map<K, T, Hash, Equal, Allocator>& o)
    {
        s << o.size();
        for (std::pair<K, T> p : o) s << p;
        return s;
    }

    export template<class K, class T, class Hash, class Equal, class Allocator>
        inline iarchive& operator>>(iarchive& s, std::unordered_map<K, T, Hash, Equal, Allocator>& o)
    {
        long long length;
        s >> length;
        for (long long i = 0; i < length; i++)
        {
            std::pair<K, T> t;
            s >> t;
            o[t.first] = t.second;
        }
        return s;
    }

    export template<class K, class T, class Hash, class Equal, class Allocator>
        inline oarchive& operator<<(oarchive& s, const std::unordered_multimap<K, T, Hash, Equal, Allocator>& o)
    {
        s << o.size();
        for (std::pair<K, T> p : o) s << p;
        return s;
    }

    export template<class K, class T, class Hash, class Equal, class Allocator>
        inline iarchive& operator>>(iarchive& s, std::unordered_multimap<K, T, Hash, Equal, Allocator>& o)
    {
        long long length;
        s >> length;
        for (long long i = 0; i < length; i++)
        {
            std::pair<K, T> t;
            s >> t;
            o.insert(t);
        }
        return s;
    }


    export template<class K, class T, class Compare, class Allocator>
        inline oarchive& operator<<(oarchive& s, const std::multimap<K, T, Compare, Allocator>& o)
    {
        s << o.size();
        for (std::pair<K, T> p : o) s << p;
        return s;
    }

    export template<class K, class T, class Compare, class Allocator>
        inline iarchive& operator>>(iarchive& s, std::multimap<K, T, Compare, Allocator>& o)
    {
        long long length;
        s >> length;
        for (long long i = 0; i < length; i++)
        {
            std::pair<K, T> t;
            s >> t;
            o.insert(t);
        }
        return s;
    }

    export template<class t>
        struct set_node : public node
    {
        t element;

        set_node(const t& elementset,
            node* parent) : node(parent), element(elementset) {}

        operator t& () { return element; }

    };

    export template <class t>
        struct set_iterator
    {
        node* _node;

        set_iterator() : _node(0) {}

        set_iterator(node* in) : _node(in) {}

        set_iterator(const set_iterator<t>& i) : _node(i._node) {}

        t& operator*() const
        {
            return ((set_node<t>*)_node)->element;
        }

        t* operator->() const
        {
            return &((set_node<t>*)_node)->element;
        }

        t* operator&() const
        {
            return &((set_node<t>*)_node)->element;
        }

        set_iterator<t>& operator++()
        {
            _node = next_item(_node); return *this;
        }

        set_iterator<t> operator++(int)
        {
            set_iterator<t> saau = *this; ++* this;return saau;
        }

        set_iterator<t>& operator+=(long long increment)
        {
            for (long long i = 0; i < increment; i++)++* this; return *this;
        }

        set_iterator<t> operator+(long long increment) const
        {
            set_iterator<t> result(*this);
            for (long long i = 0; i < increment; i++) ++result;
            return result;
        }

        set_iterator<t>& operator--()
        {
            _node = previous_item(_node); return *this;
        }

        set_iterator<t> operator--(int)
        {
            set_iterator<t> saau = *this; --* this;return saau;
        }

        set_iterator<t>& operator-=(long long decrement)
        {
            for (long long i = 0; i < decrement; i++)--* this; return *this;
        }

        set_iterator<t> operator-(long long decrement) const
        {
            set_iterator<t> result(*this);
            for (long long i = 0; i < decrement; i++) --result;
            return result;
        }

        bool operator==(const set_iterator<t>& y) const { return _node == y._node; }

        bool operator!=(const set_iterator<t>& y) const { return _node != y._node; }

        const t& operator[](long long i) const { return i >= 0 ? *(*this + i) : *(*this - -i); }

        long long operator-(set_iterator<t> iter) const
        {
            long long result = 0;
            while (iter++ != *this) { result++; }
            return result;
        }

        bool is_header() const { return _node->is_header(); }
    };

    export template <class t>
        struct const_set_iterator
    {
        const node* _node;

        const_set_iterator() : _node(0) {}

        const_set_iterator(const node* in) : _node(in) {}

        const_set_iterator(const const_set_iterator<t>& i) : _node(i._node) {}

        const_set_iterator(const set_iterator<t>& i) : _node(i._node) {}

        const t& operator*() const
        {
            return ((set_node<t>*)_node)->element;
        }

        const t* operator->() const
        {
            return &((set_node<t>*)_node)->element;
        }

        const t* operator&() const
        {
            return &((set_node<t>*)_node)->element;
        }

        const_set_iterator<t>& operator++()
        {
            _node = next_item((node*)_node); return *this;
        }

        const_set_iterator<t> operator++(int)
        {
            const_set_iterator<t> saau = *this;
            ++* this;
            return saau;
        }

        const_set_iterator<t> operator+(long long increment) const
        {
            const_set_iterator<t> result(*this);
            for (long long i = 0; i < increment; i++) ++result;
            return result;
        }

        const_set_iterator<t>& operator--()
        {
            _node = previous_item((node*)_node); return *this;
        }

        const_set_iterator<t> operator--(int)
        {
            set_iterator<t> saau = *this; --* this;return saau;
        }

        const_set_iterator<t> operator-(long long decrement) const
        {
            const_set_iterator<t> result(*this);
            for (long long i = 0; i < decrement; i++) --result;
            return result;
        }

        bool operator==(const const_set_iterator<t>& y) const { return _node == y._node; }

        bool operator!=(const const_set_iterator<t>& y) const { return _node != y._node; }

        const t& operator[](long long i) const { return i >= 0 ? *(*this + i) : *(*this - -i); }

        long long operator-(const_set_iterator<t> iter) const
        {
            long long result = 0;
            while (iter++ != *this) { result++; }
            return result;
        }

        bool is_header() const { return _node->is_header(); }
    };

    export template <class t>
        struct set : semaphore
    {
        typedef bool (*is_less)(const t&, const t&);

        typedef set_iterator<t> iterator;
        typedef const_set_iterator<t> const_iterator;

        node header;
        is_less less;

        set(is_less C = compare) : less(C) {}

        set(const set<t>& copy) : less(copy.less)
        {
            //        wait w(copy);
            for (t tiip : copy) *this << tiip;
        }

        set(const set& A, const set& B, long long operation)
        {
            wait wA(A);
            wait wB(B);

            less = A.less;

            const_set_iterator<t> first1 = A.begin();
            const_set_iterator<t> last1 = A.end();
            const_set_iterator<t> first2 = B.begin();
            const_set_iterator<t> last2 = B.end();

            switch (operation)
            {
            case set_operation::_union:
            {
                while (first1 != last1 && first2 != last2)
                {
                    bool is_less = less(*first1, *first2);
                    bool is_greater = less(*first2, *first1);

                    if (is_less)
                    {
                        insert(*first1);
                        ++first1;
                    }

                    else if (is_greater)
                    {
                        insert(*first2);
                        ++first2;
                    }

                    else
                    {
                        insert(*first1);
                        ++first1; ++first2;
                    }
                }

                while (first1 != last1)
                {
                    insert(*first1);
                    first1++;
                }

                while (first2 != last2)
                {
                    insert(*first2);
                    first2++;
                }
            }
            break;

            case set_operation::intersection:
            {
                while (first1 != last1 && first2 != last2)
                {
                    bool is_less = less(*first1, *first2);
                    bool is_greater = less(*first2, *first1);

                    if (is_less)
                        ++first1;

                    else if (is_greater)
                        ++first2;

                    else
                    {
                        insert(*first1);
                        ++first1; ++first2;
                    }
                }
            }
            break;

            case set_operation::symmetric_difference:
            {
                while (first1 != last1 && first2 != last2)
                {
                    bool is_less = less(*first1, *first2);
                    bool is_greater = less(*first2, *first1);

                    if (is_less)
                    {
                        insert(*first1);
                        ++first1;
                    }

                    else if (is_greater)
                    {
                        insert(*first2);
                        ++first2;
                    }

                    else
                    {
                        ++first1; ++first2;
                    }
                }

                while (first1 != last1)
                {
                    insert(*first1);
                    ++first1;
                }

                while (first2 != last2)
                {
                    insert(*first2);
                    ++first2;
                }
            }
            break;

            case set_operation::difference:
            {
                while (first1 != last1 && first2 != last2)
                {
                    bool is_less = less(*first1, *first2);
                    bool is_greater = less(*first2, *first1);

                    if (is_less)
                    {
                        insert(*first1);
                        ++first1;
                    }

                    else if (is_greater)
                    {
                        insert(*first1);
                        ++first1; ++first2;
                    }

                    else
                    {
                        ++first1; ++first2;
                    }
                }

                while (first1 != last1)
                {
                    insert(*first1);
                    ++first1;
                }
            }
            break;

            default:
                throw invalid_set_operation_exception();
            }
        }

        set<t>& operator<<(const set<t>& i)
        {
            wait wA(*this);
            wait wB(i);
            for (t _t : i) *this << _t;
            return *this;
        }

        template<class I>
        set(I first, I last, is_less C)
        {
            less = C;
            while (first != last) insert(*first++);
        }

        ~set()
        {
            wait w(*this);
            destroy((set_node<t>*)header.parent);
        }

        set<t>& operator=(const set<t>& copy)
        {
            wait wA(*this);
            // wait wB(copy);
            erase();
            less = copy.less;
            for (t _t : copy) *this << _t;
            return *this;
        }

        void update(const t& tiip)
        {
            wait w(*this);
            try
            {
                *this << tiip;
            }
            catch (entry_already_exists_exception)
            {
                *this >> tiip;
                *this << tiip;

            }
        }

        long long length() const { return count(header.parent); }

        long long size() const { return count(header.parent); }

        set<t>& operator<<(const t& element) { insert(element); return *this; }

        set<t>& operator>>(const t& element) { erase(element); return *this; }

        void push_back(const t& _t)
        {
            *this << _t;
        }

        set_iterator<t> begin() { return header.left; }

        set_iterator<t> end() { return &header; }

        const_set_iterator<t> begin() const { return header.left; }

        const_set_iterator<t> end() const { return &header; }

        set_iterator<t> insert(const t& element)
        {
            wait w(*this);

            node* root_node = header.parent;

            if (root_node == 0)
            {
                root_node = new set_node<t>(element, &header);
                header.left = root_node;
                header.right = root_node;
                header.parent = root_node;
                return root_node;
            }

            else
            {
                for (; ; )
                {
                    bool is_less = less(element, ((set_node<t>*)root_node)->element);
                    bool is_greater = less(((set_node<t>*)root_node)->element, element);

                    if (!is_less && !is_greater)
                        throw entry_already_exists_exception();

                    else if (is_less)
                    {
                        if (root_node->left != 0)
                            root_node = root_node->left;
                        else
                        {
                            node* nioo_node = new set_node<t>(element, root_node);
                            root_node->left = nioo_node;
                            adjust_add(nioo_node);
                            return nioo_node;
                        }
                    }

                    else
                    {
                        if (root_node->right != 0)
                            root_node = root_node->right;
                        else
                        {
                            node* nioo_node = new set_node<t>(element, root_node);
                            root_node->right = nioo_node;
                            adjust_add(nioo_node);
                            return nioo_node;
                        }
                    }
                }
            }
        }

        void erase(const t& element)
        {
            wait w(*this);

            node* root_node = header.parent;

            for (; ; )
            {
                if (root_node == 0) throw entry_not_found_exception();

                bool is_less = less(element, ((set_node<t>*)root_node)->element);
                bool is_greater = less(((set_node<t>*)root_node)->element, element);

                if (is_less)
                    root_node = root_node->left;

                else if (is_greater)
                    root_node = root_node->right;

                else
                {
                    if (root_node->left != 0 && root_node->right != 0)
                    {
                        node* replaas = root_node->left;
                        while (replaas->right != 0) replaas = replaas->right;
                        swap_nodes(root_node, replaas);
                    }

                    node* parent = root_node->parent;

                    long long from = (parent->left == root_node) ? direction::from_left : direction::from_right;

                    if (root_node->left == 0)
                    {
                        if (parent == &header)
                            header.parent = root_node->right;
                        else if (from == direction::from_left)
                            parent->left = root_node->right;
                        else
                            parent->right = root_node->right;

                        if (root_node->right != 0) root_node->right->parent = parent;
                    }
                    else
                    {
                        if (parent == &header)
                            header.parent = root_node->left;
                        else if (from == direction::from_left)
                            parent->left = root_node->left;
                        else
                            parent->right = root_node->left;

                        if (root_node->left != 0) root_node->left->parent = parent;
                    }

                    adjust_remove(parent, from);
                    delete (set_node<t>*)root_node;
                    break;
                }
            }
        }

        void erase(set_iterator<t> i)
        {
            wait w(*this);

            node* root_node = i._node;

            if (root_node->is_header()) throw is_header_exception();

            if (root_node->left != 0 && root_node->right != 0)
            {
                node* replaas = root_node->left;
                while (replaas->right != 0) replaas = replaas->right;
                swap_nodes(root_node, replaas);
            }

            node* parent = root_node->parent;

            long long from = (parent->left == root_node) ? direction::from_left : direction::from_right;

            if (root_node->left == 0)
            {
                if (parent == &header)
                    header.parent = root_node->right;
                else if (from == direction::from_left)
                    parent->left = root_node->right;
                else
                    parent->right = root_node->right;

                if (root_node->right != 0) root_node->right->parent = parent;
            }
            else
            {
                if (parent == &header)
                    header.parent = root_node->left;
                else if (from == direction::from_left)
                    parent->left = root_node->left;
                else
                    parent->right = root_node->left;

                if (root_node->left != 0) root_node->left->parent = parent;
            }

            adjust_remove(parent, from);
            delete (set_node<t>*)root_node;
        }

        bool operator[](const t& element) const { return exists(element); }

        bool exists(const t& element) const
        {
            set<t>& se = (set<t>&) * this;
            wait w(se);

            if (!header.parent)
                return false;
            else
            {
                const node* serch_node = header.parent;

                do
                {
                    bool is_less = less(element, ((set_node<t>*)serch_node)->element);
                    bool is_greater = less(((set_node<t>*)serch_node)->element, element);

                    if (is_less) serch_node = serch_node->left;

                    else if (is_greater) serch_node = serch_node->right;

                    else break;

                } while (serch_node);

                return serch_node != 0;
            }
        }

        t locate(const t& element)
        {
            set_iterator<t> si = find(element);
            return *si;
        }

        set_iterator<t> find(const t& element) const
        {
            wait w(*this);

            if (!header.parent)
                throw entry_not_found_exception();
            else
            {
                const node* serch_node = header.parent;

                do
                {
                    bool _less = less(element, ((set_node<t>*)serch_node)->element);
                    bool _greater = less(((set_node<t>*)serch_node)->element, element);

                    if (_less < 0) serch_node = serch_node->left;

                    else if (_greater > 0) serch_node = serch_node->right;

                    else break;

                } while (serch_node);

                if (serch_node == 0) throw entry_not_found_exception();

                return (node*)serch_node;
            }
        }

        t get(const t& element) const
        {
            set_iterator<t> si = find(element);
            return *si;
        }

        void erase()
        {
            wait w(*this);
            destroy((set_node<t>*)header.parent);
            header.left = &header;
            header.right = &header;
            header.parent = 0;
        }

        set_iterator<t> after(const t& element) const
        {
            wait w(*this);

            const node* y = &header;
            const node* x = header.parent;

            while (x != 0)
                if (less(element, ((set_node<t>*)x)->element))
                {
                    y = x; x = x->left;
                }
                else
                    x = x->right;

            return (node*)y;
        }

        set_iterator<t> after_equals(const t& element) const
        {
            wait w(*this);

            const node* y = &header;
            const node* x = header.parent;

            while (x != 0)
            {
                bool _less = less(element, ((set_node<t>*)x)->element);
                bool _greater = less(((set_node<t>*)x)->element, element);
                if (!_less && !_greater)
                {
                    y = x; break;
                }
                else if (_less)
                {
                    y = x; x = x->left;
                }
                else
                    x = x->right;
            }

            return (node*)y;
        }

        set_iterator<t> before(const t& element) const
        {
            wait w(*this);

            const node* y = &header;
            const node* x = header.parent;

            while (x != 0)
            {
                if (!less(((set_node<t>*)x)->element, element))
                {
                    x = x->left;
                }
                else
                {
                    y = x; x = x->right;
                }
            }
            return (node*)y;
        }

        set_iterator<t> before_equals(const t& element) const
        {
            wait w(*this);

            const node* y = &header;
            const node* x = header.parent;

            while (x != 0)
            {
                bool _less = less(element, ((set_node<t>*)x)->element);
                bool _greater = less(((set_node<t>*)x)->element, element);
                if (!_less && !_greater)
                {
                    y = x; break;
                }
                else if (_less)
                    x = x->left;
                else
                {
                    y = x; x = x->right;
                }
            }

            return (node*)y;
        }

        set_iterator<t> last() { return header.right; }

        const_set_iterator<t> last() const { return header.right; }

        long long depth() const { wait w(*this);  return depth(header.parent); }

        node* get_first()
        {
            if (!header.parent)
                return &header;

            else
            {
                node* serch_node = header.parent;
                while (serch_node->left) serch_node = serch_node->left;
                return serch_node;
            }
        }

        node* get_last()
        {
            if (!header.parent)
                return &header;

            else
            {
                node* serch_node = header.parent;
                while (serch_node->right) serch_node = serch_node->right;
                return serch_node;
            }
        }

        void destroy(node* root_node)
        {
            if (root_node)
            {
                if (root_node->left)
                    destroy((set_node<t>*)root_node->left);

                if (root_node->right)
                    destroy((set_node<t>*)root_node->right);

                delete root_node;
            }
        }

    };

    export template<class t>
    inline set<t> operator|(const set<t>& a, const set<t>& b)
    {
        set<t> r(a, b, set_operation::_union); return r;
    }

    export template<class t>
    inline set<t> operator&(const set<t>& a, const set<t>& b)
    {
        set<t> r(a, b, set_operation::intersection); return r;
    }

    export template<class t>
    inline set<t> operator^(const set<t>& a, const set<t>& b)
    {
        set<t> r(a, b, set_operation::symmetric_difference); return r;
    }

    export template<class t>
    inline set<t> operator-(const set<t>& a, const set<t>& b)
    {
        set<t> r(a, b, set_operation::difference); return r;
    }

    export template<class t>
    inline bool operator==(const set<t>& a, const set<t>& b)
    {
        const_set_iterator<t> first1 = a.begin();
        const_set_iterator<t> last1 = a.end();
        const_set_iterator<t> first2 = b.begin();
        const_set_iterator<t> last2 = b.end();

        bool equals = true;

        typename set<t>::is_less c = a;

        while (first1 != last1 && first2 != last2)
        {
            bool less = c(*first1, *first2);
            bool greater = c(*first2, *first1);

            if (less)
            {
                equals = false; break;
            }
            else if (greater)
            {
                equals = false; break;
            }
            else
            {
                ++first1; ++first2;
            }
        }

        if (equals)
        {
            if (first1 != last1) equals = false;
            if (first2 != last2) equals = false;
        }

        return equals;
    }

    export template<class t>
    inline bool operator!=(const set<t>& a, const set<t>& b) { return !(a == b); }

    export template<class t>
    inline bool operator<=(const set<t>& a, const set<t>& b)
    {

        const_set_iterator<t> first1 = a.begin();
        const_set_iterator<t> last1 = a.end();
        const_set_iterator<t> first2 = b.begin();
        const_set_iterator<t> last2 = b.end();

        typename set<t>::is_less c = a;

        bool subset = true;

        while (first1 != last1 && first2 != last2)
        {
            bool less = c(*first1, *first2);
            bool greater = c(*first2, *first1);

            if (less)
            {
                subset = false; break;
            }

            else if (greater)
                ++first2;

            else
            {
                ++first1; ++first2;
            }
        }

        if (subset) if (first1 != last1) subset = false;

        return subset;
    }

    export template<class t>
        int compare(const set<t>& a, const set<t>& b)
    {
        const_set_iterator<t> first1 = a.begin();
        const_set_iterator<t> last1 = a.end();
        const_set_iterator<t> first2 = b.begin();
        const_set_iterator<t> last2 = b.end();

        typename set<t>::is_less c = a.less;

        while (first1 != last1 && first2 != last2)
        {
            bool less = c(*first1, *first2);
            bool greater = c(*first2, *first1);
            if (less)
                return -1;
            else if (greater)
                return 1;
            else
            {
                ++first1; ++first2;
            }
        }

        if (first1 != last1) return 1;
        if (first2 != last2) return -1;

        return 0;
    }

    export template<class t>
        bool operator<(const set<t>& a, const set<t>& b)
    {
        return compare(a, b) < 0;
    }

    export template<class T>
        oarchive& operator<<(oarchive& s, const set<T>& o)
    {
        s << o.length();
        const_set_iterator<T> e = o.end();
        const_set_iterator<T> l = e - 1;
        for (const_set_iterator<T> i = o.begin(); i != e; ++i)
        {
            s << *i;
        }
        return s;
    }

    export template<class T>
        iarchive& operator>>(iarchive& s, set<T>& o)
    {
        long long length;
        s >> length;
        for (long long i = 0; i < length; i++)
        {
            T t;
            s >> t;
            o << t;
        }
        return s;
    }

    export template<class T>
        std::ostream& operator<<(std::ostream& s, const set<T>& o)
    {
        s << "{";
        const_set_iterator<T> e = o.end();
        const_set_iterator<T> l = e - 1;
        for (const_set_iterator<T> i = o.begin(); i != e; ++i)
        {
            s << *i; if (i != l) s << ",";
        }
        s << "}";
        return s;
    }

    export template<class T>
        std::wostream& operator<<(std::wostream& s, const set<T>& o)
    {
        s << L"{";
        const_set_iterator<T> e = o.end();
        const_set_iterator<T> l = e - 1;
        for (const_set_iterator<T> i = o.begin(); i != e; ++i)
        {
            s << *i; if (i != l) s << L",";
        }
        s << L"}";
        return s;
    }

    export struct bag_operation
    {
        enum
        {
            _union,
            intersection,
            symmetric_difference,
            difference,
        };
    };

    export template<class t>
        struct bag_node : public node
    {
        t element;

        bag_node(const t& elementbag,
            node* parent) : node(parent), element(elementbag) {}

        operator t& () { return element; }
    };

    export template <class t>
        struct bag_iterator
    {
        node* _node;

        bag_iterator() : _node(0) {}

        bag_iterator(node* in) : _node(in) {}

        bag_iterator(const bag_iterator<t>& i) : _node(i._node) {}

        t& operator*() const
        {
            return ((bag_node<t>*)_node)->element;
        }

        t* operator->() const
        {
            return &((bag_node<t>*)_node)->element;
        }

        t* operator&() const
        {
            return &((bag_node<t>*)_node)->element;
        }

        bag_iterator<t>& operator++()
        {
            _node = next_item(_node); return *this;
        }

        bag_iterator<t> operator++(int)
        {
            bag_iterator<t> saau = *this; ++* this;return saau;
        }

        bag_iterator<t>& operator+=(long long increment)
        {
            for (long long i = 0; i < increment; i++)++* this; return *this;
        }

        bag_iterator<t> operator+(long long increment) const
        {
            bag_iterator<t> result(*this);
            for (long long i = 0; i < increment; i++) ++result;
            return result;
        }

        bag_iterator<t>& operator--()
        {
            _node = previous_item(_node); return *this;
        }

        bag_iterator<t> operator--(int)
        {
            bag_iterator<t> saau = *this; --* this;return saau;
        }

        bag_iterator<t>& operator-=(long long decrement)
        {
            for (long long i = 0; i < decrement; i++)--* this; return *this;
        }

        bag_iterator<t> operator-(long long decrement) const
        {
            bag_iterator<t> result(*this);
            for (long long i = 0; i < decrement; i++) --result;
            return result;
        }

        bool operator==(const bag_iterator<t>& y) const { return _node == y._node; }

        bool operator!=(const bag_iterator<t>& y) const { return _node != y._node; }

        const t& operator[](long long i) const { return i >= 0 ? *(*this + i) : *(*this - -i); }

        long long operator-(bag_iterator<t> iter) const
        {
            long long result = 0;
            while (iter++ != *this) { result++; }
            return result;
        }

        bool is_header() const { return _node->is_header(); }
    };

    export template <class t>
        struct const_bag_iterator
    {
        const node* _node;

        const_bag_iterator() : _node(0) {}

        const_bag_iterator(const node* in) : _node(in) {}

        const_bag_iterator(const const_bag_iterator<t>& i) : _node(i._node) {}

        const_bag_iterator(const bag_iterator<t>& i) : _node(i._node) {}

        const t& operator*() const
        {
            return ((bag_node<t>*)_node)->element;
        }

        const t* operator->() const
        {
            return &((bag_node<t>*)_node)->element;
        }

        const t* operator&() const
        {
            return &((bag_node<t>*)_node)->element;
        }

        const_bag_iterator<t>& operator++()
        {
            _node = next_item((node*)_node); return *this;
        }

        const_bag_iterator<t> operator++(int)
        {
            const_bag_iterator<t> saau = *this;
            ++* this;
            return saau;
        }

        const_bag_iterator<t> operator+(long long increment) const
        {
            const_bag_iterator<t> result(*this);
            for (long long i = 0; i < increment; i++) ++result;
            return result;
        }

        const_bag_iterator<t>& operator--()
        {
            _node = previous_item((node*)_node); return *this;
        }

        const_bag_iterator<t> operator--(int)
        {
            bag_iterator<t> saau = *this; --* this;return saau;
        }

        const_bag_iterator<t> operator-(long long decrement) const
        {
            const_bag_iterator<t> result(*this);
            for (long long i = 0; i < decrement; i++) --result;
            return result;
        }

        bool operator==(const const_bag_iterator<t>& y) const { return _node == y._node; }

        bool operator!=(const const_bag_iterator<t>& y) const { return _node != y._node; }

        const t& operator[](long long i) const { return i >= 0 ? *(*this + i) : *(*this - -i); }

        long long operator-(const_bag_iterator<t> iter) const
        {
            long long result = 0;
            while (iter++ != *this) { result++; }
            return result;
        }

        bool is_header() const { return _node->is_header(); }
    };

    export template <class t>
        struct bag : semaphore
    {
        typedef bool (*is_less)(const t&, const t&);

        typedef bag_iterator<t> iterator;
        typedef const_bag_iterator<t> const_iterator;

        node header;
        is_less less;

        bag(is_less C = compare) : less(C) {}

        bag(const bag<t>& copy) : less(copy.less)
        {
            //        wait uu(copy);
            for (t tiip : copy) *this << tiip;
        }

        bag(const bag& A, const bag& B, long long operation)
        {
            wait waitA(A);
            wait waitB(B);

            less = A.less;

            const_bag_iterator<t> first1 = A.begin();
            const_bag_iterator<t> last1 = A.end();
            const_bag_iterator<t> first2 = B.begin();
            const_bag_iterator<t> last2 = B.end();

            switch (operation)
            {
            case bag_operation::_union:
            {
                while (first1 != last1 && first2 != last2)
                {
                    bool is_less = less(*first1, *first2);
                    bool is_greater = less(*first2, *first1);

                    if (is_less)
                    {
                        insert(*first1);
                        ++first1;
                    }

                    else if (is_greater)
                    {
                        insert(*first2);
                        ++first2;
                    }

                    else
                    {
                        insert(*first1);
                        ++first1; ++first2;
                    }
                }

                while (first1 != last1)
                {
                    insert(*first1);
                    first1++;
                }

                while (first2 != last2)
                {
                    insert(*first2);
                    first2++;
                }
            }
            break;

            case bag_operation::intersection:
            {
                while (first1 != last1 && first2 != last2)
                {
                    bool is_less = less(*first1, *first2);
                    bool is_greater = less(*first2, *first1);

                    if (is_less)
                        ++first1;

                    else if (is_greater)
                        ++first2;

                    else
                    {
                        insert(*first1);
                        ++first1; ++first2;
                    }
                }
            }
            break;

            case bag_operation::symmetric_difference:
            {
                while (first1 != last1 && first2 != last2)
                {
                    bool is_less = less(*first1, *first2);
                    bool is_greater = less(*first2, *first1);

                    if (is_less)
                    {
                        insert(*first1);
                        ++first1;
                    }

                    else if (is_greater)
                    {
                        insert(*first2);
                        ++first2;
                    }

                    else
                    {
                        ++first1; ++first2;
                    }
                }

                while (first1 != last1)
                {
                    insert(*first1);
                    ++first1;
                }

                while (first2 != last2)
                {
                    insert(*first2);
                    ++first2;
                }
            }
            break;

            case bag_operation::difference:
            {
                while (first1 != last1 && first2 != last2)
                {
                    bool is_less = less(*first1, *first2);
                    bool is_greater = less(*first2, *first1);

                    if (is_less)
                    {
                        insert(*first1);
                        ++first1;
                    }

                    else if (is_greater)
                    {
                        insert(*first1);
                        ++first1; ++first2;
                    }

                    else
                    {
                        ++first1; ++first2;
                    }
                }

                while (first1 != last1)
                {
                    insert(*first1);
                    ++first1;
                }
            }
            break;

            default:
                throw invalid_bag_operation_exception();
            }
        }

        bag<t>& operator<<(const bag<t>& i)
        {
            wait waitA(*this);
            wait waitB(i);
            for (t _t : i) *this << _t;
            return *this;
        }

        template<class I>
        bag(I first, I last, is_less C)
        {
            less = C;
            while (first != last) insert(*first++);
        }

        ~bag()
        {
            wait uu(*this);
            destroy((bag_node<t>*)header.parent);
        }

        bag<t>& operator=(const bag<t>& copy)
        {
            wait waitA(*this);
            //        wait waitB(copy);
            erase();
            less = copy.less;
            for (t _t : copy) *this << _t;
            return *this;
        }

        long long length() const { return count(header.parent); }

        long long size() const { return count(header.parent); }

        bag<t>& operator<<(const t& element) { insert(element); return *this; }

        bag<t>& operator>>(const t& element) { erase(element); return *this; }

        void push_back(const t& _t)
        {
            *this << _t;
        }

        bag_iterator<t> begin() { return header.left; }

        bag_iterator<t> end() { return &header; }

        const_bag_iterator<t> begin() const { return header.left; }

        const_bag_iterator<t> end() const { return &header; }

        bag_iterator<t> insert(const t& element)
        {
            wait uu(*this);

            node* root_node = header.parent;

            if (root_node == 0)
            {
                root_node = new bag_node<t>(element, &header);
                header.left = root_node;
                header.right = root_node;
                header.parent = root_node;
                return root_node;
            }

            else
            {
                for (; ; )
                {
                    bool is_less = less(element, ((bag_node<t>*)root_node)->element);

                    if (is_less)
                    {
                        if (root_node->left != 0)
                            root_node = root_node->left;
                        else
                        {
                            node* nioo_node = new bag_node<t>(element, root_node);
                            root_node->left = nioo_node;
                            adjust_add(nioo_node);
                            return nioo_node;
                        }
                    }

                    else
                    {
                        if (root_node->right != 0)
                            root_node = root_node->right;
                        else
                        {
                            node* nioo_node = new bag_node<t>(element, root_node);
                            root_node->right = nioo_node;
                            adjust_add(nioo_node);
                            return nioo_node;
                        }
                    }
                }
            }
        }


        void erase(bag_iterator<t> i)
        {
            wait uu(*this);

            node* root_node = i._node;

            if (root_node->is_header()) throw is_header_exception();

            if (root_node->left != 0 && root_node->right != 0)
            {
                node* replaas = root_node->left;
                while (replaas->right != 0) replaas = replaas->right;
                swap_nodes(root_node, replaas);
            }

            node* parent = root_node->parent;

            long long from = (parent->left == root_node) ? direction::from_left : direction::from_right;

            if (root_node->left == 0)
            {
                if (parent == &header)
                    header.parent = root_node->right;
                else if (from == direction::from_left)
                    parent->left = root_node->right;
                else
                    parent->right = root_node->right;

                if (root_node->right != 0) root_node->right->parent = parent;
            }
            else
            {
                if (parent == &header)
                    header.parent = root_node->left;
                else if (from == direction::from_left)
                    parent->left = root_node->left;
                else
                    parent->right = root_node->left;

                if (root_node->left != 0) root_node->left->parent = parent;
            }

            adjust_remove(parent, from);
            delete (bag_node<t>*)root_node;
        }

        bool operator[](const t& element) const { return exists(element); }

        bool exists(const t& element) const
        {
            bag<t>& se = (bag<t>&) * this;
            wait uu(se);

            if (!header.parent)
                return false;
            else
            {
                const node* serch_node = header.parent;

                do
                {
                    bool is_less = less(element, ((bag_node<t>*)serch_node)->element);
                    bool is_greater = less(((bag_node<t>*)serch_node)->element, element);

                    if (is_less) serch_node = serch_node->left;

                    else if (is_greater) serch_node = serch_node->right;

                    else break;

                } while (serch_node);

                return serch_node != 0;
            }
        }

        t locate(const t& element)
        {
            bag_iterator<t> si = find(element);
            return *si;
        }

        bag_iterator<t> find(const t& element) const
        {
            wait uu(*this);

            if (!header.parent)
                throw entry_not_found_exception();
            else
            {
                const node* serch_node = header.parent;

                do
                {
                    bool _less = less(element, ((bag_node<t>*)serch_node)->element);
                    bool _greater = less(((bag_node<t>*)serch_node)->element, element);

                    if (_less < 0) serch_node = serch_node->left;

                    else if (_greater > 0) serch_node = serch_node->right;

                    else break;

                } while (serch_node);

                if (serch_node == 0) throw entry_not_found_exception();

                return (node*)serch_node;
            }
        }

        t get(const t& element) const
        {
            bag_iterator<t> si = find(element);
            return *si;
        }

        void erase()
        {
            wait uu(*this);
            destroy((bag_node<t>*)header.parent);
            header.left = &header;
            header.right = &header;
            header.parent = 0;
        }

        bag_iterator<t> after(const t& element) const
        {
            wait uu(*this);

            const node* y = &header;
            const node* x = header.parent;

            while (x != 0)
                if (less(element, ((bag_node<t>*)x)->element))
                {
                    y = x; x = x->left;
                }
                else
                    x = x->right;

            return (node*)y;
        }

        bag_iterator<t> after_equals(const t& element) const
        {
            wait uu(*this);

            const node* y = &header;
            const node* x = header.parent;

            while (x != 0)
            {
                bool _less = less(element, ((bag_node<t>*)x)->element);
                bool _greater = less(((bag_node<t>*)x)->element, element);
                if (!_less && !_greater)
                {
                    y = x; break;
                }
                else if (_less)
                {
                    y = x; x = x->left;
                }
                else
                    x = x->right;
            }

            return (node*)y;
        }

        bag_iterator<t> before(const t& element) const
        {
            wait uu(*this);

            const node* y = &header;
            const node* x = header.parent;

            while (x != 0)
            {
                if (!less(((bag_node<t>*)x)->element, element))
                {
                    x = x->left;
                }
                else
                {
                    y = x; x = x->right;
                }
            }
            return (node*)y;
        }

        bag_iterator<t> before_equals(const t& element) const
        {
            wait uu(*this);

            const node* y = &header;
            const node* x = header.parent;

            while (x != 0)
            {
                bool _less = less(element, ((bag_node<t>*)x)->element);
                bool _greater = less(((bag_node<t>*)x)->element, element);
                if (!_less && !_greater)
                {
                    y = x; break;
                }
                else if (_less)
                    x = x->left;
                else
                {
                    y = x; x = x->right;
                }
            }

            return (node*)y;
        }

        bag_iterator<t> last() { return header.right; }

        const_bag_iterator<t> last() const { return header.right; }

        long long depth() const { wait uu(*this);  return depth(header.parent); }

        node* get_first()
        {
            if (!header.parent)
                return &header;

            else
            {
                node* serch_node = header.parent;
                while (serch_node->left) serch_node = serch_node->left;
                return serch_node;
            }
        }

        node* get_last()
        {
            if (!header.parent)
                return &header;

            else
            {
                node* serch_node = header.parent;
                while (serch_node->right) serch_node = serch_node->right;
                return serch_node;
            }
        }

        void destroy(bag_node<t>* root_node)
        {
            if (root_node)
            {
                if (root_node->left)
                    destroy((bag_node<t>*)root_node->left);

                if (root_node->right)
                    destroy((bag_node<t>*)root_node->right);

                delete root_node;
            }
        }

    };

    export template<class t>
    inline bag<t> operator|(const bag<t>& a, const bag<t>& b)
    {
        bag<t> r(a, b, bag_operation::_union); return r;
    }

    export template<class t>
    inline bag<t> operator&(const bag<t>& a, const bag<t>& b)
    {
        bag<t> r(a, b, bag_operation::intersection); return r;
    }

    export template<class t>
    inline bag<t> operator^(const bag<t>& a, const bag<t>& b)
    {
        bag<t> r(a, b, bag_operation::symmetric_difference); return r;
    }

    export template<class t>
    inline bag<t> operator-(const bag<t>& a, const bag<t>& b)
    {
        bag<t> r(a, b, bag_operation::difference); return r;
    }

    export template<class t>
    inline bool operator==(const bag<t>& a, const bag<t>& b)
    {
        const_bag_iterator<t> first1 = a.begin();
        const_bag_iterator<t> last1 = a.end();
        const_bag_iterator<t> first2 = b.begin();
        const_bag_iterator<t> last2 = b.end();

        bool equals = true;

        typename bag<t>::is_less c = a;

        while (first1 != last1 && first2 != last2)
        {
            bool less = c(*first1, *first2);
            bool greater = c(*first2, *first1);

            if (less)
            {
                equals = false; break;
            }
            else if (greater)
            {
                equals = false; break;
            }
            else
            {
                ++first1; ++first2;
            }
        }

        if (equals)
        {
            if (first1 != last1) equals = false;
            if (first2 != last2) equals = false;
        }

        return equals;
    }

    export template<class t>
    inline bool operator!=(const bag<t>& a, const bag<t>& b) { return !(a == b); }

    export template<class t>
    inline bool operator<=(const bag<t>& a, const bag<t>& b)
    {

        const_bag_iterator<t> first1 = a.begin();
        const_bag_iterator<t> last1 = a.end();
        const_bag_iterator<t> first2 = b.begin();
        const_bag_iterator<t> last2 = b.end();

        typename bag<t>::is_less c = a;

        bool subbag = true;

        while (first1 != last1 && first2 != last2)
        {
            bool less = c(*first1, *first2);
            bool greater = c(*first2, *first1);

            if (less)
            {
                subbag = false; break;
            }

            else if (greater)
                ++first2;

            else
            {
                ++first1; ++first2;
            }
        }

        if (subbag) if (first1 != last1) subbag = false;

        return subbag;
    }

    export template<class t>
        int compare(const bag<t>& a, const bag<t>& b)
    {
        const_bag_iterator<t> first1 = a.begin();
        const_bag_iterator<t> last1 = a.end();
        const_bag_iterator<t> first2 = b.begin();
        const_bag_iterator<t> last2 = b.end();

        typename bag<t>::is_less c = a.less;

        while (first1 != last1 && first2 != last2)
        {
            bool less = c(*first1, *first2);
            bool greater = c(*first2, *first1);
            if (less)
                return -1;
            else if (greater)
                return 1;
            else
            {
                ++first1; ++first2;
            }
        }

        if (first1 != last1) return 1;
        if (first2 != last2) return -1;

        return 0;
    }

    export template<class T>
    std::ostream& operator<<(std::ostream& s, const bag<T>& o)
    {
        s << "{";
        const_bag_iterator<T> e = o.end();
        const_bag_iterator<T> l = e - 1;
        for (const_bag_iterator<T> i = o.begin(); i != e; ++i)
        {
            s << *i; if (i != l) s << ",";
        }
        s << "}";
        return s;
    }

    export template<class T>
    std::wostream& operator<<(std::wostream& s, const bag<T>& o)
    {
        s << L"{";
        const_bag_iterator<T> e = o.end();
        const_bag_iterator<T> l = e - 1;
        for (const_bag_iterator<T> i = o.begin(); i != e; ++i)
        {
            s << *i; if (i != l) s << L",";
        }
        s << L"}";
        return s;
    }

    export template<class T>
        oarchive& operator<<(oarchive& s, const bag<T>& o)
    {
        s << o.length();
        const_set_iterator<T> e = o.end();
        const_set_iterator<T> l = e - 1;
        for (const_set_iterator<T> i = o.begin(); i != e; ++i)
        {
            s << *i;
        }
        return s;
    }

    export template<class T>
        iarchive& operator>>(iarchive& s, bag<T>& o)
    {
        long long length;
        s >> length;
        for (long long i = 0; i < length; i++)
        {
            T t;
            s >> t;
            o << t;
        }
        return s;
    }

    export template <class T>
        class list_value
    {
    public:

        long long c;
        T t;

        list_value(long long cIn, T tIn) : c(cIn), t(tIn) {}

        long long key() const { return c; }

        T value() const { return t; }
    };

    export template<class T>
        struct list_node : public node
    {
        long long key;
        T daata;

        list_node(long long keySet, const T& daataSet, node* parent)
            : node(parent), key(keySet), daata(daataSet) {}

        operator const long long& () const { return key; }

        operator T& () { return daata; }
    };

    export template <class T>
        struct list_iterator
    {
        node* _node;

        list_iterator() : _node(0) {}

        list_iterator(node* in) : _node(in) {}

        list_iterator(const list_iterator<T>& i) : _node(i._node) {}

        long long key() const
        {
            return ((list_node<T>*)_node)->key;
        }

        T& value() const
        {
            return ((list_node<T>*)_node)->daata;
        }

        T operator*() const
        {
            return value();
        }

        T* operator->() const
        {
            return &(((list_node<T>*)_node)->daata);
        }

        T* operator&() const
        {
            return &(((list_node<T>*)_node)->daata);
        }

        list_iterator<T>& operator++()
        {
            _node = next_item(_node); return *this;
        }

        list_iterator<T> operator++(int)
        {
            list_iterator<T> saau = *this; ++* this;return saau;
        }

        list_iterator<T>& operator+=(long long increment)
        {
            for (long long i = 0; i < increment; i++)++* this; return *this;
        }

        list_iterator<T> operator+(long long increment) const
        {
            list_iterator<T> result(*this);
            for (long long i = 0; i < increment; i++) ++result;
            return result;
        }

        list_iterator<T>& operator--()
        {
            _node = previous_item(_node); return *this;
        }

        list_iterator<T> operator--(int)
        {
            list_iterator<T> saau = *this; --* this;return saau;
        }

        list_iterator<T>& operator-=(long long decrement)
        {
            for (long long i = 0; i < decrement; i++)--* this; return *this;
        }

        list_iterator<T> operator-(long long decrement) const
        {
            list_iterator<T> result(*this);
            for (long long i = 0; i < decrement; i++) --result;
            return result;
        }

        bool operator==(const list_iterator<T>& y) const { return _node == y._node; }

        bool operator!=(const list_iterator<T>& y) const { return _node != y._node; }

        const T& operator[](long long i) const { return i >= 0 ? *(*this + i) : *(*this - -i); }

        long long operator-(list_iterator<T> iter) const
        {
            long long result = 0;
            while (iter++ != *this) { result++; }
            return result;
        }

        bool is_header() const { return _node->is_header(); }
    };

    export template<class T>
        struct const_list_iterator
    {
        const node* _node;

        const_list_iterator() : _node(0) {}

        const_list_iterator(const node* in) : _node(in) {}

        const_list_iterator(const list_iterator<T>& i) : _node(i._node) {}

        const_list_iterator(const const_list_iterator<T>& i) : _node(i._node) {}

        long long key() const
        {
            return ((list_node<T>*)_node)->key;
        }

        const T& value() const
        {
            return ((list_node<T>*)_node)->daata;
        }

        const T& operator*() const
        {
            return value();
        }

        const T* operator->() const
        {
            return &(((list_node<T>*)_node)->daata);
        }

        const T* operator&() const
        {
            return &(((list_node<T>*)_node)->daata);
        }

        const_list_iterator<T>& operator++()
        {
            _node = next_item((node*)_node); return *this;
        }

        const_list_iterator<T> operator++(int)
        {
            const_list_iterator<T> saau = *this; ++* this;return saau;
        }

        const_list_iterator<T>& operator+=(long long increment)
        {
            for (long long i = 0; i < increment; i++)++* this; return *this;
        }

        const_list_iterator<T> operator+(long long increment) const
        {
            const_list_iterator<T> result(*this);
            for (long long i = 0; i < increment; i++) ++result;
            return result;
        }

        const_list_iterator<T>& operator--()
        {
            _node = previous_item((node*)_node); return *this;
        }

        const_list_iterator<T> operator--(int)
        {
            list_iterator<T> saau = *this; --* this; return saau;
        }

        const_list_iterator<T>& operator-=(long long decrement)
        {
            for (long long i = 0; i < decrement; i++)--* this; return *this;
        }

        const_list_iterator<T> operator-(long long decrement) const
        {
            const_list_iterator<T> result(*this);
            for (long long i = 0; i < decrement; i++) --result;
            return result;
        }

        bool operator==(const const_list_iterator<T>& y) const { return _node == y._node; }

        bool operator!=(const const_list_iterator<T>& y) const { return _node != y._node; }

        const T& operator[](long long i) const { return i >= 0 ? *(*this + i) : *(*this - -i); }

        long long operator-(const_list_iterator<T> iter) const
        {
            long long result = 0;
            while (iter++ != *this) { result++; }
            return result;
        }

        bool is_header() const { return _node->is_header(); }
    };

    export template <class T>
        struct list : semaphore
    {
        node header;

        typedef list_iterator<T> iterator;

        typedef const_list_iterator<T> const_iterator;

        list() {}

        list(const list<T>& copy)
        {
            list<T>& c = (list<T>&)copy;
            wait uu(c);
            int s = c.length();
            for (int i = 0; i < s; i++) *this << c[i];
        }

        list(long long _count, const T* _values)
        {
            for (int i = 0; i < _count, i++; ) if (_values[i]) this << _values[i];
        }

        template<class I>
        list(I first, I last)
        {
            while (first != last) insert(*first++);
        }

        ~list()
        {
            wait uu(*this);
            destroy((list_node<T>*)header.parent);
        }

        list<T>& operator=(const list<T>& copy)
        {
            wait uu(*this);
            list<T>& c = (list<T>&)copy;
            erase();
            int s = c.length();
            for (int i = 0; i < s; i++) *this << c[i];
            return *this;
        }

        //    int size() const { return count(header.parent); }  // unsincroniisd

        list<T>& operator<<(const list<T>& a)
        {
            wait uu(*this);
            for (T _t : a) *this << _t;
            return *this;
        }

        int size() const { return count(header.parent); }

        long long length() const { return count(header.parent); }

        iterator begin() { return header.left; }

        iterator end() { return &header; }

        const_iterator begin() const { return header.left; }

        const_iterator end() const { return &header; }

        long long depth() const { wait uu(*this); return depth(header.parent); }

        iterator insert(const T& daata)
        {
            wait uu(*this);
            iterator Last = last();
            if (Last.is_header())
                return insert(0, daata);
            else
            {
                return insert(Last.key() + 1, daata);
            }
        }

        iterator insert(long long key,
            const T& daata)
        {
            wait uu(*this);

            node* root_node = header.parent;

            if (root_node == 0)
            {
                root_node = new list_node<T>(key, daata, &header);
                header.left = root_node;
                header.right = root_node;
                header.parent = root_node;
                return root_node;
            }

            else
            {
                for (; ; )
                {
                    bool less = compare(key, ((list_node<T>*)root_node)->key);
                    bool greater = compare(((list_node<T>*)root_node)->key, key);

                    if (!less && !greater)
                    {
                        ((list_node<T>*)root_node)->daata = daata;
                        return root_node;
                    }

                    else if (less)
                    {
                        if (root_node->left != 0)
                            root_node = root_node->left;
                        else
                        {
                            node* new_node = new list_node<T>(key, daata, root_node);
                            root_node->left = new_node;
                            adjust_add(new_node);
                            return new_node;
                        }
                    }

                    else
                    {
                        if (root_node->right != 0)
                            root_node = root_node->right;
                        else
                        {
                            node* new_node = new list_node<T>(key, daata, root_node);
                            root_node->right = new_node;
                            adjust_add(new_node);
                            return new_node;
                        }
                    }
                }
            }
        }

        void erase(long long key)
        {
            wait uu(*this);

            node* root_node = header.parent;

            for (; ; )
            {
                if (root_node == 0) throw entry_not_found_exception();

                bool less = compare(key, ((list_node<T>*)root_node)->key);
                bool greater = compare(((list_node<T>*)root_node)->key, key);

                if (less)
                    root_node = root_node->left;

                else if (greater)
                    root_node = root_node->right;

                else // Item is found
                {
                    if (root_node->left != 0 && root_node->right != 0)
                    {
                        node* replaas = root_node->left;
                        while (replaas->right != 0) replaas = replaas->right;
                        swap_nodes(root_node, replaas);
                    }

                    node* parent = root_node->parent;

                    long long from = (parent->left == root_node) ? direction::from_left : direction::from_right;

                    if (root_node->left == 0)
                    {
                        if (parent == &header)
                            header.parent = root_node->right;
                        else if (from == direction::from_left)
                            parent->left = root_node->right;
                        else
                            parent->right = root_node->right;

                        if (root_node->right != 0) root_node->right->parent = parent;
                    }
                    else
                    {
                        if (parent == &header)
                            header.parent = root_node->left;
                        else if (from == direction::from_left)
                            parent->left = root_node->left;
                        else
                            parent->right = root_node->left;

                        if (root_node->left != 0) root_node->left->parent = parent;
                    }

                    adjust_remove(parent, from);
                    delete (list_node<T>*)root_node;
                    break;
                }
            }
        }

        //const T operator[](long long key) { return find(key).value(); }

        class reference
        {
        public:

            reference(list<T>& ArraySet, long long keySet)
                : Array(&ArraySet), key(keySet) {}

            reference& operator=(const T& value)
            {
                Array->insert(key, value);
                return *this;
            }

            reference& operator=(const reference& Reference)
            {
                Array->insert(key, (T&)Reference);
                return *this;
            }

            operator T& () const
            {
                iterator i = Array->find(key);
                return i.value();
            }

            list<T>* Array;
            long long key;
        };

        reference operator[](long long key) { return reference(*this, key); }

        list<T>& operator>>(long long key) { erase(key); return *this; }

        iterator find(long long key)
        {
            wait uu(*this);

            if (!header.parent)
                throw entry_not_found_exception();
            else
            {
                const node* serch_node = header.parent;

                do
                {
                    bool less = compare(key, ((list_node<T>*)serch_node)->key);
                    bool greater = compare(((list_node<T>*)serch_node)->key, key);

                    if (less) serch_node = serch_node->left;

                    else if (greater) serch_node = serch_node->right;

                    else break;

                } while (serch_node);

                if (serch_node == 0) throw entry_not_found_exception();

                return (node*)serch_node;
            }
        }

        list<T>& operator<<(const T& t)
        {
            push(t);
            return *this;
        }

        void push_back(const T& t)
        {
            push(t);
        }

        list<T>& operator>>(T& t)
        {
            t = pop();
            return *this;
        }

        void push(const T& daata)
        {
            wait uu(*this);

            if (!header.parent)
                (*this)[0] = daata;
            else
            {
                list_iterator<T> ai(header.right);
                (*this)[ai.key() + 1] = daata;
            }
        }

        T pop()
        {
            wait uu(*this);

            if (!header.parent)
                throw entry_not_found_exception();
            else
            {
                list_iterator<T> ai(header.right);
                T r = ai.value();
                erase(ai.key());
                return r;
            }
        }

        bool exists(long long key) const
        {
            wait uu(*this);

            if (!header.parent)
                return false;
            else
            {
                const node* serch_node = header.parent;

                do
                {
                    int result = compare(key, ((list_node<T>*)serch_node)->key);

                    if (result < 0) serch_node = serch_node->left;

                    else if (result > 0) serch_node = serch_node->right;

                    else break;

                } while (serch_node);

                if (serch_node == 0) return false;

                return true;
            }
        }

        void erase()
        {
            wait uu(*this);
            destroy((list_node<T>*)header.parent);
            header.left = &header;
            header.right = &header;
            header.parent = 0;
        }

        iterator after(long long key) const
        {
            wait uu(*this);

            const node* y = &header;
            const node* x = header.parent;

            while (x != 0)
                if (compare(key, ((list_node<T>*)x)->key) < 0)
                {
                    y = x; x = x->left;
                }
                else
                    x = x->right;

            return (node*)y;
        }

        iterator after_equals(long long key) const
        {
            wait uu(*this);

            const node* y = &header;
            const node* x = header.parent;

            while (x != 0)
            {
                int c = compare(key, ((list_node<T>*)x)->key);
                if (c == 0)
                {
                    y = x; break;
                }
                else if (c < 0)
                {
                    y = x; x = x->left;
                }
                else
                    x = x->right;
            }

            return (node*)y;
        }

        iterator before(long long key) const
        {
            wait uu(*this);

            const node* y = &header;
            const node* x = header.parent;

            while (x != 0)
                if (compare(key, ((list_node<T>*)x)->key) <= 0)
                {
                    x = x->left;
                }
                else
                {
                    y = x; x = x->right;
                }

            return (node*)y;
        }

        iterator before_equals(long long key) const
        {
            wait uu(*this);

            const node* y = &header;
            const node* x = header.parent;

            while (x != 0)
            {
                int c = compare(key, ((list_node<T>*)x)->key);
                if (c == 0)
                {
                    y = x; break;
                }
                else if (c < 0)
                    x = x->left;
                else
                {
                    y = x; x = x->right;
                }
            }

            return (node*)y;
        }

        iterator last() { return header.right; }

        const_iterator last() const { return header.right; }

        bool contiguous() const
        {
            long long l = length();
            if (l == 0)
                return true;

            const_iterator i = last();
            long long k = i.key();
            return l == k + 1;
        }

        void copy(list_node<T>* Clone)
        {
            if (!header.parent) erase();
            if (Clone)
            {
                copy((list_node<T>*&)header.parent, Clone, &header);
                header.left = get_first();
                header.right = get_last();
            }
        }

        void copy(list_node<T>*& root_node,
            list_node<T>* n,
            node* parent)  // assumes root_node non-null
        {
            root_node = new list_node<T>(n->key, n->daata, parent);
            root_node->balans = n->balans;

            if (n->left)
                copy((list_node<T>*&)root_node->left, (list_node<T>*)n->left, root_node);
            else root_node->left = 0;

            if (n->right)
                copy((list_node<T>*&)root_node->right, (list_node<T>*)n->right, root_node);
            else root_node->right = 0;
        }

        node* get_first()
        {
            if (!header.parent)
                return &header;

            else
            {
                node* serch_node = header.parent;
                while (serch_node->left) serch_node = serch_node->left;
                return serch_node;
            }
        }

        node* get_last()
        {
            if (!header.parent)
                return &header;

            else
            {
                node* serch_node = header.parent;
                while (serch_node->right) serch_node = serch_node->right;
                return serch_node;
            }
        }

        void destroy(list_node<T>* root_node)
        {
            if (root_node)
            {
                if (root_node->left)
                    destroy((list_node<T>*)root_node->left);

                if (root_node->right)
                    destroy((list_node<T>*)root_node->right);

                delete root_node;
            }
        }

        void sort()
        {
            bag<T> b;
            wait uu(*this);
            for (T _t : *this) b << _t;
            erase();
            for (T _t : b) *this << _t;
        }
    };

    export template<class T>
        std::ostream& operator<<(std::ostream& s, const list<T>& o)
    {
        s << "{";
        const_list_iterator<T> e = o.end();
        const_list_iterator<T> l = e - 1;
        for (const_list_iterator<T> i = o.begin(); i != e; ++i)
        {
            s << *i; if (i != l) s << ",";
        }
        s << "}";
        return s;
    }

    export template<class T>
        std::wostream& operator<<(std::wostream& s, const list<T>& o)
    {
        s << "{";
        const_list_iterator<T> e = o.end();
        const_list_iterator<T> l = e - 1;
        for (const_list_iterator<T> i = o.begin(); i != e; ++i)
        {
            s << *i; if (i != l) s << ",";
        }
        s << "}";
        return s;
    }

    export template<class T>
        oarchive& operator<<(oarchive& s, const list<T>& o)
    {
        s << o.length();
        const_list_iterator<T> e = o.end();
        const_list_iterator<T> l = e - 1;
        for (const_list_iterator<T> i = o.begin(); i != e; ++i)
        {
            s << *i;
        }
        return s;
    }

    export template<class T>
        iarchive& operator>>(iarchive& s, list<T>& o)
    {
        long long length;
        s >> length;
        for (long long i = 0; i < length; i++)
        {
            T t;
            s >> t;
            o << t;
        }
        return s;
    }

    export template<class k, class t>
        struct dictionary_node : public node
    {
        k key;
        t data;

        dictionary_node(const k& keySet,
            const t& dataSet,
            node* parent) : node(parent), key(keySet), data(dataSet) {}

        operator const k& () const { return key; }

        operator t& () { return data; }
    };

    export template <class k, class t>
        struct dictionary_iterator
    {
        node* _node;

        dictionary_iterator() : _node(0) {}

        dictionary_iterator(node* in) : _node(in) {}

        dictionary_iterator(const dictionary_iterator<k, t>& i) : _node(i._node) {}

        const k& key() const
        {
            return ((dictionary_node<k, t>*)_node)->key;
        }

        t& value()
        {
            return ((dictionary_node<k, t>*)_node)->data;
        }

        key_value<k, t> operator*() const
        {
            return key_value<k, t>(((dictionary_node<k, t>*)_node)->key, ((dictionary_node<k, t>*)_node)->data);
        }

        t* operator->() const
        {
            return &(((dictionary_node<k, t>*)_node)->data);
        }

        t* operator&() const
        {
            return &(((dictionary_node<k, t>*)_node)->data);
        }

        dictionary_iterator<k, t>& operator++()
        {
            _node = next_item(_node); return *this;
        }

        dictionary_iterator<k, t> operator++(int)
        {
            dictionary_iterator<k, t> save = *this; ++* this;return save;
        }

        dictionary_iterator<k, t>& operator+=(long long increment)
        {
            for (long long i = 0; i < increment; i++)++* this; return *this;
        }

        dictionary_iterator<k, t> operator+(long long increment) const
        {
            dictionary_iterator<k, t> result(*this);
            for (long long i = 0; i < increment; i++) ++result;
            return result;
        }

        dictionary_iterator<k, t>& operator--()
        {
            _node = previous_item(_node); return *this;
        }

        dictionary_iterator<k, t> operator--(int)
        {
            dictionary_iterator<k, t> save = *this; --* this;return save;
        }

        dictionary_iterator<k, t>& operator-=(long long decrement)
        {
            for (long long i = 0; i < decrement; i++)--* this; return *this;
        }

        dictionary_iterator<k, t> operator-(long long decrement) const
        {
            dictionary_iterator<k, t> result(*this);
            for (long long i = 0; i < decrement; i++) --result;
            return result;
        }

        bool operator==(const dictionary_iterator<k, t>& y) const { return _node == y._node; }

        bool operator!=(const dictionary_iterator<k, t>& y) const { return _node != y._node; }

        const t& operator[](long long i) const { return i >= 0 ? *(*this + i) : *(*this - -i); }

        long long operator-(dictionary_iterator<k, t> iter) const
        {
            long long result = 0;
            while (iter++ != *this) { result++; }
            return result;
        }

        bool is_header() const { return _node->is_header(); }
    };

    export template<class k, class t>
        struct const_dictionary_iterator
    {
        const node* _node;

        const_dictionary_iterator() : _node(0) {}

        const_dictionary_iterator(const node* in) : _node(in) {}

        const_dictionary_iterator(const dictionary_iterator<k, t>& i) : _node(i._node) {}

        const_dictionary_iterator(const const_dictionary_iterator<k, t>& i) : _node(i._node) {}

        const k& key() const
        {
            return ((dictionary_node<k, t>*)_node)->key;
        }

        const t& value()
        {
            return ((dictionary_node<k, t>*)_node)->data;
        }

        const key_value<k, t> operator*() const
        {
            return key_value<k, t>(((dictionary_node<k, t>*)_node)->key, ((dictionary_node<k, t>*)_node)->data);
        }

        const t* operator->() const
        {
            return &(((dictionary_node<k, t>*)_node)->data);
        }

        const t* operator&() const
        {
            return &(((dictionary_node<k, t>*)_node)->data);
        }

        const_dictionary_iterator<k, t>& operator++()
        {
            _node = next_item((node*)_node); return *this;
        }

        const_dictionary_iterator<k, t> operator++(int)
        {
            const_dictionary_iterator<k, t> save = *this; ++* this;return save;
        }

        const_dictionary_iterator<k, t>& operator+=(long long increment)
        {
            for (long long i = 0; i < increment; i++)++* this; return *this;
        }

        const_dictionary_iterator<k, t> operator+(long long increment) const
        {
            const_dictionary_iterator<k, t> result(*this);
            for (long long i = 0; i < increment; i++) ++result;
            return result;
        }

        const_dictionary_iterator<k, t>& operator--()
        {
            _node = previous_item((node*)_node); return *this;
        }

        const_dictionary_iterator<k, t> operator--(int)
        {
            dictionary_iterator<k, t> save = *this; --* this;return save;
        }

        const_dictionary_iterator<k, t>& operator-=(long long decrement)
        {
            for (long long i = 0; i < decrement; i++)--* this; return *this;
        }

        const_dictionary_iterator<k, t> operator-(long long decrement) const
        {
            const_dictionary_iterator<k, t> result(*this);
            for (long long i = 0; i < decrement; i++) --result;
            return result;
        }

        bool operator==(const const_dictionary_iterator<k, t>& y) const { return _node == y._node; }

        bool operator!=(const const_dictionary_iterator<k, t>& y) const { return _node != y._node; }

        const t& operator[](long long i) const { return i >= 0 ? *(*this + i) : *(*this - -i); }

        long long operator-(const_dictionary_iterator<k, t> iter) const
        {
            long long result = 0;
            while (iter++ != *this) { result++; }
            return result;
        }

        bool is_header() const { return _node->is_header(); }
    };

    export template <class k, class t>
        struct dictionary : semaphore
    {
        typedef bool (*key_compare)(const k&, const k&);

        node header;
        key_compare key_comp;

        // *** iterators ***

        typedef dictionary_iterator<k, t> iterator;

        typedef const_dictionary_iterator<k, t> const_iterator;

        dictionary(key_compare C = compare) : key_comp(C) {}

        dictionary(const dictionary<k, t>& copy) : key_comp(copy.key_comp)
        {
            for (key_value<k, t> cv : copy) (*this)[cv.key] = cv.value;
        }

        ~dictionary()
        {
            wait w(*this);
            destroy((dictionary_node<k, t>*)header.parent);
        }

        dictionary<k, t>& operator=(const dictionary<k, t>& copy)
        {
            wait wA(*this);
            // wait wB(copy);
            erase();
            key_comp = copy.key_comp;
            for (key_value<k, t> cv : copy) (*this)[cv.key] = cv.value;
            return *this;
        }

        dictionary<k, t>& operator<<(key_value<k, t> kv)
        {
            insert(kv.key, kv.value);
            return *this;
        }

        long long length() const { return count(header.parent); }

        operator key_compare() const { return key_comp; }

        iterator begin() { return header.left; }

        iterator end() { return &header; }

        const_iterator begin() const { return header.left; }

        const_iterator end() const { return &header; }

        iterator insert(const k& key,
            const t& data)
        {
            wait w(*this);

            node* root_node = header.parent;

            if (root_node == 0)
            {
                root_node = new dictionary_node<k, t>(key, data, &header);
                header.left = root_node;
                header.right = root_node;
                header.parent = root_node;
                return root_node;
            }

            else
            {
                for (; ; )
                {
                    bool less = key_comp(key, ((dictionary_node<k, t>*)root_node)->key);
                    bool greater = key_comp(((dictionary_node<k, t>*)root_node)->key, key);

                    if (!less && !greater)
                    {
                        ((dictionary_node<k, t>*)root_node)->data = data;
                        return root_node;
                    }

                    else if (less)
                    {
                        if (root_node->left != 0)
                            root_node = root_node->left;
                        else
                        {
                            node* new_node = new dictionary_node<k, t>(key, data, root_node);
                            root_node->left = new_node;
                            adjust_add(new_node);
                            return new_node;
                        }
                    }

                    else
                    {
                        if (root_node->right != 0)
                            root_node = root_node->right;
                        else
                        {
                            node* new_node = new dictionary_node<k, t>(key, data, root_node);
                            root_node->right = new_node;
                            adjust_add(new_node);
                            return new_node;
                        }
                    }
                }
            }
        }

        void erase(const k& key)
        {
            wait w(*this);

            node* root_node = header.parent;

            for (; ; )
            {
                if (root_node == 0) throw entry_not_found_exception();

                bool less = key_comp(key, ((dictionary_node<k, t>*)root_node)->key);
                bool greater = key_comp(((dictionary_node<k, t>*)root_node)->key, key);

                if (less)
                    root_node = root_node->left;

                else if (greater)
                    root_node = root_node->right;

                else // Item is found
                {
                    if (root_node->left != 0 && root_node->right != 0)
                    {
                        node* replace = root_node->left;
                        while (replace->right != 0) replace = replace->right;
                        swap_nodes(root_node, replace);
                    }

                    node* parent = root_node->parent;

                    long long from = (parent->left == root_node) ? direction::from_left : direction::from_right;

                    if (root_node->left == 0)
                    {
                        if (parent == &header)
                            header.parent = root_node->right;
                        else if (from == direction::from_left)
                            parent->left = root_node->right;
                        else
                            parent->right = root_node->right;

                        if (root_node->right != 0) root_node->right->parent = parent;
                    }
                    else
                    {
                        if (parent == &header)
                            header.parent = root_node->left;
                        else if (from == direction::from_left)
                            parent->left = root_node->left;
                        else
                            parent->right = root_node->left;

                        if (root_node->left != 0) root_node->left->parent = parent;
                    }

                    adjust_remove(parent, from);
                    delete (dictionary_node<k, t>*)root_node;
                    break;
                }
            }
        }

        const t& operator[](const k& key) const { return find(key).value(); }

        struct reference
        {
            reference(dictionary<k, t>& map_set, const k& key_set)
                : nnap(&map_set), key(&key_set) {}

            reference& operator=(const t& value)
            {
                nnap->insert(*key, value);
                return *this;
            }

            reference& operator=(const reference& ref)
            {
                nnap->insert(*key, (t&)ref);
                return *this;
            }

            operator t& () const
            {
                iterator i = nnap->find(*key);
                return i.value();
            }

            dictionary<k, t>* nnap;
            const k* key;
        };

        reference operator[](const k& key) { return reference(*this, key); }

        dictionary<k, t>& operator>>(const k& key) { erase(key); return *this; }

        iterator find(const k& key)
        {
            wait w(*this);

            if (!header.parent)
                throw entry_not_found_exception();
            else
            {
                const node* search_node = header.parent;

                do
                {
                    bool less = key_comp(key, ((dictionary_node<k, t>*)search_node)->key);
                    bool greater = key_comp(((dictionary_node<k, t>*)search_node)->key, key);

                    if (less) search_node = search_node->left;

                    else if (greater) search_node = search_node->right;

                    else break;

                } while (search_node);

                if (search_node == 0) throw entry_not_found_exception();

                return (node*)search_node;
            }
        }

        bool contains(const k& key)
        {
            try
            {
                iterator i = find(key);
                return true;
            }
            catch (...) { return false; }
        }

        void erase()
        {
            wait w(*this);
            destroy((dictionary_node<k, t>*)header.parent);
            header.left = &header;
            header.right = &header;
            header.parent = 0;
        }

        iterator after(const k& key) const
        {
            wait w(*this);

            const node* y = &header;
            const node* x = header.parent;

            while (x != 0)
                if (key_comp(key, ((dictionary_node<k, t>*)x)->key))
                {
                    y = x; x = x->left;
                }
                else
                    x = x->right;

            return (node*)y;
        }

        iterator after_equals(const k& key) const
        {
            wait w(*this);

            const node* y = &header;
            const node* x = header.parent;

            while (x != 0)
            {
                bool less = key_comp(key, ((dictionary_node<k, t>*)x)->key);
                bool greater = key_comp(((dictionary_node<k, t>*)x)->key, key);
                if (!less && !greater)
                {
                    y = x; break;
                }
                else if (less)
                {
                    y = x; x = x->left;
                }
                else
                    x = x->right;
            }

            return (node*)y;
        }

        iterator before(const k& key) const
        {
            wait w(*this);

            const node* y = &header;
            const node* x = header.parent;

            while (x != 0)
                if (!key_comp(((dictionary_node<k, t>*)x)->key, key))
                {
                    x = x->left;
                }
                else
                {
                    y = x; x = x->right;
                }

            return (node*)y;
        }

        iterator before_equals(const k& key) const
        {
            wait w(*this);

            const node* y = &header;
            const node* x = header.parent;

            while (x != 0)
            {
                bool less = key_comp(key, ((dictionary_node<k, t>*)x)->key);
                bool greater = key_comp(((dictionary_node<k, t>*)x)->key, key);
                if (!less && !greater)
                {
                    y = x; break;
                }
                else if (less)
                    x = x->left;
                else
                {
                    y = x; x = x->right;
                }
            }

            return (node*)y;
        }

        iterator last() { return header.right; }

        const_iterator last() const { return header.right; }

        long long depth() const { wait w(*this); return depth(header.parent); }

        node* get_first()
        {
            if (!header.parent)
                return &header;

            else
            {
                node* search_node = header.parent;
                while (search_node->left) search_node = search_node->left;
                return search_node;
            }
        }

        node* get_last()
        {
            if (!header.parent)
                return &header;

            else
            {
                node* search_node = header.parent;
                while (search_node->right) search_node = search_node->right;
                return search_node;
            }
        }

        void destroy(dictionary_node<k, t>* root_node)
        {
            if (root_node)
            {
                if (root_node->left)
                    destroy((dictionary_node<k, t>*)root_node->left);

                if (root_node->right)
                    destroy((dictionary_node<k, t>*)root_node->right);

                delete root_node;
            }
        }
    };

    export template<class K, class T>
        inline oarchive& operator<<(oarchive& s, const dictionary<K, T>& o)
    {
        s << o.length();
        const_dictionary_iterator<K,T> e = o.end();
        const_dictionary_iterator<K, T> l = e - 1;
        for (const_dictionary_iterator<K, T> i = o.begin(); i != e; ++i)
        {
            s << *i;
        }
        return s;
    }

    export template<class K, class T>
        inline iarchive& operator>>(iarchive& s, dictionary<K, T>& o)
    {
        long long length;
        s >> length;
        for (long long i = 0; i < length; i++)
        {
            key_value<K,T> t;
            s >> t;
            o << t;
        }
        return s;
    }

    export template<class K, class T>
        inline std::ostream& operator<<(std::ostream& s, const dictionary<K, T>& o)
    {
        s << "{";
        const_dictionary_iterator<K, T> e = o.end();
        const_dictionary_iterator<K, T> l = e - 1;
        for (const_dictionary_iterator<K, T> i = o.begin(); i != e; ++i)
        {
            s << "(" << i.key() << "," << i.value() << ")"; if (i != l) s << ",";
        }
        s << "}";
        return s;
    }

    export template<class K, class T>
        inline std::wostream& operator<<(std::wostream& s, const dictionary<K, T>& o)
    {
        s << "{";
        const_dictionary_iterator<K, T> e = o.end();
        const_dictionary_iterator<K, T> l = e - 1;
        for (const_dictionary_iterator<K, T> i = o.begin(); i != e; ++i)
        {
            s << "(" << i.key() << "," << i.value() << ")"; if (i != l) s << ",";
        }
        s << "}";
        return s;
    }

    export template<class k, class t>
        int compare_key(const k& s, const t& r)
    {
        if (s < r) return -1;
        if (r < s) return 1;
        return 0;
    }

    export template <class K, class T>
        struct tree
    {
        set<T> s;

        typedef int (*key_value_compare)(const K&, const T&);

        set_iterator<T> begin() { return s.header.left; }

        set_iterator<T> end() { return &s.header; }

        const_set_iterator<T> begin() const { return s.header.left; }

        const_set_iterator<T> end() const { return &s.header; }

        key_value_compare key_to_value;

        tree(key_value_compare key, bool (*key_comparer)(const T&, const T&) = compare)
            : s(key_comparer), key_to_value(key) {}

        tree(const tree<K, T>& copee) : s(copee.s), key_to_value(copee.key_to_value) {}

        tree<K, T>& operator=(const tree<K, T>& copee)
        {
            key_to_value = copee.key_to_value;
            s.erase();
            s.less = copee.s.less;
            for (T _t : copee.s) s << _t;
            return *this;
        }

        operator key_value_compare() const { return key_to_value; }

        T find(const K& key) const
        {
            set_iterator<T> i = find_key(key);
            return *i;
        }

        T& operator[](const K& key) const
        {
            set_iterator<T> i = find_key(key);
            return *i;
        }

        tree<K, T>& operator<<(const set<T>& i)
        {
            for (T _t : i) *this << _t;
            return *this;
        }

        void erase(const K& key)
        {
            wait w(s);

            node* root_node = s.header.parent;

            for (; ; )
            {
                if (root_node == 0) throw entry_not_found_exception();

                int result = key_to_value(key, ((set_node<T>*)root_node)->element);

                if (result < 0)
                    root_node = root_node->left;

                else if (result > 0)
                    root_node = root_node->right;

                else // Item is found
                {
                    if (root_node->left != 0 && root_node->right != 0)
                    {
                        node* replace = root_node->left;
                        while (replace->right != 0) replace = replace->right;
                        swap_nodes(root_node, replace);
                    }

                    node* parent = root_node->parent;

                    long long from = (parent->left == root_node) ? direction::from_left : direction::from_right;

                    if (root_node->left == 0)
                    {
                        if (parent == &s.header)
                            s.header.parent = root_node->right;
                        else if (from == direction::from_left)
                            parent->left = root_node->right;
                        else
                            parent->right = root_node->right;

                        if (root_node->right != 0) root_node->right->parent = parent;
                    }
                    else
                    {
                        if (parent == &s.header)
                            s.header.parent = root_node->left;
                        else if (from == direction::from_left)
                            parent->left = root_node->left;
                        else
                            parent->right = root_node->left;

                        if (root_node->left != 0) root_node->left->parent = parent;
                    }

                    adjust_remove(parent, from);
                    delete (set_node<T>*)root_node;
                    break;
                }
            }
        }

        bool exists(const K& key)
        {
            wait w(s);

            if (!s.header.parent)
                return false;
            else
            {
                const node* search_node = s.header.parent;

                do
                {
                    int result = key_to_value(key, ((set_node<T>*)search_node)->element);

                    if (result < 0) search_node = search_node->left;

                    else if (result > 0) search_node = search_node->right;

                    else break;

                } while (search_node);

                if (search_node == 0) return false; else return true;
            }
        }

        bool exists(const T& t) const { return s.exists(t); }

        set_iterator<T> find_key(const K& key) const
        {
            set<T>& se = (set<T>&)s;
            wait w(se);

            if (!s.header.parent)
                throw entry_not_found_exception();
            else
            {
                const node* search_node = s.header.parent;

                do
                {
                    int result = key_to_value(key, ((set_node<T>*)search_node)->element);

                    if (result < 0) search_node = search_node->left;

                    else if (result > 0) search_node = search_node->right;

                    else break;

                } while (search_node);

                if (search_node == 0) throw entry_not_found_exception();

                return (node*)search_node;
            }
        }

        tree<K, T>& operator<<(const T& element) { s.insert(element); return *this; }

        tree<K, T>& operator>>(const T& element) { s.erase(element); return *this; }

        void create(const T& element)
        {
            wait w(s);

            try
            {
                s.insert(element);
            }
            catch (entry_already_exists_exception)
            {
                s >> element;
                s.insert(element);
            }
        }

        bool operator<(const tree<K, T>& tree) { return s < tree.s; }

        bool operator==(const tree<K, T>& tree) { return s == tree.s; return *this; }
    };

    export template<class K, class T>
    std::ostream& operator<<(std::ostream& s, const tree<K, T>& o)
    {
        set<T>& se = (set<T>&)o.s;
        s << o.s;
        return s;
    }

    export template<class K, class T>
    std::wostream& operator<<(std::wostream& s, const tree<K, T>& o)
    {
        set<T>& se = (set<T>&)o.s;
        s << o.s;
        return s;
    }

    
    export template<class K, class T>
        oarchive& operator<<(oarchive& s, const tree<K, T>& o)
    {
        s << o.s.length();
        const_set_iterator<T> e = o.end();
        const_set_iterator<T> l = e - 1;
        for (const_set_iterator<T> i = o.begin(); i != e; ++i)
        {
            s << *i;
        }
        return s;
    }

    export template<class K, class T>
        iarchive& operator>>(iarchive& s, tree<K,T>& o)
    {
        long long length;
        s >> length;
        for (long long i = 0; i < length; i++)
        {
            T t;
            s >> t;
            o << t;
        }
        return s;
    }


    // *** Binary Heaps ***

    typedef unsigned char uchar;
    typedef unsigned short ushort;

    static unsigned boundaries[] = { 0,8,16,24,32,40,56,88,120,160,184,216,256,304,352,400,472,600,728,984,1496,2008,2520,3032,3544,4056,4568,5080,5592,6104,6616,7128,7640,8152 };
    
    enum { number_of_pools = sizeof(boundaries) / sizeof(unsigned), leading = 24 };
    enum { block_size = 65536 };

    inline unsigned long long quantum_from_size(unsigned long long size)
    {
        unsigned long long i = 0;
        while (size > boundaries[i] + leading && i < number_of_pools) i++;
        return i;
    }

    inline unsigned long long quantum_size(unsigned long long size) { return boundaries[size]; }

    inline unsigned long long round_up(unsigned long long value,
        unsigned long long Base)
    {
        if (value < Base)
            return Base;
        else if (value % Base)
            return value + (Base - (value % Base));
        else
            return value;
    }

    export struct pointer_status
    {
        enum
        {
            not_in_heap,
            not_aligned,
            identity_invalid,
            free,
            allocated
        };
    };

    enum
    {
        small_unit_overhead = 8,
        large_unit_overhead = 48,
        block_overhead = 40
    };

    struct pool_node
    {
        uchar identity;
        char is_block;
        char balance;
        ushort units;
        pool_node* left;
        pool_node* right;
        pool_node* parent;

        bool is_header() { return balance == (char)state::header; }
    };

    inline void rotate_left(pool_node*& root)
    {
        pool_node* parent = root->parent;
        pool_node* x = root->right;

        root->parent = x;
        x->parent = parent;
        if (x->left) x->left->parent = root;

        root->right = x->left;
        x->left = root;
        root = x;
    }

    inline void rotate_right(pool_node*& root)
    {
        pool_node* parent = root->parent;
        pool_node* x = root->left;

        root->parent = x;
        x->parent = parent;
        if (x->right) x->right->parent = root;

        root->left = x->right;
        x->right = root;
        root = x;
    }

    inline void balance_left(pool_node*& root)
    {
        pool_node* left = root->left; // left Subtree of root pool_node

        switch (left->balance)
        {
        case state::left_high:
            root->balance = state::balanced;
            left->balance = state::balanced;
            rotate_right(root);
            break;

        case state::right_high:
        {
            pool_node* subright = left->right;  // right subtree of left
            switch (subright->balance)
            {
            case state::balanced:
                root->balance = state::balanced;
                left->balance = state::balanced;
                break;

            case state::right_high:
                root->balance = state::balanced;
                left->balance = state::left_high;
                break;

            case state::left_high:
                root->balance = state::right_high;
                left->balance = state::balanced;
                break;
            }
            subright->balance = state::balanced;
            rotate_left(left);
            root->left = left;
            rotate_right(root);
        }
        break;

        case state::balanced:
            root->balance = state::left_high;
            left->balance = state::right_high;
            rotate_right(root);
            break;
        }
    }
    
    inline void balance_right(pool_node*& root)
    {
        pool_node* right = root->right; // right Subtree of root pool_node

        switch (right->balance)
        {
        case state::right_high:
            root->balance = state::balanced;
            right->balance = state::balanced;
            rotate_left(root);
            break;

        case state::left_high:
        {
            pool_node* subleft = right->left; // left Subtree of right
            switch (subleft->balance)
            {
            case state::balanced:
                root->balance = state::balanced;
                right->balance = state::balanced;
                break;

            case state::left_high:
                root->balance = state::balanced;
                right->balance = state::right_high;
                break;

            case state::right_high:
                root->balance = state::left_high;
                right->balance = state::balanced;
                break;
            }
            subleft->balance = state::balanced;
            rotate_right(right);
            root->right = right;
            rotate_left(root);
        }
        break;

        case state::balanced:
            root->balance = state::right_high;
            right->balance = state::left_high;
            rotate_left(root);
            break;
        }
    }

    inline void balance_tree(pool_node* root, unsigned long long from)
    {
        bool taller = true;

        while (taller)
        {
            pool_node* parent = root->parent;
            unsigned long long Nextfrom = (parent->left == root) ? direction::from_left : direction::from_right;

            if (from == direction::from_left)
            {
                switch (root->balance)
                {
                case state::left_high:
                    if (parent->is_header())
                        balance_left(parent->parent);
                    else if (parent->left == root)
                        balance_left(parent->left);
                    else
                        balance_left(parent->right);
                    taller = false;
                    break;

                case state::balanced:
                    root->balance = state::left_high;
                    taller = true;
                    break;

                case state::right_high:
                    root->balance = state::balanced;
                    taller = false;
                    break;
                }
            }
            else
            {
                switch (root->balance)
                {
                case state::left_high:
                    root->balance = state::balanced;
                    taller = false;
                    break;

                case state::balanced:
                    root->balance = state::right_high;
                    taller = true;
                    break;

                case state::right_high:
                    if (parent->is_header())
                        balance_right(parent->parent);
                    else if (parent->left == root)
                        balance_right(parent->left);
                    else
                        balance_right(parent->right);
                    taller = false;
                    break;
                }
            }

            if (taller) // skip up a level
            {
                if (parent->is_header())
                    taller = false;
                else
                {
                    root = parent;
                    from = Nextfrom;
                }
            }
        }
    }

    inline void balance_tree_remove(pool_node* root, unsigned long long from)
    {
        if (root->is_header()) return;

        bool shorter = true;

        while (shorter)
        {
            pool_node* parent = root->parent;
            unsigned long long Nextfrom = (parent->left == root) ? direction::from_left : direction::from_right;

            if (from == direction::from_left)
            {
                switch (root->balance)
                {
                case state::left_high:
                    root->balance = state::balanced;
                    shorter = true;
                    break;

                case state::balanced:
                    root->balance = state::right_high;
                    shorter = false;
                    break;

                case state::right_high:
                    if (root->right->balance == state::balanced)
                        shorter = false;
                    else
                        shorter = true;
                    if (parent->is_header())
                        balance_right(parent->parent);
                    else if (parent->left == root)
                        balance_right(parent->left);
                    else
                        balance_right(parent->right);
                    break;
                }
            }
            else
            {
                switch (root->balance)
                {
                case state::right_high:
                    root->balance = state::balanced;
                    shorter = true;
                    break;

                case state::balanced:
                    root->balance = state::left_high;
                    shorter = false;
                    break;

                case state::left_high:
                    if (root->left->balance == state::balanced)
                        shorter = false;
                    else
                        shorter = true;
                    if (parent->is_header())
                        balance_left(parent->parent);
                    else if (parent->left == root)
                        balance_left(parent->left);
                    else
                        balance_left(parent->right);
                    break;
                }
            }

            if (shorter)
            {
                if (parent->is_header())
                    shorter = false;
                else
                {
                    from = Nextfrom;
                    root = parent;
                }
            }
        }
    }

    inline void swap_pool_node_reference(pool_node*& first, pool_node*& second)
    {
        pool_node* temporary = first; first = second; second = temporary;
    }

    inline void left_pool_node_swap(pool_node* root, pool_node* replace)
    {
        if (replace->left) replace->left->parent = root;
        if (replace->right) replace->right->parent = root;

        if (root->right) root->right->parent = replace;

        if (replace == root->left)
        {
            replace->parent = root->parent;
            root->parent = replace;

            root->left = replace->left;
            replace->left = root;
        }
        else
        {
            root->left->parent = replace;

            if (replace->parent->left == replace)
                replace->parent->left = root;
            else
                replace->parent->right = root;

            swap_pool_node_reference(root->left, replace->left);
            swap_pool_node_reference(root->parent, replace->parent);
        }

        swap_pool_node_reference(root->right, replace->right);

        char balance = root->balance; root->balance = replace->balance; replace->balance = balance;
    }

    inline void swap_pool_nodes(pool_node* A, pool_node* B)
    {
        if (B == A->left)
        {
            if (B->left) B->left->parent = A;
            if (B->right) B->right->parent = A;

            if (A->right) A->right->parent = B;

            if (!A->parent->is_header())
            {
                if (A->parent->left == A)
                    A->parent->left = B;
                else
                    A->parent->right = B;
            }
            else A->parent->parent = B;

            B->parent = A->parent;
            A->parent = B;

            A->left = B->left;
            B->left = A;

            swap_pool_node_reference(A->right, B->right);
        }
        else if (B == A->right)
        {
            if (B->right) B->right->parent = A;
            if (B->left) B->left->parent = A;

            if (A->left) A->left->parent = B;

            if (!A->parent->is_header())
            {
                if (A->parent->left == A)
                    A->parent->left = B;
                else
                    A->parent->right = B;
            }
            else A->parent->parent = B;

            B->parent = A->parent;
            A->parent = B;

            A->right = B->right;
            B->right = A;

            swap_pool_node_reference(A->left, B->left);
        }
        else if (A == B->left)
        {
            if (A->left) A->left->parent = B;
            if (A->right) A->right->parent = B;

            if (B->right) B->right->parent = A;

            if (!B->parent->is_header())
            {
                if (B->parent->left == B)
                    B->parent->left = A;
                else
                    B->parent->right = A;
            }
            else B->parent->parent = A;

            A->parent = B->parent;
            B->parent = A;

            B->left = A->left;
            A->left = B;

            swap_pool_node_reference(A->right, B->right);
        }
        else if (A == B->right)
        {
            if (A->right) A->right->parent = B;
            if (A->left) A->left->parent = B;

            if (B->left) B->left->parent = A;

            if (!B->parent->is_header())
            {
                if (B->parent->left == B)
                    B->parent->left = A;
                else
                    B->parent->right = A;
            }
            else B->parent->parent = A;

            A->parent = B->parent;
            B->parent = A;

            B->right = A->right;
            A->right = B;

            swap_pool_node_reference(A->left, B->left);
        }
        else
        {
            if (A->parent == B->parent)
                swap_pool_node_reference(A->parent->left, A->parent->right);
            else
            {
                if (!A->parent->is_header())
                {
                    if (A->parent->left == A)
                        A->parent->left = B;
                    else
                        A->parent->right = B;
                }
                else A->parent->parent = B;

                if (!B->parent->is_header())
                {
                    if (B->parent->left == B)
                        B->parent->left = A;
                    else
                        B->parent->right = A;
                }
                else B->parent->parent = A;
            }

            if (B->left)  B->left->parent = A;
            if (B->right) B->right->parent = A;

            if (A->left)  A->left->parent = B;
            if (A->right) A->right->parent = B;

            swap_pool_node_reference(A->left, B->left);
            swap_pool_node_reference(A->right, B->right);
            swap_pool_node_reference(A->parent, B->parent);
        }

        char balance = A->balance; A->balance = B->balance; B->balance = balance;
    }

    inline pool_node* fast_reverse(pool_node* pn)
    {
        if (pn->is_header()) { return pn->right; }

        else if (pn->left != 0)
        {
            pool_node* y = pn->left;
            while (y->right != 0) y = y->right;
            pn = y;
        }
        else
        {
            pool_node* y = pn->parent;
            if (y->is_header()) return y;
            while (pn == y->left) { pn = y; y = y->parent; }
            pn = y;
        }
        return pn;
    }

    inline pool_node* fast_forward(pool_node* pn)
    {
        if (pn->is_header()) return pn->left;

        if (pn->right != 0)
        {
            pn = pn->right;
            while (pn->left != 0) pn = pn->left;
        }
        else
        {
            pool_node* y = pn->parent;
            if (y->is_header()) return y;
            while (pn == y->right) { pn = y; y = y->parent; }
            pn = y;
        }
        return pn;
    }

    inline int pool_comparer(pool_node* pn1, pool_node* pn2)
    {
        if (pn1 < pn2)
            return -1;
        else if (pn1 > pn2)
            return 1;
        else
            return 0;
    }

    struct heap_node
    {
        char balance;
        uchar identity;
        heap_node* left;
        heap_node* right;
        heap_node* parent;
        unsigned long long size;

        bool is_header() { return balance == (char)state::header; }
    };

    inline int heap_comparer(heap_node* hn1, heap_node* hn2)
    {
        if (hn1 < hn2)
            return -1;
        else if (hn1 > hn2)
            return 1;
        else
            return 0;
    }
    inline void rotate_left(heap_node*& root)
    {
        heap_node* parent = root->parent;
        heap_node* x = root->right;

        root->parent = x;
        x->parent = parent;
        if (x->left) x->left->parent = root;

        root->right = x->left;
        x->left = root;
        root = x;
    }

    inline void rotate_right(heap_node*& root)
    {
        heap_node* parent = root->parent;
        heap_node* x = root->left;

        root->parent = x;
        x->parent = parent;
        if (x->right) x->right->parent = root;

        root->left = x->right;
        x->right = root;
        root = x;
    }

    inline void balance_left(heap_node*& root)
    {
        heap_node* left = root->left; // left Subtree of root heap_node

        switch (left->balance)
        {
        case state::left_high:
            root->balance = state::balanced;
            left->balance = state::balanced;
            rotate_right(root);
            break;

        case state::right_high:
        {
            heap_node* subright = left->right;  // right subtree of left
            switch (subright->balance)
            {
            case state::balanced:
                root->balance = state::balanced;
                left->balance = state::balanced;
                break;

            case state::right_high:
                root->balance = state::balanced;
                left->balance = state::left_high;
                break;

            case state::left_high:
                root->balance = state::right_high;
                left->balance = state::balanced;
                break;
            }
            subright->balance = state::balanced;
            rotate_left(left);
            root->left = left;
            rotate_right(root);
        }
        break;

        case state::balanced:
            root->balance = state::left_high;
            left->balance = state::right_high;
            rotate_right(root);
            break;
        }
    }

    inline void balance_right(heap_node*& root)
    {
        heap_node* right = root->right; // right subtree of root node

        switch (right->balance)
        {
        case state::right_high:
            root->balance = state::balanced;
            right->balance = state::balanced;
            rotate_left(root);
            break;

        case state::left_high:
        {
            heap_node* subleft = right->left; // left subtree of right
            switch (subleft->balance)
            {
            case state::balanced:
                root->balance = state::balanced;
                right->balance = state::balanced;
                break;

            case state::left_high:
                root->balance = state::balanced;
                right->balance = state::right_high;
                break;

            case state::right_high:
                root->balance = state::left_high;
                right->balance = state::balanced;
                break;
            }
            subleft->balance = state::balanced;
            rotate_right(right);
            root->right = right;
            rotate_left(root);
        }
        break;

        case state::balanced:
            root->balance = state::right_high;
            right->balance = state::left_high;
            rotate_left(root);
            break;
        }
    }

    inline void balance_tree(heap_node* root, unsigned long long from)
    {
        bool taller = true;

        while (taller)
        {
            heap_node* parent = root->parent;
            unsigned long long Nextfrom = (parent->left == root) ? direction::from_left : direction::from_right;

            if (from == direction::from_left)
            {
                switch (root->balance)
                {
                case state::left_high:
                    if (parent->is_header())
                        balance_left(parent->parent);
                    else if (parent->left == root)
                        balance_left(parent->left);
                    else
                        balance_left(parent->right);
                    taller = false;
                    break;

                case state::balanced:
                    root->balance = state::left_high;
                    taller = true;
                    break;

                case state::right_high:
                    root->balance = state::balanced;
                    taller = false;
                    break;
                }
            }
            else
            {
                switch (root->balance)
                {
                case state::left_high:
                    root->balance = state::balanced;
                    taller = false;
                    break;

                case state::balanced:
                    root->balance = state::right_high;
                    taller = true;
                    break;

                case state::right_high:
                    if (parent->is_header())
                        balance_right(parent->parent);
                    else if (parent->left == root)
                        balance_right(parent->left);
                    else
                        balance_right(parent->right);
                    taller = false;
                    break;
                }
            }

            if (taller) // skip up a level
            {
                if (parent->is_header())
                    taller = false;
                else
                {
                    root = parent;
                    from = Nextfrom;
                }
            }
        }
    }

    inline void balance_tree_remove(heap_node* root, unsigned long long from)
    {
        if (root->is_header()) return;

        bool shorter = true;

        while (shorter)
        {
            heap_node* parent = root->parent;
            unsigned long long Nextfrom = (parent->left == root) ? direction::from_left : direction::from_right;

            if (from == direction::from_left)
            {
                switch (root->balance)
                {
                case state::left_high:
                    root->balance = state::balanced;
                    shorter = true;
                    break;

                case state::balanced:
                    root->balance = state::right_high;
                    shorter = false;
                    break;

                case state::right_high:
                    if (root->right->balance == state::balanced)
                        shorter = false;
                    else
                        shorter = true;
                    if (parent->is_header())
                        balance_right(parent->parent);
                    else if (parent->left == root)
                        balance_right(parent->left);
                    else
                        balance_right(parent->right);
                    break;
                }
            }
            else
            {
                switch (root->balance)
                {
                case state::right_high:
                    root->balance = state::balanced;
                    shorter = true;
                    break;

                case state::balanced:
                    root->balance = state::left_high;
                    shorter = false;
                    break;

                case state::left_high:
                    if (root->left->balance == state::balanced)
                        shorter = false;
                    else
                        shorter = true;
                    if (parent->is_header())
                        balance_left(parent->parent);
                    else if (parent->left == root)
                        balance_left(parent->left);
                    else
                        balance_left(parent->right);
                    break;
                }
            }

            if (shorter)
            {
                if (parent->is_header())
                    shorter = false;
                else
                {
                    from = Nextfrom;
                    root = parent;
                }
            }
        }
    }

    inline void swap_heap_node_reference(heap_node*& first, heap_node*& second)
    {
        heap_node* temporary = first; first = second; second = temporary;
    }

    inline void swap_heap_nodes(heap_node* A, heap_node* B)
    {
        if (B == A->left)
        {
            if (B->left) B->left->parent = A;
            if (B->right) B->right->parent = A;

            if (A->right) A->right->parent = B;

            if (!A->parent->is_header())
            {
                if (A->parent->left == A)
                    A->parent->left = B;
                else
                    A->parent->right = B;
            }
            else A->parent->parent = B;

            B->parent = A->parent;
            A->parent = B;

            A->left = B->left;
            B->left = A;

            swap_heap_node_reference(A->right, B->right);
        }
        else if (B == A->right)
        {
            if (B->right) B->right->parent = A;
            if (B->left) B->left->parent = A;

            if (A->left) A->left->parent = B;

            if (!A->parent->is_header())
            {
                if (A->parent->left == A)
                    A->parent->left = B;
                else
                    A->parent->right = B;
            }
            else A->parent->parent = B;

            B->parent = A->parent;
            A->parent = B;

            A->right = B->right;
            B->right = A;

            swap_heap_node_reference(A->left, B->left);
        }
        else if (A == B->left)
        {
            if (A->left) A->left->parent = B;
            if (A->right) A->right->parent = B;

            if (B->right) B->right->parent = A;

            if (!B->parent->is_header())
            {
                if (B->parent->left == B)
                    B->parent->left = A;
                else
                    B->parent->right = A;
            }
            else B->parent->parent = A;

            A->parent = B->parent;
            B->parent = A;

            B->left = A->left;
            A->left = B;

            swap_heap_node_reference(A->right, B->right);
        }
        else if (A == B->right)
        {
            if (A->right) A->right->parent = B;
            if (A->left) A->left->parent = B;

            if (B->left) B->left->parent = A;

            if (!B->parent->is_header())
            {
                if (B->parent->left == B)
                    B->parent->left = A;
                else
                    B->parent->right = A;
            }
            else B->parent->parent = A;

            A->parent = B->parent;
            B->parent = A;

            B->right = A->right;
            A->right = B;

            swap_heap_node_reference(A->left, B->left);
        }
        else
        {
            if (A->parent == B->parent)
                swap_heap_node_reference(A->parent->left, A->parent->right);
            else
            {
                if (!A->parent->is_header())
                {
                    if (A->parent->left == A)
                        A->parent->left = B;
                    else
                        A->parent->right = B;
                }
                else A->parent->parent = B;

                if (!B->parent->is_header())
                {
                    if (B->parent->left == B)
                        B->parent->left = A;
                    else
                        B->parent->right = A;
                }
                else B->parent->parent = A;
            }

            if (B->left)  B->left->parent = A;
            if (B->right) B->right->parent = A;

            if (A->left)  A->left->parent = B;
            if (A->right) A->right->parent = B;

            swap_heap_node_reference(A->left, B->left);
            swap_heap_node_reference(A->right, B->right);
            swap_heap_node_reference(A->parent, B->parent);
        }

        char balance = A->balance; A->balance = B->balance; B->balance = balance;
    }

    inline heap_node* fast_forward(heap_node* HN)
    {
        if (HN->is_header()) return HN->left;

        if (HN->right != 0)
        {
            HN = HN->right;
            while (HN->left != 0) HN = HN->left;
        }
        else
        {
            heap_node* y = HN->parent;
            if (y->is_header()) return y;
            while (HN == y->right) { HN = y; y = y->parent; }
            HN = y;
        }
        return HN;
    }

    inline heap_node* fast_reverse(heap_node* HN)
    {
        if (HN->is_header()) { return HN->right; }

        else if (HN->left != 0)
        {
            heap_node* y = HN->left;
            while (y->right != 0) y = y->right;
            HN = y;
        }
        else
        {
            heap_node* y = HN->parent;
            if (y->is_header()) return y;
            while (HN == y->left) { HN = y; y = y->parent; }
            HN = y;
        }
        return HN;
    }

    struct heap_tree
    {
        heap_node header;
        unsigned long long nodes;

        heap_tree()
        {
            nodes = 0;
            header.left = &header;
            header.right = &header;
            header.parent = 0;
            header.balance = state::header;
        }

        void initialize()
        {
            nodes = 0;
            header.left = &header;
            header.right = &header;
            header.parent = 0;
        }

        heap_node* below_equals(void* address)
        {
            heap_node* y = &header;
            heap_node* x = header.parent;

            while (x != 0)
                if (address == x)
                {
                    y = x; break;
                }
                else if (address < x)
                    x = x->left;
                else
                {
                    y = x; x = x->right;
                }

            if (y == &header)
                return 0;
            else
                return y;
        }

        bool add(heap_node* new_node,
            unsigned long long size,
            unsigned long long identity = 0)
        {
            new_node->left = 0;
            new_node->right = 0;
            new_node->balance = state::balanced;
            new_node->size = size;
            new_node->identity = (unsigned char)identity;

            if (header.parent == 0)
            {
                new_node->parent = &header;
                header.parent = new_node;
                header.left = new_node;
                header.right = new_node;
                nodes++;
                return true;
            }
            else
            {
                heap_node* root = header.parent;

                for (; ; )
                {
                    int compare = heap_comparer(new_node, root);

                    if (compare == 0) // Item Exists
                    {
                        return false;
                    }

                    else if (compare < 0)
                    {
                        if (root->left != 0)
                            root = root->left;
                        else
                        {
                            root->left = new_node;

                            new_node->parent = root;

                            if (header.left == root) header.left = new_node;

                            balance_tree(root, direction::from_left);

                            nodes++;
                            return true;
                        }
                    }

                    else
                    {
                        if (root->right != 0)
                            root = root->right;
                        else
                        {
                            root->right = new_node;

                            new_node->parent = root;

                            if (header.right == root) header.right = new_node;

                            balance_tree(root, direction::from_right);

                            nodes++;
                            return true;
                        }
                    }
                }
            }
        }

        void remove(heap_node* root)
        {
            // If left and right subtrees exist find previous
            // inorder node, swap nodes and continue

            if (root->left != 0 && root->right != 0)
            {
                heap_node* replace = root->left;
                while (replace->right != 0)
                    replace = replace->right;

                swap_heap_nodes(root, replace);

                heap_node* parent = root->parent;

                unsigned long long from = (parent->left == root) ? direction::from_left : direction::from_right;

                if (header.left == root)
                {
                    heap_node* e = fast_forward(root);

                    if (e->is_header())
                    {
                        header.left = &header; header.right = &header;
                    }
                    else
                        header.left = e;
                }
                else if (header.right == root)
                {
                    heap_node* e = fast_reverse(root);

                    if (e->is_header())
                    {
                        header.left = &header; header.right = &header;
                    }
                    else
                        header.right = e;
                }

                if (root->left == 0)
                {
                    if (parent == &header)
                        header.parent = root->right;
                    else if (parent->left == root)
                        parent->left = root->right;
                    else
                        parent->right = root->right;

                    if (root->right != 0) root->right->parent = parent;
                }
                else
                {
                    if (parent == &header)
                        header.parent = root->left;
                    else if (parent->left == root)
                        parent->left = root->left;
                    else
                        parent->right = root->left;

                    if (root->left != 0) root->left->parent = parent;
                }

                balance_tree_remove(parent, from);
                nodes--;
            }

            else // Either left or right SubTree is 0
            {
                heap_node* parent = root->parent;

                unsigned long long from = (parent->left == root) ? direction::from_left : direction::from_right;

                if (header.left == root)
                {
                    heap_node* e = fast_forward(root);

                    if (e->is_header())
                    {
                        header.left = &header; header.right = &header;
                    }
                    else
                        header.left = e;
                }
                else if (header.right == root)
                {
                    heap_node* e = fast_reverse(root);

                    if (e->is_header())
                    {
                        header.left = &header; header.right = &header;
                    }
                    else
                        header.right = e;
                }

                if (root->left == 0)
                {
                    if (parent == &header)
                        header.parent = root->right;
                    else if (parent->left == root)
                        parent->left = root->right;
                    else
                        parent->right = root->right;

                    if (root->right != 0) root->right->parent = parent;
                }
                else
                {
                    if (parent == &header)
                        header.parent = root->left;
                    else if (parent->left == root)
                        parent->left = root->left;
                    else
                        parent->right = root->left;

                    if (root->left != 0) root->left->parent = parent;
                }

                balance_tree_remove(parent, from);
                nodes--;
            }
        }

        void destroy()
        {
            destroy(header.parent);
        }

        void destroy(heap_node* root)
        {
            if (root)
            {
                if (root->left)
                    destroy(root->left);

                if (root->right)
                    destroy(root->right);

                iplusplus::free_memory((void*)root);
            }
        }

        unsigned long long size()
        {
            return size(header.parent);
        }

        unsigned long long size(heap_node* root)
        {
            if (root)
            {
                unsigned long long allocationsize = root->size;

                if (root->left)
                    allocationsize += size(root->left);

                if (root->right)
                    allocationsize += size(root->right);

                return allocationsize;
            }
            else
                return 0;
        }
    };

    struct pool
    {
        pool_node header;
        unsigned long long nodes;
        unsigned long long units;
        unsigned long long blocks;
        unsigned long long unit_size;
        unsigned char identity;
        heap_tree* allocation_tree;

        pool() {}

        pool(unsigned char q)
        {
            unit_size = quantum_size(q);
            identity = q + 1;
            nodes = 0;
            units = 0;
            blocks = 0;
            header.left = &header;
            header.right = &header;
            header.parent = 0;
            header.balance = state::header;
        }

        pool& operator=(unsigned char q)
        {
            unit_size = quantum_size(q);
            identity = q + 1;
            nodes = 0;
            blocks = 0;
            units = 0;
            header.left = &header;
            header.right = &header;
            header.parent = 0;
            header.balance = state::header;
            return *this;
        }

        void initialize()
        {
            nodes = 0;
            blocks = 0;
            units = 0;
            header.left = &header;
            header.right = &header;
            header.parent = 0;
        }

        unsigned long long get_units()
        {
            return units;
        }

        unsigned long long get_unit_size()
        {
            return unit_size + leading;
        }

        unsigned long long get_external_unit_size()
        {
            return unit_size + sizeof(pool_node);
        }

        pool& operator=(heap_tree* pointer)
        {
            allocation_tree = pointer;
            return *this;
        }

        void* allocate()
        {
            if (header.parent != 0)
            {
                pool_node* allocation_block = header.left;
                unsigned long long external_size = sizeof(pool_node) + unit_size;

                char* buffer = (char*)allocation_block;
                char* out_pointer = buffer + (allocation_block->units - 1) * external_size;
                allocation_block->units--;

                pool_node* node_out = (pool_node*)out_pointer;
                if (allocation_block->units == 0)
                {
                    remove(allocation_block);
                }
                else
                    node_out->is_block = 0;

                node_out->units = 1;
                node_out->identity = identity;

                units++;

                return (void*)((char*)(node_out + 1) - leading);
            }
            else
            {
                heap_node* new_block = (heap_node*)iplusplus::allocate_memory(0, block_size, 0x00001000, 0x00000004);
                if (!allocation_tree->add(new_block, block_size, identity))
                {
                    iplusplus::free_memory((void*)new_block);
                    return 0;
                }

                pool_node* allocation_block = (pool_node*)(new_block + 1);
                if (!allocation_block) return 0;
                allocation_block->is_block = 1;
                unsigned long long external_size = sizeof(pool_node) + unit_size;
                allocation_block->units = (ushort)((block_size - sizeof(heap_node)) / external_size);
                blocks++;

                char* buffer = (char*)allocation_block;
                char* out_pointer = buffer + (allocation_block->units - 1) * external_size;
                allocation_block->units--;

                pool_node* node_out = (pool_node*)out_pointer;
                node_out->units = 1;
                node_out->identity = identity;
                node_out->is_block = 0;

                allocation_block->balance = state::balanced; // add to tree at root
                header.parent = allocation_block;
                header.parent->parent = &header;
                header.left = header.parent;
                header.right = header.parent;

                units++;
                return (void*)((char*)(node_out + 1) - leading);
            }
        }

        bool free(void* Memory) // Performs Synchronous Garbage Collection
        {
            unsigned long long external_size = sizeof(pool_node) + unit_size;

            pool_node* node_free = ((pool_node*)(((char*)Memory) + leading)) - 1;

            if (node_free->is_block == 1)
            {
                if (!add(node_free)) return false;

                pool_node* after = fast_forward(node_free);
                if (!after->is_header() && after->is_block != 1 && (char*)node_free + external_size == (char*)after)
                {
                    node_free->units += after->units;
                    remove(after);

                    if (node_free->units == (block_size - sizeof(heap_node)) / external_size)
                    {
                        remove(node_free);
                        allocation_tree->remove(((heap_node*)node_free) - 1);
                        if (!iplusplus::free_memory((void*)(((heap_node*)node_free) - 1)))
                        {
                            blocks--; units--; return false;
                        }
                        blocks--;
                    }
                }
            }
            else
            {
                pool_node* before = below(node_free);

                if (before != &header && (char*)before + before->units * external_size > (char*)node_free)
                    return false; // Already in heap's free list

                if (before == &header || (char*)before + before->units * external_size != (char*)node_free)
                { // before is non-contiguous

                    pool_node* after = fast_forward(before);
                    if (after == &header)
                        add(node_free);
                    else
                    {
                        if (after->is_block != 1 && (char*)node_free + external_size == (char*)after)
                        {
                            node_free->units += after->units;
                            remove(after);
                        }

                        if (node_free->units != (block_size - sizeof(heap_node)) / external_size)
                            add(node_free);
                        else
                        {
                            allocation_tree->remove(((heap_node*)node_free) - 1);
                            if (!iplusplus::free_memory((void*)(((heap_node*)node_free) - 1))) { blocks--; units--; return false; }
                            blocks--;
                        }
                    }
                }
                else // before is contiguous
                {
                    before->units++;
                    pool_node* after = fast_forward(before);
                    if (after != &header && after->is_block != 1 && (char*)before + external_size * before->units == (char*)after)
                    {
                        before->units += after->units;
                        remove(after);
                    }

                    if (before->units == (block_size - sizeof(heap_node)) / external_size)
                    {
                        remove(before);
                        allocation_tree->remove(((heap_node*)before) - 1);
                        if (!iplusplus::free_memory((void*)(((heap_node*)before) - 1)))
                        {
                            blocks--; units--; return false;
                        }
                        blocks--;
                    }
                }
            }

            units--;
            return true;
        }

        bool is_allocated(void* Memory)
        {
            unsigned long long external_size = sizeof(pool_node) + unit_size;

            pool_node* node_free = ((pool_node*)(((char*)Memory) + leading)) - 1;

            if (node_free->is_block == 1)
                return true;
            else
            {
                pool_node* before = below(node_free);

                if (before != &header && (char*)before + before->units * external_size > (char*)node_free)
                    return false; // Already in heap's free list

            }

            return true;
        }

        pool_node* below(pool_node* Searchnode)
        {
            pool_node* y = &header;
            pool_node* x = header.parent;

            while (x != 0)
                if (pool_comparer(Searchnode, x) <= 0)
                    x = x->left;
                else
                {
                    y = x; x = x->right;
                }

            return y;
        }

        bool add(pool_node* new_node)
        {
            new_node->left = 0;
            new_node->right = 0;
            new_node->balance = state::balanced;

            pool_node* root = header.parent;

            if (header.parent == 0)
            {
                new_node->parent = &header;
                header.parent = new_node;
                header.left = new_node;
                header.right = new_node;
                nodes++;
                return true;
            }
            else
            {
                for (; ; ) // Normal out of order processing
                {
                    int Compare = pool_comparer(new_node, root);

                    if (Compare == 0) // Item Exists
                        return false;

                    else if (Compare < 0)
                    {
                        if (root->left != 0)
                            root = root->left;
                        else
                        {
                            root->left = new_node;
                            new_node->parent = root;
                            if (header.left == root) header.left = new_node;
                            balance_tree(root, direction::from_left);
                            nodes++;
                            return true;
                        }
                    }

                    else
                    {
                        if (root->right != 0)
                            root = root->right;
                        else
                        {
                            root->right = new_node;
                            new_node->parent = root;
                            if (header.right == root) header.right = new_node;
                            balance_tree(root, direction::from_right);
                            nodes++;
                            return true;
                        }
                    }
                }
            }
        }

        void remove(pool_node* root)
        {
            // If left and right subtrees exist find previous
            // inorder node, swap nodes and continue

            if (root->left != 0 && root->right != 0)
            {
                pool_node* replace = root->left;
                while (replace->right != 0)
                    replace = replace->right;

                swap_pool_nodes(root, replace);

                pool_node* parent = root->parent;

                unsigned long long from = (parent->left == root) ? direction::from_left : direction::from_right;

                if (header.left == root)
                {
                    pool_node* e = fast_forward(root);

                    if (e->is_header())
                    {
                        header.left = &header; header.right = &header;
                    }
                    else
                        header.left = e;
                }
                else if (header.right == root)
                {
                    pool_node* e = fast_reverse(root);

                    if (e->is_header())
                    {
                        header.left = &header; header.right = &header;
                    }
                    else
                        header.right = e;
                }

                if (root->left == 0)
                {
                    if (parent == &header)
                        header.parent = root->right;
                    else if (parent->left == root)
                        parent->left = root->right;
                    else
                        parent->right = root->right;

                    if (root->right != 0) root->right->parent = parent;
                }
                else
                {
                    if (parent == &header)
                        header.parent = root->left;
                    else if (parent->left == root)
                        parent->left = root->left;
                    else
                        parent->right = root->left;

                    if (root->left != 0) root->left->parent = parent;
                }

                balance_tree_remove(parent, from);
                nodes--;
            }

            else // Either left or right SubTree is 0
            {
                pool_node* parent = root->parent;

                unsigned long long from = (parent->left == root) ? direction::from_left : direction::from_right;

                if (header.left == root)
                {
                    pool_node* e = fast_forward(root);

                    if (e->is_header())
                    {
                        header.left = &header; header.right = &header;
                    }
                    else
                        header.left = e;
                }
                else if (header.right == root)
                {
                    pool_node* e = fast_reverse(root);

                    if (e->is_header())
                    {
                        header.left = &header; header.right = &header;
                    }
                    else
                        header.right = e;
                }

                if (root->left == 0)
                {
                    if (parent == &header)
                        header.parent = root->right;
                    else if (parent->left == root)
                        parent->left = root->right;
                    else
                        parent->right = root->right;

                    if (root->right != 0) root->right->parent = parent;
                }
                else
                {
                    if (parent == &header)
                        header.parent = root->left;
                    else if (parent->left == root)
                        parent->left = root->left;
                    else
                        parent->right = root->left;

                    if (root->left != 0) root->left->parent = parent;
                }

                balance_tree_remove(parent, from);
                nodes--;
            }
        }

        unsigned long long free_overhead()
        {
            return free_overhead(header.parent);
        }

        unsigned long long free_overhead(pool_node* root)
        {
            if (root)
            {
                unsigned long long size = root->units * small_unit_overhead;

                if (root->left)
                    size += free_overhead(root->left);

                if (root->right)
                    size += free_overhead(root->right);

                return size;
            }
            else
                return 0;
        }

        unsigned long long block_overhead()
        {
            unsigned long long external_size = sizeof(pool_node) + unit_size;
            unsigned long long units_per_block = (block_size - sizeof(heap_node)) / external_size;
            unsigned long long O = blocks * ((block_size - sizeof(heap_node)) - (units_per_block * external_size));
            return O;
        }

        unsigned long long overhead()
        {
            unsigned long long O = get_units() * small_unit_overhead;
            O += free_overhead();
            O += block_overhead();
            return O;
        }

        unsigned long long free_space()
        {
            return free_space(header.parent);
        }

        unsigned long long free_space(pool_node* root)
        {
            if (root)
            {
                unsigned long long size = root->units * (unit_size + leading);
                if (root->left) size += free_space(root->left);
                if (root->right) size += free_space(root->right);
                return size;
            }
            else
                return 0;
        }
    };

    class heap : public semaphore
    {
    public:

        heap()
        {
            units = 0;
            for (unsigned long long i = 0; i < number_of_pools; i++) pool_array[i] = (unsigned char)i;
            for (unsigned long long i = 0; i < number_of_pools; i++) pool_array[i] = &allocation_tree;
        }

        void* allocate(size_t amount)
        {
            if (!amount) return 0;

            request();

            if (amount > boundaries[number_of_pools - 1] + leading)
            {
                size_t new_size = (size_t)round_up(amount + sizeof(heap_node) + sizeof(pool_node) - leading, 4096);
                heap_node* heap_block = (heap_node*)iplusplus::allocate_memory(0, new_size, 0x00001000, 0x00000004);
                allocation_tree.add(heap_block, new_size);
                pool_node* allocation_block = (pool_node*)(heap_block + 1);
                allocation_block->identity = 0;
                units++;
                release();
                return (void*)((char*)(allocation_block + 1) - leading);
            }
            else
            {
                unsigned long long Quantum = quantum_from_size(amount);
                void* allocated = pool_array[Quantum].allocate();
                release();
                return allocated;
            }
        }

        unsigned long long allocation()
        {
            request();
            unsigned long long allocation = allocation_tree.size() - overhead() - free_space();
            release();
            return allocation;
        }

        void destroy()
        {
            request();
            allocation_tree.destroy();
            release();
        }

        void empty()
        {
            request();
            allocation_tree.destroy();
            allocation_tree.initialize();
            for (unsigned long long i = 0; i < number_of_pools; i++) pool_array[i].initialize();
            units = 0;
            release();
        }

        bool free(void* Pointer, bool bypass_checks = false)
        {
            if (Pointer == 0) return true;

            if ((unsigned long long)Pointer % 8 != 0) return false;  // Check for alignment

            request();

            pool_node* node = (pool_node*)((char*)Pointer + leading) - 1;
            heap_node* hnode = ((heap_node*)node) - 1;

            // Perform Checking

            if (!bypass_checks)
            {
                heap_node* node_below = allocation_tree.below_equals(hnode);
                if (!node_below) { release(); return false; }
                if ((char*)node_below + node_below->size < Pointer) { release(); return false; }
                if (node_below->identity != node->identity) { release(); return false; }
                if (node->identity == 0)
                {
                    if (node_below != hnode) { release(); return false; }
                }
                else
                {
                    unsigned long long external_size = pool_array[node->identity - 1].get_external_unit_size();
                    if (((char*)node - ((char*)node_below + sizeof(heap_node))) % external_size != 0) { release(); return false; }
                }
            }

            // Passed Checks - Now free

            bool success = false;

            if (node->identity == 0)
            {
                allocation_tree.remove(hnode);
                success = iplusplus::free_memory((void*)hnode);
                units--;
            }
            else
                success = pool_array[node->identity - 1].free(Pointer);

            release();
            return success;
        }

        unsigned long long free_space()
        {
            request();
            unsigned long long size = 0;
            for (unsigned long long i = 0; i < number_of_pools; i++) size += pool_array[i].free_space();
            release();
            return size;
        }

        unsigned long long get_units()
        {
            request();
            unsigned long long allocated_units = units;
            for (unsigned long long i = 0; i < number_of_pools; i++) allocated_units += pool_array[i].get_units();
            release();
            return allocated_units;
        }

        unsigned long long get_unit_size(void* Pointer)
        {
            if (Pointer == 0) return 0;

            request();

            pool_node* node = (pool_node*)((char*)Pointer + leading) - 1;
            heap_node* hnode = ((heap_node*)node) - 1;

            // Perform Checking

            heap_node* node_below = allocation_tree.below_equals(hnode);
            if (!node_below) { release(); return 0; }
            if ((char*)node_below + node_below->size < Pointer) { release(); return 0; }
            if (node_below->identity != node->identity) { release(); return 0; }
            if (node->identity == 0)
            {
                if (node_below != hnode) { release(); return 0; }
                unsigned long long size = hnode->size - sizeof(heap_node) - sizeof(pool_node) + leading;
                release();
                return size;
            }
            else
            {
                if (node->identity > number_of_pools) { release(); return 0; }
                unsigned long long external_size = pool_array[node->identity - 1].get_external_unit_size();
                if (((char*)node - ((char*)node_below + sizeof(heap_node))) % external_size != 0) { release(); return 0; }
            }

            unsigned long long size = pool_array[node->identity - 1].get_unit_size();
            release();
            return size;
        }

        unsigned long long overhead()
        {
            request();
            unsigned long long O = units * large_unit_overhead + (allocation_tree.nodes - units) * block_overhead;
            for (unsigned long long i = 0; i < number_of_pools; i++) O += pool_array[i].overhead();
            release();
            return O;
        }

        unsigned long long query_pointer(void* Pointer)
        {
            if (Pointer == 0) return pointer_status::not_in_heap;

            if ((unsigned long long)Pointer % 8 != 0) return pointer_status::not_aligned;  // Check for alignment

            request();

            pool_node* node = (pool_node*)((char*)Pointer + leading) - 1;
            heap_node* hnode = ((heap_node*)node) - 1;

            // Perform Checking

            heap_node* node_below = allocation_tree.below_equals(hnode);
            if (!node_below) { release(); return pointer_status::not_in_heap; }
            if ((char*)node_below + node_below->size < Pointer) { release(); return pointer_status::not_in_heap; }
            if (node_below->identity != node->identity) { release(); return pointer_status::identity_invalid; }
            if (node->identity == 0)
            {
                if (node_below != hnode) { release(); return pointer_status::not_aligned; }
            }
            else
            {
                unsigned long long external_size = pool_array[node->identity - 1].get_external_unit_size();
                if (((char*)node - ((char*)node_below + sizeof(heap_node))) % external_size != 0) { release(); return pointer_status::not_aligned; }
            }

            bool allocated = pool_array[node->identity - 1].is_allocated(Pointer);

            release();

            if (allocated) return pointer_status::allocated; else return pointer_status::free;
        }

        unsigned long long size()
        {
            request();
            unsigned long long size = allocation_tree.size();
            release();
            return size;
        }

        void* operator new(size_t Compilesize);
        void operator delete(void* Pointer);

    private:
        pool pool_array[number_of_pools];
        heap_tree allocation_tree;
        unsigned long long units;
    };
    
    heap global_heap;

    export unsigned long long get_heap_control_block_size()
    {
        return sizeof(heap);
    }

    export void request_heap()
    {
        global_heap.request();
    }

    export bool release_heap()
    {
        return global_heap.release();
    }

    export void* allocate_from_heap(unsigned long long size)
    {
        return global_heap.allocate(size);
    }

    export bool free_from_heap(void* Memory)
    {
        return global_heap.free(Memory);
    }

    export void set_heap_bit(void* pMemory, unsigned long long ophset)
    {
        long long* pointer_nnennauuri = (long long*)pMemory;
        long long uuurd_ophset = ophset / 64;
        long long* pointer_uuurd = pointer_nnennauuri + uuurd_ophset;
        long long bit_ophset = ophset % 64;
        long long uuun = 1;
        uuun <<= bit_ophset;
        *pointer_uuurd |= uuun;
    }

    export void clear_heap_bit(void* pMemory, unsigned long long ophset)
    {
        long long* pointer_nnennauuri = (long long*)pMemory;
        long long uuurd_ophset = ophset / 64;
        long long* pointer_uuurd = pointer_nnennauuri + uuurd_ophset;
        long long bit_ophset = ophset % 64;
        long long uuun = 1;
        uuun <<= bit_ophset;
        long long nnasc = 0xffffffffffffffff;
        nnasc &= bit_ophset;
        *pointer_uuurd ^= uuun;
    }

    export bool get_heap_bit(void* pMemory, unsigned long long ophset)
    {
        long long* pointer_nnennauuri = (long long*)pMemory;
        long long uuurd_ophset = ophset / 64;
        long long* pointer_uuurd = pointer_nnennauuri + uuurd_ophset;
        long long bit_ophset = ophset % 64;
        long long uuun = 1;
        uuun <<= bit_ophset;
        long long nnasc = 0xffffffffffffffff;
        nnasc &= bit_ophset;
        return *pointer_uuurd & uuun;
    }

    export unsigned long long query_heap_word(void* pMemory, unsigned long long ophset)
    {
        long long* pointer_nnennauuri = (long long*)pMemory;
        long long uuurd_ophset = ophset / 64;
        long long* pointer_uuurd = pointer_nnennauuri + uuurd_ophset;
        return *pointer_uuurd;
    }

    export bool fast_free_from_heap(void* Memory)
    {
        return global_heap.free(Memory, true);
    }

    export unsigned long long query_heap_pointer(void* Memory)
    {
        return global_heap.query_pointer(Memory);
    }

    export unsigned long long get_heap_size()
    {
        return global_heap.size();
    }

    export unsigned long long get_heap_free_space()
    {
        return global_heap.free_space();
    }

    export unsigned long long get_heap_units()
    {
        return global_heap.get_units();
    }

    export unsigned long long get_heap_overhead()
    {
        return global_heap.overhead();
    }

    export unsigned long long get_heap_allocation()
    {
        return global_heap.allocation();
    }

    export unsigned long long get_heap_unit_size(void* unit)
    {
        return global_heap.get_unit_size(unit);
    }

    //************************************************************************
    //                            Binary heap APIs                           *
    //************************************************************************

    void* heap::operator new(size_t compile_size) { return allocate_from_heap(compile_size); }

    void heap::operator delete(void* pointer) { free_from_heap(pointer); }

    export void* create_binary_heap()
    {
        return new heap();
    }

    export void destroy_binary_heap(void* heap_handle)
    {
        heap* h = (heap*)heap_handle;
        h->request();
        if (!-- * h)
        {
            h->destroy();
            delete h;
        }
        else h->release();
    }

    export void empty_binary_heap(void* heap_handle)
    {
        heap* h = (heap*)heap_handle;
        h->empty();
    }

    export unsigned increment_binary_heap(void* heap_handle)
    {
        heap* h = (heap*)heap_handle;
        h->request();
        unsigned reference = ++ * h;
        h->release();
        return reference;
    }

    export void request_binary_heap(void* heap_handle)
    {
        heap* h = (heap*)heap_handle;
        h->request();
    }

    export bool release_binary_heap(void* heap_handle)
    {
        heap* h = (heap*)heap_handle;
        return h->release();
    }

    export void* allocate_from_binary_heap(void* heap_handle, unsigned long long size)
    {
        heap* h = (heap*)heap_handle;
        return h->allocate(size);
    }

    export bool free_from_binary_heap(void* heap_handle, void* Memory)
    {
        heap* h = (heap*)heap_handle;
        return h->free(Memory);
    }

    export bool fast_free_from_binary_heap(void* heap_handle, void* Memory)
    {
        heap* h = (heap*)heap_handle;
        return h->free(Memory, true);
    }

    export unsigned long long query_binary_heap_pointer(void* heap_handle, void* Memory)
    {
        heap* h = (heap*)heap_handle;
        return h->query_pointer(Memory);
    }

    export unsigned long long get_binary_heap_size(void* heap_handle)
    {
        heap* h = (heap*)heap_handle;
        return h->size();
    }

    export unsigned long long get_binary_heap_free_space(void* heap_handle)
    {
        heap* h = (heap*)heap_handle;
        return h->free_space();
    }

    export unsigned long long get_binary_heap_units(void* heap_handle)
    {
        heap* h = (heap*)heap_handle;
        return h->get_units();
    }

    export unsigned long long get_binary_heap_overhead(void* heap_handle)
    {
        heap* H = (heap*)heap_handle;
        return H->overhead();
    }

    export unsigned long long get_binary_heap_allocation(void* heap_handle)
    {
        heap* H = (heap*)heap_handle;
        return H->allocation();
    }

    export unsigned long long get_binary_heap_unit_size(void* heap_handle,
        void* Unit)
    {
        heap* H = (heap*)heap_handle;
        return H->get_unit_size(Unit);
    }

    // *** date and time classes ***

    export bool is_leap_year(unsigned year)
    {
        return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0 ? true : false;
    }

    export enum
    {
        Sunday = 0,
        Monday,
        Tuesday,
        Wednesday,
        Thursday,
        Friday,
        Saturday
    };

    export enum
    {
        January = 1,
        February,
        March,
        April,
        May,
        June,
        July,
        August,
        September,
        October,
        November,
        December
    };

    export struct date
    {
        unsigned year;
        unsigned julian;

        date();

        date(unsigned day,
            unsigned month,
            unsigned year);

        date(unsigned julian,
            unsigned year);

        date(const date& date);

        date& operator=(const date& date);

        void get();

        unsigned get_day() const;
        unsigned get_month() const;
        unsigned get_year() const { return year; }

        unsigned Julian() const { return julian; }

        operator unsigned() const;               // returns month
        unsigned get_day_of_week() const;

        date& operator+=(unsigned days_add);
        date& operator-=(unsigned days_minus);

        date& operator++() { return *this += 1; }
        date& operator--() { return *this -= 1; }

        date operator++(int) { date d = *this; *this += 1; return d; }
        date operator--(int) { date d = *this; *this -= 1; return d; }

        bool is_leap_year() const { return (year % 4 == 0 && year % 100 != 0) ||  year % 400 == 0 ? true : false;  }

        date& add_month();
        date& subtract_month();

        date& add_year();
        date& subtract_year();

        int days_to_month_end();
        int days_to_year_end();

        friend int __declspec(dllexport) operator-(const date& date1, const date& date2);

        inline friend bool operator==(const date& date1, const date& date2)
        {
            return (bool)(date1.year == date2.year && date1.julian == date2.julian);
        }

        inline friend bool operator!=(const date& date1, const date& date2)
        {
            return (bool)(date1.year != date2.year || date1.julian != date2.julian);
        }

        inline friend bool operator<=(const date& date1, const date& date2)
        {
            return (bool)(date1.year < date2.year || (date1.year == date2.year && date1.julian <= date2.julian));
        }

        inline friend bool operator>=(const date& date1, const date& date2)
        {
            return (bool)(date1.year > date2.year || (date1.year == date2.year && date1.julian >= date2.julian));
        }

        inline friend bool operator<(const date& date1, const date& date2)
        {
            return (bool)(date1.year < date2.year || (date1.year == date2.year && date1.julian < date2.julian));
        }

        inline friend bool operator>(const date& date1, const date& date2)
        {
            return (bool)(date1.year > date2.year || (date1.year == date2.year && date1.julian > date2.julian));
        }
    };

    export struct difference
    {
        unsigned hour;         // Range: 0 - 23
        unsigned minute;       // Range: 0 - 59
        unsigned second;       // Range: 0 - 59
        unsigned millisecond;  // Range: 0 - 99
        unsigned day;          // Days difference

        difference();
    };

    export enum time_compare
    {
        time_less = -1,
        time_equal = 0,
        time_greater = 1
    };

    export struct time
    {
        unsigned year;
        unsigned month;
        unsigned day_of_week;
        unsigned day;
        unsigned hour;
        unsigned minute;
        unsigned second;
        unsigned millisecond;

        time(unsigned year,
            unsigned month = 0,
            unsigned day_of_week = 0,
            unsigned day = 0,
            unsigned hour = 0,
            unsigned minute = 0,
            unsigned second = 0,
            unsigned millisecond = 0);

        time(const date& date);

        time();

        operator date() const;
    };

    time_compare operator==(const time& time_first,
        const time& time_second);

    difference operator-(const time& time_first,
        const time& time_second);


    export std::ostream& operator<<(std::ostream& os, const difference& d)
    {
        os << d.day << ":" << d.hour << ":" << d.minute << ":" << d.second << ":" << d.millisecond; return os;
    }

    static unsigned day_table[2][12] =
    {
     {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
     {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
    };

    static unsigned days_cumulative[2][13] =
    {
     {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365},
     {0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335, 366}
    };

    date::date()
    {
        time time_query;
        *this = date(time_query.day,
            (unsigned)time_query.month,
            time_query.year);
    }

    date& date::operator=(const date& date_assign)
    {
        year = date_assign.year;
        julian = date_assign.julian;
        return *this;
    }

    void date::get()
    {
        time time_query;
        *this = (date)time_query;
    }

    date::date(unsigned day,
        unsigned month_date,
        unsigned year_set)
        : year(year_set),
        julian(day)
    {
        if (month_date > 12) throw month_is_invalid_exception();

        if (day > day_table[is_leap_year()][month_date - 1])
            throw day_of_month_is_invalid_exception();

        if (month_date < January || month_date > December)
            throw month_is_invalid_exception();

        bool decide_leap_year = is_leap_year();
        for (unsigned index = January; index < (unsigned)month_date; index++)
            julian += day_table[decide_leap_year][index - 1];
    }

    date::date(unsigned julian_set,
        unsigned year_set)
        : year(year_set),
        julian(julian_set)
    {
        if (julian_set > (unsigned)(365 + is_leap_year()))
            throw julian_day_is_invalid_exception();
    }

    date::date(const date& date_copy)
        : year(date_copy.year),
        julian(date_copy.julian) {}

    date& date::operator+=(unsigned days_add)
    {
        unsigned total_days = julian + days_add;

        while (total_days > (unsigned)(365 + is_leap_year()))
        {
            total_days -= 365 + is_leap_year();
            year++;
        }

        julian = total_days;
        return *this;
    }

    date& date::operator-=(unsigned days_minus)
    {
        int total_days = (int)julian - (int)days_minus;

        while (total_days <= 0)
        {
            year--;
            total_days += 365 + is_leap_year();
        }

        julian = (unsigned)total_days;
        return *this;
    }

    int operator-(const date& date1, const date& date2)
    {
        int years_difference = (int)date1.year - (int)date2.year;

        if (!years_difference)
            return (int)date1.julian - (int)date2.julian;

        else
        {
            unsigned  year = (years_difference > 0) ? date2.year : date1.year;

            int days_difference = (years_difference > 0) ? 365 + is_leap_year(year) - date2.julian
                : -365 - is_leap_year(year) + date1.julian;
            while (years_difference)
            {
                if (years_difference > 0)
                {
                    if (!--years_difference)
                        days_difference += date1.julian;
                    else
                    {
                        year++;
                        days_difference += 365 + is_leap_year(year);
                    }
                }
                else
                {
                    if (!++years_difference)
                        days_difference -= date2.julian;
                    else
                    {
                        year++;
                        days_difference -= 365 + is_leap_year(year);
                    }
                }
            }
            return days_difference;
        }
    }

    unsigned date::get_month() const
    {
        bool decide_leap_year = is_leap_year();
        unsigned month = 0;
        while (julian > days_cumulative[decide_leap_year][month]) month++;
        return month;
    }

    date::operator unsigned() const
    {
        bool decide_leap_year = is_leap_year();
        unsigned month = 0;
        while (julian > days_cumulative[decide_leap_year][month]) month++;
        return month;
    }

    unsigned date::get_day() const
    {
        bool decide_leap_year = is_leap_year();
        unsigned month = 0;
        while (julian > days_cumulative[decide_leap_year][month]) month++;
        return julian - days_cumulative[decide_leap_year][month - 1];
    }

    unsigned date::get_day_of_week() const
    {
        date date_reference(1, January, 1995);  // Is a Sunday

        int days_difference = *this - date_reference;

        unsigned day_return = (days_difference > 0) ? (days_difference % 7 + 1)
            : ((7 + (days_difference % 7)) % 7 + 1);
        return day_return;
    }

    int date::days_to_month_end()
    {
        return (day_table[is_leap_year()][get_month()] - get_day());
    }

    int date::days_to_year_end()
    {
        return ((365 + is_leap_year()) - julian);
    }

    date& date::add_month()
    {
        if ((unsigned)*this == 4 || (unsigned)*this == 6 || (unsigned)*this == 9 || (unsigned)*this == 11)
            *this += 30;

        else if ((unsigned)*this == 2)
            *this += 28 + is_leap_year();

        else if ((unsigned)*this == 1)
        {
            if (get_day() <= (unsigned)(28 + is_leap_year()))
                *this += 31;
            else
                julian = 59 + is_leap_year();
        }

        else if (((unsigned)*this == 7) || ((unsigned)*this == 12))
            *this += 31;

        else if ((unsigned)*this == 3 || (unsigned)*this == 5 || (unsigned)*this == 8 || (unsigned)*this == 10)
        {
            if (get_day() <= 30)
                *this += 31;
            else
                *this += 30;
        }

        return *this;
    }

    date& date::subtract_month()
    {
        if ((unsigned)*this == 1 ||
            (unsigned)*this == 2 ||
            (unsigned)*this == 4 ||
            (unsigned)*this == 6 ||
            (unsigned)*this == 8 ||
            (unsigned)*this == 9 ||
            (unsigned)*this == 11)
            *this -= 31;

        else if ((unsigned)*this == 3)
        {
            if (get_day() <= (unsigned)(28 + is_leap_year()))
                *this -= 28 + is_leap_year();
            else
                julian = 59 + standard::is_leap_year(year);
        }

        else if ((unsigned)*this == 5 || (unsigned)*this == 7 || (unsigned)*this == 10 || (unsigned)*this == 12)
        {
            if (get_day() <= 30)
                *this -= 30;
            else
                *this -= 31;
        }

        return *this;
    }

    date& date::add_year()
    {
        if (julian < 60)
            *this += 365 + is_leap_year();

        else if (julian > 60)
            *this += 365 + standard::is_leap_year(year + 1);

        else if (julian == 60)
            *this += is_leap_year() ? 365 : 365 + standard::is_leap_year(year + 1);

        return *this;
    }

    date& date::subtract_year()
    {
        if (!year)
            julian = 0;

        else if (julian < 60)
            *this -= 365 + standard::is_leap_year(year - 1);

        else if (julian > 60)
            *this -= 365 + is_leap_year();

        else if (julian == 60)
            *this -= is_leap_year() ? 366 : 365;

        return *this;
    }

    const char* date_suffix(const date& date_to_suffix)
    {
        enum { th, st, nd, rd } suffix = th;

        int day = date_to_suffix.get_day();
        int day_mod_10 = day % 10;
        int day_mod_100 = day % 100;

        if (!(day_mod_100 >= 10 && day_mod_100 <= 20))
            switch (day_mod_10)
            {
            case 1:
                suffix = st;
                break;

            case 2:
                suffix = nd;
                break;

            case 3:
                suffix = rd;
                break;

            default: break;
            }

        static const char* suffix_strings[] = { "th",
                                               "st",
                                               "nd",
                                               "rd" };

        return suffix_strings[suffix];
    }

    time::time(const date& date_copy)
        : hour(0),
        minute(0),
        second(0),
        millisecond(0),
        year(date_copy.get_year()),
        month(date_copy.get_month()),
        day(date_copy.get_day()),
        day_of_week(date_copy.get_day_of_week()) {}

    time::time(unsigned year_set,
        unsigned month_set,
        unsigned day_of_week_set,
        unsigned day_set,
        unsigned hour_set,
        unsigned minute_set,
        unsigned second_set,
        unsigned millisecond_set)
        : year(year_set),
        month(month_set),
        day_of_week(day_of_week_set),
        day(day_set),
        hour(hour_set),
        minute(minute_set),
        second(second_set),
        millisecond(millisecond_set) {}

     time::time()
    {
        system_time get;
        get_local_time(&get);
        year = get.year;
        month = get.month;
        day_of_week = get.day_of_week;
        day = get.day;
        hour = get.hour;
        minute = get.minute;
        second = get.second;
        millisecond = get.millisecond;
    }

    export struct system_time
    {
        int hour;          // Range: 0 - 23
        int minute;        // Range: 0 - 59
        int second;        // Range: 0 - 59
        int millisecond;   // Range: 0 - 999
        int day;           // Current day of the month. Range: 1 - 31
        int month;         // Current month of the year. Range: 1 - 12
        int year;          // Current year

        inline system_time(const time& time_copy)
            : hour(time_copy.hour),
            minute(time_copy.minute),
            second(time_copy.second),
            millisecond(time_copy.millisecond),
            day(time_copy.day),
            month(time_copy.month),
            year(time_copy.year) {}
    };

    export time_compare operator==(const time& time_first,
        const time& time_second)
    {
        register int result;

        if (time_first.year != time_second.year)
        {
            result = (int)time_first.year -
                (int)time_second.year;
        }

        else if (time_first.month != time_second.month)
        {
            result = (int)time_first.month -
                (int)time_second.month;
        }

        else if (time_first.day != time_second.day)
        {
            result = (int)time_first.day -
                (int)time_second.day;
        }

        else if (time_first.hour != time_second.hour)
        {
            result = (int)time_first.hour -
                (int)time_second.hour;
        }

        else if (time_first.minute != time_second.minute)
        {
            result = (int)time_first.minute -
                (int)time_second.minute;
        }

        else if (time_first.second != time_second.second)
        {
            result = (int)time_first.second -
                (int)time_second.second;
        }

        else if (time_first.millisecond != time_second.millisecond)
        {
            result = (int)time_first.millisecond -
                (int)time_second.millisecond;
        }

        else result = 0;

        if (result == 0)
            return time_equal;

        else if (result < 0)
            return time_less;

        else
            return time_greater;
    }

    export difference::difference()
        : hour(0),
        minute(0),
        second(0),
        millisecond(0),
        day(0) {}

    export difference operator-(const time& time_first,
        const time& time_second)
    {
        time_compare time_compare_result = (time_first == time_second);

        if (time_compare_result == time_equal)
            return difference();

        else if (time_compare_result == time_less)
            return time_second - time_first;

        else
        {
            difference difference_return;

            system_time time_a(time_first);
            system_time time_b(time_second);

            int millisecond_carry = (time_a.millisecond < time_b.millisecond) ? 1 : 0;

            difference_return.millisecond = 1000 * millisecond_carry +
                time_a.millisecond -
                time_b.millisecond;

            int second_carry = ((time_a.second < (time_b.second + millisecond_carry)) ? 1 : 0);

            difference_return.second = 60 * second_carry +
                time_a.second -
                time_b.second -
                millisecond_carry;

            int minute_carry = ((time_a.minute < (time_b.minute + second_carry)) ? 1 : 0);

            difference_return.minute = 60 * minute_carry +
                time_a.minute -
                time_b.minute -
                second_carry;

            int hour_carry = ((time_a.hour < (time_b.hour + minute_carry)) ? 1 : 0);

            difference_return.hour = 24 * hour_carry +
                time_a.hour -
                time_b.hour -
                minute_carry;


            date d = (date)time_first;

            int days_difference = (date)time_first - (date)time_second;

            days_difference -= hour_carry;

            difference_return.day = (unsigned)days_difference;

            return difference_return;
        }
    }

    time::operator date() const
    {
        return date(day, month, year);
    }

}