class Solution {
public:
    int takeCharacters(string s, int k) {
        unordered_map<char, int> mp, w;
        for (char c : s) mp[c]++;
        if (mp['a'] < k || mp['b'] < k || mp['c'] < k) return -1;
        int n = s.size();
        int mini = n, l = 0, r = 0;
        while(r < n){
            w[s[r]]++;
            while (mp['a'] - w['a'] < k || mp['b'] - w['b'] < k || mp['c'] - w['c'] < k) {
                w[s[l]]--;
                l++;
            }
            mini = min(mini, n - (r - l + 1)) ;
            r++ ;
        }
        return mini;
    }
};