class Solution {
public:
    string removeOccurrences(string s, string p) {
        int n = s.length(), m = p.length() ;
        string str = "" ;
        for(char c : s) {
            str.push_back(c) ;
            int sz = str.size() ;
            if(c == p.back() && sz >= m) {
                if(str.substr(sz - m) == p) str.erase(sz - m) ;
            }
        }
        return str ;
    }
};
