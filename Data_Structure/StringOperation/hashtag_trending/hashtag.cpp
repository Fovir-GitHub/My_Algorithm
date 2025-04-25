#include <algorithm>
#include <cctype>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>

std::string String2Lower(std::string s);

int main(void)
{
    std::string                          input;
    std::string                          token;
    std::unordered_map<std::string, int> trend;

    std::cout << "Please input a string:\n";
    std::getline(std::cin, input);

    std::istringstream iss(input);
    while (iss >> token)
        if (!token.empty() && token.front() == '#')
            trend[String2Lower(token)]++;

    std::unordered_map<std::string, int>::iterator result =
        std::max_element(trend.begin(), trend.end());

    for (const auto & [key, value] : trend) std::cout << key << '\n';

    std::cout << "Most Trending Hashtag: " << result->first << " ("
              << result->second << " times)\n";

    return 0;
}

std::string String2Lower(std::string s)
{
    for (char & ch : s) ch = std::tolower(ch);

    return s;
}
