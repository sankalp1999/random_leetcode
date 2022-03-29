class Solution {
public:
    
    
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int curr = 0;
        vector<int> stops(1002, 0);
        for(auto trip : trips)
        {
            stops[trip[1]] += trip[0];
            stops[trip[2]] -= trip[0]; // At a particular time, how many peeps get out
        }
        for(int i = 0; i < 1001; i++)
        {
            curr += stops[i];
            if(curr > capacity)return false;
        }
        return true;
    }
};