class LRUCache {
public:
    #include<list>
    //hashmap to store key and iterator to the corresponding node in the list
    unordered_map<int,list<pair<int,int>>::iterator> mp;
    //list of pairs to store key, value
    list<pair<int,int>> dq;
    int n;
    LRUCache(int capacity) {
        n = capacity;
        mp.clear();
        mp.clear();
    }
    
    int get(int key) {
        //if no key in map return -1
        if(mp.count(key) == 0)
            return -1;
        
        //if key exists get the iterator from map
        auto it = mp[key];
        int val = it->second;
        
        //erease node from queue and insert at the back, high priority
        dq.erase(it);
        dq.push_back({key,val});
        
        //new address of key
        it = dq.end();
        it--; //cannot do it-1 for pointers
        
        mp[key] = it;
        return val;
    }
    
    void put(int key, int val) {
        if(mp.count(key)) {
            //if already exists no need to insert
            auto it = mp[key];
            //will be insereted again
            dq.erase(it);
        }
        else if(mp.size() == n) {
            //if list is full, pop least recently used which is in the front
            int k = dq.front().first;
            mp.erase(k);
            dq.pop_front();
        }
        //push the node at the back of the queue
        dq.push_back({key, val});
        
        //get iterator of the last node from queue 
        auto it = dq.end();
        it--;
        
        //and push it ot the map
        mp[key] = it;
         
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */