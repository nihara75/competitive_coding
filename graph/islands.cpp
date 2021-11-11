/*An island is a small piece of land surrounded by water . A group of islands is said to be connected if we can reach from any given island to any other island in the same group . 
Given V islands (numbered from 1 to V) and E connections or edges between islands. Can you count the number of connected groups of islands.*/


//Islands

#include <iostream>
#include<queue>
using namespace std;
queue<int> q;
void bfs(int v,int e,int **arr,bool *vis,int start)
{	int c=0,curr;
    if(!vis[start]&&c==0)
    {
       q.push(start); 
        vis[start]=true;
        curr=start;
        
    }
 //cout<<q.front()<<" ";
 
 while(!q.empty())
 {
     
      curr=q.front();
     
    
     //q.pop();
     //cout<<curr<<" ";
 
     
     for(int i=1;i<v;i++)
    {
         
        if(curr==i)
            continue;
        if(arr[curr][i]==1&&!vis[i])
        {
            
            q.push(i);
            vis[i]=true;
            
        }
    }
 q.pop();
     
    
 
}}

int main() {
    // Write your code here
    int v,e;
    cin>>v>>e;
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
        int v1,v2;
        cin>>v1>>v2;
        arr[v1][v2]=1;
        arr[v2][v1]=1;
        
    }
    
    bool*visited=new bool[v];
    int c=0;
    for(int i=0;i<v;i++)
    {
        visited[i]=false;
    }
    for(int i=0; i<v; i++)
    {
        if(!visited[i])
        {
            c++;
            bfs(v,e,arr,visited,i);
        }
    }
    
    cout<<c<<endl;
    
    
    return 0;
}