class Solution 
{
public:
    int lengthOfLongestSubstring(string s) 
    {
        int left = 0, right = 0, result = 0;
        
        int n = s.size();
        
        set<char> charset;
        
        while(right < n) {
            if(charset.count(s[right]) == 0) {
                //insert
                charset.insert(s[right]);
                right++;
                result = max(result, right-left);
            }
            else {
                //if already exists, left++
                charset.erase(s[left]);
                left++;
            }
        }
        
        return result;
    }
};