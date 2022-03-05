class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) 
    {
        vector<vector<int>> ans;
             
        for(int i = 0; i < intervals.size(); i++)
        {
            //no overlap, so push and go to next
            if(newInterval[0] > intervals[i][1])
                ans.push_back(intervals[i]);
            
            
            else if(newInterval[1] < intervals[i][0] )
            {
                //new is before 
                ans.push_back(newInterval);
                newInterval = intervals[i];
            }
            else
            {
                newInterval[0] = min(intervals[i][0], newInterval[0]);
                newInterval[1] = max(intervals[i][1], newInterval[1]);
            }
        }
        ans.push_back(newInterval);
        
        return ans;
    }
};