#include <cstdio>
#include <queue>
#include<iostream>
#include <vector>
#include<map>
#include<string>
#include<cstring>
using namespace std;

#define MAX 100010
#define INF (1<<30)
#define DEBUG if(0)
#define pii pair< int, int >
#define pb(x) push_back(x)

char *ipos, *opos,InpFile[20000000], OutFile[20000000], DIP[20];
inline int input(int  flag=0) {

  while(*ipos <= 32) ++ipos;
  if ( flag  ) return (*ipos++-'0');
  int  x=0, neg=0;char c;
  while( true ) {
    c=*ipos++;if(c == '-') neg=1;
    else {
      if (c<=32) return neg?-x:x;
      x=(x<<1)+(x<<3)+c-'0';
    }
  }
}
void inp(char * s)
{
  int i=0;char c;
  while(*ipos <= 32) ++ipos;
  while(true)
    {
      c=*ipos++;
      if(c<=32){s[i]=0;return;}
      s[i++]=c;
    }
}
inline void output(int  x,int  flag) {
  int  y,dig=0;
  while (x||!dig) { y=x/10;DIP[dig++]=x-((y << 3)+(y << 1))+'0';x=y;}
  while (dig--) *opos++=DIP[dig];
  *opos++= flag ? '\n' : ' ';
}
inline void initFASTIO() {
  ipos=InpFile; opos=OutFile;
  fread_unlocked(InpFile,20000000,1,stdin);
}
inline void FlushFASTIO() {
  fwrite_unlocked(OutFile,opos-OutFile,1,stdout);
}

struct comp {
  bool operator() (const pii &a, const pii &b) {
    return a.second > b.second;
  }
};
map<string,int>city_no;
priority_queue< pii, vector< pii >, comp > Q;
vector< pii > G[MAX];
int D[MAX];
bool F[MAX];
char city1[20],city2[20];

int main()
{
  initFASTIO();
  int i, u, v, w, sz, nodes, edges, query;
  int s,des;
  int kases,city,r,NUM;
  string name1,name2;

  //printf("%c\n",56);
  kases=input();
  while(kases--)
    {
      city_no.clear();
      city=input();
      for(int m=1;m<=city;++m)
	G[m].clear();
      
      int index=0;
      NUM=city;
      while(NUM--)
	{
	  inp(city1);
	  city_no[city1]=++index;
	  edges=input();
	  for(i=0; i<edges; i++)
	    {
	      v=input();w=input();
	      G[index].pb(pii(v, w));
                 
	    }
	}
      query=input();
      while(query--)
	{

	  inp(city1);inp(city2);

	  s=city_no[city1];
	  des=city_no[city2];
	  memset(D,127,sizeof D);
	  memset(F,false,sizeof F);
	  D[s] = 0;
	  Q.push(pii(s, 0));

    
	  while(!Q.empty())
	    {
	      u = Q.top().first;
	      Q.pop();
	      if(u==des)
		break;
	      if(F[u]) continue;
	      sz = G[u].size();
                   
	      for(i=0; i<sz; i++)
		{
		  v = G[u][i].first;
		  w = G[u][i].second;
		  if(D[u]+w < D[v])
		    {
		      D[v] = D[u] + w;
		      Q.push(pii(v, D[v]));
               
		    }
		}
        
	      F[u] = 1; 
	      if(F[des]==1)
		break;
	    }

	  output(D[des],1);//printf("%d\n",D[des]);
	}
    }
  FlushFASTIO();
  // result
  //for(i=1; i<=nodes; i++) printf("Node %d, min weight = %d\n", i, D[i]);
  return 0;
}



