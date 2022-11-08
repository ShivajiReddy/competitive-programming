class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        //[1,3,4,2,2]
        //[0,1,2,3,4]
        //-1,-3,-4,-2,already -2
        int ans;
        for(int i = 0; i < nums.size(); i++) {
            int index = abs(nums[i]) - 1;
            if(nums[index] < 0) {
                ans = abs(nums[i]);
                break;
            }
            else 
                nums[index] *= -1;
        }
        
        return ans;
        
        //[3,1,3,4,2]
        //[0,1,2,3,4]
        /*[3,1,-3,4,2]
          [-3,1,-3,4,2]
          [-3,1,-3,4,2]
        
        */
    }
};