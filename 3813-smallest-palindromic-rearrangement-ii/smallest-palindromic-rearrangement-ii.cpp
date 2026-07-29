class Solution {
private:
    long long nCrCapped(int n, int r, long long cap) {
        r = min(r, n - r);

        long long result = 1;

        for (int i = 1; i <= r; i++) {
            __int128 value =
                (__int128)result * (n - r + i) / i;

            if (value >= cap)
                return cap;

            result = (long long)value;
        }

        return result;
    }

    long long countWays(
        const array<int, 26>& count,
        long long cap
    ) {
        int remaining = 0;

        for (int frequency : count)
            remaining += frequency;

        long long ways = 1;

        for (int frequency : count) {
            if (frequency == 0)
                continue;

            long long combinations =
                nCrCapped(remaining, frequency, cap);

            __int128 total =
                (__int128)ways * combinations;

            if (total >= cap)
                return cap;

            ways = (long long)total;
            remaining -= frequency;
        }

        return ways;
    }

public:
    string smallestPalindrome(string s, int k) {
        array<int, 26> frequency{};

        for (char ch : s)
            frequency[ch - 'a']++;

        array<int, 26> halfCount{};
        string middle = "";

        for (int i = 0; i < 26; i++) {
            halfCount[i] = frequency[i] / 2;

            if (frequency[i] % 2 == 1)
                middle = string(1, char('a' + i));
        }

        long long required = k;

        if (countWays(halfCount, required) < required)
            return "";

        int halfLength = s.length() / 2;
        string leftHalf;

        for (int position = 0; position < halfLength; position++) {
            bool characterPlaced = false;

            for (int ch = 0; ch < 26; ch++) {
                if (halfCount[ch] == 0)
                    continue;

                halfCount[ch]--;

                long long arrangements =
                    countWays(halfCount, required);

                if (arrangements >= required) {
                    leftHalf.push_back(char('a' + ch));
                    characterPlaced = true;
                    break;
                }

                required -= arrangements;
                halfCount[ch]++;
            }

            if (!characterPlaced)
                return "";
        }

        string rightHalf = leftHalf;
        reverse(rightHalf.begin(), rightHalf.end());

        return leftHalf + middle + rightHalf;
    }
};