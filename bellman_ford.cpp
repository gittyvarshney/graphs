#include<bits/stdc++.h>
using namespace std;
#define MAX 100005
//.this algorithm used in finding shortest path for negative directed graphs
// If the graph contains a cycle with negative weight the alogrithm fails
// the algorithm have time complexity between O(n^2) to O(^3) 


bool add_edge(map<int,vector<pair<int,int>>> &m, int a, int b,int dist)
{
	for(auto i: m[a])
	{
		if(i.first == b)
		{
			return false;
		}
	}
	m[a].emplace_back(make_pair(b,dist));
	return true;
}

bool bellmand_ford(map<int,vector<pair<int,int>>>&m,vector<int>& vec,int starting)
{
	bool flag = true;
	vec[starting] = 0;
	int k = 0; // 
	while(k<6 && flag==true)// if k is going to 5 this means that this algorithm is
	{ //going for change till 6th iteration if changes happended in this means
		flag=false;//algorithm fails
		for(auto i: m)
		{
			for(auto j: i.second)
			{
				if(vec[i.first] + j.second < vec[j.first])
				{
					//cout << "vec[" << j.first << "] = " << vec[i.first] << " + " << j.second << "\n"; 
					vec[j.first] = vec[i.first] + j.second;
					flag=true;
				}
			}
		}
		k++;
	}

	if(k== 6 && flag==true)
	{
		return false;
	}
	return true;
}

int main()
{
	 /*
    #ifndef ONLINE_JUDGE
      freopen("D:\\Project Sunrise\\input.txt", "r", stdin);
      freopen("D:\\Project Sunrise\\output.txt", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    */
    map<int,vector<pair<int,int>>> m; 
    //building graph
    add_edge(m,0,1,6);
    add_edge(m,0,2,4);
    add_edge(m,0,3,5);
    add_edge(m,3,2,-2);
    add_edge(m,3,5,-1);
    add_edge(m,2,1,-2);
    add_edge(m,1,4,-1);
    add_edge(m,2,4,3);
    add_edge(m,4,5,3);
    //building negative cycle graph
    /*
    add_edge(m,0,1,4);
    add_edge(m,0,2,5);
    add_edge(m,2,1,7);
    add_edge(m,1,3,7);
    add_edge(m,3,2,-15);
    */
    vector<int> vec(6,MAX);
    if(bellmand_ford(m,vec,0))
    {
    	int j=0;
    	cout << "shortes paths are \n";
    	for(auto i: vec)
    	{
    		cout << j << ":->" << i << ", ";
    		j++;
    	}
    }
    else
    {
    	cout << "bellmand_ford fails thank you \n";
    }
    
}
