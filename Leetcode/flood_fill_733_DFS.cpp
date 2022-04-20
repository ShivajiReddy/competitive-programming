class Solution {
    vector<pair<int,int>> directions { {1,0}, {0,1}, {-1,0}, {0,-1} };
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int m = image.size();
        int n = image[0].size();
        
        //bfs instead of DFS to prevent stack overflow
        
        //base case
        if(m == 0 || n == 0 || sr < 0 || sr >= m || sc < 0 || sc >= n )
            return image;
        
        int cur_color = image[sr][sc];
        
        //if same then no need to proceed
        if(cur_color == newColor)
            return image;
        
        queue<pair<int,int>> q;
        image[sr][sc] = newColor;
        
        q.push({sr,sc});
        
        while(!q.empty()) {
            //pop first and push its adjacents
            auto cur = q.front(); q.pop();
            
            //adjacent cells, change push if they are valid and of cur_color
            for(auto dir : directions) {
                int x = cur.first + dir.first;
                int y = cur.second + dir.second;
                
                
                if(x < 0 || y < 0 || x >= m || y >= n) 
                    continue;
                
                if(image[x][y] != cur_color)
                    continue;
                
                image[x][y] = newColor;
                q.push({x,y});
            }  
        }
        return image;    
    }
};