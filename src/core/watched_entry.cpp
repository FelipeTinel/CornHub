#include "core/watched_entry.hpp"

WatchedEntry::WatchedEntry():
    content_id(0), title(""), type(Type::MOVIE), genre(Genre::ACTION), times_watched(0) {}

WatchedEntry::WatchedEntry(int content_id, std::string title, Type type, Genre::Value genre, long times_watched):
    content_id(content_id), title(title), type(type), genre(genre), times_watched(times_watched) {}

int WatchedEntry::get_id() const { return content_id; }
std::string WatchedEntry::get_title() const { return title; }
Type WatchedEntry::get_type() const { return type; }
Genre::Value WatchedEntry::get_genre() const { return genre; }
long WatchedEntry::get_times_watched() const { return times_watched; }

void WatchedEntry::add_watch() { times_watched++; }

bool watched_desc(const WatchedEntry &a, const WatchedEntry &b) {
    return a.get_times_watched() > b.get_times_watched();
}