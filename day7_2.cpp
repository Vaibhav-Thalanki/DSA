class Solution
{
public:
    bool checkfinal(vector<char> originalv, vector<char> windowv)
    {
        map<char, int> original, window;
        for (int i = 0; i < windowv.size(); i++)
        {
            if (!original[originalv[i]])
            {
                original[originalv[i]] = 1;
            }
            else
            {
                original[originalv[i]]++;
            }
            if (!window[windowv[i]])
            {
                window[windowv[i]] = 1;
            }
            else
            {
                window[windowv[i]]++;
            }
        }
        return window == original;
    }
    bool checkInclusion(string s1, string s2)
    {
        if (s2.size() < s1.size())
        {
            return false;
        }
        vector<char> window;
        vector<char> original;
        map<char, int> originalset, windowset;
        for (int i = 0; i < s1.size(); i++)
        {
            original.push_back(s1[i]);
            originalset[s1[i]]++;
        }
        int start = 0, end = 0;
        vector<char>::iterator it;
        vector<char>::iterator itr;
        int k = s1.length();
        for (int i = 0; i < s2.length(); i++)
        {
            windowset[s2[i]]++;
            if (i >= k)
            {
                windowset[s2[i - k]]--;
                if (windowset[s2[i - k]] == 0)
                    windowset.erase(s2[i - k]);
            }
            if (windowset == originalset)
                return true;
        }
        return false;
        // while (end < s2.size())
        // {
        //     it = find(original.begin(), original.end(), s2[end]);
        //     if (it == original.end() && original.size() == window.size())
        //     {
        //         if(checkfinal(original,window)) return true;
        //     }
        //     else if (it == original.end())
        //     {

        //         window.clear();
        //     }
        //     else
        //     {
        //         window.push_back(s2[end]);
        //         if(window.size() == original.size() && checkfinal(original, window)){

        //             return true;
        //         }
        //         if (window.size() == original.size())
        //         {
        //             window.erase(window.begin(), window.begin() + 1);

        //         }

        //     }

        //     end++;
        // }

        // return false;
    }
};