#include<iostream>
#include<string>
using namespace std;
class Solution
{
public:
    int conversion(char s)
    {
        switch (s)
        {
        case 'I':
            return 1;
        case 'V':
            return 5;
        case 'X':
            return 10;
        case 'L':
            return 50;
        case 'C':
            return 100;
        case 'D':
            return 500;
        case 'M':
            return 1000;
        }
        return 0;
    }
    int exceptions(char a, char b)
    {
        int aa = conversion(a);
        int bb = conversion(b);
        return (bb - aa);
    }
    int exceptionChecker(char aa, char bb)
    {
        char hierarchy[] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
        int i = 0;
        if (aa != 'I' && aa != 'X' && aa != 'C')
            return 0;
        for (i = 0; i < sizeof(hierarchy); i++)
        {
            if (hierarchy[i] == aa)
            {
                break;
            }
        }
        if (bb == hierarchy[i + 1] || bb == hierarchy[i + 2])
            return 1;
        else
            return 0;
    }
    int romanToInt(string s)
    {
        int n = 0, sum = 0;
        while (n < s.length())
        {
            string x = "";
            if (n + 1 < s.length())
            {
                x += s[n];
                x += s[n + 1];
            }
            else
            {
                x += s[n];
            }
            if (exceptionChecker(x[0], x[1]))
            {
                n += 2;
                sum += exceptions(x[0], x[1]);
            }
            else
            {
                n++;
                sum += conversion(x[0]);
            }
        }
        return sum;
    }
};
int main()
{
    string s;
    cout<<"enter a roman numeral: ";
    cin>>s;
    Solution ss;
    cout<<ss.romanToInt(s);

}