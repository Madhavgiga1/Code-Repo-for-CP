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
int main(){
    return 0;
}