class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        
        while(n) {
            //if last bit is 1
            res += n % 2;
            
            //right shift by 1
            n = n >> 1;
        }
        
        return res;
    }
};