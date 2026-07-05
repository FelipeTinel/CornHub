#include <iostream>

#include "containers/doubly_linked_list.hpp"
#include "containers/node.hpp"

void DoublyLinkedList::insert(const Content &content) {

    Node * new_node = new Node(content);
    if (head == nullptr) tail = new_node;
    else head->previous = new_node;
    new_node->next = head;
    head = new_node;

}

Content DoublyLinkedList::pop (const Content &content) {
}