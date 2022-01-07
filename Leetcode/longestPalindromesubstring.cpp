class Solution {
public:
    string longestPalindrome(string s) {
        if(s.empty()) 
            return "";
        
        int start = 0;
        int end = 0;
        
        for(int i = 0; i < s.size(); i++) 
        {
            int len1 = expandAroundCenter(s, i, i);
            int len2 = expandAroundCenter(s, i, i+1);
            int len = max(len1, len2);
            if(len > (end - start)) 
            {  
                start = i - ((len-1)/2);
                end = i + (len/2);
            }   
        }
        return s.substr(start, end+1);
    }
    //racecar
    //aabbaa
    int expandAroundCenter(string s, int left, int right) {
        
        while(left >= 0 && right < s.length() &&                            s[left]==s[right]) 
        {
            left--;
            right++;
        }
        //returns the maximum length substring from the index of expansion
        return right-left-1;
    }
};