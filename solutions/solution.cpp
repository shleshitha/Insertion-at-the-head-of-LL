#include <stack>
#include <unordered_map>
#include <string>  // Required for std::string
using namespace std;
 
class Solution {
    public:
        ListNode* insertAtHead(ListNode* &head, int X) {
            ListNode* newNode = new ListNode(X);
            newNode->next = head;
            head = newNode;
            return head;
        }
    };
    
