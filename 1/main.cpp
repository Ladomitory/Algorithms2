//BFS main file

#include <iostream>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <string>
#include <vector>
#include <string>
#include <queue>
#include <cmath>

using namespace std;

int BFS(vector <vector <int>> matrix, int s, int f, int n)
{
    queue <int> Queue;
    vector <int> dst(n, INT_MAX);
    //vector <int> pr(n, -1);
    
    Queue.push(s);
    dst[s] = 0;
    //pr[s] = 0;
    while (!Queue.empty())
    {
        int v = Queue.front();
        Queue.pop();
        for (int i = 0; i < n; i++)
        {
            if (matrix[v][i] != 0 && (!matrix[i][i]))
            {
                Queue.push(i);
                dst[i] = dst[v] + matrix[v][i];
                //pr[i] = v;
            }
        }
    }
/* path
    vector <int> path;
    if (pr[f] != -1)
    {
        for (int i = f; i != -1; i = pr[i])
            path.push_back(i);
    }
*/
    
    return (dst[f] == INT_MAX) ? -1 : dst[f];
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

    int N, M, Type, s, f;

    input_file >> s >> f;
    input_file >> N >> M >> Type;
    vector <vector <int>> matrix(N, vector <int>(N));



    for (int l = 0; l < M; l++)
    {
        int i, j, k;
        input_file >> i >> j;
        if (Type == 2 || Type == 4)
        {
            input_file >> k;
        }
        if (Type == 1)
        {
            matrix[i][j] = 1;
        } else if (Type == 2)
        {
            matrix[i][j] = k;
        } else if (Type == 3)
        {
            matrix[i][j] = 1;
            matrix[j][i] = 1;
        } else if (Type == 4)
        {
            matrix[i][j] = k;
            matrix[j][i] = k;
        }
    }
    input_file.close();


    int path = BFS(matrix, s, f, N);
    ofstream output_file(output_filename, std::ios::trunc);
    output_file << path << endl;

    output_file.close();
    return 0;
}