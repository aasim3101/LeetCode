class Solution {
public:
    vector<int> dx={0,0,1,-1};
    vector<int> dy={-1,1,0,0};
    int ans=0;
    bool isValid(int new_x, int new_y, int m, int n, vector<vector<int> > &grid,vector<vector<bool> > &visited){
        if(new_x<0 or new_x>=m or new_y<0 or new_y>=n)
            return false;
        if(visited[new_x][new_y] or grid[new_x][new_y]==0)
            return false;
        return true;
    }
    void dfs(int x,int y,int m,int n,vector<vector<int> > &grid,vector<vector<bool> > &visited,int &curr_area){
        visited[x][y]=true;
        for(int i=0; i<4; i++){
            if(isValid(x+dx[i], y+dy[i],m,n,grid,visited)){
                curr_area++;
                dfs(x+dx[i], y+dy[i], m, n, grid, visited,curr_area);
            }
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m=(int)grid.size();
        int n=(int)grid[0].size();
        vector<vector<bool> > visited(m,vector<bool> (n,false));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==1 and !visited[i][j]){
                    int curr_area=1;
                    dfs(i,j,m,n,grid,visited,curr_area);
                    ans=max(ans,curr_area);
                }
            }
        }
        return ans;
    }
};