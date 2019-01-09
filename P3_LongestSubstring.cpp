//problem 3
//Given a string, find the length of the longest substring without repeating characters.
//给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。

#include <stdio.h>
#include <string>
#include <map>
using namespace std;

class Solution
{
  public:
    int lengthOfLongestSubstring(string s)
    {
        if (s.size() == 0)
            return 0;
        char *p = &s[0], *q = &s[0];
        map<char, int> charMap;
        int length = 1;
        for (int i = 0; *q != '\0'; ++i)
        {
            q = &s[i];
            if (*q == '\0' || charMap.find(*q) != charMap.end())
            {
                length = (q - p) > length ? (q - p) : length;
                p = &s[charMap[*q] + 1] > p ? &s[charMap[*q] + 1] : p;
            }
            charMap[*q] = i;
        }
        return length;
    }
};

int main()
{
    while (1)
    {
        printf("enter a string:");
        string str;
        str.resize(1024);
        scanf("%s", &str[0]);
        puts(str.c_str());

        Solution s;
        int result = s.lengthOfLongestSubstring(str);
        printf("\nlength Of longest substring without repeating characters: %d", result);

        printf("\n\nenter 0 to stop, otherwise continue\n");
        int stop = 0;
        scanf("%d", &stop);

        if (!stop)
            break;
    }
    return 0;
}
