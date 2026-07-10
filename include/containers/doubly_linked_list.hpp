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

        Node<T> * get_head() const;
        Node<T> * get_tail() const;


};