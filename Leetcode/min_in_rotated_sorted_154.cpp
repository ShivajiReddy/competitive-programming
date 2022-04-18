class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1, mid = 0;
        int result = INT_MAX;
        
        while(left <= right) {
            //if array[l,r] is already sorted
            if(nums[left] < nums[right]) {
                result = min(result, nums[left]);
                break;
            }
            
            mid = left + (right-left)/2;
            result = min(result, nums[mid]);
            
            if(nums[mid] >= nums[right])
                left = mid + 1;
            else
                right = mid - 1;
        }
        
        return result;
    }
};