#include<bits/stdc++.h>
#include<string.h>
using namespace std;

struct node
{
	char data;
	struct node *next;
};
 struct Node
 {
 	int data;
 	struct Node *next;
 };

class stack1
{
	node *top;
	public:
	stack1()
	{
		top=NULL;
	}
	void push(char data)
	{
		node *temp=new node;
		temp->data=data;
		if(top==NULL)
		{
			temp->next=NULL;
			top=temp;
		}
		else
		{
			temp->next=top;
			top=temp;
		}
	}
	void pop()
	{
		node *temp=top;
		top=temp->next;
		delete(temp);
	}
	void display()
	{
		node *temp=top;
		while(temp!=NULL)
		{
			cout<<temp->data<<" ";
			temp=temp->next;
		}
		cout<<"\n";
	}
	
	bool is_empty()
	{
		if(top==NULL)
		return true;
		else 
		return false;
	}
	char top1()
	{
		return top->data; 
	}
	
	int priority(char a)
	{
	if(a=='/' )
	return 4;
	if(a=='*')
	return 3;
	if(a=='+')
	return 2;
	if(a=='-')
	return 1;
	if(a=='(')
	return 0;
	else
	return 0;
	}
	bool priority_1(char a,char b)
	{
		if(priority(a)<priority(b))
		return true;
		else return false;
		
	}
	
	char post (char inp[],char op[])
	{
	int x=strlen(inp);
	int k=0;
	for(int i=0;i<x;i++)
	{
		if(inp[i]=='(' )
		{
			push(inp[i]);
		}
		if(isalnum(inp[i]))
		{
			op[k]=inp[i];
			k++;
		}
		if( inp[i]=='+' || inp[i]=='-' || inp[i]=='/' || inp[i]=='*')
		{
					
			while(!is_empty() && top1()!='(' && priority_1(top1(),inp[i]) )
				{
					op[k]=top1();
					k++;
					pop();
				}
				push(inp[i]);
			
		}
		if(inp[i]==')')
		{
			while(!is_empty() && top1()!='(')
			{
				op[k]=top1();
				k++;
				pop();
			}
			pop();
			
		}
	
	}
	
	while(!is_empty())
	{
			op[k]=top1();
			k++;
			pop();
	}
	return *op;
	}
	
	void reverse(char inp[])
	{
	
		int start=0;
		int end=strlen(inp)-1;
		while(start<end)
		{
			char temp=inp[start];
			inp[start]=inp[end];
			inp[end]=temp;
			start++;
			end--;
		}
		
		
	}
	void prefix(char inp[],char new_op[])
	{
		
		reverse(inp);
		for(int i=0;i<strlen(inp);i++)
		{
			if(inp[i]==')'){
			
			inp[i]='(';i++;}
			if(inp[i]=='('){
			
			inp[i]=')';i++;}
		}
		
		*new_op=post(inp,new_op);
		reverse(new_op);
		
		
		
	}

};

class stack2
{
	Node *top;
	public:
	stack2()
	{
		top=NULL;
	}
	void push(int data)
	{
		Node *temp=new Node;
		temp->data=data;
		if(top==NULL)
		{
			temp->next=NULL;
			top=temp;
		}
		else
		{
			temp->next=top;
			top=temp;
		}
	}
	void pop()
	{
		Node *temp=top;
		top=temp->next;
		delete(temp);
	}
	int top1()
	{
		return top->data; 
	}
	
		void Evaluate(char op[])
	{
		char hash[26]={0};
		int inp[100];
		int k=0,x,y;
		for(int i=0;i<strlen(op);i++)
		{
			
			if(isalnum(op[i]) && hash[op[i]-97]==0)
			{
				cout<<"Enter the value for "<<op[i];
				cin>>k;
				push(k);
			}
			if( op[i]=='+')
			{
				 x=top1();
				pop();
				 y=top1();
				pop();
				push(x+y);
			}
			if(op[i]=='-')
			{
				x=top1();
				pop();
				y=top1();
				pop();
				push(y-x);
			}
			if(op[i]=='/')
			{
				x=top1();
				pop();
				y=top1();
				pop();
				push(y/x);
			}
			if(op[i]=='*')
			{
				x=top1();
				pop();
				y=top1();
				pop();
				push(x*y);
			}
			
		}
		cout<<top1();
	}
};





int main()
{
	char inp[100],op[100],new_op[100];
	stack1 s,h;
	stack2 t;
	int x;
	string q;
	cout<<"Enter the inflix expression\n";
	cin>>inp;
	
	
	do
	{
		cout<<"1.inflix to post-fix\n2.inflix to pre-fix\n3.Evaluate\n4.Exit\n";
		cin>>x;
		if(x==1)
		{
			*op=s.post(inp,op);
			for(int i=0;i<strlen(op);i++)
			cout<<op[i];
			cout<<"\n";	
		}
		if(x==2)
		{
			s.prefix(inp,new_op);
			for(int i=0;i<strlen(new_op);i++)
			cout<<new_op[i];
			cout<<"\n";
		}
		if(x==3)
		{
			t.Evaluate(op);
		}
	}while(x!=4);
}
