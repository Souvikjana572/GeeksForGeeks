// User function template for C++

/*

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution {
  public:
    Node* addOne(Node* head) {
       int countNine = 0, totalCount = 1, tempCount = 0, liveCount = 1;
       Node* left = head;
       while(left->next != NULL) 
       {
           if (left->data == 9) countNine++;
           else countNine = 0;
           left = left->next;
           totalCount++;
       }
       if (left->data != 9) 
       {
           left->data = left->data + 1;
           return head;
       }
       countNine++;
       if (countNine == totalCount){
            Node* newNode = new Node(1);
            newNode->next = head;
            head = newNode;
            left = head->next;
            while(left != NULL)
            {
                left->data = 0;
                left = left->next;
            }
            return head;
       }
       left = head;
       tempCount = totalCount - countNine;
       while(left != NULL) 
       {
        //   cout<<countNine<<" -> "<<totalCount<<" -> "<<tempCount<<" -> "<<liveCount<<endl;
           if (liveCount == tempCount)
           {
            //   cout<<"left -> "<<left->data<<" "<<liveCount<<" "<<tempCount<<endl;
               left->data = left->data + 1;
               left = left->next;
           }
           else if (liveCount > tempCount)
           {
               left->data = 0;
               left = left->next;
           }
           else left = left->next;
           liveCount++;
       }
       return head;
       
    }
};
