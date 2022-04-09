
class Solution {
public:
    Node* copyRandomList(Node* head) {
        
    
        Node* curr = head;
        while(curr)
        {
            Node* temp = curr->next;
            curr->next = new Node(curr->val);
            curr = curr->next;
            curr->next = temp;
            curr = curr->next;
        }

        curr = head;
        while(curr)
        {   
            if(curr->random != NULL)
            {
                curr->next->random = curr->random->next;
            }
            curr = curr->next->next;
        }

        curr = head;
        
        Node* newlist = new Node(0); // Create a new list node in memory
        
        Node* dummy;
        
        dummy = newlist;
        
        
        
        while(curr)
        {
            Node* nextItr = curr->next->next; // save link to next node
            
            newlist->next = curr->next;
            newlist = newlist->next;
            
            curr->next = nextItr;
            curr = nextItr;
            
        }

        
        return dummy->next;
        
        
    }
};