// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        int ans=0;
        vector<int>adj[N];
        for(int i=0;i<M;i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int>dist(N,-1);
        vector<bool>visited(N,0);
        queue<int>q;
        q.push(src);
        dist[src]=0;
        visited[src]=1;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(int j=0;j<adj[node].size();j++){
                if(visited[adj[node][j]])
                continue;
                visited[adj[node][j]]=1;
                q.push(adj[node][j]);
                dist[adj[node][j]]=dist[node]+1;
            }
        }
        return dist;
    }
};