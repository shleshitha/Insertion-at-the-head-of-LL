package tests; // ✅ Define package name

import solutions.Solution; // ✅ Import the Solution class

public class Test {
    private static int passed = 0;
    private static int total = 0;

    // Helper function to print the linked list
    public static void printList(ListNode head) {
        while (head != null) {
            System.out.print(head.val + (head.next != null ? " -> " : ""));
            head = head.next;
        }
        System.out.println();
    }

    // Helper function to convert linked list to array for comparison
    public static int[] listToArray(ListNode head) {
        int size = 0;
        ListNode temp = head;
        while (temp != null) {
            size++;
            temp = temp.next;
        }
        
        int[] result = new int[size];
        int index = 0;
        while (head != null) {
            result[index++] = head.val;
            head = head.next;
        }
        return result;
    }

    // Function to run individual test cases
    public static void runTestCase(int[] inputList, int X, int[] expected) {
        total++;

        // Create linked list from input array
        ListNode head = null;
        for (int i = inputList.length - 1; i >= 0; i--) {
            head = new ListNode(inputList[i], head);
        }

        // Insert the new value at the head
        Solution solution = new Solution();
        head = solution.insertAtHead(head, X);

        // Convert the resulting linked list to an array
        int[] actual = listToArray(head);

        // Check if actual result matches expected
        if (java.util.Arrays.equals(actual, expected)) {
            passed++;
            System.out.println("✅ Test Passed");
        } else {
            System.out.println("❌ Test Failed for input: " + java.util.Arrays.toString(inputList) + " with X = " + X);
            System.out.println("   Expected: " + java.util.Arrays.toString(expected));
            System.out.println("   Actual  : " + java.util.Arrays.toString(actual));
        }
    }

    // Main function to run all test cases
    public static void main(String[] args) {
        runTestCase(new int[] {1, 2, 3}, 7, new int[] {7, 1, 2, 3});
        runTestCase(new int[] {}, 7, new int[] {7});
        runTestCase(new int[] {10}, 5, new int[] {5, 10});
        runTestCase(new int[] {4, 6}, 9, new int[] {9, 4, 6});
        runTestCase(new int[] {100}, 0, new int[] {0, 100});

        System.out.printf("\n✅ Passed %d / %d test cases!\n", passed, total);
        if (passed != total) {
            throw new AssertionError("Some test cases failed!");
        }
    }
}
