#include <iostream>
#include<stack>
using namespace std;

class Queue
{

    int front;
    int rear;
    int size;
    int *arr;

public:
    Queue(int size)
    {
        front = -1;
        rear = -1;
        this->size = size;
        arr = new int[size];
    }
    bool isEmpty()
    {
        if (front == -1 && rear == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool isFull()
    {
        if (((rear + 1) % size) == front)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void enqueue(int val)
    {
        if (isFull())
        {
            cout << "Queue is full" << endl;
            return;
        }
        else if (isEmpty())
        {
            front = 0;
            rear = 0;
        }
        else
        {
            //It give us the next index
            rear = (rear + 1) % size;
        }
        arr[rear] = val;
        // cout << "Enqueued: " << val << endl;
    }
    int dequeue()
    {
        if (!isEmpty())
        {
            int val = arr[front];
            if (front == rear)
            {
                front = -1;
                rear = -1;
            }
            else
            {
                //Move front to next value
                front = (front + 1) % size;
            }
            // cout << "Dequeued: " << val << endl;
            return val;
        }
        else
        {
            cout << "Queue is empty" << endl;
            return 0;
        }
    }
    int getFront()
    {
        int f = arr[front];
        cout << "front: " << front << endl;
        return f;
    }
    int getRear()
    {
        int r = arr[rear];
        cout << "rear: " << rear << endl;
        return r;
    }

  void display()
{
    if (isEmpty())
    {
        cout << "Queue is empty" << endl;
        return;
    }
    int i = front;
    while (true)
    {
        cout << arr[i] << " ";
        if (i == rear) break; // Stop when we reach the rear
        i = (i + 1) % size; // Move to the next index
    }
    cout << endl;
}

    int length()
    {
        if(isEmpty())
        {
            cout<<"The queue is empty"<<endl;
        }
        else if(front==0)
        {
            // cout<<"Length of queue is:"<<rear+1<<endl;
            return rear+1;
        }
        else if(rear > front)
        {
            // cout<<"Length of queue is:"<<(rear-front)+1<<endl;
            return (rear-front)+1;
        }
        else if(front> rear)
        {
            // cout<<"Length of queue is:"<<size-(front-(rear+1))<<endl;
             return (size-(front-(rear+1)));
        }
        
        return -1;
    }

    
};


void reverse_evens(Queue *obj)
{
    stack <int> s;
    int size2=obj->length();
    for( int  i = 1; i<=size2; i++)
    {
        int value;
        if(i%2==0)
        {
         value=obj->dequeue();
            s.push(value);
            obj->enqueue(value);
        }
        else
        {
            value=obj->dequeue();
            obj->enqueue(value);
        }
    }
    int value1=s.size();
  
    for(int i=1;i<=size2;i++)
    {
        int value;
        if(i%2 == 0)
        {
            obj->dequeue();
            value=s.top();
            obj->enqueue(value);
            s.pop();
        }
        else
        {
            value=obj->dequeue();
            obj->enqueue(value);
        }
    }
  

}

int main()
{
    Queue q(11);
    q.enqueue(14);
    q.enqueue(13);
    q.enqueue(17);
    q.enqueue(8);
    q.enqueue(5);
    q.enqueue(10);
    q.enqueue(11);
    q.enqueue(4);
    q.enqueue(15);
    q.enqueue(18);
    q.enqueue(19);

    // q.length();
    q.display();

    reverse_evens(&q);

    q.display();

}