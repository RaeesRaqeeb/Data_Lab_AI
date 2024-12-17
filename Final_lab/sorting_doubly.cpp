// C++ program to sort a doubly linked list 
// using insertion sort
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int x) {
        data = x;
        next = nullptr;
        prev = nullptr;
    }
};

// Function to sort the doubly linked list 
// using insertion sort
Node* insertionSort(Node* head) {
    if (head == nullptr) return head;

    Node* sorted = nullptr;
    Node* curr = head;

    // Traverse the list to sort each element
    while (curr != nullptr) {
      
        // Store the next node to process
        Node* next = curr->next;

        // Insert `curr` into the sorted part
        if (sorted == nullptr || 
                      sorted->data >= curr->data) {
            curr->next = sorted;

            // If sorted is not empty, set its `prev`
            if (sorted != nullptr) sorted->prev = curr;

            // Update sorted to the new head
            sorted = curr;
            sorted->prev = nullptr;

        } 
       else {
          
            // Pointer to traverse the sorted part
            Node* current_sorted = sorted;

            // Find the correct position to insert
            while (current_sorted->next != nullptr &&
                   current_sorted->next->data < curr->data) {
                current_sorted = current_sorted->next;
            }

            // Insert `curr` after `current_sorted`
            curr->next = current_sorted->next;

            // Set `prev` if `curr` is not inserted 
            // at the end
            if (current_sorted->next != nullptr) 
                current_sorted->next->prev = curr;

            // Set `next` of `current_sorted` to `curr`
            current_sorted->next = curr;
            curr->prev = current_sorted;
        }

        // Move to the next node to be sorted
        curr = next;
    }

    return sorted;
}

void printList(Node* node) {
    Node* curr = node;
    while (curr != nullptr) {
        cout << " " << curr->data;
        curr = curr->next;
    }
}

int main() {
  
    // Create a hard-coded doubly linked list:
    // 5 <-> 3 <-> 4 <-> 1 <-> 2
    Node* head = new Node(5);
    head->next = new Node(3);
    head->next->prev = head;
    head->next->next = new Node(4);
    head->next->next->prev = head->next;
    head->next->next->next = new Node(1);
    head->next->next->next->prev = head->next->next;
    head->next->next->next->next = new Node(2);
    head->next->next->next->next->prev
                     = head->next->next->next;

    head = insertionSort(head);

    printList(head);

    return 0;
}