class Solution {
  public:
    vector <int> bottomView(Node *root) {
        queue<pair<Node*,int>>q;
        map<int,int> umap;
        
        vector<int> ans;
        
        if(root==NULL)
         return ans;
        
        q.push({root,0});
        
        while(!q.empty()){
            auto temp=q.front();
            q.pop();
            
            Node* tempNode=temp.first;
            int hd=temp.second;
            
            umap[hd]=tempNode->data;
            
            if(tempNode->left)
            q.push({tempNode->left,hd-1});
            
            if(tempNode->right)
            q.push({tempNode->right,hd+1});
        }
        
        for(auto i:umap)
        ans.push_back(i.second);
        
        return ans;
    }
};
