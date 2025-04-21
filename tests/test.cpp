#include <bits/stdc++.h>
#include "../solutions/solution.cpp"  // Include your solution file

using namespace std;

// Helper function to create a linked list from an array
ListNode* createList(vector<int>& arr) {
    ListNode* head = nullptr;
    for (int i = arr.size() - 1; i >= 0; --i) {
        head = Solution().insertAtHead(head, arr[i]);
    }
    return head;
}

// Helper function to convert list to vector (for comparison)
vector<int> listToArray(ListNode* head) {
    vector<int> result;
    while (head != nullptr) {
        result.push_back(head->val);
        head = head->next;
    }
    return result;
}

// Function to run individual test cases
void runTestCase(vector<int> inputList, int X, vector<int> expected, int *passedCount, int *total) {
    (*total)++;

    ListNode* head = createList(inputList);
    head = Solution().insertAtHead(head, X);

    vector<int> actual = listToArray(head);

    if (actual == expected) {
        (*passedCount)++;
        cout << "\n✅ " << *passedCount;
    } else {
        cout << "\n❌ Test failed for input: ";
        cout << "X = " << X << ", list = [";
        for (int i = 0; i < inputList.size(); i++) {
            cout << inputList[i] << (i == inputList.size() - 1 ? "" : ", ");
        }
        cout << "]\nExpected: [";
        for (int i = 0; i < expected.size(); i++) {
            cout << expected[i] << (i == expected.size() - 1 ? "" : ", ");
        }
        cout << "], Actual: [";
        for (int i = 0; i < actual.size(); i++) {
            cout << actual[i] << (i == actual.size() - 1 ? "" : ", ");
        }
        cout << "]\n";
    }
}

// ✅ Main function to run all test cases
int main() {
    int passedCount = 0;
    int total = 0;

    // ✅ Basic Cases
    runTestCase({1, 2, 3}, 7, {7, 1, 2, 3}, &passedCount, &total);
    runTestCase({}, 7, {7}, &passedCount, &total);
    runTestCase({10}, 5, {5, 10}, &passedCount, &total);
    runTestCase({4, 6}, 9, {9, 4, 6}, &passedCount, &total);
    runTestCase({100}, 0, {0, 100}, &passedCount, &total);

    // ✅ Summary
    cout << "\n\nPassed " << passedCount << " / " << total << " test cases!" << endl;
    if (passedCount != total) {
        assert(false);  // Force failure
    }

    return 0;
}
