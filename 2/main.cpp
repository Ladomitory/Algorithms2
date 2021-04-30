#include <iostream>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <queue>
#include <cmath>
#include <cstring>
#include <vector>

using namespace std;

void DFS(vector <vector <int>> matrix, int start, vector <bool> &visited)
{
    visited[start] = true;
    for (int next = 0; next < matrix.size(); ++next)
        if (matrix[start][next] == 1 && !visited[next])
        {
            DFS(matrix, next, visited);
        }
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
    vector <bool> visited(N, false);

    DFS(matrix, start, visited);

    ofstream output_file(output_filename, std::ios::trunc);

    output_file << visited[finish] << endl;
    output_file.close();

    return 0;
}