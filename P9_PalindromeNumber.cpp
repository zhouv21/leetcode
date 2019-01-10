//problem 9
//Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.
//判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。

#include <stdio.h>
#include <string>
using namespace std;

class Solution
{
  public:
    bool isPalindrome(int x)
    {
        if (x < 0 || (x % 10 == 0 && x != 0))
            return false;
        string str = to_string(x);
        int half = str.size() / 2 + 0.5;
        for (int i = 0; i < half; ++i)
        {
            if (str[i] != str[str.size() - i - 1])
                return false;
        }
        return true;
    }

    bool isPalindrome1(int x)
    {
        if (x < 0 || (x % 10 == 0 && x != 0))
            return false;

        int reverseNum = 0;
        while (x > reverseNum)
        {
            reverseNum = reverseNum * 10 + x % 10;
            x /= 10;
        }

        return x == reverseNum || x == reverseNum / 10;
    }
};

int main()
{
    while (1)
    {
        printf("input a integer: ");
        int val = 0;
        scanf("%d", &val);

        Solution s;
        bool result = s.isPalindrome1(val);

        printf("\nis a palindrome: %s", result ? "true" : "false");

        printf("\n\nenter 0 to stop, otherwise continue\n");
        int stop = 0;
        scanf("%d", &stop);

        if (!stop)
            break;
    }
    return 0;
}