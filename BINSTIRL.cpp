#include <map>
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
#include <cassert>
#include <cstring>

using namespace std;

#define fr(i,n) for(int i = 0; i < (int)(n);i++)
#define pl cout<<endl;
#define all(v) v.begin(),v.end()
#define sz(v) v.size()
#define SENTINEL 1000001


typedef long long int lli;
typedef vector<string, string> vpss;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef map<string, int> msi;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;

int main()
{
  int d, n,m;

  scanf("%d",&d);

  while(d--){

    scanf("%d %d",&n,&m);

    if(!n&&!m){
      printf("1\n");
      continue;
    }
    
    if(!n||!m){
      printf("0\n");
      continue;
    }

    if((n-m)&((m-1)/2)) printf("0\n");
    else printf("1\n");
    
  }
  return 0;
}

// Wikipedia provides a direct O(1) formula
