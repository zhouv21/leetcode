//problem 4
//There are two sorted arrays nums1 and nums2 of size m and n respectively.
//Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
//You may assume nums1 and nums2 cannot be both empty.
//给定两个大小为 m 和 n 的有序数组 nums1 和 nums2。
//请你找出这两个有序数组的中位数，并且要求算法的时间复杂度为 O(log(m + n))。
//你可以假设 nums1 和 nums2 不会同时为空。

#include <stdio.h>
#include <vector>
using namespace std;

class Solution
{
  public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int m = nums1.size(), n = nums2.size();
        if (m > n)
        {
            vector<int> tmp(nums1);
            nums1 = nums2;
            nums2 = tmp;
        }
        m = nums1.size();
        n = nums2.size();
        int min = 0, max = m;
        while (min <= max)
        {
            int i = (min + max) / 2;
            int j = (m + n + 1) / 2 - i;
            if (i > min && nums1[i - 1] > nums2[j])
                max = i - 1;
            else if (i < max && nums1[i] < nums2[j - 1])
                min = i + 1;
            else
            {
                int maxLeft = 0;
                if (i == 0)
                    maxLeft = nums2[j - 1];
                else if (j == 0)
                    maxLeft = nums1[i - 1];
                else
                    maxLeft = nums1[i - 1] > nums2[j - 1] ? nums1[i - 1] : nums2[j - 1];
                if ((m + n) % 2 == 1)
                    return maxLeft;

                int minRight = 0;
                if (i == m)
                    minRight = nums2[j];
                else if (j == n)
                    minRight = nums1[i];
                else
                    minRight = nums1[i] < nums2[j] ? nums1[i] : nums2[j];
                return (maxLeft + minRight) / 2.0;
            }
        }
        return 0.0;
    }
};

int main()
{
    while (1)
    {
        vector<int> nums1, nums2;
        printf("input the first ordered array:");
        int val = 0;
        while (scanf("%d", &val))
        {
            nums1.push_back(val);
            if (getchar() == '\n')
                break;
        }
        printf("\ninput the second ordered array:");
        while (scanf("%d", &val))
        {
            nums2.push_back(val);
            if (getchar() == '\n')
                break;
        }

        Solution s;
        double result = s.findMedianSortedArrays(nums1, nums2);
        printf("\n the median of two arrays: %lf", result);

        printf("\n\nenter 0 to stop, otherwise continue\n");
        int stop = 0;
        scanf("%d", &stop);

        if (!stop)
            break;
    }
    return 0;
}