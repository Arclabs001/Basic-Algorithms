/**
 * The Depth First Search Algorithm in C++
 * Using the Adjecency List
 * Time Cost : O(|V|+|E|)
 * Author: Zheng Chen / Arclabs001
 * Copyright 2015 Xi'an University of Posts & Telecommunications
 */
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

const int N = 8; // The number of Vertex

enum status {UNDISCOVERED,DISCOVERED,VISITED};

struct Vertex
{
    int inDegree, outDegree;
    int data;
    status _stat;
    int discovered_time, finished_time;

}V[N];

vector<int> AdjList[N];   //Using vector to simulate the adjlist
stack<int> vertexStack;   //The call srack
stack<int> topo_order;
int clock;

/**
 * Initialize the graph as below:
The Graph:

0->1->3
|  |  |
\/ \/ \/
2->4<--

 * @return The pointer to the start vertex
 */
 /*
Vertex* init_graph()
{
    while(!vertexStack.empty())
        vertexStack.pop();

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

    vertexStack.push(0);
    clock = 0;
    V[0].discovered_time = clock;

    return & V[0];
}
*/
Vertex* init_graph()
{
    while(!vertexStack.empty())
        vertexStack.pop();

    for(int i=0; i<N; i++)
    {
        AdjList[i].clear();
        V[i]._stat = UNDISCOVERED;
        V[i].data = i;
    }


    V[0].inDegree = 1; V[0].outDegree = 1;
    V[1].inDegree = 1; V[1].outDegree = 3;
    V[2].inDegree = 2; V[2].outDegree = 2;
    V[3].inDegree = 1; V[3].outDegree = 2;
    V[4].inDegree = 1; V[4].outDegree = 2;
    V[5].inDegree = 3, V[5].outDegree = 1;
    V[6].inDegree = 1; V[6].outDegree = 2;
    V[7].inDegree = 3; V[4].outDegree = 1;

    AdjList[0].push_back(1);
    AdjList[1].push_back(2); AdjList[1].push_back(4); AdjList[1].push_back(5);
    AdjList[2].push_back(3); AdjList[2].push_back(6);
    AdjList[3].push_back(2); AdjList[3].push_back(7);
    AdjList[4].push_back(0); AdjList[4].push_back(5);
    AdjList[5].push_back(6);
    AdjList[6].push_back(5); AdjList[6].push_back(7);
    AdjList[7].push_back(7);

    clock = 0;
    V[0].discovered_time = clock;

    vertexStack.push(0);
    clock = 0;
    V[0].discovered_time = clock;

    return & V[0];
}

//Here is the method of CLRS
void dfs_Visit(int i)
{
    clock++;
    V[i].discovered_time = clock;
    V[i]._stat = DISCOVERED;

    for(int v : AdjList[i])
    {
        if(V[v]._stat == UNDISCOVERED)
        {
            dfs_Visit(v);
        }
    }

    V[i]._stat = VISITED;
    clock++;
    V[i].finished_time = clock;
    topo_order.push(i);
}

void DFS()
{
    for(int i=0; i<N; i++)
    {
        if(V[i]._stat == UNDISCOVERED)
        {
            dfs_Visit(i);
        }
    }
}
/*

void DFS(int root)
{
    clock++;
    if(vertexStack.empty())
    {
        return;
    }

    if(V[root]._stat == VISITED)
    {
        vertexStack.pop();
        if(!vertexStack.empty())
        {
            int frt = vertexStack.top();
            DFS(frt);
        }
        return;
    }

    cout<<"Vertex "<<V[root].data<<" found !"<<endl;
    //print the vertex with its topological order.
    vertexStack.pop();
    for(int v : AdjList[root])
    {
        if(V[v]._stat == UNDISCOVERED)
        {
            V[v]._stat = DISCOVERED;
            V[v].discovered_time = clock;
            vertexStack.push(v);
            DFS(vertexStack.top());
        }
    }

    clock++;

    V[root].finished_time = clock;
    V[root]._stat = VISITED;

    topo_order.push(root);
//
    if(!vertexStack.empty())
    {
        int frt = vertexStack.top();
        DFS(frt);
    }
    else
    {
        for(int i=0; i<N; i++)
        {
            if(V[i]._stat == UNDISCOVERED)
            {
                vertexStack.push(i);
                break;
            }
        }
    }

//
}
*/
int main()
{
    init_graph();
    DFS();

    for(int n=0; n<8; n++)
    {
        cout<<"V["<<n<<"] : Discovered time = "<<V[n].discovered_time
            <<", Finished time = "<<V[n].finished_time<<endl;
    }

    cout<<"The topo order is : ";
    for(int n=0; n<8; n++)
    {
        cout<<topo_order.top()<<" ";
        topo_order.pop();
    }
    return 0;
}

