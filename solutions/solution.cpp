#include <stack>
#include <unordered_map>
#include <string>  // Required for std::string
using namespace std; 

struct ListNode {
    int data;
    ListNode* next;

    ListNode(int val) {
        data = val;
        next = nullptr;
    }
};

class Solution {
public:
    ListNode* insertAtHead(ListNode* &head, int X) {
        ListNode* newNode = new ListNode(X); // Create a new node with the given value
        newNode->next = head; // Point new node to the current head
        head = newNode; // Update head to new node
        return head; // Return new head
    }
};
