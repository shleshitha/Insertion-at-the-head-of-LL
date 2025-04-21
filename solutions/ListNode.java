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

// ❌ Do NOT make Solution public
