#include <vector>
#include <string>
#include <queue>

using namespace std;

struct State {
    int row;
    int col;
    int mask;
    int dist;
};

class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        int startRow = -1, startCol = -1;
        int totalKeys = 0;
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '@') {
                    startRow = i;
                    startCol = j;
                } else if (grid[i][j] >= 'a' && grid[i][j] <= 'f') {
                    totalKeys++;
                }
            }
        }
        
        int targetMask = (1 << totalKeys) - 1;
        bool visited[31][31][64] = {false};
        
        queue<State> q;
        q.push({startRow, startCol, 0, 0});
        visited[startRow][startCol][0] = true;
        
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        
        while (!q.empty()) {
            State curr = q.front();
            q.pop();
            
            if (curr.mask == targetMask) {
                return curr.dist;
            }
            
            for (int i = 0; i < 4; ++i) {
                int nextRow = curr.row + dr[i];
                int nextCol = curr.col + dc[i];
                int nextMask = curr.mask;
                
                if (nextRow >= 0 && nextRow < m && nextCol >= 0 && nextCol < n) {
                    char cell = grid[nextRow][nextCol];
                    
                    if (cell == '#') continue;
                    
                    if (cell >= 'A' && cell <= 'F') {
                        if (!(nextMask & (1 << (cell - 'A')))) {
                            continue;
                        }
                    }
                    
                    if (cell >= 'a' && cell <= 'f') {
                        nextMask |= (1 << (cell - 'a'));
                    }
                    
                    if (!visited[nextRow][nextCol][nextMask]) {
                        visited[nextRow][nextCol][nextMask] = true;
                        q.push({nextRow, nextCol, nextMask, curr.dist + 1});
                    }
                }
            }
        }
        
        return -1;
    }
};