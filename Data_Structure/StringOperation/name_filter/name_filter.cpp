#include <cctype>
#include <iostream>
#include <sstream>
#include <string>

int main(void) {
    std::string input, name;

    std::getline(std::cin, input);

    std::istringstream iss(input);

    while (std::getline(iss, name, ',')) {
        if (std::tolower(name.front()) == std::tolower(name.back()))
            std::cout << name << '\n';

        while (!isgraph(iss.peek()) && !iss.eof())
            iss.get();
    }

    return 0;
}