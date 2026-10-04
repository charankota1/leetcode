class Solution {
public:
    vector<int> closestPrimes(int l, int r) {
        vector<bool> p(r + 1, 1);
        p[0] = p[1] = 0;

        for(int i = 2; i * i <= r; i++)
            if(p[i])
                for(int j = i * i; j <= r; j += i)
                    p[j] = 0;

        int a = -1, b = -1, x = -1, d = 1e9;

        for(int i = l; i <= r; i++) {
            if(!p[i]) continue;
            if(x != -1 && i - x < d) {
                d = i - x;
                a = x;
                b = i;
            }
            x = i;
        }

        return {a, b};
    }
};