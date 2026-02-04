class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        //queue for conataining <<row, col> , time>
       queue<pair<pair<int,int>,int>> q;
       int m = grid.size();
       int n = grid[0].size();

       //making visited array
        vector<vector<int>> visited(m, vector<int>(n, 0));
         
       int fresh_count =0;
       // pushing rotten oranges
       for(int i =0;i<m;i++){
        for(int j =0;j<n;j++){
            if(grid[i][j]==2){
              q.push({{i,j},0});    
              visited[i][j]=1;
            }
            if(grid[i][j]==1)
            fresh_count ++;
        }
       }

       int row[]={-1,0,1,0};
       int col[]={0,1,0,-1};
       int time =0;
       
       int rotten_count =0;
    
       //bfs traversal
       while(!q.empty()){
         int r = q.front().first.first;
         int c = q.front().first.second;
         int t = q.front().second;
         
         time = max(time,t);
         q.pop();
         for(int i =0;i<4;i++){
            int nr = r+row[i];
            int nc = c+col[i];

            if(nr>=0 && nr <m && nc>=0 && nc <n 
            && visited[nr][nc] ==0 && grid[nr][nc]==1){

                visited[nr][nc]=1;
                q.push({{nr,nc},t+1});
                grid[nr][nc]=2;
                rotten_count++;
            }
         }
        }
       if(fresh_count != rotten_count) return -1;
       return time;
    }
};