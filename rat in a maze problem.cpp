#include <iostream>
#include <vector>

const int N = 5; // Size of the maze

// Function to print the solution matrix
void printSolution(std::vector<std::vector<int>>& sol) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cout << sol[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

// Function to check if the cell (x, y) is valid to move
bool isSafe(std::vector<std::vector<int>>& maze, int x, int y) {
    return (x >= 0 && y >= 0 && x < N && y < N && maze[x][y] == 1);
}

// Function to solve the maze using backtracking
bool solveMaze(std::vector<std::vector<int>>& maze, int x, int y, std::vector<std::vector<int>>& sol) {
    if (x == N - 1 && y == N - 1) {
        // Reached the destination
        sol[x][y] = 1;
        return true;
    }

    if (isSafe(maze, x, y)) {
        // Mark the cell as part of the solution path
        sol[x][y] = 1;

        // Move right
        if (solveMaze(maze, x, y + 1, sol)) {
            return true;
        }

        // Move down
        if (solveMaze(maze, x + 1, y, sol)) {
            return true;
        }

        // If no valid move, backtrack
        sol[x][y] = 0;
        return false;
    }

    return false;
}

int main() {
    std::vector<std::vector<int>> maze = {
        {1, 0, 0, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 1, 1, 1, 0},
        {0, 0, 0, 1, 0},
        {0, 0, 0, 1, 1}
    };

    std::vector<std::vector<int>> solution(N, std::vector<int>(N, 0));

    if (solveMaze(maze, 0, 0, solution)) {
        std::cout << "Solution found:" << std::endl;
        printSolution(solution);
    } else {
        std::cout << "No solution exists." << std::endl;
    }

    return 0;
}
