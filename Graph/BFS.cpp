/**
 * The Breadth First Search Algorithm in C++
 * Using the Adjecency List
 * Time Cost : O(|V|+|E|)
 * Author: Zheng Chen / Arclabs001
 * Copyright 2015 Xi'an University of Posts & Telecommunications
 */
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int N = 5; // The number of Vertex

enum status {UNDISCOVERED,DISCOVERED,VISITED};

struct Vertex  
{
    int inDegree, outDegree;
    int data;
    status _stat;
}V[N];

vector<int> AdjList[N];   //Using vector to simulate the adjlist
queue<int> vertexQueue;   //The call queue
/**
 * Initialize the graph as below:
The Graph:

0->1->3
|  |  |
\/ \/ \/
2->4<--

 * @return The pointer to the start vertex
 */
Vertex* init_graph()
{
    while(!vertexQueue.empty())
        vertexQueue.pop();

    for(int i=0; i<N; i++)
    {
        AdjList[i].clear();
        V[i]._stat = UNDISCOVERED;
        V[i].data = i;
    }

    V[0].inDegree = 0; V[0].outDegree = 2;
    V[1].inDegree = 1; V[1].outDegree = 3;
    V[2].inDegree = 1; V[2].outDegree = 1;
    V[3].inDegree = 1; V[3].outDegree = 1;
    V[4].inDegree = 3; V[4].outDegree = 0;

    AdjList[0].push_back(1); AdjList[0].push_back(2);
    AdjList[1].push_back(3); AdjList[1].push_back(4);
    AdjList[2].push_back(4);
    AdjList[3].push_back(4);

    vertexQueue.push(0);
    return & V[0];
}

void BFS(int root)
{
    if(vertexQueue.empty())
        return;

    if((V[root]._stat == VISITED))
    {
        vertexQueue.pop();
        int frt = vertexQueue.front();
        BFS(frt);

        return;
    }

    V[root]._stat = DISCOVERED;
    cout<<"vertex "<<V[root].data<<" found !"<<endl;

    for(int v : AdjList[V[root].data])
    {
        vertexQueue.push(v);
    }

    V[root]._stat = VISITED;
    vertexQueue.pop();
    int frt = vertexQueue.front();
    BFS(frt);
}

int main()
{
    init_graph();
    int frt = vertexQueue.front();
    BFS(frt);

    return 0;
}

