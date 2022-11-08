class Solution {
public:
    bool isPowerOfTwo(int n) {
        
        //n & (n-1) EVALUATES to FALSE for power of 2
        
        return (n > 0) ? !(n & (n-1)) : false;
    }
};