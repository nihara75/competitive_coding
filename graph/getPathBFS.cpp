/*

Given an undirected graph G(V, E) and two vertices v1 and v2 (as integers), find and print the path from v1 to v2 (if exists). Print nothing if there is no path between v1 and v2.
Find the path using BFS and print the shortest path available.

*/

//Get Path using BFS

#include <iostream>
#include<vector>
#include<queue>
#include<map>
using namespace std;
queue<int> q;
map<int,int> m;
void getPath(int v,int **arr,bool *vis,int curr,int end)
{
    
    q.push(curr);
    m[curr]=-1;
    
    while(!q.empty())
    {
        if(curr==end)
            break;
        for(int i=0;i<v;i++)
        {
            
            if(!vis[i]&& i!=curr&&arr[curr][i]==1)
            {
                vis[i]=true;
                q.push(i);
                m[i]=curr;
                
                
            }
        }
        q.pop();
        curr=q.front();
        
    }
    
    if (q.empty())
		{
			return;
		}
    int i=m[end];
    cout<<end<<" ";
    while(i!=-1)
    {
        cout<<i<<" ";
        i=m[i];
    }
    
    
}

int main() {
    // Write your code her
    
    int v,e,a,b;
    cin>>v>>e;
    bool *vis=new bool[v];
    for(int i=0;i<v;i++)
    {
        vis[i]=false;
    }
    int **arr=new int*[v];
    
    for(int i=0;i<v;i++)
    {
        arr[i]=new int[v];
        for(int j=0;j<v;j++)
        {
            arr[i][j]=0;
        }
    }
    
    
    for(int i=0;i<e;i++)
    {
        cin>>a>>b;
        arr[a][b]=1;
        arr[b][a]=1;
    }
    
    int v1,v2;
    cin>>v1>>v2;
    vis[v1]=true;
    
    getPath(v,arr,vis,v1,v2);
    
}