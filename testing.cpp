
#include<iostream>

using namespace std;

class Nodes
{
public:
Nodes *Next;
string song_name;

Nodes(string name)
{
song_name= name;
Next=NULL;
}

};

class Circular_singly_Linked_list
{
private:
int length;
Nodes *head;

public:
Circular_singly_Linked_list()
{
length=0;
head=NULL;

}

void insertion(string value, int position)
{
//Position check
if(position<0 || position>length+1)
{
cout<<"INvalid position entered !!!"<<endl;
return;
}
Nodes *New_node= new Nodes(value);
if(position==1)
{
if(head!=NULL)
{
New_node->Next=head;
head=New_node;
Nodes *curr_ptr= head;
for (int i=1;i<=length;i++)
{
curr_ptr=curr_ptr->Next;
}
curr_ptr->Next=New_node;
}
else
{
head=New_node;
New_node->Next=head;
}
}
length+=1;

}
void display_linked_list()
{
Nodes *Curr_ptr=head;
if(length==0)
{
cout<<"\nPlaylist is empty!!!Enter the songs name first\n";
return;
}
for(int i=1;i<=length;i++)
{
cout<<i<<")"<<Curr_ptr->song_name<<endl;

Curr_ptr=Curr_ptr->Next;
}
}

//removing song from the end of playlist
string remove()
{
Nodes *curr1=head;
Nodes *slow=head;

if(length==0)
{
cout<<"\nThe playlist is empty! First add some songs"<<endl;
return " ";
}
for(int i=0;i<length-1;i++)
{
slow=curr1;
curr1=curr1->Next;
}
slow->Next=head;
string value=curr1->song_name;
length-=1;
delete curr1;
return value;
}
};

int main(void)
{
Circular_singly_Linked_list CSL1;
int user_input;
while(1)
{
cout<<"\n***********SONGS PLAYLIST**************\n";
cout<<"1)Add new song\n2)Remove Song from the end of the list\n3)Display all songs\n4)Quit";
cout<<"\nUser_input:";
cin>>user_input;
if(user_input==1)
{
cout<<"\nEnter the name of song you want to enter:";
string song_name;
cin.ignore();
getline(cin,song_name);
CSL1.insertion(song_name,1);
cout<<"Song Added successfully!"<<endl;
}
else if(user_input==2)
{ 

string check=CSL1.remove();
if(check!=" ")
{
cout<<check<<" is the removed value from the playlist"<<endl;
}
}
else if(user_input==3)
{
cout<<"\nSongs in Playlist\n";
CSL1.display_linked_list();
}
else if(user_input==4)
{
break;
}
}

}

