class RandomizedSet {
public:
    
    vector<int> nums;
    unordered_map<int, int> mp;
    
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(mp.find(val) != mp.end())    return false;
        nums.push_back(val);
        mp[val] = nums.size() - 1;
    	// for(int i = 0; i < nums.size(); i++)    cout << nums[i] << " ";
        // cout << endl;
        return true;
    }
    
    bool remove(int val) {
        if(mp.find(val) == mp.end())    return false;
        int temp = nums.back();
        nums[mp[val]] = temp;
        nums.pop_back();
        mp[temp] = mp[val];
        //nums[mp[val]] = nums[nums.size() - 1];
        // nums.pop_back();
        mp.erase(val);
        // for(int i = 0; i < nums.size(); i++)    cout << nums[i] << " ";
        // cout << endl;
        return true;
    }
    
    int getRandom() {
        int idx = rand() % nums.size();
        return nums[idx];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */