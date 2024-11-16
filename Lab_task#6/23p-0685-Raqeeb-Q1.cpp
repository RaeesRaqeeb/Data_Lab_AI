#include <iostream>
#include <string>

using namespace std;

class Node {
public:
    string item_name;
    int price;
    Node* next;

    Node(string name, int price)
    {
        item_name = name;
        price = price;
        next = NULL;
    }
};

class Queue {
private:
    Node* front;
    Node* rear;
    int length;

public:
    Queue()
     {
        front=NULL;
        rear=NULL;
        length=0;
     }

    void enqueue(string value, int price) {
        Node* new_node = new Node(value, price);
        if (rear == nullptr)
         {
            front = new_node;
            rear = new_node;
        } else 
        {
            rear->next = new_node;
            rear = new_node;
        }
        length++;
        cout<<"\n";
        cout<<"********************************\n";
        cout << value << " added to the queue.\n";
        cout<<"********************************\n";

    }

   
    void dequeue() {
        if (front == nullptr)
        {
            cout << "\nThe queue is empty! No orders to process.\n";
            return;
        }

        Node* curr = front;
        front = front->next;
        cout<<"\n********************************\n";

        cout << "Processing order: " << curr->item_name << " ($" << curr->price << ")\n";
        cout<<"\n********************************\n";

        delete curr;
        length--;

        if (front == nullptr) 
        {
            rear = nullptr; 
        }
    }

    // Display current orders in the queue
    void display() {
        if (front == nullptr)
         {
            cout << "\nNo current orders in the queue.\n";
            return;
        }

        cout<<"\n********************************\n";
        cout << "Current orders in the queue:\n";
        Node* curr = front;
        while (curr != nullptr) 
        {
            cout << "- " << curr->item_name << " ($" << curr->price << ")\n";
            curr = curr->next;
        }
        cout<<"\n********************************\n";

    }

    // Check if the queue is empty
    bool isEmpty() {
        return front == nullptr;
    }
};

void displayMenu() 
{
    cout << "\nAvailable food items and beverages:\n";
    cout << "1. Sabzi - $120\n";
    cout << "2. Bendi - $150\n";
    cout << "3. Biryani - $250\n";
    cout << "4. Remove the proceed orders \n";
    cout<<  "5. Display the orders in Queue\n";
    cout << "6. Quit\n";
}

int main() {
    Queue orderQueue;
    int choice;

    while (1) 
    {
        displayMenu();
        cout << "Select an option (1-4): ";
        cin >> choice;

        switch (choice) {
            case 1:
                orderQueue.enqueue("Sabzi", 120);
                break;
            case 2:
                orderQueue.enqueue("Bendi", 150);
                break;
            case 3:
                orderQueue.enqueue("Biryani", 250);
                break;
            case 4:
                orderQueue.dequeue();
                break;

            case 5:
                orderQueue.display();
                break;

            case 6:
                cout << "Exiting the application.\n";
                return 0;
            default:
                cout << "Enter a valid choice.\n";
                continue;
        }
    }


    return 0;
}

