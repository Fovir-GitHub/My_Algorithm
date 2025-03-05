#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using std::string;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        std::unordered_map<char, int> hash; /* character - index */
        int                           left                  = 0;
        int                           max_sub_stirng_length = 0;
        int                           length                = s.length();

        for (int right = 0; right < length; right++)
        {
            // update left
            if (hash.count(s[right]) && hash[s[right]] >= left)
                left = hash[s[right]] + 1;

            hash[s[right]] = right;
            max_sub_stirng_length =
                std::max(right - left + 1, max_sub_stirng_length);
        }

        return max_sub_stirng_length;
    }
};

int main(void)
{
    string   s = "abcabcbb";
    Solution solution;

    std::cout << solution.lengthOfLongestSubstring(s);

    return 0;
}