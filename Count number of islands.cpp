// Link to the problem : https://www.techiedelight.com/count-the-number-of-islands/

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
 
// Below arrays detail all eight possible movements from a cell
// (top, right, bottom, left, and four diagonal moves)
int row[] = { -1, -1, -1, 0, 1, 0, 1, 1 };
int col[] = { -1, 1, 0, -1, -1, 1, 0, 1 };
 
// Function to check if it is safe to go to position (x, y)
// from the current position. The function returns false if (x, y)
// is not valid matrix coordinates or (x, y) represents water or
// position (x, y) is already processed
 
bool isSafe(vector<vector<int>> const &mat, int x, int y,
        vector<vector<bool>> const &processed)
{
    return (x >= 0 && x < mat.size()) && (y >= 0 && y < mat[0].size()) &&
        mat[x][y] && !processed[x][y];
}
 
void BFS(vector<vector<int>> const &mat, vector<vector<bool>> &processed, int i, int j)
{
    // create an empty queue and enqueue source node
    queue<pair<int, int>> q;
    q.push(make_pair(i, j));
 
    // mark source node as processed
    processed[i][j] = true;
 
    // loop till queue is empty
    while (!q.empty())
    {
        // dequeue front node and process it
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
 
        // check for all eight possible movements from the current cell
        // and enqueue each valid movement
        for (int k = 0; k < 8; k++)
        {
            // skip if the location is invalid, or already
            // processed, or consists of water
            if (isSafe(mat, x + row[k], y + col[k], processed))
            {
                // mark it as processed and enqueue it
                processed[x + row[k]][y + col[k]] = 1;
                q.push(make_pair(x + row[k], y + col[k]));
            }
        }
    }
}
 
int countIslands(vector<vector<int>> const &mat)
{
    // base case
    if (mat.size() == 0) {
        return 0;
    }
 
    // `M × N` matrix
    int M = mat.size();
    int N = mat[0].size();
 
    // stores if a cell is processed or not
    vector<vector<bool>> processed(M, vector<bool>(N));
 
    int island = 0;
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            // start BFS from each unprocessed node and increment island count
            if (mat[i][j] && processed[i][j] == 0)
            {
                BFS(mat, processed, i, j);
                island++;
            }
        }
    }
 
    return island;
}
 
int main()
{
    vector<vector<int>> mat =
    {
        { 1, 0, 1, 0, 0, 0, 1, 1, 1, 1 },
        { 0, 0, 1, 0, 1, 0, 1, 0, 0, 0 },
        { 1, 1, 1, 1, 0, 0, 1, 0, 0, 0 },
        { 1, 0, 0, 1, 0, 1, 0, 0, 0, 0 },
        { 1, 1, 1, 1, 0, 0, 0, 1, 1, 1 },
        { 0, 1, 0, 1, 0, 0, 1, 1, 1, 1 },
        { 0, 0, 0, 0, 0, 1, 1, 1, 0, 0 },
        { 0, 0, 0, 1, 0, 0, 1, 1, 1, 0 },
        { 1, 0, 1, 0, 1, 0, 0, 1, 0, 0 },
        { 1, 1, 1, 1, 0, 0, 0, 1, 1, 1 }
    };
 
    cout << "The total number of islands is " << countIslands(mat) << endl;
 
    return 0;
}
