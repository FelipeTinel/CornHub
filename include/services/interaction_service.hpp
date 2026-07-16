#pragma once

#include <iostream>

#include "services/auth_service.hpp"
#include "containers/doubly_linked_list.hpp"
#include "core/content.hpp"
#include "core/comment.hpp"
#include "core/watched_entry.hpp"
#include "containers/node.hpp"

struct RatedNode {
    int user_id;
    int content_id;
     RatedNode * next;
};

class InteractionService {

    private:
        
        AuthService & auth_service;             
        DoublyLinkedList<Comment> & global_comments;
        RatedNode * rated_head;

        //ordenada em ordem decrescente de vezes assistido).
        //Reorganizada automaticamente a cada chamada de watch_content().
        DoublyLinkedList<WatchedEntry> watch_history;

    public:

        InteractionService(AuthService & auth, DoublyLinkedList<Comment> & comments);
        ~InteractionService();

        void watch_content(Content & content);
        bool add_comment_to_content(Content& content, const std::string & text);
        bool rate_content(Content & content, float new_note);
        bool has_rated(int user_id, int content_id) const;

        const DoublyLinkedList<WatchedEntry> & get_watch_history() const { return watch_history; }

};