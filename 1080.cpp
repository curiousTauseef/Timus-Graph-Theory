/*
   Mayank Pratap Singh
   MNNIT, 2nd year IT
   AC ho.
*/
#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

#define MOD 1000000007

typedef long long ll;
typedef long double ld;

const int INF=(int)(1e9);
const ll INF64=(ll)(1e18);
const ld EPS=1e-9;
const ld PI=3.1415926535897932384626433832795;


typedef vector<int> vi;
typedef vector<pair<int,int> > vii;
typedef vector<list<int> > vl;
typedef vector<list<pair<int,int> > > vlp;
typedef map<int,int> mi;
typedef map<string,int> ms;
typedef set<int> si;

vl adjList(100);

int color[100],parent[100];

int flag,n;

void dfs_explore(int start){

    list<int>::iterator it;

    for(it=adjList[start].begin();it!=adjList[start].end();++it){

        if(parent[*it]==-1){
            color[*it]=!color[start];
            parent[*it]=start;
            dfs_explore(*it);
        }
        else{

            if(parent[start]!=*it){

                if(color[*it]==color[start]){
                  flag=1;
                }

            }

        }

    }


}

void dfs(){

   for(int i=1;i<=n;++i)
      parent[i]=-1;

   for(int i=1;i<=n;++i){

       if(parent[i]==-1){

           parent[i]=0;
           dfs_explore(i);

       }
   }

}

int main(){

  cin>>n;

  for(int i=1;i<=n;++i){

      while(1){

         int x;
         cin>>x;
         if(x==0)
            break;
         adjList[i].pb(x);
         adjList[x].pb(i);

      }

  }

  color[1]=0;   // color of first node is red

  flag=0;

  dfs();

  if(flag==1)
     printf("-1\n");

  else{

     for(int i=1;i<=n;++i){

         printf("%d",color[i]);

     }

     printf("\n");

  }

  return 0;
}
