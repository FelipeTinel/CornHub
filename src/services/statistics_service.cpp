#include "services/statistics_service.hpp"

StatisticsService::StatisticsService(): total_recommendations(0) {
    for (int i = 0; i < TYPE_COUNT; i++) type_recommend_count[i] = 0;
    for (int i = 0; i < GENRE_COUNT; i++) genre_recommend_count[i] = 0;
}

void StatisticsService::register_recommendation(const DoublyLinkedList<Content> & recommended) {

    // Nao conta tentativas que nao geraram nenhum resultado.
    if (recommended.get_head() == nullptr) return;

    total_recommendations++;

    Node<Content> * node = recommended.get_head();
    while (node != nullptr) {

        int type_index = static_cast<int>(node->info.get_type());
        if (type_index >= 0 && type_index < TYPE_COUNT) type_recommend_count[type_index]++;

        int genre_index = static_cast<int>(node->info.get_genre());
        if (genre_index >= 0 && genre_index < GENRE_COUNT) genre_recommend_count[genre_index]++;

        node = node->next;
    }
}

Type StatisticsService::get_most_recommended_type() const {
    int best = 0;
    for (int i = 1; i < TYPE_COUNT; i++) {
        if (type_recommend_count[i] > type_recommend_count[best]) best = i;
    }
    return static_cast<Type>(best);
}

Type StatisticsService::get_least_recommended_type() const {
    int worst = 0;
    for (int i = 1; i < TYPE_COUNT; i++) {
        if (type_recommend_count[i] < type_recommend_count[worst]) worst = i;
    }
    return static_cast<Type>(worst);
}

Genre::Value StatisticsService::get_most_recommended_genre() const {
    int best = 1; // indice 0 nao e usado (nao existe Genre::Value == 0)
    for (int i = 2; i < GENRE_COUNT; i++) {
        if (genre_recommend_count[i] > genre_recommend_count[best]) best = i;
    }
    return static_cast<Genre::Value>(best);
}

Genre::Value StatisticsService::get_least_recommended_genre() const {
    int worst = 1;
    for (int i = 2; i < GENRE_COUNT; i++) {
        if (genre_recommend_count[i] < genre_recommend_count[worst]) worst = i;
    }
    return static_cast<Genre::Value>(worst);
}

long StatisticsService::get_total_views(const DoublyLinkedList<Content> & contents) {
    long total = 0;
    Node<Content> * node = contents.get_head();
    while (node != nullptr) {
        total += node->info.get_views();
        node = node->next;
    }
    return total;
}

Content * StatisticsService::get_most_watched_by_type(const DoublyLinkedList<Content> & contents, Type type) {
    Content * best = nullptr;
    Node<Content> * node = contents.get_head();
    while (node != nullptr) {
        if (node->info.get_type() == type) {
            if (best == nullptr || node->info.get_views() > best->get_views()) best = &node->info;
        }
        node = node->next;
    }
    return best;
}

Content * StatisticsService::get_most_watched_by_genre(const DoublyLinkedList<Content> & contents, Genre::Value genre) {
    Content * best = nullptr;
    Node<Content> * node = contents.get_head();
    while (node != nullptr) {
        if (node->info.get_genre() == genre) {
            if (best == nullptr || node->info.get_views() > best->get_views()) best = &node->info;
        }
        node = node->next;
    }
    return best;
}