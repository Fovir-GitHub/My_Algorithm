#include <filesystem>
#include <iostream>

namespace fs = std::filesystem;

int getDirectorySize(const fs::path & path);

int main(void) {
    fs::path path;

    while (std::cin >> path)
        std::cout << "Size: " << getDirectorySize(path) << " B\n";

    return 0;
}

int getDirectorySize(const fs::path & path) {
    using Entry = fs::directory_entry;

    int result = 0;

    for (const Entry & entry : fs::directory_iterator(path))
        if (entry.is_regular_file())
            result += entry.file_size();
        else
            result += getDirectorySize(entry);

    return result;
}
