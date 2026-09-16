class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;

        vector<bool> isPrime(n, true);
        isPrime[0] = isPrime[1] = false;
        for (int i = 4; i < n; i += 2)
            isPrime[i] = false;

        for (int p = 3; p * p < n; p += 2) {
            if (isPrime[p]) {
                for (int i = p * p; i < n; i += 2 * p) {
                    isPrime[i] = false;
                }
            }
        }

        int count = 1;

        for (int i = 3; i < n; i += 2) {
            if (isPrime[i])
                count++;
        }

        return count;
    }
};