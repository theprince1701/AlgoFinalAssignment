// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <unordered_map>

using namespace std;

#define INF INT_MAX

struct Node
{
    char label;
    vector<pair<Node*, int>> neighbors;
    bool bIsChargingStation;

    Node(char l) : label(l), bIsChargingStation(false) {}
};

struct ShortestRouteInfo 
{
    vector<Node*> Nodes;
    int Distance;
};

class Graph
{
public:
    vector<Node*> nodes;

    void AddNode(Node* Node)
    {
        nodes.push_back(Node);
    }

    void AddEdge(Node* U, Node* V, int Distance)
    {
        U->neighbors.push_back(make_pair(V, Distance));
        V->neighbors.push_back(make_pair(U, Distance));
    }

    void SetChargingStations(vector<char> Stations)
    {
        for (char label : Stations)
        {
            for (Node* node : nodes)
            {
                if (node->label == label)
                {
                    node->bIsChargingStation = true;
                }
            }
        }
    }

    Node* GetNodeFromLabel(char label) 
    {
        for (Node* node : nodes)
        {
            if (node->label == label) 
            {
                return node;
            }
        }
        return nullptr; // Return nullptr if node with given label is not found
    }

    char GetShortestRoute(Node* Source)
    {
        unordered_map<char, int> distance;

        for (Node* node : nodes)
        {
            distance[node->label] = INF;
        }

        priority_queue<pair<int, Node*>, vector<pair<int, Node*>>, greater<pair<int, Node*>>> pq;
        pq.push(make_pair(0, Source));

        while (!pq.empty()) {
            Node* u = pq.top().second;
            pq.pop();

            for (auto neighbor : u->neighbors) {
                Node* v = neighbor.first;
                int weight = neighbor.second;
                if (distance[u->label] + weight < distance[v->label]) {
                    distance[v->label] = distance[u->label] + weight;
                    pq.push(make_pair(distance[v->label], v));
                }
            }
        }

        char nearestChargingStation = ' '; // Default value if no charging station is found
        int minDistance = INF;
        for (auto it : distance)
        {
            if (nodes[it.first - 'A']->bIsChargingStation && it.second < minDistance)
            {
                minDistance = it.second;
                nearestChargingStation = it.first;
            }
        }

        return nearestChargingStation;
    }
};

 

int main()
{
    std::cout << "Hello World!\n";

    Graph graph;


    for (char label = 'A'; label <= 'W'; label++)
    {
      //  cout << label << endl;
        graph.AddNode(new Node(label));
    }

    graph.AddEdge(graph.nodes['A' - 'A'], graph.nodes['B' - 'A'], 6);
    // Distance from A to F is 2
    graph.AddEdge(graph.nodes['A' - 'A'], graph.nodes['F' - 'A'], 5);
    // Distance from B to C is 3
    graph.AddEdge(graph.nodes['B' - 'A'], graph.nodes['C' - 'A'], 5);
    // Distance from B to G is 6
    graph.AddEdge(graph.nodes['B' - 'A'], graph.nodes['G' - 'A'], 6);
    // Continue adding edges down to node W with their respective distances

    // Add edges with their respective distances continued down to node W
    // Example:
    // Distance from C to D is 5
    graph.AddEdge(graph.nodes['C' - 'A'], graph.nodes['D' - 'A'], 7);
    // Distance from C to H is 3
    graph.AddEdge(graph.nodes['C' - 'A'], graph.nodes['H' - 'A'], 5);
    // Distance from D to E is 4
    graph.AddEdge(graph.nodes['D' - 'A'], graph.nodes['E' - 'A'], 7);
    // Distance from D to I is 7
    graph.AddEdge(graph.nodes['D' - 'A'], graph.nodes['I' - 'A'], 8);
    // Continue adding edges down to node W with their respective distances

    // Add edges with their respective distances continued down to node W
    // Example:
    // Distance from E to J is 2
    graph.AddEdge(graph.nodes['E' - 'A'], graph.nodes['N' - 'A'], 15);
    // Distance from F to J is 5
    graph.AddEdge(graph.nodes['F' - 'A'], graph.nodes['K' - 'A'], 7);
    // Distance from G to L is 3
    graph.AddEdge(graph.nodes['F' - 'A'], graph.nodes['G' - 'A'], 8);
    // Distance from H to M is 4
    graph.AddEdge(graph.nodes['H' - 'A'], graph.nodes['M' - 'A'], 4);
    // Continue adding edges down to node W with their respective distances

    // Add edges with their respective distances continued down to node W
    // Example:
    // Distance from I to N is 6
    graph.AddEdge(graph.nodes['I' - 'A'], graph.nodes['N' - 'A'], 6);
    // Distance from J to O is 5
    graph.AddEdge(graph.nodes['J' - 'A'], graph.nodes['O' - 'A'], 5);
    // Distance from K to P is 2
    graph.AddEdge(graph.nodes['K' - 'A'], graph.nodes['P' - 'A'], 2);
    // Distance from L to Q is 4
    graph.AddEdge(graph.nodes['L' - 'A'], graph.nodes['Q' - 'A'], 4);
    // Continue adding edges down to node W with their respective distances

    // Add edges with their respective distances continued down to node W
    // Example:
    // Distance from M to R is 5
    graph.AddEdge(graph.nodes['M' - 'A'], graph.nodes['R' - 'A'], 5);
    // Distance from N to S is 6
    graph.AddEdge(graph.nodes['N' - 'A'], graph.nodes['S' - 'A'], 6);
    // Distance from O to T is 3
    graph.AddEdge(graph.nodes['O' - 'A'], graph.nodes['T' - 'A'], 3);
    // Distance from P to U is 2
    graph.AddEdge(graph.nodes['P' - 'A'], graph.nodes['U' - 'A'], 2);
    // Continue adding edges down to node W with their respective distances

    // Add edges with their respective distances continued down to node W
    // Example:
    // Distance from Q to V is 7
    graph.AddEdge(graph.nodes['Q' - 'A'], graph.nodes['V' - 'A'], 7);
    // Distance from R to W is 3
    graph.AddEdge(graph.nodes['R' - 'A'], graph.nodes['W' - 'A'], 3);
    // Distance from S to W is 5
    graph.AddEdge(graph.nodes['S' - 'A'], graph.nodes['W' - 'A'], 5);
    // Distance from T to W is 6
    graph.AddEdge(graph.nodes['T' - 'A'], graph.nodes['W' - 'A'], 6);


    vector<char> ChargingStations = { 'K', 'H', 'Q', 'T' };
    graph.SetChargingStations(ChargingStations);


    char GasStation = graph.GetShortestRoute(graph.GetNodeFromLabel('B'));

    cout << GasStation << endl;

    for (Node* node : graph.nodes)
    {
        delete node;
    }

    return 0;
}
