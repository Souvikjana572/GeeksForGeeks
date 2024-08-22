class Solution{
    public:
    string findOrder(string dict[], int N, int K) {
        vector<int>adj[K];
        vector<int>indeg(K,0);
        for(int i=0;i<N-1;i++){
            string str1=dict[i],str2=dict[i+1];
            int j=0,k=0;
            while(j<str1.size()&&k<str2.size()&&str1[j]==str2[k])
            j++,k++;
            if(j==str1.size())
            continue;
            
            adj[str1[j]-'a'].push_back(str2[k]-'a');
            indeg[str2[k]-'a']++;
        }
        
        queue<int>q;
        string ans;
        for(int i=0;i<K;i++)
        if(!indeg[i])
        q.push(i);
        while(!q.empty()){
            int node=q.front();
            q.pop();
            char c='a'+node;
            ans+=c;
            for(int i=0;i<adj[node].size();i++){
                indeg[adj[node][i]]--;
                if(!indeg[adj[node][i]])
                q.push(adj[node][i]);
            }
        }
        return ans;
    }
};
