class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> v(nums.size(), 1);
        
        v[0] = 1;
        
        for(int i = 1; i < nums.size(); i++)
        {
            v[i] = v[i-1] * nums[i-1];
        }
        
        int rightp = 1;
        for(int i = nums.size() - 1; i >= 0; i--)
        {
            v[i] = v[i] * rightp;
            rightp *= nums[i];
        }
        return v;
    }
};