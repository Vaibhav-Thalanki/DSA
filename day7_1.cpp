class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        vector<char> window;
        vector<char>::iterator it;
        int low = 0, high = -1, max = 0;
        while (high != s.size() - 1)
        {
            high++;
            it = find(window.begin(), window.end(), s[high]);
            if (it == window.end())
            {
                window.push_back(s[high]);
            }
            else
            {
                low = it - window.begin() + 1;
                window.erase(window.begin(), window.begin() + low);
                window.push_back(s[high]);
            }
            // for(int i=0;i<window.size();i++){
            //    cout<<window[i]<<" ";
            //}
            // cout<<endl;
            if (max < window.size())
                max = window.size();
        }
        return max;
    }
};