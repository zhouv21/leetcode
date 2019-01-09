//problem 1
//Given an array of integers, return indices of the two numbers such that they add up to a specific target.
//给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。

#include <stdio.h>
#include <vector>
#include <map>
using namespace std;

class Solution 
{
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        vector<int> result;
        map<int, int> numsMap;
        for(int i=0; i < nums.size(); ++i)
        {
            int &num = nums[i];
            int remainder = target - num;
            if(numsMap.find(remainder) != numsMap.end())
            {
                result.push_back(numsMap[remainder]);
                result.push_back(i);
                break;
            }
            numsMap[num] = i;
        }

        return result;
    }
};

int main()
{
    while(1)
    {
        printf("count of nums:");
        int count = 0;
        scanf("%d", &count);
        printf("nums:");
        vector<int> nums(count, 0);
        for(int i = 0; i < count; ++i)
        {
            scanf("%d", &nums[i]);
        }
        printf("target:");
        int target = 0;
        scanf("%d", &target);
        Solution s;
        vector<int> result = s.twoSum(nums, target);
        if(result.size() == 0)
            printf("no sum of two nums equals the target");
        else
            printf("indices: %d, %d", result[0], result[1]);

        printf("\n\nenter 0 to stop, otherwise continue\n");
        int stop = 0;
        scanf("%d", &stop);

        if(!stop) break;
    }

    return 0;
}