class Solution
{
public:
    string recursive(string s, int high, int low)
    {
        if (high >= low)
        {
            char a = s[high];
            s[high] = s[low];
            s[low] = a;
            s = recursive(s, high - 1, low + 1);
        }
        return s;
    }
    string reverseWords(string s)
    {
        string ss = "";
        int low = 0, high = 0;
        while (high <= s.size())
        {
            if ((s[high] == ' ') || (high == s.size()))
            {
                cout << s.substr(low, high - low) << "\n";
                ss += recursive(s.substr(low, high - low), s.substr(low, high - low).size() - 1, 0);
                if (!(high == s.size()))
                    ss += " ";
                low = high + 1;
            }
            high++;
        }
        return ss;
    }
};