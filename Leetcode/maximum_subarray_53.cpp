class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int current_sum = 0, best_sum = INT_MIN;
        for(int num : nums) {
            //add num or not
            current_sum = current_sum + num;
            best_sum = max(current_sum, best_sum);
            if(current_sum < 0)
                current_sum = 0;
        }
        
        return best_sum;
    }   
    
};