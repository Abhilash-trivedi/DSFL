#include <bits/stdc++.h>
using namespace std;


struct node {
    string name;
    int pri;
    struct node *next;
};



class prior
{ struct node *front,*back;
public:
  prior()
  {
    front=NULL;
    back=NULL;
  }
void insert()
  { string name;
    int pri;
    cout<<"\nEnter name\n";
    cin>>name;
    cout<<"\nEnter priority\n1.General\n2.Medium\n3.Serious\n";
    cin>>pri;
    struct node* temp=new node;
    temp->name=name;
    temp->pri=pri;
    temp->next=NULL;


    if(front==NULL)
    {front=temp;
      back=temp;
      temp->next=NULL;

    }
  else{
        struct node* np;
          if(temp->pri==3)
          {
            temp->next=front;
            //front->next=temp;
            front=temp;

            return;
          }
          else if(temp->pri==1)
          {
            //temp->next=back;
            back->next=temp;
            back=temp;
            return;
          }
          else if(pri==2)
          { struct node* np,*n;
            np=front;
            if(np->next==NULL&&np->pri==1)
            {
              front=temp;
              temp->next=np;
            }
            else
            {

            while(np->next!=NULL){
              if(np->next->pri==2 || np->next->pri==1){
                break;
              }

              np=np->next;
            }
            if(np->next==NULL){
              np->next=temp;
              back=temp;
            }else{
              temp->next=np->next;
              np->next=temp;
            }

          }
        }

      }




  }

  void DisplayAll()
  {
    if(front==NULL)
    {
      cout<<"\nEmpty queue\n";

    }
    else
    {
      struct node* np;
      np=front;
      while(np!=NULL){cout<<"..................."<<endl;
        cout<<"NAME:"<<np->name<<endl;
        cout<<"PRIORITY:"<<np->pri<<endl;
        np=np->next;

      }
    }
  }
  void delet()
  {
    if(front==NULL)
    {
      cout<<endl<<"NO element present"<<endl;
    }
    else
    {
      struct node* np;
      np=front;
      front=front->next;
      delete np;
    }
  }
  void displays()
  {
    struct node* np=front;
    cout<<endl<<"Enter the priority you want to display"<<endl;
    int a;
    cin>>a;
    if(np==NULL)
    {
      cout<<"Empty"<<endl;
    }
    else
    {
    while(np->next!=NULL)
    {
      if(np->pri==a)break;
      np=np->next;
    }
    if(np==NULL)
    {
      cout<<"\nNO element present with given priority\n";

    }
    else
    {
      while(np->pri==a)
      {
        cout<<"NAME:"<<np->name<<endl;
        cout<<"priority:"<<np->pri<<endl;
        np=np->next;
      }
    }
  }


  }
};




int main()
{


  int ch;
  prior ob;
  do {
    cout<<"\n1.insert\n2.DisplayAll\n3.Display Specific\n4.Delete"<<endl;
    cin>>ch;
    switch(ch)
    {
      case 1:
      {
      ob.insert();
        break;
      }
      case 2:
      {
        ob.DisplayAll();
        break;
      }
      case 4:
      {
        ob.delet();
        break;
      }
      case 3:
      {
        ob.displays();
        break;
      }

    }

  } while(ch!=0);
}
