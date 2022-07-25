class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        vector<int> a;
        int low = 0, high = numbers.size() - 1, sum = 0;
        while (low < high)
        {
            sum = numbers[low] + numbers[high];
            if (sum == target)
            {
                a.push_back(low + 1);
                a.push_back(high + 1);
                break;
            }
            else if (sum > target)
            {
                high--;
            }
            else
                low++;
        }
        return a;
    }
};