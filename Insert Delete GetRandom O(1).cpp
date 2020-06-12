class RandomizedSet {
public:
    /** Initialize your data structure here. */
    unordered_map<int,int>mp;//stores the index of element in vector for faster access
    vector<int>v;//store the elements
    RandomizedSet() {
        mp.clear();
        v.clear();
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(mp.find(val)!=mp.end() ){
            return false;
        }
        v.push_back(val);
        mp[val]=v.size()-1;
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(mp.find(val)==mp.end() ){
            return false;
        }
        
        int index_to_be_deleted=mp[val];
        int value_at_last_index=v[v.size()-1];
        
        v[index_to_be_deleted]=value_at_last_index;
        v.pop_back();
        
        mp[value_at_last_index]=index_to_be_deleted;
        
        mp.erase(val);
        
        // if(mp.find(val)==mp.end()){
        //     cout<<"haan"<<endl;
        // }
        return true;
        
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int random=rand()%(v.size());
        return v[random];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
