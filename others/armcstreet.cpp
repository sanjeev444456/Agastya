#include<stdio.h>
#include <stdlib.h>
#include <assert.h>
struct edge
{
   int src,dest;
    int length;
}e[300025];

int compare (const void * a, const void * b)
{
   struct edge n1=*((struct edge*)a);
   struct edge n2=*((struct edge*)b);
   return(n1.length-n2.length);
}

int main()
{
   int i,k,t,m,n,r,c,u, v,parent[1020],p,q,count;
   int j,total=0,l,cost,min;
   scanf("%d",&t);
   for(i=0;i<t;i++)
   {
      total=0;
      scanf("%d",&cost);
      scanf("%d%d",&m,&n);
      for(j=0;j<n;j++)
      {
         scanf("%d%d%d",&r,&c,&l);
         e[j].src=r;
         e[j].dest=c;
         e[j].length=l;
      }

      qsort(e,n,sizeof(struct edge),compare);
      for(j=1;j<=m;j++)
         parent[j]=j;
      count=0;
      for(j=0;j<n;j++)
      {
         u=e[j].src;
         v=e[j].dest;
         p=parent[u];
         q=parent[v];
         while(parent[p]!=p)
            p=parent[p];
         while(parent[q]!=q)
            q=parent[q];
         if(p==q)
            continue;
         if(p<q)
            parent[v]=parent[u];
         else 
            parent[u]=parent[v];
         total+=e[j].length;
         count++;
         if(count==m-1)
            break;
      }
      printf("%d\n",total*cost);   
   }
   return 0;
}

