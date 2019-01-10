//problem 5
//Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.
//给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。

#include <iostream>
#include <string>
using namespace std;

class Solution
{
  public:
    string longestPalindrome(string s)
    {
        if (s.size() == 0)
            return "";
        int start = 0, length = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            int left = i, right = i;
            findPalindrome(s, left, right);
            if ((right - left + 1) > length)
            {
                length = right - left + 1;
                start = left;
            }

            if (i > 0 && s[i - 1] == s[i])
            {
                left = i - 1;
                right = i;
                findPalindrome(s, left, right);
                if ((right - left + 1) > length)
                {
                    length = right - left + 1;
                    start = left;
                }
            }
        }
        return s.substr(start, length);
    }

    string longestPalindrome1(string s)
    {
        if (s.size() == 0)
            return "";
        int start = 0, length = 1;
        bool p[1000][1000];
        for (int i = 0; i < s.size(); ++i)
        {
            p[i][i] = true;
            if (i < s.size() - 1 && s[i] == s[i + 1])
            {
                p[i][i + 1] = true;
                length = 2;
                start = i;
            }
        }
        for (int len = 3; len <= s.size(); ++len)
        {
            for (int i = 0; i <= s.size() - len; ++i)
            {
                int j = i + len - 1;
                if (p[i + 1][j - 1] && s[i] == s[j])
                {
                    p[i][j] = true;
                    length = len;
                    start = i;
                }
            }
        }

        return s.substr(start, length);
    }

  private:
    void findPalindrome(const string &s, int &left, int &right)
    {
        while (left > 0 && right < s.size() - 1)
        {
            if (s[left - 1] == s[right + 1])
            {
                left--;
                right++;
            }
            else
                break;
        }
    }
};

int main()
{
    while (1)
    {
        cout << "input a string: ";
        string str;
        cin >> str;

        Solution s;
        string result = s.longestPalindrome1(str);

        cout << "\nthe longest palindromic substring: " << result << endl;

        cout << "\nenter 0 to stop, otherwise continue" << endl;
        int stop = 0;
        cin >> stop;

        if (!stop)
            break;
    }
    return 0;
}