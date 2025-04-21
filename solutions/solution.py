class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def insertAtHead(self, head: 'ListNode', X: int) -> 'ListNode':
        newNode = ListNode(X)
        newNode.next = head
        head = newNode
        return head

