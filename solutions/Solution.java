package solutions;  
import java.util.Stack;

class ListNode {
    int val;
    ListNode next;
    ListNode(int data) {
        val = data; 
        next = null;
    }
    ListNode(int data, ListNode nextNode) {
        val = data;
        next = nextNode;
    }
}

class Solution {
    public ListNode insertAtHead(ListNode head, int X) {
        ListNode newNode = new ListNode(X);
        newNode.next = head;
        head = newNode;
        return head;
    }
}
