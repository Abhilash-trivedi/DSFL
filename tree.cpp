#include<bits/stdc++.h>
#define rep(i, n)    for(int i = 0; i < (n); ++i)
using namespace std;

typedef struct node
{
	int data;
	struct node *left,*right;
}node;



class tree_
{ node* root;

	stack<int> s;
public:
  tree_()
  {
    root=NULL;


  }

  void ino(node* temp)
{
  if (temp == NULL)
      return;

    ino(temp->left);
    cout << temp->data << " ";
    ino(temp->right);
}

/*void ino_non(node* T)
{

	while(T!=NULL)
	{
		s.push(T);
		T=T->left;
	}
	while(!s.empty())
	{
		T=s.pop();
		cout<<T->data;
		T=T->right;
		while(T!=NULL)
		{
			s.push(T);
			T=T->left;

		}
	}
}*/


int depth(node *temp)
{
  if (temp == NULL)
        return 0;
    else
    {

        int lDepth = depth(temp->left);
        int rDepth = depth(temp->right);


        return max(lDepth+1,rDepth+1);
    }
}
void create_r()
{
  root=new node;

  int val,ch1,ch2;
  cout<<"Enter value for the node\n";
  cin>>val;
  root->data=val;
  cout<<"Enter 1. To add left child of node\n";
  cin>>ch1;
  if(ch1==1){root->left=create();}
  else{root->left=NULL;}
  cout<<"Enter 1. to add right child of the node\n";
  cin>>ch2;
  if(ch2==1){root->right=create();}
  else{root->right=NULL;}

}
int height_non()
{
	if(root==NULL)return 0;

	queue<struct node *> q;
	q.push(root);
    int height = 0;

    while (1)
    {
        int nodeCount = q.size();
        if (nodeCount == 0)
            return height;

        height++;
        while (nodeCount > 0)
        {
            struct node *node = q.front();
            q.pop();
            if (node->left != NULL)
                q.push(node->left);
            if (node->right != NULL)
                q.push(node->right);
            nodeCount--;
        }
    };
}

  node* create()
  {
    node *n=new node;
    int val,ch1,ch2;
    cout<<"Enter value for the node\n";
    cin>>val;
    n->data=val;
    cout<<"Enter 1. To add left child of node\n";
    cin>>ch1;
    if(ch1==1)
        {n->left=create();

        }
    else{n->left=NULL;}
    cout<<"Enter 1. to add right child of the node\n";
    cin>>ch2;
    if(ch2==1)
      {n->right=create();

      }
    else{n->right=NULL;}
    return n;
    }
    node* rot()
    {
      return root;
    }
		int leaf()
		{
			if(root==NULL)return 0;

			queue<struct node *> q;
			q.push(root);
		    int leaf = 0;
				while (!q.empty())
				{
									struct node *temp = q.front();
							q.pop();

						if (temp->left != NULL)
								q.push(temp->left);
						if (temp->right != NULL)
								q.push(temp->right);
						if (temp->left == NULL && temp->right == NULL)
								leaf++;
				}
				return leaf;
		}




};
int main()
{
  tree_ obj;
  int ch;
  do{
    cout<<"1.Create Tree\n2.Depth of tree\n3.INORDER Recursion Traversal\n4.height\n5.count leaf nodes\n\n0.EXIT"<<endl;
    cin>>ch;
    switch (ch) {
      case 1:
      {
      obj.create_r();

        break;
      }
      case 2:
      { cout<<"Depth:"<<obj.depth(obj.rot())<<endl<<endl;
        break;
      }
      case 3:
      { if(obj.rot()==NULL)
        {
          cout<<"Empty TREE\n";
        }
        else{
        obj.ino(obj.rot());
        cout<<endl;

      }
			break;
      }
			case 4:
			{
				cout<<"height:"<<obj.height_non()<<endl<<endl;
				break;
			}
			case 5:
			{
				cout<<"Number of leaf:"<<obj.leaf()<<endl<<endl;
				break;
			}
		}


  }while(ch!=0);

}
