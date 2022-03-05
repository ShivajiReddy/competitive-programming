class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        
        if(intervals.size() <= 1)
            return intervals;
        
        sort(intervals.begin(), intervals.end());
        
        int j = 0;
        ans.push_back(intervals[0]);
        
        for(int i = 1; i < intervals.size(); i++)
        {
            //if [x, ] > [, y] of previous
            
            if(ans[j][1]>=intervals[i][0]) ans[j][1]=max(ans[j][1],intervals[i][1]);
            //else push and increment
            else
            {
                j++;
                ans.push_back(intervals[i]);
            }
        }  
        return ans;
    }
};