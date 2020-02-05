
#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define rep(i, n)    for(int i = 0; i < (n); ++i)
#define repA(i, a, n)  for(int i = a; i < (n); ++i)
#define repB(i, a, n)  for(int i = a; i <=(n); ++i)
#define repD(i, a, n)  for(int i = a; i >= (n); --i)
#define vec(i, a)  for( auto i=a.begin();i != a.end(); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define fill(a)  memset(a, 0, sizeof (a))
#define time cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
#define fst first
#define snd second
#define mp make_pair
#define pb push_back
typedef long double ld;
typedef long long ll;
typedef std::pair<ll, ll> pii;
typedef std::vector<ll> vi;
//ahshgh///

const ll MOD = 1e9 + 7;
using namespace std;
ll n_bits(ll n ) { ll x= __builtin_popcount(n) ;return x ;}
#define in  freopen("input.txt","r",stdin);
#define out freopen("output.txt","w",stdout);
#define dark_lord in out
#define fast  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);



struct node {
    char data;
    struct node* next;
};

class postgit
{
  struct node* top;
  string b,o;mm
public:
  post()
  {
    top=NULL;
    b="";
    o="";
  }
  void pop()
  {
    node *temp=top;
    top=temp->next;
    delete(temp);
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
  void postfix(string str)
  { str="("+str+")";
    ll n=str.size();
    rep(i,n)
    {
          if(str[i]=="(")
          {
            push(str[i]);
          }

          else if(isalnum(str[i]))
          {
            cout<<str[i];
          }

          else if(str[i]==")")
          {
              while(top1()!="(")
              {
                o+=top1();
              }

          }
          else
          {
            ll pri=priority(str[i]);
            if(pri>priority(top1()))
              {
                push(str[i]);
              }
            else
            {
              while(pri<priority(top1())&&top!=NULL)
              {
                cout<<top->data;
                pop();
              }
            }
          }
    }
  }

}
};
//asjda
int main()
{ int ch;
  post obj;
  string q;
  cin>>q;
  do { cout<<"\n1.Infix to postfix\n2.infix to prefix\n3.Evaluate\n4.exit";
    cin>>ch;
    switch(ch)
    {
      case1:
      { obj.postfix(q);
        break;

      }
    }
  }while(ch!=0);

    return 0;


}
