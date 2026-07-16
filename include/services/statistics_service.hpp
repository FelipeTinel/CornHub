#pragma once

#include "containers/doubly_linked_list.hpp"
#include "containers/node.hpp"
#include "core/content.hpp"
#include "core/type.hpp"
#include "core/genre.hpp"

// Quantidade de valores validos dos enums Type e Genre::Value, usada para
// dimensionar os vetores de contagem abaixo.
// Type vai de 0 (MOVIE) a 4 (CARTOON) -> 5 valores.
// Genre::Value vai de 1 (ACTION) a 8 (SLICE_OF_LIFE) -> usamos indice 0..8
// e simplesmente ignoramos a posicao 0.
constexpr int TYPE_COUNT = 5;
constexpr int GENRE_COUNT = 9;

// Concentra as estatisticas do sistema pedidas no enunciado:
//   - tipo/genero mais e menos recomendado (acumulado a cada recomendacao)
//   - total de recomendacoes realizadas
//   - total de visualizacoes, titulo mais assistido por tipo/genero (calculados
//     na hora, direto da lista de conteudos)
class StatisticsService {

    private:

        long type_recommend_count[TYPE_COUNT];
        long genre_recommend_count[GENRE_COUNT];
        long total_recommendations;

    public:

        StatisticsService();

        // Deve ser chamada toda vez que uma nova lista de recomendacoes for
        // gerada (ver Console::build_recommendations em src/ui/console.cpp).
        void register_recommendation(const DoublyLinkedList<Content> & recommended);

        Type get_most_recommended_type() const;
        Type get_least_recommended_type() const;
        Genre::Value get_most_recommended_genre() const;
        Genre::Value get_least_recommended_genre() const;
        long get_total_recommendations() const { return total_recommendations; }

        // Estatisticas calculadas na hora, direto da lista principal de conteudos
        // (nao precisam de estado acumulado).
        static long get_total_views(const DoublyLinkedList<Content> & contents);
        static Content * get_most_watched_by_type(const DoublyLinkedList<Content> & contents, Type type);
        static Content * get_most_watched_by_genre(const DoublyLinkedList<Content> & contents, Genre::Value genre);

};