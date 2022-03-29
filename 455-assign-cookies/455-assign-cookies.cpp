class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(s.begin(), s.end(),greater<int>());
        sort(g.begin(), g.end(),greater<int>());
        int curr = 0;
        int i = 0;
        int j = 0;
        while(i < g.size() && j < s.size())
        {
            if(s[j] >= g[i])
            {
                j++;
                i++;
                curr++;
            }
            else{
                i++;
            }
        }
        return curr;
        
    }
};