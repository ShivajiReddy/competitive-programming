class Solution {
public:
    vector<vector<int>> result;
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        add(nums, 0, n-1);
        
        return result;
    }
    
    //add a number to permutaion by fixing one element at left
    void add(vector<int> &nums, int left, int n) {
        if(left >= n) {
            result.push_back(nums);
            return;
        }
        else {
            for(int i = left; i <= n; i++) {
                //put all the elements right side of left in left position 
                //and iterate recurively to next position and repeat
                swap(nums[i], nums[left]);
                add(nums, left+1, n);
                swap(nums[i], nums[left]);
            }
        }
    }
    
    
};