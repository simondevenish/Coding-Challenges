#include <vector>
#include <limits.h>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
          // Ensure nums1 is the shorter array, this simplifies the binary search steps.
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int m = (int)nums1.size();
        int n = (int)nums2.size();
        int total = m + n;
        int half = (total + 1) / 2; 

        int left = 0;
        int right = m;

        while (left <= right) {
            int i = (left + right) / 2;       // i is the partition in nums1
            int j = half - i;                 // j is the partition in nums2
            
            int nums1_left_max = (i == 0) ? INT_MIN : nums1[i - 1];
            int nums1_right_min = (i == m) ? INT_MAX : nums1[i];

            int nums2_left_max = (j == 0) ? INT_MIN : nums2[j - 1];
            int nums2_right_min = (j == n) ? INT_MAX : nums2[j];

            // Check if partitions are correct
            if (nums1_left_max <= nums2_right_min && nums2_left_max <= nums1_right_min) {
                // Correct partition
                if (total % 2 == 0) {
                    // Even length
                    return (double)(max(nums1_left_max, nums2_left_max) + min(nums1_right_min, nums2_right_min)) / 2;
                } else {
                    // Odd length
                    return (double)max(nums1_left_max, nums2_left_max);
                }
            } else if (nums1_left_max > nums2_right_min) {
                // Move partition i to the left
                right = i - 1;
            } else {
                // Move partition i to the right
                left = i + 1;
            }
        }

        return 0.0;
    }
};