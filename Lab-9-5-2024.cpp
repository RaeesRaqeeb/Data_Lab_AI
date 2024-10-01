#include<iostream>
#include<string>
#include<stdlib.h>
#include<time.h>

using namespace std;

class Student
{
    public:
        string name;

    public:
        Student()
        {
            cout<<"I am constructor\n";

        }
        ~Student()
        {
            cout<<"I am destructor\n";
        }

};

class Array_based_list
{
    public:
        public:
        int *My_Array;
        int size;
        int *Current_ptr;
        int *length;

        void insert(int value,int position)
        {
            
        }

};

int main(void)
{
    //Four segments 
    /*Code segment, Data segment, Stack segment , Heap segment*/
    int size;//
    cin>>size;//Taking size by user at runtime 
    int array[size];//Arrayins declaraed at the compile time
    //THis is wrong


    //Type of object

   // Student s1;//Regular object made in stack

    Student *s2= new Student();// made in heap segment must be destoried by the user to call the destructor

    cout<<s2->name;
    cout<<(*s2).name;

    int *arr1= (int*) calloc(size,5);
    int **my_array= new int*[5];

    for( int i=0;i<5;i++)
    {
        my_array[i]=new int[5];
    }

    srand(time(NULL));
    for (int i=0;i<5;i++)
    {
        
        for (int j=0;j<5;j++)
        {
            my_array[i][j]=rand()%9;
        }
    }



    for (int i=0;i<5;i++)
    {
        
        for (int j=0;j<5;j++)
        {
            cout<<my_array[i][j]<<" ";
        }
        cout<<" \n";
    }

    for(int i=0;i<5;i++)
    {
        delete my_array[i];
    }

    delete[] my_array;



    //Data Structure
    /*Array based list
    Linked list
    stack 
    quere
    heap 
    hashing
    BST
    AVL
    
    We use data structure according to the Data 
    
    O(n) array time complexicity
    
    Why Size of Array is fixed?
    Array is sequencial data structure
    adventage of Array:
    random access*/
    return 0;
}