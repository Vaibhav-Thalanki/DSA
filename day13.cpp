class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        pair<int,int> temp;
        int n=0,healthy=0,len=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==2){
                    q.push(make_pair(i,j));
                }
                if(grid[i][j]==1)
                    healthy++;
            }
        }
        while(!q.empty() && healthy>0){
        
            len = q.size();
            for(int i=0;i<len;i++){
               temp = q.front();

            if(temp.first-1>=0 && grid[temp.first-1][temp.second]==1){
                grid[temp.first-1][temp.second] =2;
                q.push(make_pair(temp.first-1,temp.second));
                healthy--;
            }
            if(temp.first+1<grid.size() && grid[temp.first+1][temp.second]==1){
                grid[temp.first+1][temp.second] =2;
                q.push(make_pair(temp.first+1,temp.second));
                healthy--;
            }
            if(temp.second-1>=0 && grid[temp.first][temp.second-1]==1){
                grid[temp.first][temp.second-1] =2;
                q.push(make_pair(temp.first,temp.second-1));
                healthy--;
            }
            if(temp.second+1<grid[0].size() && grid[temp.first][temp.second+1]==1){
                grid[temp.first][temp.second+1] =2;
                q.push(make_pair(temp.first,temp.second+1));
                healthy--;
            }
                
                q.pop();
            }
            n++;
            
        }
        if(healthy==0)
        return n;
        else
            return -1;
    }
};