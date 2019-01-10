//problem 6
//The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this:
//  P   A   H   N
//  A p L S I I G
//  Y   I   R
//And then read line by line: "PAHNAPLSIIGYIR"
//Write the code that will take a string and make this conversion given a number of rows.
//将一个给定字符串根据给定的行数，以从上往下、从左到右进行 Z 字形排列。
//之后，从左往右逐行读取，产生出一个新的字符串,输出新字符串

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
  public:
    string convert(string s, int numRows)
    {
        if (numRows > 1)
        {
            vector<string> rowString(numRows);
            int row = 0;
            int addRow = -1;
            for (char c : s)
            {
                rowString[row] = rowString[row] + c;
                if (row == 0 || row == numRows - 1)
                    addRow = -addRow;
                row += addRow;
            }
            string result;
            for (string str : rowString)
                result += str;
            return result;
        }
        return s;
    }
};

int main()
{
    while (1)
    {
        cout << "input a string: ";
        string str;
        cin >> str;
        cout << "input num of  rows: ";
        int rows;
        cin >> rows;

        Solution s;
        string result = s.convert(str, rows);

        cout << "\nthe ZigZag conversion result: " << result << endl;

        cout << "\nenter 0 to stop, otherwise continue" << endl;
        int stop = 0;
        cin >> stop;

        if (!stop)
            break;
    }
    return 0;
}
