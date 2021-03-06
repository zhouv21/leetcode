//problem 8
//Implement atoi which converts a string to an integer.
//The function first discards as many whitespace characters as necessary until the first non-whitespace character is found.
//Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible,
//and interprets them as a numerical value.
//The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.
//If the first sequence of non-whitespace characters in str is not a valid integral number,
//or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.
//If no valid conversion could be performed, a zero value is returned.
//Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−2^31,  2^31 − 1].
//If the numerical value is out of the range of representable values, INT_MAX (2^31 − 1) or INT_MIN (−2^31) is returned.
//请你来实现一个 atoi 函数，使其能将字符串转换成整数。
//首先，该函数会根据需要丢弃无用的开头空格字符，直到寻找到第一个非空格的字符为止。
//当我们寻找到的第一个非空字符为正或者负号时，则将该符号与之后面尽可能多的连续数字组合起来，作为该整数的正负号；假如第一个非空字符是数字，则直接将其与之后连续的数字字符组合起来，形成整数。
//该字符串除了有效的整数部分之后也可能会存在多余的字符，这些字符可以被忽略，它们对于函数不应该造成影响。
//假如该字符串中的第一个非空格字符不是一个有效整数字符、字符串为空或字符串仅包含空白字符时，则你的函数不需要进行转换。在任何情况下，若函数不能进行有效的转换时，请返回 0。
//假设我们的环境只能存储 32 位大小的有符号整数，那么其数值范围为 [−2^31,  2^31 − 1]。如果数值超过这个范围，返回  INT_MAX (2^31 − 1) 或 INT_MIN (−2^31) 。

#include <iostream>
#include <string>
using namespace std;

class Solution
{
  public:
    int myAtoi(string str)
    {
        long long result = 0;
        int symbol = 1;
        bool readNumber = false;
        for (char c : str)
        {
            if (c == ' ')
            {
                if (readNumber)
                    break;
                else
                    continue;
            }
            if (c == '+' || c == '-')
            {
                if (readNumber)
                    break;
                else
                {
                    readNumber = true;
                    symbol = c == '-' ? -1 : 1;
                    continue;
                }
            }
            if (c >= '0' && c <= '9')
            {
                result = result * 10 + (c - '0');
                if (result * symbol > __INT_MAX__)
                    return __INT_MAX__;
                if (result * symbol < (-__INT_MAX__ - 1))
                    return -__INT_MAX__ - 1;
                readNumber = true;
            }
            else
                break;
        }
        return (int)result * symbol;
    }
};

int main()
{
    while (1)
    {
        cout << "input a string: ";
        string str;
        getline(cin, str);

        Solution s;
        int result = s.myAtoi(str);

        cout << "\nthe integer: " << result << endl;

        cout << "\nenter 0 to stop, otherwise continue" << endl;
        int stop = 0;
        cin >> stop;
        cin.ignore();

        if (!stop)
            break;
    }
    return 0;
}