#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "node_tree.hpp"

#include "core/genre.hpp"
#include "core/type.hpp"

class BinaryTree {

    private:

        NodeTree * root;

        NodeTree* build_genre_nodes(Node<Genre>* current);
        NodeTree* build_subgenre_nodes(Node<std::string>* currentSub);

        void destroy(NodeTree* node) {
            if (node != nullptr) {
                destroy(node->no);
                destroy(node->yes);
                delete node->question;
                delete node;
            }
        }
        

    public:

        BinaryTree (): root(nullptr) {}
        ~BinaryTree() { destroy(root); }

        void build_tree(DoublyLinkedList<Genre>& genreList); // Inicia a construção


        NodeTree* get_root() const { return root; }
        void set_root(NodeTree* new_root) { root = new_root; }

};