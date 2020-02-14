#include<bits/stdc++.h>

using namespace std;


struct node
{
  int data;
  struct node* left;
  struct node* right;
};


class bst
      { struct node *root,*mroot;
          public:
                bst()
                {
                  root=NULL;
                  mroot=NULL;
                }

              struct node *newnode(int item)
              {
                  struct node *temp =  new node;
                  temp->data = item;
                  temp->left = temp->right = NULL;
                  return temp;
              }


              struct node* insert(struct node* p, int data)
            {   if(root==NULL){p=root=newnode(data);}
                else
                {
                  if (p == NULL) return newnode(data);
                if (data < p->data)
                    p->left  = insert(p->left, data);
                else if (data > p->data)
                    p->right = insert(p->right, data);

                }
                return p;
            }


            struct node* rt()
            {
              return root;
            }

            struct node* mrt()
            {
              return mroot;
            }

            void dis_in(struct node *p)
            {
                if (root== NULL)
                {
                  cout<<"EMPTY BST"<<endl;
                }
                if(p!=NULL)
                {
                    dis_in(p->left);
                    cout<<p->data<<endl;
                    dis_in(p->right);
                }
            }

            struct node* mirror(struct node *T)
            {
              if(T==NULL)
              {
                return NULL;
              }
              else
              {
              struct node* p=new node;
              p->data=T->data;

              p->left=mirror(T->right);
              p->right=mirror(T->left);
              return (p);
              }
            }
            void fill(struct node* p)
            {
              mroot=p;
            }
            struct node * min(struct node* node)
            {
                struct node* current = node;
                while (current && current->left != NULL)
                    current = current->left;

                return current;
            }

                  struct node * mv(struct node* node)
      {
          struct node* current = node;


          while (current && current->left != NULL)
              current = current->left;

          return current;
      }



                            void searchKey(struct node* &curr, int key,struct node* &parent)
                      {

                      	while (curr != NULL && curr->data != key)
                      	{

                      		parent = curr;


                      		if (key < curr->data)
                      			curr = curr->left;
                      		else
                      			curr = curr->right;
                      	}
                      }



                              struct node* minimumKey(struct node* curr)
                              {
                              	while(curr->left != NULL) {
                              		curr = curr->left;
                              	}
                              	return curr;
                              }


                            void deletenode(struct node *r, int key)
                      {

                      struct node* parent = NULL;


                      struct node* curr = r;


                      searchKey(curr, key, parent);


                      if (curr == NULL)
                      {cout<<"Element not found"<<endl;
                      return;
                    }


                      if (curr->left == NULL && curr->right == NULL)
                      {

                      if (curr != r)
                      {
                      if (parent->left == curr)
                        parent->left = NULL;
                      else
                        parent->right = NULL;
                      }
                      else
                      r = NULL;
                      delete curr;
                      }


                      else if (curr->left && curr->right)
                      {
                      struct node* successor  = minimumKey(curr->right);
                      int val = successor->data;
                      deletenode(root, successor->data);
                      curr->data = val;
                      }

                      else
                      {
                      node* child = (curr->left)? curr->left: curr->right;
                      if (curr != r)
                      {
                      if (curr == parent->left)
                        parent->left = child;
                      else
                        parent->right = child;
                      }
                      else
                      r = child;
                      delete curr;
                      }
                    }
    };
int main()
{
  bst obj;
  int d;
  int ch;
  do{
  cout<<"1.Insert\n2.Display\n3.Reverse The tree\n4.Print mirror tree\n5.Delete\n\n0.EXIT\n";
  cin>>ch;
  switch(ch)
  {
      case 1:{
                //  struct node *p=obj.insert(obj.rt(), 50);
                  // p=obj.insert(obj.rt(), 30);
                  // p=obj.insert(obj.rt(), 20);
                  // p=obj.insert(obj.rt(), 40);
                  // p=obj.insert(obj.rt(), 70);
                  // p=obj.insert(obj.rt(), 60);
                  // p=obj.insert(obj.rt(), 80);
                  int c=1;
              do{   cout<<"Enter element"<<endl;
                                cin>>d;
                  struct node *p=obj.insert(obj.rt(),d);
                  cout<<"enter 0 to exit"<<endl;
                  cin>>c;
                }while(c!=0);
                    break; }

      case 2:{
                obj.dis_in(obj.rt());
                break;
            }
      case 3:
            {
              struct node *p=obj.mirror(obj.rt());
              obj.fill(p);

              break;
            }
    case 4:
            {
              obj.dis_in(obj.mrt());

              break;
            }
    case 5:
            {
              int val;
              cout<<"Enter value that need to be deleted"<<endl;
              cin>>val;
            obj.deletenode(obj.rt(),val);

            }
}

}while(ch!=0);
}
