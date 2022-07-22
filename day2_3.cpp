class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        int low = 0, high = nums.size() - 1, mid = 0;
        while (high > low)
        {
            mid = (low + high) / 2;
            if (target == nums[mid])
                return mid;
            else if (target < nums[mid])
            {
                high = mid;
            }
            else
            {
                low = mid + 1;
            }
        }
        if (nums[high] < target)
            return high + 1;
        return high;
    }
};