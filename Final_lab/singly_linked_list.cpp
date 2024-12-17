#include<iostream>
#include<vector>

using namespace std; 


class Node
{
    public:
        int info;
        Node* next;
        
    Node(int info)
    {
        this -> info= info;
        next= NULL;
    }

};


class singly_Linked_list
{

    public:
        Node *head;
        int length;
        singly_Linked_list()
        {
            head=NULL;
            length=0;
        }

        void insertion_value(int value)
        {
            if(head==NULL)
            {
                head= new Node(value);
                return;
            }

            Node *curr=head;
            while(curr->next!=NULL)
            {
                curr=curr->next;
            }
            curr->next=new Node(value);
            length++;
        }

        void insertion_at(int value, int position)
        {
            //Position check
            if(position<0 || position>length+1)
            {
                cout<<"INvalid position entered !!!"<<endl;
                return;
            }
            
            Node *New_node= new Node(value);
            if(position==1)
            {
                if(head!=NULL)
                    {
                        New_node->next=head;
                        head=New_node;
                    }
                else
                {
                    head=New_node;
                }
            }
            else 
            {
                //For moving through the linked list we make tem ptr
                Node *Curr_ptr= head;
                for (int i=1;i<position-1;i++)
                {
                    Curr_ptr=Curr_ptr->next;
                }
                New_node->next=Curr_ptr->next;
                Curr_ptr->next=New_node;
            }
            length+=1;


        }

 
        void remove_value(int value)
        {
            if(head==NULL)
            {
                cout<<"The linked list is empty"<<endl;
                return;
            }

            if(head->info == value)
            {
                Node *temp=head;
                head=head->next;
                delete temp;
            }
            else
            {
                Node *curr=head;
                while(curr->next->info != value)
                {
                    curr=curr->next;
                }
                Node *temp=curr->next;  
                curr->next=curr->next->next;
                delete temp;
            }
            length--;
        }

        void display()
        {
            Node *curr=head;
            while(curr!=NULL)
            {
                cout<<curr->info<<" ";
                curr=curr->next;
            }
            cout<<"\n"<<endl;
        }


        void dividing_list(singly_Linked_list &obj)
        {
            if(head==NULL)
              {  cout<<"the linked list is empty "<<endl;
                return;
              }
              Node *curr=head;
              int count=0;
              cout<<"Here"<<endl;
              while(count!=(length/2))
              {
                curr=curr->next;
                count++;
              }
              cout<<"Here"<<endl;

              Node *temp=curr;

             while (curr != NULL || curr->next != NULL) 
             {
                obj.insertion_value(curr->info);
                
                cout << "Here" << endl;
                if(curr->next == NULL ||curr ==NULL)
                    break;
                else
                {
                    curr = curr->next;
                    cout << "Here2" << endl;
                }

            }
              cout<<"Here"<<endl;

              vector<int> values_to_remove;
              while(temp != NULL)
              {
                  values_to_remove.push_back(temp->info);
                  temp = temp->next;
              }

              for(int value : values_to_remove)
              {
                  remove_value(value);
              }
              
        }   

         void dividing_at(singly_Linked_list &obj, int value)
        {
            if(head==NULL)
              {  cout<<"the linked list is empty "<<endl;
                return;
              }
              Node *curr=head;
              while(curr->info!=value)
              {
                curr=curr->next;

              }

              Node *temp=curr;

             while (curr != NULL || curr->next != NULL) 
             {
                obj.insertion_value(curr->info);
                
                if(curr->next == NULL ||curr ==NULL)
                    break;
                else
                {
                    curr = curr->next;
                }

            }

              vector<int> values_to_remove;
              while(temp != NULL)
              {
                  values_to_remove.push_back(temp->info);
                  temp = temp->next;
              }

              for(int value : values_to_remove)
              {
                  remove_value(value);
              }
              length++;

              cout<<"removing length:"<<length<<endl;
        }   

        void Merging_list(singly_Linked_list &obj1, singly_Linked_list &obj2)
        {
            obj1.length+=1;
            length=obj1.length+obj2.length;

            if(obj1.head==NULL && obj2.head == NULL)
            {
                cout<<"The linked list is empty"<<endl;
                return;
            }

            Node *curr=obj1.head;
            Node *cur2=obj2.head;
            while(curr != NULL)
            {
            if(curr->next == NULL ||curr ==NULL)
                    break;
                else
                {
                    curr = curr->next;
                }
            }

            curr->next=obj2.head;

            head=obj1.head;
        }
        
        void sorting_linkedlist()
        {
            if(head==NULL)
            {
                cout<<"The linkedlist is empty"<<endl;
                return;
            }
            Node *curr=head;
            while(curr != NULL)
            {
                Node *curr2=curr->next;
                while(curr2 != NULL)
                {
                    if(curr->info > curr2->info)
                    {
                        int temp=curr->info;
                        curr->info=curr2->info;
                        curr2->info=temp;
                    }
                    curr2=curr2->next;
                }
                curr=curr->next;
            }
        }
        void Clear_linkedlist()
        {
            if(head==NULL)
            {
                cout<<"The linkedlist is already empty"<<endl;
                return;
            }
            Node *curr=head;
            while(curr != NULL)
            {
                Node *temp = curr;
                curr = curr->next;
                delete temp;
            }
            head = NULL;
            length = 0;
        }

        void reversing_linkelist()
        {
            if(head==NULL)
            {
                cout<<"THe linkedlist is empty"<<endl;
                return;
            }

            int arr[length];
            Node *curr=head;
            for(int i=0;i<=length;i++)
            {
                arr[i]=curr->info;
                if(curr!=NULL || curr->next!=NULL)
                     curr=curr->next;
            }

            int temp=length;

            Clear_linkedlist();
            for(int i=temp;i>=0;i--)
            {
                insertion_value(arr[i]);

            }

        }

        void Merged_sort(singly_Linked_list &obj1,singly_Linked_list &obj2)
        {
            Merging_list(obj1,obj2);
            sorting_linkedlist();
            display();
        }

    bool checkPalindrome(Node*& left, Node* right) 
       {
                // Base case
                if (right == nullptr) {
                    return true;
                }

                bool result = checkPalindrome(left, right->next) && (left->info == right->info);
                left = left->next;

                return result;
        }

// Function to check if the linked list is a palindrome
    bool isPalindrome()
        {
            return checkPalindrome(head, head);
        }


void even_end_reversed()
{
    if (head == NULL) {
        cout << "The list is empty" << endl;
        return;
    }

    Node *curr = head;
    Node *prev = NULL;
    singly_Linked_list even;

    while (curr != NULL) 
    {
        cout << curr->info << endl;

        if (curr->info % 2 == 0)
        {
            even.insertion_value(curr->info);
            if (prev == NULL) 
            {
                head = curr->next;
            } 
            else 
            {
                prev->next = curr->next;
            }
            Node *temp = curr;
            curr = curr->next;
            delete temp;
        }
        else
        {
            prev = curr;
            curr = curr->next;
        }
    }

    cout << "Odd" << endl;
    display();
    cout << "Even number:" << endl;
    // even.display();

    even.reversing_linkelist();
    // even.display();
    curr=head;
    while(curr->next !=NULL)
        curr=curr->next;

    Node *even_cur=even.head;
    
        curr->next=even_cur;
    
    display();
    
}
};


int main(void)
{
    singly_Linked_list obj1,obj2,obj3;

    obj1.insertion_value(90);
    obj1.insertion_value(91);
    obj1.insertion_value(92);
    obj1.insertion_value(93);
    obj1.insertion_value(94);
    obj1.insertion_value(96);
    obj1.insertion_value(97);
    obj1.insertion_value(95);

    cout<<"Before division of linkedlist"<<endl;
    obj1.display();

    obj1.dividing_at(obj2,94);

    cout<<"AFter division of linkedlis"<<endl;
    obj1.display();
    cout<<"New linkedlist"<<endl;
    obj2.display();

    //Using merged sort function
    obj3.Merged_sort(obj2,obj1);
    // obj3.Merging_list(obj2,obj1);
    // cout<<"after merging:"<<endl;
    // obj3.display();

    // cout<<"Applying the reversing function"<<endl;
    // obj3.reversing_linkelist();
    // obj3.display();


    // obj3.sorting_linkedlist();
    // obj3.display();

    singly_Linked_list pal;
    pal.insertion_value(1);
    pal.insertion_value(2);
    pal.insertion_value(3);
    pal.insertion_value(2);
    pal.insertion_value(6);
    pal.insertion_value(4);
    pal.insertion_value(5);
    pal.insertion_value(7);
    pal.insertion_value(8);
    pal.display();
    // pal.palindrome();
    pal.even_end_reversed();


    singly_Linked_list palendrom;
    palendrom.insertion_value(1);
    palendrom.insertion_value(2);
    palendrom.insertion_value(3);
    palendrom.insertion_value(2);
    palendrom.insertion_value(4);
    if(palendrom.isPalindrome())
    {
        cout<<"The linkedlist is Palendrom"<<endl;
        return 0;
    }
    else    
        cout<<"The linked list is not palendrom"<<endl;
    
    return 0;
}