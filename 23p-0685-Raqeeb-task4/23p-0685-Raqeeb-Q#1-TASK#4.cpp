#include<iostream>

using namespace std;

class Nodes
{
    public:
            Nodes *Next;
            Nodes *Prev;
            int ID;
            string Name;
            int Quantity;
            int Price;

    Nodes(int value, string name, int quantity, int price)
    {
        ID= value;
        Name=name;
        Quantity=quantity;
        Next=NULL;
        Prev=NULL;
        Price= price;
    }


};


class Double_Linked_list
{
    private:
            int length;
            Nodes *head;

    public:
    Double_Linked_list()
    {
        length=0;
        head=NULL;

    }

    void insertion(int value, string name, int quantity,int price)
    {
        //Insertion with sorting the ID's
        Nodes *ptr1=head;
        Nodes *ptr2=head;
        Nodes *new_node= new Nodes(value,name,quantity,price);
        bool checker=false;
            
            if(head!=NULL)
            {
            for(int i=1;i<=length;i++)
            {
            if(ptr2->ID > new_node->ID)
            {
                new_node->Next=ptr2;

                
                if(ptr2==head)
                   {
                     head= new_node;
                    ptr2->Prev=new_node;
                   }
                else
                {
                    ptr1->Next=new_node;
                    new_node->Prev=ptr1;
                    ptr2->Prev=new_node;

                }
                checker=true;
                break;
            }
            
            ptr1=ptr2;
            if(ptr2->Next !=NULL)
                ptr2=ptr2->Next;

            
            }
            if(!checker)
            {
            ptr2->Next=new_node;
            new_node->Prev=ptr2;
            }
            }
            else
            {
                head=new_node;
            }
            

        
       

        length+=1;
    }

    void remove(int ID)
    {
        if(length==0)
        {
            cout<<"\nTheir is no product exist !!!!First add the products\n"<<endl;
            return;
        }
        Nodes *Curr_ptr=head;
        Nodes *Slow_ptr=head;

        for(int i=1;i<length;i++)
        {
            if(Curr_ptr->ID == ID)
            {
                if(Curr_ptr == head)
                {
                    head=Curr_ptr->Next;
                    delete Curr_ptr;
                    length-=1;

                    return;
                }
                else
                {
                    Slow_ptr->Next= Curr_ptr->Next;
                    Curr_ptr->Next->Prev=Slow_ptr;
                    delete Curr_ptr;
                    length-=1;

                    return;
                }
            }
            else
            {
                Slow_ptr=Curr_ptr;
                Curr_ptr=Curr_ptr->Next;

            }
        }
        if(Curr_ptr->Next == NULL)
        {
            cout<<"\nNo such ID exist!!!"<<endl;
            return;
        }
        
    }

    void Doubly_display()
    {
        if(length==0)
        {
            cout<<"Their are not products to show first add the products details!!!!!"<<endl;
            return;
        }
        cout<<"\nAll Products Details:\n";
        Nodes *Curr_ptr=head;
        for (int i=1; i<=length;i++)
        {   
            // cout<<i<<endl;
            cout<<"ID:"<<Curr_ptr->ID<<endl;
            cout<<"Name:"<<Curr_ptr->Name<<endl;
            cout<<"Quantity:"<<Curr_ptr->Quantity<<endl;
            cout<<"Price:"<<Curr_ptr->Price<<endl;
             if(Curr_ptr->Next!=NULL)
                Curr_ptr= Curr_ptr->Next;
                cout<<endl;
        }
        

    }

    void Update_price(int ID, int price)
    {
        if(length==0)
        {
            cout<<"\nTheir are no products yet !!!!\nAdd the products first!!!\n";
            return;
        }
        Nodes *curr=head;
        for(int i=1;i<=length;i++)
       { 
        if(curr->ID==ID)
        {
            curr->Price=price;
            cout<<"\n*********\nPrice is updated successfully !!!\n*********"<<endl;
            return;
        }
        curr=curr->Next;
       }
       cout<<"Invalid ID"<<endl;
    }

    void find_product(int id)
    {
        if(length==0)
        {
            cout<<"\nTheir are no products to find !!!!\nFirst add the products!!!\n";
            return;
        }
        Nodes *curr=head;
        for(int i=1;i<=length;i++)
       { if(curr->ID==id)
        {
            cout<<"\nProduct Details:"<<endl;
            cout<<"ID:"<<curr->ID<<endl;
            cout<<"Product Name:"<<curr->Name<<endl;
            cout<<"Quantity:"<<curr->Quantity<<endl;
            cout<<"Price:"<<curr->Price<<endl;
            return;
        }
        curr=curr->Next;
       }
    
        {
            cout<<"Invalid Id such ID does not exist!!!"<<endl;
        }
    }
};


int main(void)
{

    Double_Linked_list DL1;
    int user_input;
    int ID;
    string name;
    int quantity;
    int price;
    while(1)
    {

        cout<<"\n**************************"<<endl;
        cout<<"1)Add New Product\n2)Remove Product\n3)Display Product\n4)Update Price\n5)Find Product\n6)Exit";
        cout<<"\nUser input:";
        cin>>user_input;
        if(user_input==1)
        {
            cout<<"Enter Product ID in between (1-10):";
            cin>>ID;
            cout<<"Enter the Product Name:";
            cin.ignore();
            getline(cin,name);
            cout<<"Enter Quantity of Product:";
            cin>>quantity;
            cout<<"Enter the price of the product:";
            cin>>price;

            DL1.insertion(ID,name,quantity,price);
        }
        else if(user_input==2)
        {
            cout<<"Enter the ID of the Product you want to remove:";
            cin>>ID;
            cout<<"\n*******************************\n";

            DL1.remove(ID);
        }
        else if(user_input==3)
        {
            cout<<"\n*******************************\n";
            DL1.Doubly_display();
        }
        else if(user_input==4)
        {
            cout<<"Enter the ID:";
            cin>>ID;
            cout<<"Enter the price you want to Update:";
            cin>>price;
            cout<<"\n*******************************\n";

            DL1.Update_price(ID,price);
        }
        else if(user_input==5)
        {
            cout<<"Enter the ID:";
            cin>>ID;
            cout<<"\n*******************************\n";

            DL1.find_product(ID);
        }
        else if(user_input==6)
        {
            cout<<"**********************************************"<<endl;
            cout<<"Thanks for using our services. Have a nice day!"<<endl;
            cout<<"**********************************************"<<endl;

            break;
        }
    }











}