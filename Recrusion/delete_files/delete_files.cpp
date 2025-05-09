#include <algorithm>
#include <filesystem>
#include <iostream>
#include <string>
#include <vector>

namespace fs = std::filesystem;

class DeleteFiles
{
private:
    fs::path root_path;
    int      ident_count;

    void DeleteHelper(const fs::path & current_path);

public:
    DeleteFiles(const fs::path & rp) : root_path(rp), ident_count(0) {}
    ~DeleteFiles() {}

    void operator()();
};

void DeleteFiles::DeleteHelper(const fs::path & current_path)
{
    using Entry = fs::directory_entry;

    std::vector<Entry> entries;
    int                total_file_size      = 0;
    bool               finish_regular_files = false;

    for (const Entry & entry : fs::directory_iterator(current_path))
        entries.push_back(entry);

    std::sort(entries.begin(), entries.end(),
              [](const Entry & a, const Entry & b) {
                  return a.is_regular_file() > b.is_regular_file();
              });

    for (const Entry & entry : entries)
        if (entry.is_regular_file())
        {
            total_file_size += entry.file_size();
            // fs::remove(entry);
        }
        else
        {
            if (!finish_regular_files)
            {
                finish_regular_files = true;
                std::cout << std::string(ident_count, '\t')
                          << current_path.filename().string() << ": "
                          << total_file_size << " B\n";
            }

            ident_count++;
            DeleteHelper(entry);
            ident_count--;
        }

    if (!finish_regular_files)
    {
        finish_regular_files = true;
        std::cout << std::string(ident_count, '\t')
                  << current_path.filename().string() << ": " << total_file_size
                  << " B\n";
    }

    return;
}

void DeleteFiles::operator()()
{
    ident_count = 0;
    DeleteHelper(root_path);

    return;
}

int main(void)
{
    fs::path path;

    while (std::cin >> path)
    {
        DeleteFiles temp(path);
        temp();
    }

    return 0;
}