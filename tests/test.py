import sys
import os

# Ensure the parent directory is in the Python path
sys.path.insert(0, os.path.abspath(os.path.join(os.path.dirname(__file__), "..")))

from solutions.solution import Solution
from solutions.ListNode import ListNode


def run_test_case(input_list, X, expected, passed_count, total):
    total[0] += 1

    # Create linked list from input list
    head = None
    for val in reversed(input_list):
        head = ListNode(val, head)

    # Insert X at the head
    solution = Solution()
    head = solution.insertAtHead(head, X)

    # Convert the linked list to a list for easy comparison
    actual = []
    while head:
        actual.append(head.val)
        head = head.next

    if actual == expected:
        passed_count[0] += 1
        print(f"\n✅ {passed_count[0]}")
    else:
        print("\n❌ Test failed for input:", input_list, "with X =", X)
        print(f"Actual: {actual}, Expected: {expected}")


# ✅ Main function to run all test cases
def main():
    passed_count = [0]
    total = [0]

    # ✅ Basic Cases
    run_test_case([1, 2, 3], 7, [7, 1, 2, 3], passed_count, total)
    run_test_case([], 7, [7], passed_count, total)
    run_test_case([10], 5, [5, 10], passed_count, total)
    run_test_case([4, 6], 9, [9, 4, 6], passed_count, total)
    run_test_case([100], 0, [0, 100], passed_count, total)

    # ✅ Summary
    print(f"\nPassed {passed_count[0]} / {total[0]} test cases!")
    if passed_count[0] != total[0]:
        raise AssertionError("Some test cases failed!")


if __name__ == "__main__":
    main()
