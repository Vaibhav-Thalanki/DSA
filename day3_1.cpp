class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> a,b;
        for(int k=0;k<nums.size();k++){
            if(nums[k]<0){
                a.push_back(-1*(nums[k]));
            }
            else
                b.push_back(nums[k]);
        }
        int i=0,j=a.size()-1;
        vector<int> c;
        while(i<b.size() && j>=0){
            if(a[j]<=b[i]){
                c.push_back(a[j]*a[j]);
                j--;
            }
            else{
                c.push_back(b[i]*b[i]);
                i++;
            }
        }
        while(i<b.size()){
            c.push_back(b[i]*b[i]);
            i++;
        }
        while(j>=0){
            c.push_back(a[j]*a[j]);
            j--;
        }
        return c;
    }
};