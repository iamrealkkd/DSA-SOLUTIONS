#include <bits/stdc++.h>
using namespace std;

class Solution {
    using Factors = array<int, 4>;

    const array<Factors, 10> digitFactors = {{
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {1, 0, 0, 0},
        {0, 1, 0, 0},
        {2, 0, 0, 0},
        {0, 0, 1, 0},
        {1, 1, 0, 0},
        {0, 0, 0, 1},
        {3, 0, 0, 0},
        {0, 2, 0, 0}
    }};

    Factors subtractFactors(Factors a, const Factors& b) {
        for (int i = 0; i < 4; ++i) {
            a[i] = max(0, a[i] - b[i]);
        }

        return a;
    }

    bool covers(const Factors& available, const Factors& required) {
        for (int i = 0; i < 4; ++i) {
            if (available[i] < required[i]) {
                return false;
            }
        }

        return true;
    }

    string buildSmallest(Factors need) {
        array<int, 10> count{};

        count[8] = need[0] / 3;
        need[0] %= 3;

        count[9] = need[1] / 2;
        need[1] %= 2;

        count[4] = need[0] / 2;
        need[0] %= 2;

        count[2] = need[0];
        count[3] = need[1];

        if (count[2] == 1 && count[3] == 1) {
            count[2] = 0;
            count[3] = 0;
            count[6] = 1;
        }

        if (count[3] == 1 && count[4] == 1) {
            count[3] = 0;
            count[4] = 0;
            count[2] = 1;
            count[6] = 1;
        }

        count[5] = need[2];
        count[7] = need[3];

        string result;

        for (int digit = 2; digit <= 9; ++digit) {
            result.append(count[digit], char('0' + digit));
        }

        return result;
    }

public:
    string smallestNumber(string num, long long t) {
        Factors required{0, 0, 0, 0};
        const array<int, 4> primes{2, 3, 5, 7};

        for (int i = 0; i < 4; ++i) {
            while (t % primes[i] == 0) {
                ++required[i];
                t /= primes[i];
            }
        }

        if (t != 1) {
            return "-1";
        }

        string minimumDigits = buildSmallest(required);
        int n = static_cast<int>(num.size());

        if (static_cast<int>(minimumDigits.size()) > n) {
            return minimumDigits;
        }

        Factors prefixFactors{0, 0, 0, 0};
        int firstZero = n;

        for (int i = 0; i < n; ++i) {
            int digit = num[i] - '0';

            if (digit == 0 && firstZero == n) {
                firstZero = i;
            }

            for (int j = 0; j < 4; ++j) {
                prefixFactors[j] += digitFactors[digit][j];
            }
        }

        if (firstZero == n && covers(prefixFactors, required)) {
            return num;
        }

        for (int i = n - 1; i >= 0; --i) {
            int currentDigit = num[i] - '0';

            for (int j = 0; j < 4; ++j) {
                prefixFactors[j] -= digitFactors[currentDigit][j];
            }

            if (i > firstZero) {
                continue;
            }

            int suffixLength = n - i - 1;

            for (int biggerDigit = currentDigit + 1;
                 biggerDigit <= 9;
                 ++biggerDigit) {

                Factors remaining =
                    subtractFactors(required, prefixFactors);

                remaining =
                    subtractFactors(remaining,
                                    digitFactors[biggerDigit]);

                string suffixDigits = buildSmallest(remaining);

                if (static_cast<int>(suffixDigits.size())
                    <= suffixLength) {

                    int ones =
                        suffixLength -
                        static_cast<int>(suffixDigits.size());

                    return num.substr(0, i)
                         + char('0' + biggerDigit)
                         + string(ones, '1')
                         + suffixDigits;
                }
            }
        }

        int ones =
            n + 1 -
            static_cast<int>(minimumDigits.size());

        return string(ones, '1') + minimumDigits;
    }
};