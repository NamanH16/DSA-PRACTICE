class Solution {
private:
    void dfs(int node,vector<int> &vis,vector<int>adj[]){
        vis[node]=1;
        for(auto x:adj[node]){
            if(vis[x]==0){
                dfs(x, vis, adj);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        // given : adjacency matrix -> adj list
        int v = isConnected.size();
        vector<int> adj[v];
        for(int i=0;i<v;i++){
            for(int j=0;j<v;j++){
                if(isConnected[i][j]==1 && i!=j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<int> vis(v, 0);
        int cnt=0;
        for(int i=0;i<v;i++){
            if(vis[i]==0){
                cnt++;
                dfs(i, vis, adj);
            }
        }
        return cnt;
    }
};