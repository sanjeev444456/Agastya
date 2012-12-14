#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iterator>
#include <queue>

using namespace std;

#define pl cout<<endl;
#define all(v) v.begin(),v.end()
#define sz(v) v.size()

typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<string> vs;

int main()
{
  int T;
  scanf("%d",&T);
  while(T--){
    int s=0,i,n;
    scanf("%d",&n);
    vi m(n),w(n);
    for(i=0;i<n;i++) scanf("%d",&m[i]);
    for(i=0;i<n;i++) scanf("%d",&w[i]);

    sort(all(m));
    sort(all(w));
    
    for(i=0;i<n;i++) s+=m[i]*w[i];
    printf("%d\n",s);
  }
  return 0;
}

