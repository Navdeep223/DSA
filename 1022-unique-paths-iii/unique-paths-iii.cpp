class Solution {
public:
     int solve(int r,int c,int remaining,vector<vector<int>> &grid,vector<vector<int>> &vis){
        int m=grid.size();
        int n=grid[0].size();
        if(r<0 || c<0 || r>=m|| c>=n || grid[r][c]==-1 || vis[r][c]==1){
        return 0;}
        remaining--;
        if(grid[r][c]==2)
        return remaining==0?1:0;

        vis[r][c]=1;

        int dr[]={1,0,0,-1};
        int dc[]={0,-1,1,0};
        int totalpaths=0;
        for(int i=0;i<4;i++){
            int nr=r+dr[i];
            int nc=c+dc[i];
            totalpaths+=solve(nr,nc,remaining,grid,vis);

        }
        vis[r][c]=0;
        return totalpaths;
     }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));

        int startrow=0;
        int startcol=0;
        int remaining=0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
              if(grid[i][j]!=-1)
              remaining++;
              if(grid[i][j]==1){
                startrow=i;
                startcol=j;
              }
            }
        }
        return solve(startrow,startcol,remaining,grid,vis);
    }
};