class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> v(m, vector<int>(n, 1)) ;
        for(vector<int>& a : guards) v[a[0]][a[1]] = 2 ;
        for(vector<int>& a : walls) v[a[0]][a[1]] = -1 ;
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}} ;
        for(const auto& guard : guards) {
            for(const auto& dir : directions) {
                int x = guard[0], y = guard[1] ;
                while(true){
                    x += dir.first ;
                    y += dir.second ;
                    if(x < 0 || x >= m || y < 0 || y >= n || v[x][y] == -1 || v[x][y] == 2) break ;
                    if(v[x][y] == 1) v[x][y] = 0 ;
                }
            }
        }
        int cnt = 0 ;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(v[i][j] == 1) cnt++ ;
            }
        }
        return cnt ;
    }
};
