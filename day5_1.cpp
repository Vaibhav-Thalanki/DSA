class Solution
{
public:
    void recursive(vector<char> &s, int high, int low)
    {
        if (high > low)
        {
            swap(s[high], s[low]);
            recursive(s, high - 1, low + 1);
        }
        return;
    }
    void reverseString(vector<char> &s)
    {
        recursive(s, s.size() - 1, 0);
    }
};