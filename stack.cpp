
#include <bits/stdc++.h>
using namespace std;


struct Node {
    char data;
    struct Node* link;
};


bool isOperator(char x)
 {
  switch (x) {
  case '+':
  case '-':
  case '/':
  case '*':

    return true;
  }
  return false;
}

void push(char a,struct Node* top)
{

    struct Node* temp;
    temp = new Node();


    if (!temp) {
        cout << "\nNode not created\n";
        exit(1);
    }
  temp->data=a;
  temp->link=top;
  top=temp;

}


int isEmpty(struct node* top)
{
    if(top == NULL)
    cout<<"Empty stack";
    else
    {
      cout<<"Non empty stack";
    }
}


int peek()
{

    if (!isEmpty())
        return top->data;
    else
        exit(1);
}



void pop()
{
    struct Node* temp;


    if (top == NULL) {
        cout << "\nStack didn,t have element to delete\n" << endl;
        exit(1);
    }
    else {

        temp = top;
        top = top->link;
        temp->link = NULL;
        free(temp);
        cout<<"Deletion successful\n";
    }
}

void check(string data,struct Node* top1,struct Node* top2)
{ char b[100];
  int j=0;
  for (int i = 0; i < data.size(); i++)
  {
    if(isOperator(data[i]))
    {
      push(data[i],top1);
    }
    else
    {
      push(data[i],top2);
    }
  }
}


void display(struct node* top)
{
    struct Node* temp;
    if (top == NULL) {
        cout << "\nStack didn't have any element\n";
        exit(1);
    }
    else {
        temp = top;
        while (temp != NULL) {


            cout <<  temp->data << " ";


            temp = temp->link;
        }
    }
}


int main()
{ int ch;
  struct Node* top1=NULL,top2=NULL;
  do { cout<<"0.Exit\n1.Enter a element in stack\n2. Delete element from stack\n3.Display stack\n4.check if stack is empty or not\n5.Display top element";
      cin>>ch;
      switch(ch)
      {
        case 1:
        { string data;
          cout<<"Enter string \n";
          cin>>data;
          check(data,top1,top2);
          break;
        }
        case 2:
        {
          pop();
          break;
        }
        case 3:
        {
          display(top1);
          cout<<"\n";
          cout<<"STRING IS:"<<
          break;
        }
        case 4:
        {
          isEmpty(top1);
        }
        case 5:
        {

        }
      }

  }while(ch!=0);

    return 0;


}
