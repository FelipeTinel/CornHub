#pragma once

#include <iostream>

#include "containers/doubly_linked_list.hpp"
#include "core/content.hpp"

class ContentList {

    private:

        DoublyLinkedList<Content> main_list, recomendation_list, rating_list, popula_list, launch_list;

    public:

        ContentList () {}
        ~ ContentList () {}

        void create_main_list(Node<Content>* head);
        void create_recomendation_list();
        void create_rating_list();
        void create_popular_list();
        void create_launch_list ();

};