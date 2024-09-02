class Solution
{
    public:
    //Function to return the minimum cost to react at bottom
	//right cell from top left cell.
	int row[4] = {1, -1, 0, 0};
    int col[4] = {0, 0, 1, -1};
    int r, c;

    bool valid(int i, int j) {
        return i >= 0 && j >= 0 && i < r && j < c;
    }

    int minimumCostPath(vector<vector<int>>& grid) {
        r = grid.size();
        c = grid[0].size();
        vector<vector<int>> dist(r, vector<int>(c, INT_MAX));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

        dist[0][0] = grid[0][0];
        pq.push({grid[0][0], {0, 0}});

        while (!pq.empty()) {
            int i = pq.top().second.first;
            int j = pq.top().second.second;
            int currCost = pq.top().first;
            pq.pop();

            if (i == r - 1 && j == c - 1) return currCost;

            for (int k = 0; k < 4; k++) {
                int newI = i + row[k];
                int newJ = j + col[k];
                if (valid(newI, newJ) && dist[newI][newJ] > currCost + grid[newI][newJ]) {
                    dist[newI][newJ] = currCost + grid[newI][newJ];
                    pq.push({dist[newI][newJ], {newI, newJ}});
                }
            }
        }

        return dist[r-1][c-1];
    }
};
