//student: Herold Makgaba
//Student No: 24706221
//project: Transport Connectivity in Southern Africa  

#include <iomanip>
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <limits>
#include <stack>
#include <algorithm>

using namespace std;


/*
----------------------------------------
Breadth first search Function
----------------------------------------
BFS: explores all cities layer by layer; good for connectivity checks.
function purpose 
Traverses the graph from a starting city using Breadth-First Search.
Prints all reachable cities in the order they are visited.
Uses a queue to explore all neighbors level by level.

how it works:

Starts from a given city.provide the start city.
Visits all neighbors before moving to neighbors’ neighbors.
Guarantees all cities reachable from start are explored, but does not find shortest weighted paths (it’s unweighted traversal).
*/


void BFS(int start, int numberOfCities,vector<vector<int>> &distance, vector<string> Cities){

    vector<bool> visited(numberOfCities, false); // Marks if a city has been visited
    queue<int> q; // Queue for BFS traversal

    visited[start] = true;
    q.push(start);
    bool first = true; // Track if it's the first city
    cout <<"BFS Traversal starting from "<< Cities[start]<<":"<<endl;

    while(!q.empty()){
        int city = q.front();
        q.pop();

        // Print with "->" only if it's not the first city
        if (!first) {
            cout << "->";
        }
        cout << Cities[city];
        first = false;

        for(int neighbor = 0; neighbor < numberOfCities;neighbor++){
            if(distance[city][neighbor] > 0 && !visited[neighbor]){
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    cout <<endl;

}


/*
----------------------------------------
Dijkstra Function
----------------------------------------
Dijkstra: finds the shortest path and distance from start to a specific destination.
Finds the shortest path from start city to end city using Dijkstra’s algorithm.
Keeps track of distances and previous cities.
Reconstructs and prints the shortest path and total distance.

how it works:

Starts from a given city. and provide the end city.
Maintains shortest known distance to each city.
At each step, picks the unvisited city with the smallest distance and updates distances to its neighbors.
Ends when all cities are visited or the end city is reached.
Uses prev vector to reconstruct the exact shortest path.

*/

void dijkstraTraversal(int start, int end, const vector<vector<int>>& distanceMatrix, const vector<string>& Cities) {
    int n = distanceMatrix.size();
    const int INF = numeric_limits<int>::max();
    vector<int> dist(n, INF);
    vector<int> prev(n, -1);
    vector<bool> visited(n, false);

    dist[start] = 0;

    // Dijkstra algorithm
    for (int i = 0; i < n; ++i) {
        int u = -1;
        int minDist = INF;
        for (int j = 0; j < n; ++j) {
            if (!visited[j] && dist[j] < minDist) {
                minDist = dist[j];
                u = j;
            }
        }

        if (u == -1) break;
        visited[u] = true;

        for (int v = 0; v < n; ++v) {
            if (distanceMatrix[u][v] > 0 && !visited[v]) {
                if (dist[u] + distanceMatrix[u][v] < dist[v]) {
                    dist[v] = dist[u] + distanceMatrix[u][v];
                    prev[v] = u;
                }
            }
        }
    }

    // Reconstruct path
    vector<int> path;
    int current = end;
    while (current != -1) {
        path.push_back(current);
        current = prev[current];
    }

    reverse(path.begin(), path.end());

    // Display path
    cout << "Dijkstra' Shortest Path from " << Cities[start] << " to " << Cities[end] << ":\nPath: ";
    for (size_t i = 0; i < path.size(); ++i) {
        cout << Cities[path[i]];
        if (i < path.size() - 1) cout << " -> ";
    }
    cout << "\nTotal distance: " << dist[end] << " km" << endl;
}

int main(){

    /*
    This first two lines of code declares the format representation, i.e project output header and boarder separator.
    */
   
    cout <<"Southern Africa Transport Graph"<<endl;
    cout <<"------------------------------------------------------"<<endl;

    /*
    Display of the adjacency matrix with the matrix of reachability(weights)
    Display of the the 6 realistic cities names (i.e Windhoek, Gaborone, Johannesburg, Harare, Maputo)
    Number_of_cities variable displays the number number of vertices
    vector<string> Cities 
    This is the hard coded part of the realistic cities and vector<vector<int>>  distance, is an adjacency 
    matrix that shows the different cities and path between their cities.
    and zero displays a a city to itself.
    Your graph is stored as a 2D array distance[i][j].
    Rows = source city, columns = destination city.
    Entry = weight (distance) if there is a direct route; 0 for no route or self-loop

    */

    int Number_Of_Cities = 6;
    vector<string> Cities ={"Windhoek","Gaborone","Johannesburg","Harare","Maputo","Cape Town"};
    
    //Hardcoded links between the cities

    vector<vector<int>> distance ={
    {0,1108,1390,1858,1891,1480},//Windhoek
    {1108,0,360,1070,890,1466},//Gaborone
    {1390,360,0,1120,545,1400},//Johannesburg
    {1858,1070,1120,0,1286,2520},//Harare
    {1891,890,545,1286,0,1947},//Maputo
    {1480,1466,1400,2520,1947,0}//Cape Town
    };
    cout <<""<<endl;
    
    //Display line for cities and their short version name

    cout << "Cities: Windhoek (C1), "
         << "Gaborone (C2),"
         << "Johannesburg (C3),"
         << "Harare (C4),"
         << "Maputo (C5),"<<"Cape Town (C6)"<<endl;
    cout <<""<<endl;

    cout <<"Adjacency Matrix (Distances in km):"<<endl;
    cout <<""<<endl;

    // Print header

    cout << setw(15) << " ";
    for (int i = 0; i < Number_Of_Cities; i++)
        cout << setw(15) << "C" + to_string(i+1);
    cout << endl;

    // Print adjacency matrix with row labels

    for (int i = 0; i < Number_Of_Cities; i++) {
        cout << setw(15) << "C" + to_string(i+1);
        for (int j = 0; j < Number_Of_Cities; j++) {
            cout << setw(15) << distance[i][j];
        }
        cout << endl;
    }

    /*
    At the very start a prompt from cmd will be required of you, since
    there are two algorithms at play here BFS and Djikstras, with BFS BFS can start at any city and does not require end city
    and with the second algorithm you need to specify a start city and end city, so the algorithm determines the shortest path between the two city.
    Think of Djikstras as like a google maps where you have to specify your location and destination and it
    usually show many paths and chooses the shortest one(may have high traffic or many tolls).
    */
    
    cout << "Please input the start city for BFS:(0-5) "<<endl;
    int startcity1_BFS ;
    cin >> startcity1_BFS;
    cout << "Please input the start city and end city respectively for Djikstras:(0-5) "<<endl;

    int startcity2_Djikstras ;
    cin >> startcity2_Djikstras;
    int endcity_Djikstras;
    cin >> endcity_Djikstras;

    cout << " "<<endl;//Line jump

    //Run BFS
    BFS(startcity1_BFS, Number_Of_Cities, distance, Cities);
    cout <<" "<<endl;

    //Run Dijkstra 
    dijkstraTraversal(startcity2_Djikstras, endcity_Djikstras, distance, Cities);
    return 0;

}


//All Ai Generative prompts

/*
1)
my adjacency matrix
int distance[Number_Of_Cities][Number_Of_Cities] ={
    {0,1108,1390,1858,1891,1480},
    {1108,0,360,1070,890,1466},
    {1390,360,0,1120,545,1400},
    {1858,1070,1120,0,1286,2520},
    {1891,890,545,1286,0,1947},
    {1480,1466,1400,2520,1947,0}
    };

how can i implement BFS here?
such that it traverses the graphs,from the specified vertex.

2)
Dijkstra’s Shortest Path

with the adjacency matrix 
my adjacency matrix
vector<int> distance ={
    {0,1108,1390,1858,1891,1480},
    {1108,0,360,1070,890,1466},
    {1390,360,0,1120,545,1400},
    {1858,1070,1120,0,1286,2520},
    {1891,890,545,1286,0,1947},
    {1480,1466,1400,2520,1947,0}
    };

what is the simplest way to implement the djikstra's algorithm?
such that it traverses the graphs,from the specified vertex and find the shortest path
as a function 

3)i want to see the path of the distance on a direct , like finding the shortest path from specified and traverse the whole graph and get me to it and calculate the distance, and chow a path, 
i.e c1-> c3->c4-> c2-> c5



Ai reflection
The assignment was relatively doable, especially the adjacency matrix setup and BFS traversal.
However, I struggled with implementing Dijkstra’s algorithm to correctly print the path sequence and total distance between specified cities.
Initially, I tried using arrays, but the algorithm kept mixing up indices and distances, which caused confusion.
Switching to vector<vector<int>> made the implementation much easier and allowed dynamic access like lists.
Overall, AI guidance helped clarify the steps, but I still had to manually adjust the program to get accurate path sequences and distances.
*/