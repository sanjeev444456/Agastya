#include <stdio.h>

int main()
{
  int t,n,i;
  double s=0;
  scanf("%d",&t);
  while(t--){
    s=0.0;
    scanf("%d",&n);
    s=2.0/3.0;
    for(i=2;i<n+1;i++)
      s+=1.0/(i*(i+1)*(i+2));
    printf("%.11f\n",s);
  }

  return 0;
}


/* obvious TLE in 10^9 case */
