class Solution {
public:
    bool isPowerOfFour(int n) {
        //> 0 & only one bits & set bit is in odd indexes 
        //0x55555555 is 1010101010101010101010101010101 in binary with a length of 32. 
        return n > 0 && ((n & (n - 1)) == 0 && (n & 0x55555555));
    }
};