#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

class Graph {
private:
    vector<vector<int>> adjacencyMatrix;
    int numNodes;

public:
    Graph(int n) {
        numNodes = n;
        adjacencyMatrix.resize(n, vector<int>(n, 0));
    }

    void addEdge(int from, int to) {
        adjacencyMatrix[from][to] = 1;
        adjacencyMatrix[to][from] = 1;
    }

    void printGraph() {
        cout << "Adjacency Matrix:" << endl;
        for (int i = 0; i < numNodes; ++i) {
            for (int j = 0; j < numNodes; ++j) {
                cout << adjacencyMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    void iterativeBFS(int startNode) {
        // Create a queue for BFS
        queue<int> q;

        // Mark all the vertices as not visited
        vector<bool> visited(numNodes, false);

        // Mark the current node as visited and enqueue it
        visited[startNode] = true;
        q.push(startNode);

        // Iterate over the queue
        while (!q.empty()) {
            // Dequeue a vertex from queue and print it
            int currentNode = q.front();
            q.pop();
            cout << currentNode << " ";

            // Get all adjacent vertices of the dequeued vertex
            // If an adjacent has not been visited, then mark it visited
            // and enqueue it
            for (int neighbor = 0; neighbor < numNodes; ++neighbor) {
                if (adjacencyMatrix[currentNode][neighbor] && !visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
    }

    void recursiveBFS(int startNode) {
        // Create a queue for BFS
        queue<int> q;

        // Mark all the vertices as not visited
        vector<bool> visited(numNodes, false);

        // Mark the current node as visited and enqueue it
        visited[startNode] = true;
        q.push(startNode);

        // Start recursive BFS from the start node
        recursiveBFSHelper(q, visited);
    }

    void iterativeDFS(int startNode) {
        // Create a stack for DFS
        stack<int> s;

        // Mark all the vertices as not visited
        vector<bool> visited(numNodes, false);

        // Push the start node onto the stack
        s.push(startNode);

        // Iterate until the stack is empty
        while (!s.empty()) {
            // Pop a vertex from stack and print it
            int currentNode = s.top();
            s.pop();

            // If the current node has not been visited, mark it visited and print it
            if (!visited[currentNode]) {
                cout << currentNode << " ";
                visited[currentNode] = true;
            }

            // Push all adjacent vertices of the popped vertex that have not been visited
            // onto the stack
            for (int neighbor = numNodes - 1; neighbor >= 0; --neighbor) {
                if (adjacencyMatrix[currentNode][neighbor] && !visited[neighbor]) {
                    s.push(neighbor);
                }
            }
        }
    }

    void recursiveDFS(int startNode) {
        // Mark all the vertices as not visited
        vector<bool> visited(numNodes, false);

        // Call the recursive DFS helper function
        recursiveDFSHelper(startNode, visited);
    }

private:
    void recursiveBFSHelper(queue<int>& q, vector<bool>& visited) {
        if (q.empty())
            return;

        // Dequeue a vertex from queue and print it
        int currentNode = q.front();
        q.pop();
        cout << currentNode << " ";

        // Get all adjacent vertices of the dequeued vertex
        // If an adjacent has not been visited, then mark it visited
        // and enqueue it
        for (int neighbor = 0; neighbor < numNodes; ++neighbor) {
            if (adjacencyMatrix[currentNode][neighbor] && !visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }

        // Recursively call BFS for the next level
        recursiveBFSHelper(q, visited);
    }

    void recursiveDFSHelper(int currentNode, vector<bool>& visited) {
        // Mark the current node as visited and print it
        visited[currentNode] = true;
        cout << currentNode << " ";

        // Recursively visit all adjacent vertices
        for (int neighbor = 0; neighbor < numNodes; ++neighbor) {
            if (adjacencyMatrix[currentNode][neighbor] && !visited[neighbor]) {
                recursiveDFSHelper(neighbor, visited);
            }
        }
    }
};

int main() {
    int numNodes;
    cout << "Enter the number of nodes in the graph: ";
    cin >> numNodes;

    Graph graph(numNodes);
    int choice;
    int from, to;

    while (true) {
        cout << "\nMenu:" << endl;
        cout << "1. Add Edge" << endl;
        cout << "2. Print Adjacency Matrix" << endl;
        cout << "3. Iterative BFS" << endl;
        cout << "4. Recursive BFS" << endl;
        cout << "5. Iterative DFS" << endl;
        cout << "6. Recursive DFS" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the source node and destination node: ";
                cin >> from >> to;
                graph.addEdge(from, to);
                cout << "Edge added between nodes " << from << " and " << to << endl;
                break;
            case 2:
                graph.printGraph();
                break;
            case 3:
                cout << "Iterative BFS starting from node 0: ";
                graph.iterativeBFS(0);
                cout << endl;
                break;
            case 4:
                cout << "Recursive BFS starting from node 0: ";
                graph.recursiveBFS(0);
                cout << endl;
                break;
            case 5:
                cout << "Iterative DFS starting from node 0: ";
                graph.iterativeDFS(0);
                cout << endl;
                break;
            case 6:
                cout << "Recursive DFS starting from node 0: ";
                graph.recursiveDFS(0);
                cout << endl;
                break;
            case 7:
                cout << "Exiting program." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please enter a valid option." << endl;
        }
    }

    return 0;
}
