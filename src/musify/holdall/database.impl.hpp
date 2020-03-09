
#pragma once

#include <iostream>
#include <string>
#include <utility>
#include <vector>

namespace musify { namespace database {

    enum class LoadingResult;
    struct Database;
    struct Artist;
    struct Album;
    struct Song;

    std::vector<std::string> ask_new_database_lines(std::ostream& output_stream, std::istream& input_stream);

    std::pair<std::string, std::string> parse_until(const std::string& text, char separator);

    LoadingResult parse_and_load_database_line(const std::string& line, Database& database);

    template <typename T>
    inline void display_music_entities(std::ostream& output_stream, const std::string& entity_type,
                                       const std::vector<T>& music_entities)
    {
        output_stream << "-----------------\n";
        unsigned int entity_index = 0;
        for (const auto& artist : music_entities)
        {
            output_stream << entity_type << " #" << ++entity_index << ": " << artist << "\n";
            output_stream << "-----------------\n";
        }
        output_stream << "--> " << music_entities.size() << " " << entity_type << "s\n";
        output_stream << "-----------------\n";
    }

    LoadingResult parse_and_load_artist(std::string name_year_rating_genre, Database& database);

    LoadingResult parse_and_load_album(std::string name_artistname_date, Database& database);

    LoadingResult parse_and_load_song(std::string name_albumname_artistname_duration, Database& database);

    bool operator==(const Artist& artist1, const Artist& artist2);

    bool operator==(const Album& album1, const Album& album2);

    bool operator==(const Song& song1, const Song& song2);

    std::ostream& operator<<(std::ostream& output_stream, const Artist& artist);

    std::ostream& operator<<(std::ostream& output_stream, const Album& album);

    std::ostream& operator<<(std::ostream& output_stream, const Song& song);

}} // namespace musify::database