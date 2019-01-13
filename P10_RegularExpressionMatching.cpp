//problem 10
//Given an input string (s) and a pattern (p), implement regular expression matching with support for '.' and '*'.
//'.' Matches any single character. '*' Matches zero or more of the preceding element.
//The matching should cover the entire input string (not partial).
//给定一个字符串 (s) 和一个字符模式 (p)。实现支持 '.' 和 '*' 的正则表达式匹配。
//'.' 匹配任意单个字符。 '*' 匹配零个或多个前面的元素。
//匹配应该覆盖整个字符串 (s) ，而不是部分字符串。

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
  public:
    bool isMatch(string s, string p)
    {
        if (p.empty())
            return s.empty();
        if (p.size() == 1)
            return (s.size() == 1) && (s[0] == p[0] || p[0] == '.');
        if (p[1] != '*')
        {
            if (s.empty())
                return false;
            return (s[0] == p[0] || p[0] == '.') && isMatch(s.substr(1), p.substr(1));
        }
        //p[1]=='*'
        while (!s.empty() && (s[0] == p[0] || p[0] == '.'))
        {
            if (isMatch(s, p.substr(2)))
                return true;
            s = s.substr(1);
        }
        return isMatch(s, p.substr(2));
    }

    bool isMatch1(string s, string p)
    {
        if (p.empty())
            return s.empty();
        if (p.size() > 1 && p[1] == '*')
        {
            return isMatch(s, p.substr(2)) || (!s.empty() && (s[0] == p[0] || p[0] == '.') && isMatch(s.substr(1), p));
        }
        else
        {
            return !s.empty() && (s[0] == p[0] || p[0] == '.') && isMatch(s.substr(1), p.substr(1));
        }
    }

    bool isMatch2(string s, string p)
    {
        //dp[i][j]: if s[0:i-1] matchs p[0:j-1]
        //dp[0][0]=true;
        //if p[j-1]!='*'
        //  dp[i][j]=dp[i-1][j-1]&&s[i-1]==p[j-1]
        //if p[j-1]=='*' denote p[j - 2] = x
        //  dp[i][j] is true if any of the following is true
        //  1) "x*" repeats 0 time and matches empty: dp[i][j - 2]
        //  2) "x*" repeats >= 1 times and matches "x*x": s[i - 1] == x && dp[i - 1][j]

        int m = s.size(), n = p.size();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;
        for (int i = 0; i <= m; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (p[j - 1] != '*')
                    dp[i][j] = (i > 0) && dp[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
                else
                    dp[i][j] = dp[i][j - 2] || (i > 0 && dp[i - 1][j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.'));
            }
        }

        return dp[m][n];
    }
};

int main()
{
    while (1)
    {
        cout << "input a string: ";
        string str;
        getline(cin, str);

        cout << "\ninput regular expression: ";
        string p;
        getline(cin, p);

        Solution s;
        bool result = s.isMatch(str, p);

        cout << "\nis match: " << (result ? "true" : "false") << endl;

        cout << "\nenter 0 to stop, otherwise continue" << endl;
        int stop = 0;
        cin >> stop;
        cin.ignore();

        if (!stop)
            break;
    }
    return 0;
}