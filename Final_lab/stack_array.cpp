#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<climits>
using namespace std;


class Stack_list
{
    private:
        int *Array_ptr;
        int capacity;
        int top;

    public:

        Stack_list(int size)
        {
            Array_ptr= new int[size];
            capacity=size;
            top=-1;
        }

       
       bool IsFull()
       {
            if(top +1== capacity)
            {
                return true;
            }
            else 
                 return false;
       }
        bool IsEmpty()
       {
            if(top ==-1)
            {
                return true;
            }
            else 
            return false;
       }
        
        bool push(int value)
        {
            if(IsFull())
            {
                cout<<"\nStack is full. you cannot push any other value in it"<<endl;
                return false;
            }
            
            
            Array_ptr[top+1]=value;
            top+=1;
           
        }

        void Display_The_Array()
        {
            for(int i=top;i>=0;i--)
            {
                cout<<Array_ptr[i]<<endl;
            }
        }

 
       
    int pop()
    {
        if(IsEmpty())
        {
            cout<<"The stack is empty ";
            return -1;
        }
        else
        {
        int value=Array_ptr[top];
        top-=1;
        return value;
        }
        
    }

    int peek()
    {
        if(!IsEmpty())
        {
            return Array_ptr[top];
        }
        else
        {
            cout<<"\nThe stack is empty\n";
            return -1;
        }
    }


    void sort() {
        Stack_list tmp(capacity); // Initialize a temporary stack
        while (!IsEmpty()) {
            int x = pop(); // Pop an element from the original stack
            while (!tmp.IsEmpty() && tmp.peek() > x) {
                // Pop elements from the temporary stack and push them back onto the original stack        	
                push(tmp.pop()); 
            }
            // Push the popped element onto the temporary stack    
            tmp.push(x); 
        }
        // Copy elements from the temporary stack back to the original stack
        while (!tmp.IsEmpty()) {
            push(tmp.pop());
        }
    } 

    void Duplicate_remove()
    {
        if(IsEmpty())
        {
            cout<<"The stack is  empty"<<endl;
            return;
        }


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
 int main(void)
 {

    Stack_list Obj1(5);

int value;
for(int i=0;i<5;i++)
{
    value=Obj1.pop();
   if(value!=-1)
   {
        cout<<value<< " is poped from the stack"<<endl;
   }
   else if(value==-1)
   {
    break;
   }
}
    Obj1.push(1);
    Obj1.push(2);
    Obj1.push(3);
    Obj1.push(4);
    Obj1.push(5);
    Obj1.push(7);
    Obj1.push(0);
    Obj1.push(9);

cout<<"\nThe values are reversed:"<<endl;
Obj1.Display_The_Array();


cout<<endl;
cout<<"Peek value:";
cout<<Obj1.peek()<<endl;

cout<<"The values are reversed:"<<endl;

Obj1.Display_The_Array();
cout<<"INT MIN"<<larger<<endl;
Obj1.sort();
cout<<"Sorted"<<endl;
Obj1.Display_The_Array();

    return 0;
 }