class Solution {
public:
    set<int> st;
    vector<bool> ui;
    vector<int> dis;

    void solve(int p, int num) {
        if(p == 3) {
            if(num % 2 == 0) st.insert(num);
            return;
        }

        for(int i = 0; i < dis.size(); i++) {
            if(ui[i]) continue;
            if(p == 0 && dis[i] == 0) continue;

            ui[i] = true;
            solve(p + 1, num * 10 + dis[i]);
            ui[i] = false;
        }
    }

    int totalNumbers(vector<int>& digits) {
        dis = digits;
        ui.resize(dis.size(), false);
        solve(0, 0);
        return st.size();
    }
};