#pragma once

#include <string>

#include "type.hpp"
#include "genre.hpp"

// Representa uma entrada do historico de conteudos mais assistidos.
class WatchedEntry {

    private:

        int content_id;
        std::string title;
        Type type;
        Genre::Value genre;
        long times_watched;

    public:

        WatchedEntry();
        WatchedEntry(int content_id, std::string title, Type type, Genre::Value genre, long times_watched);


        int get_id() const;
        std::string get_title() const;
        Type get_type() const;
        Genre::Value get_genre() const;
        long get_times_watched() const;

        void add_watch();

};

// Comparador para manter a lista ordenada em ordem decrescente de visualizacoes.
bool watched_desc(const WatchedEntry &a, const WatchedEntry &b);