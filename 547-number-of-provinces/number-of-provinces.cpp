class Solution {
private:
   void dfs(int node ,vector<int>& visited, vector<vector<int>>& adj){
    
    if(visited[node] == 0){
        visited[node]++;

        for(int neighbour :adj[node]){
            if(!visited[neighbour]){
            dfs(neighbour,visited,adj);
        }
        }
    }
   }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int v = isConnected[0].size();

        // adjacency list prep
        vector<vector<int>> adj(v);
        for(int i= 0;i<v;i++ ){
            for(int j =0;j<v;j++){
                if(i!=j && isConnected[i][j]== 1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        // visited array
        vector<int> visited(v,0);

        // setting count for counting connected city
        int count =0;

        for(int i =0;i<v;i++){
           if(visited[i]==0){
            count++;
            dfs(i,visited,adj);
           }
        }

        return count;
    }
};