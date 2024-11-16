#include<iostream>

using namespace std;

class Nodes
{
    public:
            Nodes *next;
            Nodes *prev;
            string info;

    Nodes(string value)
    {
        info= value;
        next=NULL;
        prev=NULL;
    }
            
};


class Double_Circular_Linked_list
{
    private:
            int length;
            Nodes *head;

    public:
    Double_Circular_Linked_list()
    {
        length=0;
        head=NULL;

    }
   
      void insertion(string value, int position)
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
                  Curr_ptr->next=head;
                }
            else
            {
                head=new_node;
                new_node->next=new_node;
                new_node->prev=new_node;
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
                new_node->next=slow2;
                slow2->prev=new_node;
                }

        length+=1;
    }
      
    void remove(int position)
    {
        //Position Checker
        if(position< 0)
        {
            cout<<"\nInvalid Position"<<endl;
            return;
        }

        if(position==1)
        {
            Nodes *Curr_ptr=head;
            head= Curr_ptr->next;
            Nodes *end_ptr=head;
            for (int i=1;i<length;i++)
            {
                end_ptr=end_ptr->next;
            }
            head->prev=end_ptr;
            end_ptr->next=head;

            delete Curr_ptr;
        }
        if(position==length)
        {
            Nodes *Curr_ptr=head;
            Nodes *End=head;
            
            for(int i=1;i<length-1; i++)
            {
                End= End->next;
            }
            
            End->next=Curr_ptr;
            Curr_ptr->prev=End;
        }
        else
        {
            Nodes *Curr_ptr=head;
            Nodes *slow_ptr=head;

            for( int i=1;i<position;i++)
            {
                slow_ptr=Curr_ptr;
                Curr_ptr=Curr_ptr->next;
            }
           
            if(Curr_ptr->next!=NULL)
                {slow_ptr->next=Curr_ptr->next;
                Curr_ptr=Curr_ptr->next;
                Curr_ptr->prev=slow_ptr;}
            else
            {
                delete Curr_ptr;
            }
            
            
        }
        length-=1;
        
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

    int position_finder(string value)
    {
        Nodes *curr=head;
        int position=1;
        do
        {
        if(curr->info==value)
        {
            return position;
        }
        else
            position+=1;
        
        curr=curr->next;
        }while (position!=length+1);

        return 0;
    }


    void remove_by_value(string value)
     {
    if (head == nullptr) return;

    Nodes *curr = head;
    Nodes *toDelete = nullptr;

    do {
        if (curr->info == value) {
            toDelete = curr;
            break;
        }
        curr = curr->next;
    } while (curr != head); 

    if (toDelete != nullptr) {
        if (toDelete->next == toDelete) {
            delete toDelete;
            head = nullptr; 
        } else {
            if (toDelete == head) {
                head = head->next;
            }
            toDelete->prev->next = toDelete->next;
            toDelete->next->prev = toDelete->prev;
            delete toDelete; 
        }
    }
    length-=1;
}
   

void Elimination_process(string starter, int jumps, int direction)
{   
    int position;
    int checker=1;
    int temp=length;
    string temp2;
    string servior;
    int j=1;
    cout<<"Elimination Sequence:"<<endl;
    if(direction==1)
    {
        Nodes *curr=head;
        while(1)
        {
            if(curr->info==starter)
                break;
            else if (checker==temp)
            {
                cout<<"Invaild starter!!!!\n";
                return;
            }
            else 
               {
                curr=curr->next;
                checker+=1;
               }
        }
        while(length!=1)
        {
            for(int i=0; i<jumps;i++)
            {
                curr=curr->next;

            }
                temp2=curr->info;
                curr=curr->next;
                servior=curr->info;
                remove_by_value(temp2);
                cout<<j<<". Eliminate person "<<temp2<<endl;
                j+=1;
            
        }
    }
    else if(direction==2)
    {
        Nodes *curr=head;
        while(1)
        {
            if(curr->info==starter)
                break;
            else if (checker==temp)
            {
                cout<<"Invaild starter!!!!\n";
                return;
            }
            else 
               {
                curr=curr->next;
                checker+=1;
               }
        }
        while(length!=1)
        {

             for(int i=0; i<jumps;i++)
            {
                if(curr->prev!=NULL)
                    curr=curr->prev;

            }
                temp2=curr->info;
            
                if(curr->prev!=NULL)
                    curr=curr->prev;
                servior=curr->info;
                remove_by_value(temp2);
                cout<<j<<". Eliminate person "<<temp2<<endl;
                j+=1;
        }
    }

    cout<<"Servivor is:"<<servior<<endl;
    

}

};


int main(void)
{

    Double_Circular_Linked_list DCL1;
    int user_choice;
    int direction;
    int jump_value;
    string name;
    int i=1;
   while(1)
   {
     cout<<"\nMENU:\n";
     cout<<"1. Add Person\n";
     cout<<"2. Start Elimination Process\n";
     cout<<"3. Exit\n";
     cout<<"\nUser input:";
     cin>>user_choice;
     if(user_choice==1)
     {
        cout<<"Enter the name for the person:";
        cin.ignore();
        getline(cin,name);

        DCL1.insertion(name,i);
        i+=1;
     }
     else if(user_choice==2)
     {
        cout<<"Enter the starting point:\n";
        DCL1.Doubly_display();
        cout<<"\nUserChoice:";
        cin.ignore();
        getline(cin,name);
        cout<<"Enter the jump value:";
        cin>>jump_value;
        cout<<"\nChoose the direction (1. Clockwise 2. Anticlockwise):";
        cin>>direction;
        DCL1.Elimination_process(name,jump_value,direction);
        i=0;
     }
     else  if(user_choice==3)
     {
        cout<<"Exiting the program"<<endl;
        break;
     }

   }





  
    DCL1.Doubly_display();

}