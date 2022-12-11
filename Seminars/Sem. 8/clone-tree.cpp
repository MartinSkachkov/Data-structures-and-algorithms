template <class T>
Tree<T> *clone(const Tree<T> *t) {
    if (!t)
        return nullptr;

    return new Tree<T>(t->data, clone(t->left), clone(t->right));
}