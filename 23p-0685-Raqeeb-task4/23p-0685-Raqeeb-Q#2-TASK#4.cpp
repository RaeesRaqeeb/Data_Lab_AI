#include<iostream>


using namespace std;


class Nodes
{
    public:
            Nodes *next;
            int info;
            Nodes *prev;

    Nodes(int value)
    {
        info=value;
        next=NULL;
        prev=NULL;
    }

};

class LinkedList
{
    private:
            Nodes *head;
            int length;

    public:
            LinkedList()
            {
                head=NULL;
                length=0;
            }

      void insertion(int value, int position)
    {
        //Position check
        if(position<0 || position> length+1)
        {
            cout<<"\nInvalid Position entered!!!!!"<<endl;
            return;
        }

        Nodes *new_node= new Nodes(value);
       if(position==1)
        {
            if(head!=NULL)
                {
                Nodes *Curr_ptr=head;
                new_node->next=Curr_ptr;
                Curr_ptr->prev=new_node;
                head=new_node;
                for(int i=1;i<length;i++)
                {
                  Curr_ptr=Curr_ptr->next;
                
                
                  }
                  
                }
            else
            {
                head=new_node;
            }
        }
       
        else if(position!=length+1)
        {
            Nodes *Curr_ptr=head;
            Nodes *slow2=head;
            for (int i=1;i<position;i++)
            {
                slow2=Curr_ptr;
                Curr_ptr=Curr_ptr->next;
            }
            new_node->next=Curr_ptr;
            slow2->next=new_node;
            Curr_ptr->prev=new_node;
            new_node->prev=slow2;   
        }
        else//For insertion at the end of the circular doubly linkedlist
        {   Nodes*Curr_ptr=head;
            Nodes *slow2=head;
            
            for (int i=1;i<position-1;i++)
            {
            
                Curr_ptr=Curr_ptr->next;
            }
            
                Curr_ptr->next=new_node;
                new_node->prev=Curr_ptr;
                }

    
        

        length+=1;
    }
        
        void Odd_creator(LinkedList OL)
        {
            Nodes *Curr1=head;
            Nodes *Curr2=OL.head;

             for( int i=1;i<=OL.length;i++)
            {
                if(Curr2->info % 2 != 0)
                {
                Nodes *new_node= new Nodes(Curr2->info);
                if(head==NULL)
                   { 
                    head=new_node;
                    Curr1=new_node;
                   }
                else
                {
                    Curr1->next=new_node;
                    new_node->prev=Curr1;
                    Curr1= Curr1->next;
                }
                
                length+=1;
                }
                Curr2=Curr2->next;

            }
            Curr1->next=head;

        }
     void Even_creator(LinkedList OL)
        {
            Nodes *Curr1=head;
            Nodes *Curr2=OL.head;

             for( int i=1;i<=OL.length;i++)
            {
                if(Curr2->info % 2 == 0)
                {
                Nodes *new_node= new Nodes(Curr2->info);
                if(head==NULL)
                   { 
                    head=new_node;
                    Curr1=new_node;
                   }
                else
                {
                    Curr1->next=new_node;
                    new_node->prev=Curr1;
                    Curr1= Curr1->next;
                }
                
                length+=1;
                }
                Curr2=Curr2->next;

            }
            Curr1->next=head;

        }
          void Doubly_display()
    {
        Nodes *Curr_ptr=head;
    
        for (int i=1; i<=length;i++)
        {   
            cout<<Curr_ptr->info<<endl;
                Curr_ptr= Curr_ptr->next;
        }
        

    }

};


int main(void)
{
    LinkedList OL,L1,L2;

    for(int i=1;i<=10;i++)
    {
        OL.insertion(i,i);
    }

    OL.Doubly_display();

    L1.Odd_creator(OL);
    L2.Even_creator(OL);

    cout<<"Odd number linked list:"<<endl;
    L1.Doubly_display();

    cout<<"Even number linked list:"<<endl;
    L2.Doubly_display();


    return 0;
}