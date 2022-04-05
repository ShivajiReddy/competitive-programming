class Solution {
public:
    int getIndex(vector<int> &nums, int left, int right)
    {
        while(left < right) 
        {
            int middle = left + (right - left)/2;
            if(nums[middle] > nums[right])
            {
                left = middle + 1; 
            }
            else
            {
                right = middle;
            }
        }
        
        return left;
    }
    
    int search(vector<int>& nums, int target) {
        
        if(nums.size() == 0)
            return -1;
        
        int left = 0, right = nums.size()-1;
        
        int pivot = getIndex(nums, left, right);
        
        if(nums[pivot] <= target && target <= nums[right])
        {
            left = pivot;
        }
        else 
        {
            right = pivot;
        }
        
        while(left < right)
        {
            int middle = left + (right - left)/2;
            if(nums[middle] == target)
            {
                return middle;
            }
            else if(target < nums[middle])
            {
                right = middle - 1;
            }
            else
            {
                left = middle + 1;
            }   
        }
        return -1;
    }
};