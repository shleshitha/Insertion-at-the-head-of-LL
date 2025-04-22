package solutions;

public class Solution {
    public ListNode insertAtHead(ListNode head, int val) {
        ListNode newNode = new ListNode(val); // create a new node with the value
        newNode.next = head; // point the new node's next to the current head
        return newNode; // ne
    }
}
