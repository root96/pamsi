#ifndef DATA_STRUCTURES_NODE_H
#define DATA_STRUCTURES_NODE_H

template <class T>
class Node {
    using value_type = T;
public:
    Node(value_type d, Node *n = nullptr) : data(d), next(n) {}

    value_type data;
    Node *next;
};

#endif //DATA_STRUCTURES_NODE_H
