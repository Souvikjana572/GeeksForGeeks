/*

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/


class Solution
{
    public:
    //Function to rotate a linked list.
    Node* rotate(Node* head, int k)
    {
        if(head==NULL||head->next==NULL)return NULL;
       Node*tail=head;
       while(tail->next){
           tail=tail->next;
       }
       while(k--){
           tail->next=head;
           tail=tail->next;
           head=head->next;
           tail->next=NULL;
       }
       return head;
    }
};
    
