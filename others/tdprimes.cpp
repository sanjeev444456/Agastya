#include<stdio.h>

using namespace std;

int main()
{
  bool prime[10001];
  prime[1]=false;
  prime[0]=false;
  for(int i=2;i<10001;i++)
    prime[i]=true;
  for(int i=2;i*i<=10000;i++)
    { 
      if(prime[i])
	{
	  for(int j=i*2;j<=10000;j=i+j)
	    {
	      if(prime[j])
		prime[j]=false;
	    }
	}
    }
  int m=2,j,n=1000000,count=1;bool flag=true;
  bool new_p[n-m+1];
  while(n<=100000000)
    {
      for(int i=0;i<n-m+1;i++)
	new_p[i]=true;
      for(int i=2;i*i<=n;i++)
	{
	  j=m;
	  if(prime[i])
	    {
	      while(j%i!=0)
		j++; 
	      if(i==j)
		j=j+i;
	      while(j<=n)
		{      if(new_p[j-m])
		    new_p[j-m]=false;
		  j=j+i;
		}
	    }
	}
      for(int i=0,r=m;i<n-m+1;i++,r++)
	{
	  if(new_p[i])
	    {   
	      if(count%100==1);
	      printf("%d\n",r);count++;
	    }
	}
      if(flag)
	{m=m+999998;flag=false;  }
      else
	m=m+1000000;
      n=n+1000000;
    }
  return 0;
}
