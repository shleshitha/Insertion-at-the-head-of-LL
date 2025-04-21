#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};


struct ListNode* insertAtHead(struct ListNode* head, int X) {
<<<<<<< HEAD
    //implement your code
}
=======
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = X;
    newNode->next = head;
    head = newNode;
    return head;
}
>>>>>>> 00b203b79b53b91286a9f094bf0acf2cb6db28c6
