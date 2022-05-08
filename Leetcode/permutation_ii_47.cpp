class Solution {
public:
    vector<vector<int>> result;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        
        sort(nums.begin(), nums.end());
        add(nums, 0, n-1);
        
        return result;
    }
    
    void add(vector<int> nums, int left, int n) {
        if(left == n) {
            result.push_back(nums);
            return;
        }
        else {
            for(int i = left; i <= n; i++) {
                //if duplicate, continue
                if(i != left && nums[i] == nums[left])
                    continue;
                swap(nums[left], nums[i]);
                add(nums, left + 1, n);
                //swap(nums[left], nums[i]);
            }
        }
    
    }
};