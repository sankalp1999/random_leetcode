class Solution {
public:
    
    static bool compare(vector<int>& a, vector<int>& b)
    {
        if(a[0]==b[0])
        {
            return a[1]>b[1];
        }
        return a[0]<b[0];
    }
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<vector<int>> v;
        for(int i = 0; i < trips.size(); i++)
        {
            vector<int> temp = {trips[i][1],1,trips[i][0] };
            v.push_back(temp);
            vector<int> temp2 = {trips[i][2],2,trips[i][0]} ;
            v.push_back(temp2);
        }
        sort(v.begin(), v.end(),compare);
        int curr = 0;
        for(int i = 0; i < v.size(); i++)
        {
            if(v[i][1]==1)curr+=v[i][2];
            if(v[i][1]==2)curr-=v[i][2];
            if(curr>capacity)return false;
        }
        return true;
    }
};