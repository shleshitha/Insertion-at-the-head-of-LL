package solutions;

public class ListNode {
    public int val; 
    public ListNode next;

    public ListNode(int data) {
        val = data;
        next = null;
    }

    public ListNode(int data, ListNode nextNode) {
        val = data;
        next = nextNode;
    }
}

public class Solution {
    public ListNode insertAtHead(ListNode head, int X) {
        ListNode newNode = new ListNode(X);
        newNode.next = head;
        return newNode;
    }
}
