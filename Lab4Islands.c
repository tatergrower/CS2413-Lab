void dfs(char** grid, int gridSize, int* gridColSize, int i, int j) {
    //bound check
    if (i < 0 || i >= gridSize || j < 0 || j >= gridColSize[i] || grid[i][j] == '0') {
        return;
    }
    grid[i][j] = '0'; // marks as visited by converting 1 to 0
    
    //recursively checks all possible directions
    dfs(grid, gridSize, gridColSize, i + 1, j);//down
    dfs(grid, gridSize, gridColSize, i - 1, j);//up
    dfs(grid, gridSize, gridColSize, i, j + 1);//right
    dfs(grid, gridSize, gridColSize, i, j - 1);//left
}
//counts the islands, intiats dfs from every unvisted land 
int numIslands(char** grid, int gridSize, int* gridColSize) {
    int count = 0;
    //iterates through cells
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridColSize[i]; j++) {
            if (grid[i][j] == '1') {
                count++;            // Only increment when we find a new island
                dfs(grid, gridSize, gridColSize, i, j);
            }
        }
    }
 return count;
}

