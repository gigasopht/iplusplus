// Standard Kernel - Implements the Russian AVL Algorithm

export module iplusplus:kernel;

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

export struct node  // Base node Class for all Trees
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

    node(node* parent_ordered_set)
    {
        balance = state::balanced;
        left = 0;
        right = 0;
        parent = parent_ordered_set;
    }

    bool is_header() const { return !balance; }
};

struct direction
{
    enum { from_left, from_right };
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

export node* previous_item(node* _node)
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

export node* next_item(node* _node)
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

export void adjust_add(node* root)
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

export void adjust_remove(node* parent, unsigned long long direction)
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

export unsigned long long depth(const node* root)
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


export unsigned long long count(const node* root)
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
