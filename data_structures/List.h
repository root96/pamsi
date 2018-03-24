#ifndef DATA_STRUCTURES_LIST_H
#define DATA_STRUCTURES_LIST_H

#include "IContainer.h"
#include "Node.h"
#include <new>


template <class T>
class List : public IContainer<T> {
    using value_type = T;
public:
    explicit List() { head = tail = nullptr; counter = 0; }

    void push_front(const value_type&);
    void push_back(const value_type&);
    value_type pop_front();
    value_type pop_back();
    int returnSize();

private:
    int counter;
    Node<value_type> *head;
    Node<value_type> *tail;
};

template <class T>
void List<T>::push_front(const value_type &value) {
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
void List<T>::push_back(const value_type &value) {
    try {
        if (tail != nullptr) {
            counter++;
            tail->next = new Node<value_type>(value);
            tail = tail->next;
        } else {
            counter++;
            head = tail = new Node<value_type>(value);
        }
    } catch (const std::bad_alloc& ba) {
        std::cerr << "bad alloc caught" << ba.what() << "\n";
        counter--;
    }
}

template <class T>
T List<T>::pop_back() {
    value_type data = head->data;
    if (head == nullptr) {
        std::cerr << "List is empty!" << std::endl;
    } else if (head == tail) {
        counter--;
        delete head;
        head = tail = nullptr;
    } else {
        Node<value_type> *tmp = head;
        head = head->next;
        delete tmp;
    }
    return data;
}

template <class T>
T List<T>::pop_front() {
    value_type data = tail->data;
    if (head == nullptr) {
        std::cerr << "List is empty!" << std::endl;
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
int List<T>::returnSize() {
    return counter;
}

#endif //DATA_STRUCTURES_LIST_H
