//problem 75
//Given an array with n objects colored red, white or blue, sort them in-place so that objects of the same color are adjacent,
//with the colors in the order red, white and blue.
//Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.
//给定一个包含红色、白色和蓝色，一共 n 个元素的数组，原地对它们进行排序，使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。
//此题中，我们使用整数 0、 1 和 2 分别表示红色、白色和蓝色。

#include <stdio.h>
#include <vector>
using namespace std;

class Solution
{
  public:
    void sortColors(vector<int> &nums)
    {
        int count[3] = {0};
        for (int num : nums)
            count[num]++;
        for (int i = 0; i < nums.size(); ++i)
            nums[i] = i < count[0] ? 0 : (i - count[0]) < count[1] ? 1 : 2;
    }

    void sortColors1(vector<int> &nums)
    {
        int left = 0, right = nums.size() - 1;
        int i = 0;
        while (i <= right)
        {
            if (nums[i] == 0)
            {
                nums[i] = nums[left];
                nums[left++] = 0;
            }
            if (nums[i] == 2)
            {
                nums[i] = nums[right];
                nums[right--] = 2;
                i--;
            }
            i++;
        }
    }

    void sortColors2(vector<int> &nums)
    {
        int i = -1, j = -1, k = -1;
        for (int n = 0; n < nums.size(); ++n)
        {
            if (nums[n] == 0)
            {
                nums[++k] = 2;
                nums[++j] = 1;
                nums[++i] = 0;
            }
            else if (nums[n] == 1)
            {
                nums[++k] = 2;
                nums[++j] = 1;
            }
            else
                nums[++k] = 2;
        }
    }
};

int main()
{
    while (1)
    {
        printf("input colors (press 'enter' to end): ");
        int val = 0;
        vector<int> nums;
        while (scanf("%d", &val))
        {
            nums.push_back(val);
            if (getchar() == '\n')
                break;
        }

        Solution s;
        s.sortColors1(nums);

        printf("\n the sort result: ");
        for (int num : nums)
            printf("%d ", num);

        printf("\n\nenter 0 to stop, otherwise continue\n");
        int stop = 0;
        scanf("%d", &stop);

        if (!stop)
            break;
    }
    return 0;
}