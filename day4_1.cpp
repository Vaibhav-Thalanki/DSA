class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int cnt = 0, cnt2 = cnt, j;
        for (int i = 0, n = 0; i < nums.size() - 1 && n < nums.size(); i++, n++)
        {
            if (cnt2 == cnt)
            {
                if (nums[i] == 0)
                {
                    j = 0;
                    for (j = i; j < nums.size() - 1 - cnt; j++)
                    {

                        nums[j] = nums[j + 1];
                    }
                    cnt++;
                    nums[j] = 0;
                    i--;
                }
            }
            else
            {
                if (nums[i] == 0)
                {

                    j = 0;
                    for (j = i; j < nums.size() - 1 - cnt; j++)
                    {
                        nums[j] = nums[j + 1];
                    }
                    cnt2 = cnt;
                    cnt++;
                    nums[j] = 0;
                    i--;
                    continue;
                }
                cnt2 = cnt;
            }
        }
    }
};

// class Solution {
// public:
//     void moveZeroes(vector<int>& nums) {
//         for(int i=0,n=0;i<nums.size()&&n<nums.size();i++,n++){
//             if(nums[i]==0){
//                 nums.push_back(0);
//                 nums.erase(next(nums.begin(),i));
//                 i--;
//             }
//         }

//     }
// };