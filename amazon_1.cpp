int findCycles(vector<int> task)
{
    map<int, int> freq;
    // finding frequency of all numbers occuring
    for (int i = 0; i < task.size(); i++)
    {
        freq[task[i]]++;
    }
    for (auto it = freq.begin(); it != freq.end(); it++)
    {
        while (it->second > 0)
        {
            if (it->second == 1)
                return -1; // because not divisible by 2 or 3
            if (it->second > 3 && it->second != 0)
            {
                it->second -= 3;
                n++;
            }
            if (it->second > 2 && it->second != 0)
            {
                it->second -= 2;
                n++;
            }
        }
    }
    return n;
}