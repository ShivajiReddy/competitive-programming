class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> freq;
        for(char c: s) {
            freq[c] += 1;
        }
        
        priority_queue<pair<int, char>> pq;
        for(auto a : freq) {
            pq.push(make_pair(a.second, a.first));
        }
        
        string res = "";
        
        while(pq.size() > 1) {
            auto top1 = pq.top(); pq.pop();
            auto top2 = pq.top(); pq.pop();
            
            res += top1.second;
            res += top2.second;
            
            if(--top1.first > 0) 
                pq.push(top1);
            
            if(--top2.first > 0)
                pq.push(top2);
        }
        
        if(!pq.empty()) {
            //more than one occurrece remaining -> duplicate
            if(pq.top().first > 1)
                return "";
            else
                res += pq.top().second;
        }
        
        return res;
    }
};