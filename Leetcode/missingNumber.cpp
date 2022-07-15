class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int v_sum = 0, n = nums.size();
        /*for(int i = 0; i < n; i++) {
            v_sum += nums[i];
        }*/
        
        v_sum = accumulate(nums.begin(), nums.end(), 0);
        return (n*(n+1)/2) - v_sum;
    }
};