class Solution {
public:
    int longestPalindrome(string s) {
        vector <int> freq(128, 0);
        for(char c : s) {
            freq[c]++;
        }
        
        int odd_freq = 0;
        
        for(int i : freq) {
            if(i%2 == 1) {
                odd_freq++;
            }
        }
        
        return s.size() - odd_freq + (odd_freq > 0);
    }
};