#include<iostream>

using namespace std;


class Queue_array
{
    public:
        int *arry;
        int capacity;
        int front;
        int rear;

        Queue_array(int size)
        {
            capacity=size;
            arry= new int(size);
            front=-1;
            rear=-1;
        }

        bool is_empty()
        {
            if(front=rear=-1)
            {
                return true;
            }
            else
                return false;

        }


        bool is_full()
        {
            if((rear+1 % capacity)==front)
            {
                return true;
            }
            else 
                return false;
        }
        void enqueue(int value)
        {

        }


        void enqueue(int value)
        {
            if(is_full())
            {
                cout<<"The Queue is full no enqueue is possible"<<endl;
                return;
            }

            if(is_empty())
            {
                rear=0;
                front=0;
            }
            else
            {
                rear=(rear+1)%capacity;
            }

            arr[rear]=value;

        }


        void dequeue()
        {
            if(is_empty())
            {
                cout<<"The queue is empty:"<<endl;
                return;
            }
            else
            {
                int value= arr[front];
                if(rear==front)
                {
                    rear=-1;
                    front=-1;
                }
                else 
                {
                    front=(front+1)%capacity;
                }
            }

            return value;

        }

};