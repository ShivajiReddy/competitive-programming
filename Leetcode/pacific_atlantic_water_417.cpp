class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> res;
        
        int m = heights.size(), n = heights[0].size();
        
        vector<vector<bool>> pacific(m, vector<bool>(n, false));;
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));;
        
        for(int i = 0; i < m; i++) {
            dfs(i, 0, pacific, heights);
            dfs(i, n-1, atlantic, heights);
        }
        
        for(int i = 0; i < n; i++) {
            dfs(0, i, pacific, heights);
            dfs(m-1, i, atlantic, heights);
        }
        
        
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(pacific[i][j] == true && atlantic[i][j] == true) 
                    res.push_back({i,j});
            }
        }
        
        return res;
        
    }
    
    void dfs(int i, int j, vector<vector<bool>>& visited, vector<vector<int>>& heights){
        if(visited[i][j])
            return;
        visited[i][j] = true;
        
        if(i-1 >= 0 && heights[i-1][j] >= heights[i][j])
            dfs(i-1, j, visited, heights);
        if(j-1 >= 0 && heights[i][j-1] >= heights[i][j])
            dfs(i, j-1, visited, heights);
        if(i+1 < heights.size() && heights[i+1][j] >= heights[i][j])
            dfs(i+1, j, visited, heights);
        if(j+1 < heights[0].size() && heights[i][j+1] >= heights[i][j])
            dfs(i, j+1, visited, heights);
        
        
        
    }
};