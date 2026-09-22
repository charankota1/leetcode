class Solution {
public:
    string frequencySort(string s) {
        
        unordered_map<char, int> mp;

        for(char it : s) {
            mp[it]++;
        }

        vector<pair<char, int>> res(mp.begin(), mp.end());

        sort(res.begin(), res.end(), [](pair<char,int> a, pair<char,int> b) {
            return a.second > b.second;
        });
        string ans = "";

        for(auto p : res) {
            for(int i = 0; i < p.second; i++) {
                ans += p.first;
            }
        }

        return ans;
    }
};