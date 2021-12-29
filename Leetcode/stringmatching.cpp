//https://leetcode.com/problems/implement-strstr/

class Solution {
public:
    int strStr(string haystack, string needle) {
        int h = haystack.size();
        int l = needle.size();
        
        int answer = 0;
        //if(l == 0) return 0;        
        //if(h < l) return -1;
        
        for(int i = 0; i < h-l+1; i++) {
            answer = i;
            int j = 0;
            for(; j < l; j++) {
                if(haystack[i+j] != needle[j])
                {
                    answer = -1;
                    break;
                }
            }
            if(j == l) return answer;
        }
        return -1;
    }
};