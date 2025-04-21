#include <iostream>
#include <vector>
using namespace std;

// ListNode definition
struct ListNode {
    int data;
    ListNode* next;
    ListNode(int val) : data(val), next(nullptr) {}
};

// Solution class
class Solution {
public:
    ListNode* insertAtHead(ListNode*& head, int X) {
        ListNode* newNode = new ListNode(X);
        newNode->next = head;
        head = newNode;
        return head;
    }
};

// Utility to create a linked list from vector
ListNode* createList(vector<int>& arr) {
    ListNode* head = nullptr;
    for (int i = arr.size() - 1; i >= 0; --i) {
        ListNode* newNode = new ListNode(arr[i]);
        newNode->next = head;
        head = newNode;
    }
    return head;
}

// Utility to convert linked list to vector
vector<int> listToArray(ListNode* head) {
    vector<int> result;
    while (head) {
        result.push_back(head->data);
        head = head->next;
    }
    return result;
}

// Test function
void runTestCase(vector<int> inputList, int X, vector<int> expectedList, int* passed, int* total) {
    (*total)++;
    ListNode* head = createList(inputList);
    head = Solution().insertAtHead(head, X);
    vector<int> outputList = listToArray(head);
    if (outputList == expectedList) {
        cout << "Test case passed\n";
        (*passed)++;
    } else {
        cout << "Test case failed\n";
        cout << "Expected: ";
        for (int x : expectedList) cout << x << " ";
        cout << "\nGot: ";
        for (int x : outputList) cout << x << " ";
        cout << endl;
    }
}

// Main
int main() {
    int passed = 0, total = 0;

    runTestCase({1, 2, 3}, 0, {0, 1, 2, 3}, &passed, &total);
    runTestCase({}, 10, {10}, &passed, &total);
    runTestCase({5}, 7, {7, 5}, &passed, &total);

    cout << passed << "/" << total << " test cases passed." << endl;
    return 0;
}
