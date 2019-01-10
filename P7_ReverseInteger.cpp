//problem 7
//Given a 32-bit signed integer, reverse digits of an integer.
//Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−2^31,  2^31 − 1].
//For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.
//给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。
//假设我们的环境只能存储得下 32 位的有符号整数，则其数值范围为 [−2^31,  2^31 − 1]。请根据这个假设，如果反转后整数溢出那么就返回 0。

#include <stdio.h>

class Solution
{
  public:
    int reverse(int x)
    {
        long long result = 0;
        while (x != 0)
        {
            result = result * 10 + x % 10;
            x = x / 10;
        }
        if (result > __INT_MAX__ || result < (-__INT_MAX__ - 1))
            result = 0;

        return (int)result;
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
        int result = s.reverse(val);

        printf("\n the reverse result: %d", result);

        printf("\n\nenter 0 to stop, otherwise continue\n");
        int stop = 0;
        scanf("%d", &stop);

        if (!stop)
            break;
    }
    return 0;
}