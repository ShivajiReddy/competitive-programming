//https://leetcode.com/problems/word-search/
class Solution {
public:
    bool dfs(vector<vector<char>>&board, int i, int j, string word, int count)
    {
        if(count == word.size())
            return true;
        
        if(i < 0 || i >= board.size() ||
           j < 0 || j >= board[0].size() || 
           board[i][j] != word[count])
        {
            return false;
        }
        
        char temp = board[i][j];
        //to mark as visited so that it won't be compared in later stages
        board[i][j] = ' ';
        
        if(dfs(board, i-1, j, word, count+1) ||
           dfs(board, i+1, j, word, count+1) ||
           dfs(board, i, j-1, word, count+1) ||
           dfs(board, i, j+1, word, count+1))
        {
            return true;
        }
        
        board[i][j] = temp;
        
        return false;
        
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        
        if(word == "")
            return false;
        
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(dfs(board, i, j, word, 0))
                    return true;
            }
        }
        
        return false;
    }
};