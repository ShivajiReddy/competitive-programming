class Solution 
{
public:
    void setZeroes(vector<vector<int>>& a) 
    {
        int m = a.size();
        int n = a[0].size();
        
        int first_row = 1, first_col = 1;
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(a[i][j] == 0)
                {
                    if(i == 0) 
                        first_row = 0;
                    if(j == 0)
                        first_col = 0;
                    a[0][j] = 0;
                    a[i][0] = 0;
                }
            }
        }
        /*
        0 1 2 0
        3 4 5 2
        1 3 1 5
        
        
        */
        for(int i = 1; i < m; i++)
        {
            for(int j = 1; j < n; j++)
            {
                if(a[i][0] == 0 || a[0][j] == 0)
                {
                    a[i][j] = 0;   
                }
            }
            
        }
        if(first_row == 0)
            for(int i = 0; i < n; i++)
                a[0][i] =0;
        
        if(first_col == 0)
            for(int i = 0; i < m; i++)
                a[i][0] = 0;
        
        //return &a;
    }
};