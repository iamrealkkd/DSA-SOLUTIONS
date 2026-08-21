class Solution {
public:
    long long gcd(long long a, long long b) {
        while (b) {
            long long temp = a % b;
            a = b;
            b = temp;
        }
        return a;
    }

    long long findKthSmallest(vector<int>& coins, int k) {
        int n = coins.size();

        auto count = [&](long long x) {
            long long cnt = 0;

            for (int mask = 1; mask < (1 << n); mask++) {
                long long lcm = 1;
                int bits = 0;
                bool valid = true;

                for (int i = 0; i < n; i++) {
                    if (mask & (1 << i)) {
                        bits++;

                        long long g = gcd(lcm, (long long)coins[i]);

                        // Prevent overflow and also no contribution if LCM > x
                        if (lcm > x / (coins[i] / g)) {
                            valid = false;
                            break;
                        }

                        lcm = lcm / g * coins[i];
                    }
                }

                if (!valid || lcm > x)
                    continue;

                if (bits % 2 == 1)
                    cnt += x / lcm;
                else
                    cnt -= x / lcm;
            }

            return cnt;
        };

        long long low = 1;
        long long high = 1LL * (*min_element(coins.begin(), coins.end())) * k;

        while (low < high) {
            long long mid = low + (high - low) / 2;

            if (count(mid) >= k)
                high = mid;
            else
                low = mid + 1;
        }

        return low;
    }
};