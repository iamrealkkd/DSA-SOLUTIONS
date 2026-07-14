class Solution {
public:

    int climbStairs(int n) {

        // Step 1: Create DP table
        vector<int> dp(n+1);

        // Step 2: Base Cases
        dp[0]=1;
        dp[1]=1;

        // Step 3: Build answers from smaller states
        for(int i=2;i<=n;i++){

            dp[i]=dp[i-1]+dp[i-2];

        }

        // Step 4: Final Answer
        return dp[n];
    }
};