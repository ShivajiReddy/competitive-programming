class Solution {
public:
    string intToRoman(int num) {
        string result;
        
        vector<int> numbers = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        vector<string> roman = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

        
        for(int i = 0; i < numbers.size(); i++) {
            if(num/numbers[i] > 0) {
                int temp = num/numbers[i];
                while(temp--) {
                    result = result + roman[i];
                }
                num = num%numbers[i];
            }  
        }
        
        return result;
        
    }
};