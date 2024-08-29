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
class Solution {
  public:
    // Function to find the length of a loop in the linked list.
    int countNodesinLoop(Node *head) {
 Node *slow ,*fast;
    slow = fast = head;
    while(fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast)
        break;
    }
    if(fast == NULL || fast->next == NULL)
    return 0;
    slow = fast->next;
    int count = 1;
    while (slow != fast )
    {
        count++;
        slow = slow->next;
    }
    return count;
    }
};
