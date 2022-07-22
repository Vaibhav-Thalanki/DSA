#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        if (nums.size() == 1 && target != *(nums.begin()))
        {
            return -1;
        }
        int mid = nums[nums.size() / 2];
        if (mid == target)
            return nums.size() / 2;
        else if (mid < target)
        {
            vector<int> temp(nums.begin() + nums.size() / 2, nums.end());
            if (search(temp, target) == -1)
                return -1;
            return nums.size() / 2 + search(temp, target);
        }
        else
        {
            vector<int> temp(nums.begin(), nums.begin() + nums.size() / 2);
            if (search(temp, target) == -1)
                return -1;
            return search(temp, target);
        }
    }
};
