class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        int left = 0, right = s.size()-1;
        
        while(left < right) {
            //make sure you reach a valid char before comparing
            while(left < right && !isalnum(s[left])) {
                left++; //not alpha-numeric                 
            }
            
            while(left < right && !isalnum(s[right])) {
                right--;
            }
            
            if(tolower(s[left++]) != tolower(s[right--]))
                return false;
        }
        
        return true;
    }
};