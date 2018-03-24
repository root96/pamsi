#ifndef DATA_STRUCTURES_DOUBLYLINKEDLIST_H
#define DATA_STRUCTURES_DOUBLYLINKEDLIST_H

template <class T>
class DLLNode {
    using value_type = T;
public:
    DLLNode(const value_type& d, DLLNode* n = nullptr, DLLNode* p = nullptr)
            : data(d), next(n), prev(p) {}

    value_type data;
    DLLNode *next;
    DLLNode *prev;
};

template<class T>
class DoublyLinkedList {
    using value_type = T;
public:
    DoublyLinkedList() { counter = 0; head = tail = nullptr; }

    void push_front(const value_type&);
    void push_back(const value_type&);
    value_type pop_front();
    value_type pop_back();
    void printAll() const;
    int returnSize() const;

private:
    int counter;
    DLLNode<value_type> *head;
    DLLNode<value_type> *tail;
};

template <class T>
void DoublyLinkedList<T>::push_front(const value_type &value) {
    counter++;
    if (head == nullptr && tail == nullptr) {
        head = tail = new DLLNode<value_type>(value);
    } else {
        head = new DLLNode<value_type>(value, head, nullptr);
        head->next->prev = head;
    }
}
template <class T>
void DoublyLinkedList<T>::push_back(const value_type &value) {
    counter++;
    if (head == nullptr && tail == nullptr) {
        head = tail = new DLLNode<value_type>(value);
    } else {
        tail = new DLLNode<value_type>(value, nullptr, tail);
        tail->prev->next = tail;
    }
}

template <class T>
T DoublyLinkedList<T>::pop_front() {
    if (head == nullptr) {
        std::cerr << "Doubly Linked List is empty! ";
        return -1;
    } else if (head == tail) {
        counter--;
        value_type data = head->data;
        delete head;
        head = tail = nullptr;
        return data;
    } else {
        counter--;
        value_type data = head->data;
        head = head->next;
        delete head->prev;
        head->prev = nullptr;
        return data;
    }
}

template <class T>
T DoublyLinkedList<T>::pop_back() {
    if (tail == nullptr) {
        std::cerr << "Doubly Linked List is empty! ";
        return -1;
    } else if (tail == head) {
        counter--;
        value_type data = tail->data;
        delete tail;
        tail = head = nullptr;
        return data;
    } else {
        counter--;
        value_type data = tail->data;
        tail = tail->prev;
        delete tail->next;
        tail->next = nullptr;
        return data;
    }
}

template <class T>
void DoublyLinkedList<T>::printAll() const {
    DLLNode<value_type> *node = head;
    for(; node != nullptr; node = node->next) {
        std::cout << node->data << " ";
    }
}

template <class T>
int DoublyLinkedList<T>::returnSize() const {
    return counter;
}

#endif //DATA_STRUCTURES_DOUBLYLINKEDLIST_H
