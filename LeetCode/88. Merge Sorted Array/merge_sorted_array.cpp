#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void merge(vector<int> & nums1, int m, vector<int> & nums2, int n)
    {
        vector<int> temp(m + n);
        int         num1_index = 0, num2_index = 0;
        int         i = 0;

        while (num1_index < m && num2_index < n)
        {
            if (nums1[num1_index] < nums2[num2_index])
            {
                temp[i] = nums1[num1_index];
                num1_index++;
            }
            else
            {
                temp[i] = nums2[num2_index];
                num2_index++;
            }
            i++;
        }
        while (num1_index < m)
        {
            temp[i] = nums1[num1_index];
            i++;
            num1_index++;
        }
        while (num2_index < n)
        {
            temp[i] = nums2[num2_index];
            i++;
            num2_index++;
        }

        copy(temp.begin(), temp.end(), nums1.begin());
    }
};