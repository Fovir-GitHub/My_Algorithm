#include<vector>
#include<iostream>
#include<unordered_map>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> & nums, int target)
    {
        unordered_map<int, int> hash;   /* value - position */
        int number_size = nums.size();

        for (int i = 0; i < number_size; i++)
        {
            if (hash.count(target - nums[i]))
                return { hash[target - nums[i]],i };
            else
                hash.emplace(nums[i], i);
        }

        return {};
    }
};

int main(void)
{
    std::vector<int> vec;
    Solution solution;
    int target = 0;
    int temp = 0;

    std::cin >> target;
    while (std::cin >> temp)
        vec.push_back(temp);

    std::vector<int> result = solution.twoSum(vec, target);
    for (auto x : result)
        std::cout << x << ' ';

    return 0;
}