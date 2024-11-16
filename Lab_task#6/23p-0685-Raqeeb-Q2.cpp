    #include<iostream>


    using namespace std;

    class Nodes
    {
        public:
        int info;
        Nodes *Next; //It will point to the object of the class made in the main function

        Nodes(int value)
        {
            info= value;
            Next=NULL;

        }

    };


    class Queue
    {
        private:
                Nodes *front; //Like a head 
                Nodes *rear;
                int capacity;
                int length;
        
        public:
            Queue(int size)
            {
                capacity=size;
                length=0;
                front=NULL;
                rear=NULL;
            }

        void enqueue(int value)
        {
            
            Nodes *new_node= new Nodes(value);
            if(rear==NULL)
            {
                front=new_node;
                rear=new_node;
                
            }
            else
            {
                rear->Next=new_node;
                rear=new_node;
            }
            length++;

        }

        int dequeue()
        {
            if(front==NULL)
            {
                cout<<"THe queue is empty!!\n";
                return -1;
            }
            
            Nodes *curr=front;
            front=front->Next;
            int value=curr->info;
            delete curr;
            length--;
            return value;
        }

    


        void display()
        {
            Nodes *curr=front;
            for(int i=0;i<length;i++)
            {
                cout<<curr->info;
                curr=curr->Next;
            }
        }
        void insert_by_position(int value, int position)
        {
            if(position<1 || position>length+1)
            {
                cout<<"\nInvalid position input\n";
                return;
            }

            Nodes *n= new Nodes(value);

            if(position==1)
            {
                n->Next=front;
                front=n;
            }
            else //if the input position is between 1 and the length of the linked list
            {
                Nodes *Curr_ptr=front;

                for( int i=1; i<position-1;i++)
                {
                    Curr_ptr=Curr_ptr->Next;
                }
                n->Next=Curr_ptr->Next;
                Curr_ptr->Next=n;
            }
            length++;
        }

        void X_time_duplicating()
        {
            Nodes *Curr=front;
            int original=length;
            int position=1;
            int counter=1;
            for( int i=1;i<=original;i++)
            {
                int value=Curr->info;
                
            if(value > 1)
            {

                int times=Curr->info;
                if(Curr->Next !=NULL)
                Curr=Curr->Next;
                counter=1;
                while (times!=1)
                {
                    insert_by_position(value,position);
                    counter+=1;
                    times-=1;
                }
                position+=counter;
            
            }
            else 
                {
                    if(Curr->Next !=NULL)
                        Curr=Curr->Next;
                    position+=1;
                        
                }
            

        }
        }
    };


    int main(void)
    {
        Queue Q_LinkedLIst(5);
        Q_LinkedLIst.enqueue(1);
        Q_LinkedLIst.enqueue(2);
        Q_LinkedLIst.enqueue(3);
        Q_LinkedLIst.enqueue(4);
        Q_LinkedLIst.enqueue(1);
        Q_LinkedLIst.enqueue(6);
        Q_LinkedLIst.enqueue(7);
        Q_LinkedLIst.enqueue(8);
        Q_LinkedLIst.enqueue(9);

    cout<<"\nbefore:\n";


        Q_LinkedLIst.display();

        Q_LinkedLIst.X_time_duplicating();

    cout<<"\nAfter:\n";
        Q_LinkedLIst.display();


        return 0;
    }