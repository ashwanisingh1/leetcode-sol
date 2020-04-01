class RandomizedSet {
     vector<int> ar;
     unordered_map<int,int> mp;
public:
    /** Initialize your data structure here. */
    RandomizedSet() {   
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(mp[val]!=0){
            return 0;
        }
        mp[val]=ar.size()+1;
        ar.push_back(val);
        return 1;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
       if(mp[val]==0){
            return 0;
        }
        int temp=ar[ar.size()-1];
        swap(ar[mp[val]-1],ar[ar.size()-1]);
        mp[temp]=mp[val];
        mp[val]=0;
        ar.pop_back();
        return 1; 
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int n=rand()%ar.size();
        return ar[n];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
