#include <algorithm>
#include <cctype>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

bool isCleanString(std::string s);

int main(void) {
    std::freopen("./input.in", "r", stdin);

    std::string input;

    while (std::getline(std::cin, input))
        std::cout << (isCleanString(input) ? "Clean" : "Flagged") << '\n';

    return 0;
}

bool isCleanString(std::string s) {
    const static std::unordered_map<char, char> character_map = {
        {'@', 'a'},
        {'3', 'e'},
    };

    const static std::vector<std::string> bad_words = {"bad", "hate", "ugly"};
    std::string word;

    for (char & ch : s)
        if (character_map.count(ch))
            ch = character_map.at(ch);

    std::transform(s.begin(), s.end(), s.begin(),
                   [](char ch) { return std::tolower(ch); });

    s.erase(
        std::remove_if(s.begin(), s.end(),
                       [](char ch) { return !std::isalpha(ch) && ch != ' '; }),
        s.end());

    std::istringstream iss(s);
    while (iss >> word)
        for (const std::string & bword : bad_words)
            if (bword == word)
                return false;

    return true;
}
