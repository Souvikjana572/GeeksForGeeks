

/* A binary tree node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

//Function to return a list containing elements of left view of the binary tree.
vector<int> leftView(Node *root)
{
    vector<int>v;
   if(root==NULL){
       return v;
   }
   queue<Node*>q;
   Node* new_node=root;
   q.push(new_node);
   while(!q.empty()){
       int size=q.size();
       for(int i=0;i<size;i++){
       Node* node=q.front();
       q.pop();
       
       if(node->left){
           q.push(node->left);
       }
       if(node->right){
           q.push(node->right);
       }
       if(i==0)
       v.push_back(node->data);
       }
   }
   
   return v;
}
