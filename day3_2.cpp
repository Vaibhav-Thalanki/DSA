class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        // vector<int> nums2=nums;

        // for(int i=0;i<nums.size();i++){
        //     int g = (i+k)%nums.size();
        //     nums[g]=nums2[i];
        // }
        // for(int i=0;i<nums.size();i++){
        //     cout<<nums[i]<<" ";
        // }e: 24.8 MB, less than 99.25% of C++ onl
        k = k % nums.size();
        for (int i = 0; i < nums.size() / 2; i++)
        {
            int t = nums[i];
            nums[i] = nums[nums.size() - 1 - i];
            nums[nums.size() - 1 - i] = t;
        }
        int i, t, g;
        if (k - 1 >= 0)
            i = k - 1;
        else
            i = 0;
        int j = nums.size() - 1;

        while ((i >= k / 2 && i != 0) || (j >= (k + (nums.size() - k) / 2) && j != 0))
        {
            if (i >= k / 2 && i != 0)
            {
                t = nums[i];
                nums[i] = nums[k - i - 1];
                nums[k - i - 1] = t;
                i--;
            }
            else if (j >= (k + (nums.size() - k) / 2) && j != 0)
            {
                g = nums[j];
                nums[j] = nums[nums.size() - j - 1 + k];
                nums[nums.size() - j - 1 + k] = g;
                j--;
            }
        }
    }
};