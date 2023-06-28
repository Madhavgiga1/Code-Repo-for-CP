#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    Node* constructDLL(vector<int>& arr) {
        Node* head = new Node;
        Node* curr = head;
        Node* before = NULL;
        
        for (auto p : arr) {
            curr->data = p;
            curr->prev = before;
            before = curr;
            Node* t = new Node;
            curr->next = t;
            curr = curr->next;
        }
        // Update the next pointer of the last node to NULL
        delete curr;  
        before->next = NULL;
        
        return head;
    }
};
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *cur1{l1};
        ListNode *cur2{l2};
        ListNode *start = new ListNode(0);
        ListNode *prev = start;
        int carry = 0;
        while (cur1 || cur2 || carry) {
            int sum = (cur1 ? cur1->val : 0) + (cur2 ? cur2->val : 0) + carry;
            carry = 0;
            if (sum > 9) {
                sum -= 10;
                carry = 1;
            }
            ListNode *new_node = new ListNode(sum);
            prev->next = new_node;
            prev = new_node;

            cur1 = cur1 ? cur1->next : cur1;
            cur2 = cur2 ? cur2->next : cur2;
        }
        return start->next;
        
        
    }
};
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head) return head;
        ListNode* temp =head;
        int count=0,count1=1;
       while(temp){
           count++;
           temp=temp->next;
       }
        count-=n;
        temp=head;
        if(count==0) return head->next;
        
        while(temp){
            if(count==count1){
                temp->next=temp->next->next;
                break;
            }
            count1++;
            temp=temp->next;
        }
        
        return head;
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return {};
        
        ListNode origin;
        ListNode* node { &origin };
        
        auto comp = [] (ListNode* a, ListNode* b) {
            if (a && b) {
                return a->val > b->val;
            }
            return a ? false : true;            
        };
        
        priority_queue<ListNode*, vector<ListNode*>, decltype(comp)> q(comp);
        
        for (auto l_node : lists) {
            q.push(l_node);
        }
        
        while (true) {
            auto min_node = q.top();
            q.pop();
            
            if (min_node == nullptr) break;
                        
            node->next = min_node;
            node = node->next;
            min_node = min_node->next;
            q.push(min_node);
        }
        
        return origin.next;
    }
};
class Solution {
public:
   ListNode* swapPairs(ListNode* head) {
        if(head==NULL || head->next==NULL) return head; 
        
        ListNode* dummyNode = new ListNode();
        
        ListNode* prevNode=dummyNode;
        ListNode* currNode=head;
        
        while(currNode && currNode->next){
            prevNode->next = currNode->next;
            currNode->next = prevNode->next->next;
            prevNode->next->next = currNode;
            
            prevNode = currNode;
            currNode = currNode->next;
        }
        
        return dummyNode->next;
    }
};
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head) 
            return false;
        
        ListNode *slow = head, *fast = head;
        
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) 
                return true;
        }
        
        return false;
    }

};
class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) { 
                ListNode* temp = head;

                while (temp != slow) { 
                    slow = slow->next;
                    temp = temp->next;
                }

                return slow;
            }
        }

        return NULL;
    }
};

int main(){
    return 0;
}