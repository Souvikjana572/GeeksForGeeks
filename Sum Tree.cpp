class Solution {
  public:
    int ans(Node*ptr)
    {
        if(ptr==NULL)
        return 0;
        int a=ans(ptr->left);
        int b=ans(ptr->right);
        if((ptr->left!=NULL||ptr->right!=NULL)&&ptr->data!=a+b)
        return 0;
        return ptr->data+a+b;
    }
    bool isSumTree(Node* root) {
        // Your code here
        return ans(root);
    }
};
