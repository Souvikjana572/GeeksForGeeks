//User function Template for C++

/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
  void find(Node* root,int target,Node * &temp){
      if(!root)return;
      if(root->data==target){
          temp=root;
          return;
      }
      find(root->left,target,temp);
      find(root->right,target,temp);
  }
  
  int height(Node*root){
      if(!root)return 0;
      return 1+max(height(root->left),height(root->right));
  }
  
  int burn(Node*root,int &timer,int target){
      if(!root)return 0;
      if(root->data==target)return -1;
      int left=burn(root->left,timer,target);
      int right=burn(root->right,timer,target);
      if(left<0){
          timer=max(timer,abs(left)+right);
          return left -1;
          
      }
      if(right<0){
          timer=max(timer,abs(right)+left);
          return right -1;
          
      }
      return 1+max(left,right);
  }
  
    int minTime(Node* root, int target) 
    {
        int timer=0;
        burn(root,timer,target);
        Node*temp=NULL;
        find(root,target,temp);
        int high=height(temp)-1;
        return max(timer,high);
    }
};
