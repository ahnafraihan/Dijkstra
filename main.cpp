//Ahnaf Raihan
//Dijkstra - main.cpp

#include <iostream>
#include <stdio.h>
#include <limits.h>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

int V = 0;

void dijkstra(vector<vector<int> > &matrix, int Source) {
    vector <int> q;
    vector <int> :: iterator k;
    int d[V], ind[V];
    bool s[V];
    
    // initialize arrays & vectors
    for (int i = 0; i < V; i++)
        d[i] = 99999, s[i] = false, ind[i] = 0;
    
    // initialize distance to source as 0 (always true)
    d[Source] = 0;
    
    // create table header
    cout << "Step\tN'\t";
    for (int i = 0; i < V; i++) {
        cout<< "D(" << i << "),p(" << i << ")" << "\t";
    }
    cout << endl;
    
    // find min distance from vertices still not used
    for (int i = 0; i < V; i++) {
        int min = 99999, u;
        for (int v = 0; v < V; v++)
            if (s[v] == false && d[v] <= min)
                min = d[v], u = v;
        
        // add vertex to list of used vertices
        s[u] = true;
        q.push_back(u);
        cout << i << "\t";
        
        // print shortest path so far, for current step
        for (k = q.begin(); k != q.end(); ++k)
            cout << *k;
        cout <<  ": ";
        for (int j = 0; j < V-i; j++)
            cout << " ";
        
        // update values for adjacent matrices and fill table
        for (int v = 0; v < V; v++) {
            if (!s[v] && matrix[u][v] && d[u] != 99999 && d[u] + matrix[u][v] < d[v]) {
                d[v] = d[u] + matrix[u][v];
                if (!(find(q.begin(), q.end(), u) != q.end()) )
                    q.push_back(u);
                ind[v] = u;
                cout << to_string(d[v]) << "," << u;
            }
            // v is already used
            else if (s[v])
                cout <<"-"<< " ";
            else if (d[u] == 99999)
                cout << "Y" << " ";
            // weight of new path is not smaller than previous path in d[u]
            else if (!(d[u] + matrix[u][v] < d[v]))
                cout << to_string(d[v]) << "," << ind[v];
            // no edge from u to v exists
            else if (!matrix[u][v]) {
                if (d[v] == 99999)
                    cout << "∞" << " ";
                else
                    cout << to_string(d[v]) << "," << ind[v];
            }
            else
                cout <<"I"<< " ";
            cout << "\t         ";
        }
        cout << endl;
    }
}

int main(int argc, char **argv) {
    // validate command line arguments
    if (argc != 3) {
        cerr << "You have entered the incorrect number of parameters" << endl;
        cerr << "Usage: ./Dijkstra <input_file> <source>" << endl;
        return 1;
    }
    int source = atoi(argv[2]);
    int line = 0;
    string str;
    // retrieve size of array, V
    ifstream in(argv[1]);
    if(!in) {
        cerr << "Cannot open input file.\n";
        return 1;
    }
    while (getline(in, str)) {
        if (line == 0)
            V = stoi(str);
        line++;
    }
    in.close();
    
    // 2D vector to hold adjacency matrix
    vector<vector<int> > matrix(V, vector<int>(V));
    
    // retrieve matrix line by line, from input file
    line = 0;
    str = "";
    ifstream in1(argv[1]);
    if(!in1) {
        cerr << "Cannot open input file.\n";
        return 1;
    }
    while (getline(in1, str)) {
        if (line != 0) {
            string result;
            istringstream iss(str);
            for(string str; iss >> str;) {
                result.push_back(stoi(str));
            }
            for (int i = 0; i < V; i++) {
                matrix[line-1][i] = result[i];
            }
        }
        line++;
    }
    in1.close();
    
    // Implement Dijkstra’s shortest path algorithm on matrix with given source
    dijkstra(matrix, source);
    return 0;
}
