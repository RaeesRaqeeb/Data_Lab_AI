#include<iostream>
using namespace std;

class Nodes
{
    public:
    char info;
    Nodes *next; 

    Nodes(int value)
    {
        info= value;
        next=NULL;

    }

};

class Linked_List
{   
    private:
        Nodes *top;
        int length;

    public:
        Linked_List()
        {
            length=0;
            top =NULL;


        }

    void push(int value)
    {
        

        Nodes *n= new Nodes(value);
        Nodes *curr=top;
        if(top==NULL)
        {
            
            top=n;

        }
        else if(top!=NULL)
        {
            n->next=curr;
            top=n;
        }
        
        length++;
    }

    char pop()
    {
        if(length==0)
        {
            return 'N';
        }
        Nodes *curr=top;
        top=curr->next;
        length-=1;
        return curr->info;
        delete curr;

    }
    void display()
    {
        if(length!=0)
    {    Nodes *curr=top;
        for(int i=0;i<length;i++)
        {
            cout<<(curr)->info<<endl;
            curr=curr->next;
        }
        }
        else 
        {
            cout<<"\nThe linkedlist stack is empty"<<endl;
        }
    }

bool Bracket_validator(string value)
    {
        bool t=true,f=false;
        //These to check the open and close brackets
    char B1_open='(',B1_close=')',B2_open='[',B2_close=']',B3_open='{',B3_close='}';

        for(int i=0;i<value.size();i++)
        {
            if(i==0)
           { 
            if(value[i] != B1_close && value[i] != B2_close && value[i] !=B3_close)
                {
                    if(value[i]==B1_open || value[i]==B2_open || value[i]==B3_open)
                         push(value[i]);
                }
            else 
            {
                return f;
            }
        }
        else 
        {
            if(value[i] == B1_close || value[i] == B2_close || value[i] ==B3_close)
            {
                char poped_value=pop();
                if(value[i]==B1_close && poped_value==B1_open || value[i]==B2_close && poped_value==B2_open || value[i]==B3_close && poped_value==B3_open)
                {
                    continue;
                }   
                else
                {
                    return f;
                }
            }
            else 
            {
                if(value[i]==B1_open || value[i]==B2_open || value[i]==B3_open)
                     push(value[i]);
            }

        }

    }
    return t;
}

};



int main(void)
{
   

    Linked_List LD_1;
    while(1)
    {
    cout<<"Enter the brackets to check its validity:";
    string user_input;
    cin>>user_input;
    if(LD_1.Bracket_validator(user_input)==1)
    {
        cout<<"true"<<endl;
        cout<<"\nWant to end(1/0):";
        cin>>user_input;
        if(user_input=="1")
            break;
    }
    else 
    {
        cout<<"false"<<endl;
        cout<<"\nWant to end(1/0):";
        cin>>user_input;
        if(user_input=="1")
            break;
    }
    }
    return 0;
}