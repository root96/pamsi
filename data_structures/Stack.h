#ifndef DATA_STRUCTURES_STACK_H
#define DATA_STRUCTURES_STACK_H

#include "IContainer.h"
#include "Node.h"
#include <new>

template <class T>
class Stack : public IContainer<T> {
    using value_type = T;
public:
    explicit Stack() { counter = 0; head = nullptr; }

    void push(const value_type&);
    value_type pop();
    int returnSize();

private:
    int counter;
    Node<value_type > *head;
};

template <class T>
void Stack<T>::push(const value_type &value) {
    try {
        head = new Node<value_type>(value, head);
        counter++;
    } catch (const std::bad_alloc& ba) {
        std::cerr << "bad alloc caught" << ba.what() << "\n";
        counter--;
    }
}

template <class T>
T Stack<T>::pop() {
    if (head == nullptr) {
        std::cerr << "Stack is empty!" << std::endl;
    } else {
        counter--;
        Node<value_type> *tmp = head;
        value_type data = head->data;
        head = head->next;
        delete tmp;
        return data;
    }
}

template <class T>
int Stack<T>::returnSize() {
    return counter;
}

#endif //DATA_STRUCTURES_STACK_H
