#include <algorithm>
#include <filesystem>
#include <iostream>
#include <vector>

namespace fs = std::filesystem;

class TraverseDirectory
{
private:
    fs::path root_path;

    void ExploreHelper(const fs::path & current_path, int & total_size,
                       int & total_files);

public:
    TraverseDirectory(const fs::path & rp) : root_path(rp) {}
    ~TraverseDirectory() {}

    void Explore();
};

void TraverseDirectory::ExploreHelper(const fs::path & current_path,
                                      int & total_size, int & total_files)
{
    std::vector<fs::directory_entry> entires;

    for (const fs::directory_entry & entry :
         fs::directory_iterator(current_path))
        entires.push_back(entry);

    std::sort(entires.begin(), entires.end(),
              [](const fs::directory_entry & a, const fs::directory_entry & b) {
                  return a.is_regular_file() > b.is_regular_file();
              });

    for (const fs::directory_entry & entry : entires)
        if (fs::is_regular_file(entry))
        {
            std::cout << (current_path / entry).string() << " ("
                      << fs::file_size(entry) << " KB)\n";
            total_files++;
            total_size += fs::file_size(entry);
        }
        else
            ExploreHelper(entry, total_size, total_files);

    return;
}

void TraverseDirectory::Explore()
{
    int total_size = 0, total_files = 0;
    ExploreHelper(root_path, total_size, total_files);

    std::cout << "\nTotal files: " << total_files
              << "\nTotal size: " << total_size << '\n';

    return;
}

int main(void)
{
    fs::path path;

    while (std::cin >> path)
    {
        TraverseDirectory td(path);
        td.Explore();
    }

    return 0;
}
