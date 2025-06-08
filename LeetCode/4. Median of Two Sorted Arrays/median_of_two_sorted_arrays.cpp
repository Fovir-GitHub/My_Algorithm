#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // double findMedianSortedArrays(vector<int> & nums1, vector<int> & nums2)
    // {
    //     nums1.insert(nums1.end(), nums2.begin(), nums2.end());
    //     sort(nums1.begin(), nums1.end());

    //     int vector_size = nums1.size();
    //     if (vector_size % 2 != 0)
    //         return (double) nums1[vector_size / 2];
    //     else
    //     {
    //         vector_size /= 2;
    //         return (double) (nums1[vector_size] + nums1[vector_size - 1]) /
    //         2;
    //     }
    // }

    double findMedianSortedArrays(vector<int> & nums1, vector<int> & nums2) {
        int nums1_size = nums1.size();
        int nums2_size = nums2.size();

        if (nums1_size > nums2_size)
            return findMedianSortedArrays(nums2, nums1);

        int total_size = nums1_size + nums2_size;
        int left_size = (total_size + 1) / 2;

        int low = 0, high = nums1_size;

        while (low <= high) {
            int nums1_middle = (low + high) >> 1;
            int nums2_middle = left_size - nums1_middle;
            int nums1_left = INT_MIN, nums1_right = INT_MAX;
            int nums2_left = INT_MIN, nums2_right = INT_MAX;

            if (nums1_middle < nums1_size)
                nums1_right = nums1[nums1_middle];
            if (nums2_middle < nums2_size)
                nums2_right = nums2[nums2_middle];
            if (nums1_middle - 1 >= 0)
                nums1_left = nums1[nums1_middle - 1];
            if (nums2_middle - 1 >= 0)
                nums2_left = nums2[nums2_middle - 1];

            if (nums1_left <= nums2_right && nums2_left <= nums1_right) {
                if (total_size % 2 == 0)
                    return (double)(max(nums1_left, nums2_left) +
                                    min(nums1_right, nums2_right)) /
                           (double)2;
                else
                    return (double)max(nums1_left, nums2_left);
            } else if (nums1_left > nums2_right)
                high = nums1_middle - 1;
            else
                low = nums1_middle + 1;
        }

        return 0;
    }
};

int main(void) {
    Solution solution;

    vector<int> first = {1, 3};
    vector<int> second = {2, 4};

    cout << (double)solution.findMedianSortedArrays(first, second);

    return 0;
}