/*

Given an undirected graph G(V, E) and two vertices v1 and v2(as integers), find and print the path from v1 to v2 (if exists). Print nothing if there is no path between v1 and v2.
Find the path using DFS and print the first path that you encountered.

*/

//Get path using DFS


#include <iostream>
#include<vector>
using namespace std;
vector<int> getPath(int v,int **arr,bool *vis,int curr,int end){
   
    
    if(curr==end)
    {
        vector<int> ans;
        ans.push_back(curr);
        return ans;
    }
    else{
        for(int i=0;i<v;i++)
        {
            if(!vis[i]&&i!=curr&&arr[curr][i]==1)
            {
                vector<int> ans;
                vis[i]=true;
                ans=getPath(v,arr,vis,i,end);
                if(ans.size()!=0)
                {
                ans.push_back(curr);
                return ans;
                }
                
            }
        }
    }
    
    vector<int> ans;
    return ans;
}

int main() {
    // Write your code here
    
    
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
    vector<int> ans;
    ans=getPath(v,arr,vis,v1,v2);
    if(ans.size()!=0)
    {
        for(int i=0;i<ans.size();i++)
        {
            cout<<ans[i]<<" ";
        }
    }
    
}