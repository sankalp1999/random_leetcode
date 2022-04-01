class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        int rows = board.size();
        int cols = board[0].size();
        for(int idx = 0; idx < rows; idx++)
        {
            // unordered_map<char,int> mapper;
            unordered_set<char> s;
            for(int j = 0; j < cols; j++)
            {
                char char1 = board[idx][j];
                if(char1 == '.')continue;
                if(s.find(char1) != s.end())
                {
                    return false;
                }
                else s.insert(char1);
            }   
        }
        for(int idx = 0; idx < cols; idx++)
        {
            unordered_set<char> s;
            for(int j = 0; j < rows; j++)
            {   
                
                char char1 = board[j][idx];
                    if(char1 == '.')continue;
                if(s.find(char1) != s.end())
                {
                    return false;
                }
                else s.insert(char1);
            }
        }
        
        int h_offset = 0;
        int v_offset = 0;
        // we are going to need two offsets
        // these are going to be top left points
        int dx[] = {0,0,0,3,3,3,6,6,6};
        int dy[] = {0,3,6,0,3,6,0,3,6};
        for(int k = 0; k < 9; k++)
        {
            unordered_set<char> s;
            
            for(int i = 0; i < 3; i++)
            {
                for(int j = 0; j < 3; j++)
                {     
                   
                   
                    int x = dx[k] + i;
                    int y = dy[k] + j;
                     char char1 = board[x][y];
                    if(char1 == '.')continue;
                    if(s.find(char1) != s.end())
                    {
                        return false;
                    }
                    else s.insert(char1);
                }
            }
        }
        return true;
            
    }
};

/*
For each row, we can check if there are any repetitions or not.
For each column, we can check if there are any repetitions or not.

For each sub-grid, we can again check if there are any 
repetitions or not.

*/