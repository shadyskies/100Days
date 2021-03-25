#include<bits/stdc++.h>
using namespace std;

void add_edge(vector<int> v[], int a, int b) //for undirected graph
{
    v[a].push_back(b);
    // v[b].push_back(a);
}

void print_adjacency_list(vector<int> adj[], int V)
{
    for (int v = 0; v < V; ++v)
    {
        cout << "\n Adjacency list of vertex "
             << v << "\n head ";
        for (auto x : adj[v])
           cout << "-> " << x;
    }
        printf("\n");
}

//bfs between start and end nodes only for undirected graph
void bfs(vector<int>v[], int V, int start, int end)
{
    vector<int> visited(V, 0);
    // int count = 0;
    queue<int> q1;
    // visited[start] = 1; //start node
    q1.push(start);
    while(!q1.empty())
    {
        cout<<q1.front()<<" ";
        int top = q1.front();
        //mark adjacent nodes as visited and enqueue
        for(int j=0; j<v[top].size(); j++)
            if (visited[v[top][j]] == 0)
            {
                q1.push(v[top][j]); 
                visited[v[top][j]] = 1; 
            }
        q1.pop();
    }
}

//dfs between start and end nodes
void dfs(vector<int>v[], int V, int start, int end)
{
    vector<int> visited(V, 0);
    stack<int> s;
    visited[start] = 1;
    s.push(start);
    cout<<start<<" ";
    // iter(v, visited, s);
    while(!s.empty())
    {
        auto top = s.top(); //indicates node top of stack
        if (s.top() == end)
        {
            cout<<end<<" ";
            return;
        }
        if(visited[top]==0)
        {
            cout<<top<<" ";
            visited[top] = 1;
        }
        for(auto i=v[top].begin(); i<v[top].end(); i++)
        {
            if (visited[*i]==0) //is node visited?
            {
                s.push(*i); 
                break;  
            }
        }
        if (s.top() == top) //indicates if new node is added or not
            s.pop();
    }
}



int main()
{
    int V = 8; //number of vertices
    vector<int>v[V]; //creating adjacency list
    add_edge(v, 0, 1);
    add_edge(v, 0, 2);
    add_edge(v, 0, 3);
    add_edge(v, 0, 4);
    add_edge(v, 1, 5);
    add_edge(v, 2, 5);
    add_edge(v, 3, 6);
    add_edge(v, 4, 6);
    add_edge(v, 5, 7);
    add_edge(v, 6, 7);
    // print_adjacency_list(v, V);
    // bfs(v, V, 1, 6); //prints bfs between two nodes in undirected graph
    dfs(v, V, 0, 3);
    return 0;
}