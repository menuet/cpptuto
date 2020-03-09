
#include <holdall/database.hpp>
#include <iostream>

namespace mdb = musify::database;
namespace fs = std::filesystem;

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        std::cerr << "Please, provide the database file path as an argument\n";
        return -1;
    }

    fs::path database_file_path{argv[1]};
    if (database_file_path.is_relative())
        database_file_path = fs::current_path() / database_file_path;

    std::cout << "Loading database file " << database_file_path << "...\n";

    mdb::Database database;
    const auto result = mdb::load_database(database_file_path, database);
    switch (result)
    {
    case mdb::LoadingResult::FileNotFound:
        std::cerr << "The database file does not exist\n";
        break;
    case mdb::LoadingResult::FileNotReadable:
        std::cerr << "The database file is not readable\n";
        break;
    case mdb::LoadingResult::UnknownLineType:
        std::cerr << "The database file contains a line of unknow type\n";
        break;
    case mdb::LoadingResult::IncompleteLine:
        std::cerr << "The database file contains an incomplete line\n";
        break;
    case mdb::LoadingResult::DuplicateArtist:
        std::cerr << "The database file contains a duplicate artist\n";
        break;
    case mdb::LoadingResult::UnknownArtist:
        std::cerr << "The database file refers to an unknown artist\n";
        break;
    case mdb::LoadingResult::Ok:
        std::cout << "Database file's contents:\n";
        mdb::display_database(database);
        break;
    }

    std::cout << "Searching for artist 'Oasis'...\n";
    const mdb::Artist* oasis = mdb::find_artist(database, "Oasis");
    if (oasis)
        mdb::display_artist(*oasis);
    else
        std::cout << "Unknown artist\n";

    return static_cast<int>(result);
}
