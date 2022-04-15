class Solution {
public:
    int jump(vector<int>& nums) {
        /*int jumps = 0;
        int curEnd = 0;
        int maxstep = 0;
        
        for(int i = 0; i < nums.size()-1; i++) {
            curEnd = max(maxstep, i+nums[i]);
            
            if(i == curEnd) {
                jumps++;
                curEnd = maxstep;
            }
        }
        
        return jumps;*/
        
                int n = nums.size();
        
        int jumps = 0;
        int maxReach = 0;
        int currReach = 0;
        
        for(int i=0; i<n-1; i++)
        {
            maxReach = max(maxReach, i+nums[i]);
            
            if(i==currReach)
            {
                jumps++;
                currReach = maxReach;
            }
            
        }
        
        return jumps;
        
    }
};