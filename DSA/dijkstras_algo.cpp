#include<bits/stdc++.h>
#include<limits.h>

using namespace std;

//returns node num with minimum distance vertex from vertex not yet visited
int min_distance(vector<int> distance, vector<bool> visited, int num)
{
    int min = INT_MAX, min_idx; //min_idx to be returned
    for(int i=0; i<num; i++)
    {
        if (distance[i] <= min && !visited[i])
            min = distance[i], min_idx = i;
    }
    return min_idx;
}


void printmindistance(vector<int>distance, int num)
{
    cout<<"Vertex:"<<"\t"<<"Distance";
    for(int i = 0; i < num; i++)
        cout<<"\n"<<i<<"\t"<<distance[i];
}

template <size_t rows, size_t columns>
void dijkstra(int (&Graph)[rows][columns], int start, int num)
{
    vector<int>distance(num, INT_MAX);
    vector<bool>visited(num, false);

    distance[start] = 0;
    for(int i = 0; i < num; i++)
    {
        int min_node = min_distance(distance, visited, num);
        visited[min_node] = true;

        // set distances of adjacent nodes of visited node
        for(int j = 0; j < num; j++)
        {
            if (!visited[j] && Graph[min_node][j] && distance[min_node] != INT_MAX && distance[min_node] + Graph[min_node][j] < distance[j])
                distance[j] = distance[min_node] + Graph[min_node][j];
        }
    }
    printmindistance(distance, num); 
}

int main()
{
    int num = 9;
    int graph[9][9] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                    { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                    { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                    { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                    { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                    { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                    { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                    { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                    { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };
    dijkstra(graph, 0, num);
    return 0;
}