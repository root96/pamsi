#ifndef DATA_STRUCTURES_QUEUE_H
#define DATA_STRUCTURES_QUEUE_H

#include "IContainer.h"
#include "Node.h"
#include <new>

template <class T>
class Queue : public IContainer<T> {
    using value_type = T;
public:
    explicit Queue() { head = tail = nullptr; counter = 0; }

    void enqueue(const value_type&);
    value_type dequeue();
    int returnSize();

private:
    int counter;
    Node<value_type> *head;
    Node<value_type> *tail;
};

template <class T>
void Queue<T>::enqueue(const value_type &value) {
    try {
        head = new Node<value_type>(value, head);
        if (tail == nullptr) tail = head;
        counter++;
    } catch (const std::bad_alloc& ba) {
        std::cerr << "bad alloc caught" << ba.what() << "\n";
        counter--;
    }
}

template <class T>
T Queue<T>::dequeue() {
    value_type data = tail->data;
    if (head == nullptr) {
        std::cerr << "Queue is empty!" << std::endl;
    } else if (head == tail) {
        counter--;
        delete head;
        head = tail = nullptr;
    } else {
        counter--;
        Node<value_type> *tmp = nullptr;
        for (tmp = head; tmp->next != tail; tmp = tmp->next);
        delete tail;
        tail = tmp;
        tail->next = nullptr;
    }
    return data;
}

template <class T>
int Queue<T>::returnSize() {
    return counter;
}

#endif //DATA_STRUCTURES_QUEUE_H
