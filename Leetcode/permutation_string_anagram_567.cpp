class Solution {
public:
    bool checkInclusion(string s1, string s) {
        int left = 0, right = 0, m = s1.size(), n = s.size();
        
        vector<int> freq(26,0);
        
        
        for(char c : s1) {
            freq[c-'a']++;
        }
        

        int char_count = m;
        while(right < n) {
            //expand window if current character can be placed in permutation
            if(freq[s[right++]-'a']-- > 0)
            {
                //decrement occurrence by one
                //freq[s[right]-'a']--;
                
                //remaining chars to be found in the window
                char_count--;
                //right++;
            }
            
            if(char_count == 0) 
                return true;
            
            if(right-left== m)
            {
                //move left++. if the char is in s1 then freq will be >= zero, 
                //so increment char_count, else only increase its freq -1 to 0
                if(freq[s[left++]-'a']++ >= 0) {
                    char_count++;
                }
            }
        }
        return false;
    }
};