# Transport Connectivity in Southern Africa (Graph Algorithms)

A C++ application demonstrating graph theory and pathfinding algorithms, developed for the COS2611 (Data Structures) course at the University of South Africa (UNISA).

The project models direct road distances between major Southern African metropolitan hubs using an adjacency matrix and evaluates network traversal and optimal path selection.

## Modeled Cities

1. **C1:** Windhoek
2. **C2:** Gaborone
3. **C3:** Johannesburg
4. **C4:** Harare
5. **C5:** Maputo
6. **C6:** Cape Town

## Algorithms Implemented

- **Breadth-First Search (BFS):** Explores all reachable nodes layer-by-layer starting from a selected city using a queue structure (`std::queue`).
- **Dijkstra's Algorithm:** Computes the shortest path distance and reconstructs the full travel itinerary between a designated origin and destination.

## Data Structures & Concepts

- **Graph Representation:** 2D vectors (`std::vector<vector<int>>`) forming a $6 \times 6$ weighted adjacency matrix.
- **Path Reconstruction:** Backtracking using predecessor lists (`vector<int> prev`) and stack operations via `std::reverse`.
- **Formatted I/O:** Visualizing matrix representations using `std::setw`.

## How to Run

1. Compile the main file:
   ```bash
   g++ -std=c++11 main.cpp -o TransportGraph
