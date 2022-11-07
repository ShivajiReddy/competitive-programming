class Solution {
public:
    //Reverse each word; then the whole sentence
    void reverseWord(string &s, int left, int right) {
        while(left < right) {
            swap(s[left++], s[right--]);
        }
    }
    
    string reverseWords(string s) {
        int i = 0, j = 0, left = 0, firstWord = 0;
        while(true) {
            while(i < s.size() && s[i] == ' ') {
                i++;
            }
            if(i == s.size()) 
                break;
            if(firstWord) {
                s[j] = ' ';
                j++;
            }
            firstWord = 1;
            left = j;
            while(i < s.size() && s[i] != ' ') {
                s[j] = s[i];
                j++;
                i++;
            }
            reverseWord(s, left, j-1);
        }
        s.resize(j);
        reverseWord(s, 0, j-1);
        return s;
    }
};
