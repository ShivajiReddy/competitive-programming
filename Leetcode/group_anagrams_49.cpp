class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        //for each sorted string store other anagrams as keys
        unordered_map<string, vector<string>> umap;
        
        for(auto s : strs) {
            string t = s;
            sort(t.begin(), t.end());
            umap[t].push_back(s);
        }
        
        vector<vector<string>> res;
        
        //push keys into vector
        for(auto map_element : umap) {
            res.push_back(map_element.second);
        }
        
        return res;
    }
};