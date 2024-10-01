#include<iostream>
#include<stdio.h>
#include<time.h>

using namespace std; 

class Array_based_list
{
    public:
        public:
        int *My_Array;
        int size;
        int *Current_ptr;
        int *length;

    Array_based_list(int size)
    {
        My_Array= new int[size];
        length=My_Array;
        this ->size=size;


    }
    
    bool Is_full()
    {
       return (length==My_Array+size)? true:false; 
    }

    bool Is_Empty()
    {
        return (length==My_Array)?true:false;
    }

    int* next(int *ptr)
    {
        return ++ptr;
    }

    int* back(int *ptr)
    {
        return --ptr;
    }

    void start()
    {
        Current_ptr=My_Array;

    }

    void tail()
    {
        
        Current_ptr=My_Array+*length;

    }

        void insert(int value,int position)
        {
            //Full condition
                if(Is_full())
                return;
                

            //Empty
                if(Is_Empty())
                return;
            //invalid position
            if(position<1 || My_Array+position-1 > length)
            {
                cout<<"\nInvalid Position";
                    return;
            }

            tail();
            for(int* i=length;i<(My_Array+position-1);--i)
            {
                *(Current_ptr+1)=*(Current_ptr);
                back(Current_ptr);
            }
            
            *(Current_ptr+1)=value;
            ++length;

        }

        void Input_values()
        {
            srand(time(NULL));
            for(int i=0;i<size-2;i++)
            {
                *(My_Array+i)=rand()%10;
                length++;
            }   
        }

        void output()
        {
            for( int *i=My_Array;i<length;i++)
            {
                cout<<*(i);
            }
        }


    //If the array is empty then the length pointer is at the zero index of the array
};


int main(void)
{
    Array_based_list My_obj(5);
    My_obj.Input_values();
    int user_input,value ;
    cout<<"\nEnter value and position to insert it in the array\n";
    cout<<"value:";
    cin>>value;
    cout<<"\nInput position:";
    cin>>user_input;
    My_obj.insert(value,user_input);
    My_obj.output();
}