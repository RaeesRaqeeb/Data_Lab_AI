#include <iostream>
#include <vector>

using namespace std;

class Node {
public:
    Node* next;
    Node* prev;
    int info;

    Node(int value) {
        info = value;
        next = nullptr;
        prev = nullptr;
    }
};

class DoublyLinkedList {
private:
    Node* head;
    int length;

public:
    DoublyLinkedList() {
        head = nullptr;
        length = 0;
    }

    // Insert value at the end
    void insertion_value(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* curr = head;
            while (curr->next != nullptr) {
                curr = curr->next;
            }
            curr->next = newNode;
            newNode->prev = curr;
        }
        length++;
    }

    // Insert at a specific position
    void insertion_at(int value, int position) {
        // Position check
        if (position < 1 || position > length + 1) {
            cout << "Invalid position entered!!!" << endl;
            return;
        }

        Node* newNode = new Node(value);

        if (position == 1) {
            newNode->next = head;
            if (head != nullptr)
                head->prev = newNode;
            head = newNode;
        } else {
            Node* curr = head;
            for (int i = 1; i < position - 1; i++) {
                curr = curr->next;
            }
            newNode->next = curr->next;
            if (curr->next != nullptr)
                curr->next->prev = newNode;
            curr->next = newNode;
            newNode->prev = curr;
        }
        length++;
    }

    // Remove node with a specific value
    void remove_value(int value) {
        if (head == nullptr) {
            cout << "The linked list is empty" << endl;
            return;
        }

        Node* curr = head;

        while (curr != nullptr && curr->info != value) {
            curr = curr->next;
        }

        if (curr == nullptr) {
            cout << "Value not found in the list" << endl;
            return;
        }

        if (curr->prev != nullptr)
            curr->prev->next = curr->next;
        else
            head = curr->next;

        if (curr->next != nullptr)
            curr->next->prev = curr->prev;

        delete curr;
        length--;
    }

    // Display the list
    void display() {
        Node* curr = head;
        while (curr != nullptr) {
            cout << curr->info << " ";
            curr = curr->next;
        }
        cout << "\n";
    }

    // Divide the list into two halves
    void dividing_list(DoublyLinkedList& obj) {
        if (head == nullptr) {
            cout << "The linked list is empty" << endl;
            return;
        }

        Node* curr = head;
        int mid = length / 2;
        for (int i = 0; i < mid; i++) {
            curr = curr->next;
        }

        obj.head = curr;
        obj.head->prev = nullptr;

        if (curr->prev != nullptr)
            curr->prev->next = nullptr;

        length = mid;
        obj.length = mid + (length % 2 == 0 ? 0 : 1);
    }

    // Divide the list at a specific value
    void dividing_at(DoublyLinkedList& obj, int value) {
        if (head == nullptr) {
            cout << "The linked list is empty" << endl;
            return;
        }

        Node* curr = head;
        while (curr != nullptr && curr->info != value) {
            curr = curr->next;
        }

        if (curr == nullptr) {
            cout << "Value not found in the list" << endl;
            return;
        }

        obj.head = curr;
        if (curr->prev != nullptr) {
            curr->prev->next = nullptr;
            curr->prev = nullptr;
        }

        // Update lengths
        int count = 0;
        Node* temp = obj.head;
        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }
        obj.length = count;

        // Update original list length
        length -= count;
    }

    // Merge two lists
    void Merging_list(DoublyLinkedList& obj1, DoublyLinkedList& obj2) {
        if (obj1.head == nullptr && obj2.head == nullptr) {
            cout << "Both linked lists are empty" << endl;
            return;
        }

        head = obj1.head;
        Node* curr = obj1.head;

        // Move to the end of the first list
        while (curr->next != nullptr) {
            curr = curr->next;
        }

        // Link the second list
        curr->next = obj2.head;
        if (obj2.head != nullptr)
            obj2.head->prev = curr;

        // Update length
        length = obj1.length + obj2.length;
    }

    // Sort the list
    void sorting_linkedlist() {
        if (head == nullptr) {
            cout << "The linked list is empty" << endl;
            return;
        }

        Node* i = head;
        while (i != nullptr) {
            Node* j = i->next;
            while (j != nullptr) {
                if (i->info > j->info) {
                    int temp = i->info;
                    i->info = j->info;
                    j->info = temp;
                }
                j = j->next;
            }
            i = i->next;
        }
    }

    // Clear the list
    void Clear_linkedlist() {
        if (head == nullptr) {
            cout << "The linked list is already empty" << endl;
            return;
        }
        Node* curr = head;
        while (curr != nullptr) {
            Node* temp = curr;
            curr = curr->next;
            delete temp;
        }
        head = nullptr;
        length = 0;
    }

    // Reverse the list
    void reversing_linkelist() {
        if (head == nullptr) {
            cout << "The linked list is empty" << endl;
            return;
        }

        Node* curr = head;
        Node* temp = nullptr;

        while (curr != nullptr) {
            // Swap next and prev
            temp = curr->prev;
            curr->prev = curr->next;
            curr->next = temp;
            curr = curr->prev;
        }

        if (temp != nullptr)
            head = temp->prev;
    }

    // Merge two lists and sort
    void Merged_sort(DoublyLinkedList& obj1, DoublyLinkedList& obj2) {
        Merging_list(obj1, obj2);
        sorting_linkedlist();
        display();
    }

    // Check if the list is a palindrome
    bool checkPalindrome(Node*& left, Node* right) {
        if (right == nullptr)
            return true;

        bool result = checkPalindrome(left, right->next) && (left->info == right->info);
        left = left->next;
        return result;
    }

    bool isPalindrome() {
        Node* left = head;
        return checkPalindrome(left, head);
    }

    // Place even numbers at the end in reversed order
    void even_end_reversed() {
        if (head == nullptr) {
            cout << "The list is empty" << endl;
            return;
        }

        DoublyLinkedList evenList;
        Node* curr = head;

        while (curr != nullptr) {
            if (curr->info % 2 == 0) {
                evenList.insertion_at(curr->info, 1);
                Node* toDelete = curr;
                if (curr->prev != nullptr)
                    curr->prev->next = curr->next;
                else
                    head = curr->next;
                if (curr->next != nullptr)
                    curr->next->prev = curr->prev;
                curr = curr->next;
                delete toDelete;
                length--;
            } else {
                curr = curr->next;
            }
        }

        // Attach reversed even list at the end
        if (head == nullptr) {
            head = evenList.head;
        } else {
            curr = head;
            while (curr->next != nullptr) {
                curr = curr->next;
            }
            curr->next = evenList.head;
            if (evenList.head != nullptr)
                evenList.head->prev = curr;
        }
        length += evenList.length;
    }
};


int main() {
    DoublyLinkedList list;
    list.insertion_value(1);
    list.insertion_value(2);
    list.insertion_value(3);
    list.insertion_value(4);
    list.insertion_value(5);

    cout << "Original list:" << endl;
    list.display();

    cout << "Reversed list:" << endl;
    list.reversing_linkelist();
    list.display();

    cout << "After removing value 3:" << endl;
    list.remove_value(3);
    list.display();

    cout << "Checking if the list is a palindrome:" << endl;
    if (list.isPalindrome())
        cout << "The list is a palindrome" << endl;
    else
        cout << "The list is not a palindrome" << endl;

    cout << "Even numbers moved to end in reversed order:" << endl;
    list.even_end_reversed();
    list.display();

    return 0;
}