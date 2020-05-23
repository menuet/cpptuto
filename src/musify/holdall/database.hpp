
#pragma once

#include <filesystem>
#include <string>
#include <vector>

namespace musify { namespace database {

    std::vector<std::string> ask_new_database_lines();

    void save_new_database_lines(const std::filesystem::path& database_file_path,
                                 const std::vector<std::string>& database_lines);

    struct Artist
    {
        std::string name;
        std::string start_year;
        std::string rating;
        std::string genre;
    };

    struct Album
    {
        std::string name;
        std::string artist_name;
        std::string date;
    };

    struct Song
    {
        std::string name;
        std::string album_name;
        std::string artist_name;
        std::string duration;
    };

    struct Database
    {
        std::vector<Artist> artists;
        std::vector<Album> albums;
        std::vector<Song> songs;
    };

    enum class LoadingResult
    {
        Ok = 0,
        FileNotFound,
        FileNotReadable,
        UnknownLineType,
        IncompleteLine,
        DuplicateArtist,
        UnknownArtist,
    };

    LoadingResult load_database(const std::filesystem::path& database_file_path, Database& database);

    void display_database(const Database& database);

    bool contains_artist(const Database& database, const std::string& artist_name);

    const Artist* find_artist(const Database& database, const std::string& artist_name);

    void display_artist(const Artist& artist);

}} // namespace musify::database
