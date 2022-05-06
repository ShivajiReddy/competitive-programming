class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size()/2];
        
        //have to implement Boyre_Moore for O(n) O(1)
    }
    
    
};