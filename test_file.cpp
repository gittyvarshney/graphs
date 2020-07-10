#include<bits/stdc++.h>
using namespace std;
#define MAX 100005

int main()
{
  #ifndef ONLINE_JUDGE
    freopen("D:\\Project sunrise\\input.txt", "r", stdin);
    freopen("D:\\Project sunrise\\output.txt", "w", stdout);
  #endif
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  vector<vector<int> > vec( 9 , vector<int> (9, MAX));
  for(auto i : vec)
  {
    for(auto j: i)
    {
      cout << j << " ";
    }
    cout << "\n";
  }

}
