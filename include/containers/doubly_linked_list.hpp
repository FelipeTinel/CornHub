#include <iostream>

#include "node.hpp"
#include "content.hpp"

template <typename T>
class DoublyLinkedList {

    Node * head, * tail, * current;

    public:

        DoublyLinkedList(): head(nullptr) {}
        DoublyLinkedList(Node * head): head(head) {}
    
        ~ DoublyLinkedList ();
    
        void insert (const T &info);
        T pop (const T &info);

        Node<T> * get_head() const { return head; }
        Node<T> * get_tail() const; { return tail; }


};


template <typename T>
void DoublyLinkedList<T>::insert(const T &info) {

    Node<T> * new_node = new Node<T>(info);
    
    new_node->previous = nullptr;

    if (head == nullptr) tail = new_node;
    else head->previous = new_node;

    new_node->next = head;

    head = new_node;

}

template <typename T>
T DoublyLinkedList<T>::pop (const T &info) {

    Node<T> * temp = tail;

    while (temp != nullptr) {

        if (info.get_id() == temp->info.get_id()) {

            if (temp->previous != nullptr) temp->previous->next = temp->next;
            else head = temp->next;

            if (temp->next != nullptr) temp->next->previous = temp->previous;
            else tail = temp->previous;

            T save_content = temp->info;
            delete temp;
            return save_content;
        
        }

        temp = temp->previous;

    }

    return info;

}
