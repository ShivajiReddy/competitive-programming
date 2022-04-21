class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0, right = 0, n = s.size();
        int result = 0;
        
        int mostFreqLetter = 0;
        
        vector<int> freq(26,0);
        
        while(right < n) {
            freq[s[right] - 'A']++;
            
            mostFreqLetter = max(mostFreqLetter, freq[s[right]-'A']);
            
            //number of chars to be replaced is window size minus the char               //which need not be replaced
            int lettersToChange = (right - left + 1) - mostFreqLetter;
            
            //if number of different chars in window 
            //that must be replaced is > k then left++
            if(lettersToChange > k) {
                freq[s[left] - 'A']--;
                left++;
            }
            result = max(result, right-left+1);
            right++;
        }
        
        return result;
    }
};