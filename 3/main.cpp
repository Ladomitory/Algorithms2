#include <iostream>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cmath>
#include <vector>
#include <limits>

using namespace std;

struct edge
{
    edge(int i, int j, int w) : source(i), destination(j), weight(w) {}
    int source;
    int destination;
    int weight;
};

int BellmanFord(vector <edge> array, int N, int M, int start, int finish)
{
    vector <int> distance(N, INT_MAX);

    distance[start] = 0;

    for (int i = 0; i < N - 1; i++)
    {
        for (int j = 0; j < M; j++)
        {
            int u = array[j].source;
            int v = array[j].destination;
            int weight = array[j].weight;

            if (distance[u] != INT_MAX && distance[u] + weight < distance[v])
            {
                distance[v] = distance[u] + weight;
            }
        }
    }

    for (int j = 0; j < M; j++)
    {
        int u = array[j].source;
        int v = array[j].destination;
        int weight = array[j].weight;

        if (distance[u] + weight < distance[v])
        {
            return -1;
        }
    }

    return distance[finish];
}

int main(int argc, char **argv)
{
    string input_filename = "input.txt";
    string output_filename = "output.txt";
    if (argc == 2)
    {
        input_filename = argv[1];
    }
    else if (argc >= 3)
    {
        input_filename = argv[1];
        output_filename = argv[2];
    }

    ifstream input_file(input_filename);

    int N, M, Type, start, finish;

    input_file >> start >> finish;
    input_file >> N >> M >> Type;

    vector <edge> array;
    for (int ii = 0; ii < M; ii++)
    {
        int i, j, k;
        input_file >> i >> j;
        if (Type == 2 || Type == 4)
        {
            input_file >> k;
        }
        if (Type == 1)
        {
            array.push_back(edge(i, j, 1));
        }
        else if (Type == 2)
        {
            array.push_back(edge(i, j, k));
        }
        else if (Type == 3)
        {
            array.push_back(edge(i, j, 1));
            array.push_back(edge(j, i, 1));
        }
        else if (Type == 4)
        {
            array.push_back(edge(i, j, k));
            array.push_back(edge(j, i, k));
        }
    }
    input_file.close();

    int cost = BellmanFord(array, N, M, start, finish);

    ofstream output_file(output_filename, std::ios::trunc);

    output_file << cost << endl;
    output_file.close();

    return 0;
}