class Solution {
public:
    int search(vector<int>& nums, int target) {
        return binary_search(nums, target, 0, nums.size() - 1);
    }
    
    int binary_search(vector<int> &nums, int target, int left, int right) {
        if(left > right) {
            return -1;
        }
        else {
            int mid = (right + left)/2;
            if(nums[mid] == target)
                return mid;
            if(nums[mid] > target) {
                return binary_search(nums, target, left, mid-1);
            }
            else {
                return binary_search(nums, target, mid+1, right);
            }
        }
        
    }
};