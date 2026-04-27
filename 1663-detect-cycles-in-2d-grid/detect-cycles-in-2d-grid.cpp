class Solution {
public:
bool dfs(int i,int j,int lr,int lc,int l,vector<vector<char>>& grid,vector<vector<int>> &vis){
    vis[i][j]=1;
    int dr[]={-1,0,1,0};
    int dc[]={0,1,0,-1};
    for(int k=0;k<4;k++){
        int nr=i+dr[k];
        int nc=j+dc[k];
        if(nr>=0 && nr<grid.size() && nc>=0 && nc<grid[0].size() && (nr != lr || nc != lc) && grid[nr][nc]==grid[i][j] && vis[nr][nc]==1){
            return true;
        }
        if(nr>=0 && nr<grid.size() && nc>=0 && nc<grid[0].size() &&vis[nr][nc]!=1 && grid[nr][nc]==grid[i][j]){
            bool g=dfs(nr,nc,i,j,l+1,grid,vis);
            if(g==true) return true;
        }
    }
    return false;

}
    bool containsCycle(vector<vector<char>>& grid) {
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        vector<vector<int>> vis(grid.size(),vector<int>(grid[0].size(),-1));
         for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(vis[i][j]==-1){
                    if(dfs(i,j,i,j,0,grid,vis)){
                        return true;
                    }
                }
            }
         }
         return false;
    }
};