public:
    // Helper function to find paths in the matrix
    void helper(vector<vector<int>>& mat, int r, int c, string path, vector<string>& ans, vector<vector<bool>>& vis) {
        int n = mat.size();

        // Boundary checks and obstacle check
        if (r < 0 || c < 0 || r >= n || c >= n || mat[r][c] == 0 || vis[r][c] == true) {
            return;
        }

        // If the destination is reached, store the path
        if (r == n - 1 && c == n - 1) {
            ans.push_back(path);
            return;
        }

        // Mark the cell as visited
        vis[r][c] = true;

        // Move in all possible directions
        helper(mat, r + 1, c, path + "D", ans, vis); // Down
        helper(mat, r - 1, c, path + "U", ans, vis); // Up
        helper(mat, r, c + 1, path + "R", ans, vis); // Right
        helper(mat, r, c - 1, path + "L", ans, vis); // Left

        // Backtrack: unmark the cell
        vis[r][c] = false;
    }

    vector<string> findPath(vector<vector<int>>& mat) {
        vector<string> ans;
        int n = mat.size();
        
        // If starting or ending cell is blocked, return empty result
        if (n == 0 || mat[0][0] == 0 || mat[n - 1][n - 1] == 0) {
            return ans;
        }

        vector<vector<bool>> vis(n, vector<bool>(n, false));
        helper(mat, 0, 0, "", ans, vis);
        return ans;
    }
};
