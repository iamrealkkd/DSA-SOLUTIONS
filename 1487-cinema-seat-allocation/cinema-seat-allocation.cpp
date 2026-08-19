class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        
        unordered_map<int, int> mp;
        
        // Store reserved seats as bitmask
        for (auto& seat : reservedSeats) {
            int row = seat[0];
            int col = seat[1];
            
            mp[row] |= (1 << (col - 1));
        }
        
        // Initially, assume every row can accommodate 2 groups
        int ans = 2 * n;
        
        // Bitmasks for valid blocks
        int left   = 0b0000011110; // seats 2,3,4,5
        int middle = 0b0001111000; // seats 4,5,6,7
        int right  = 0b0111100000; // seats 6,7,8,9
        
        for (auto& [row, mask] : mp) {
            
            // Remove the initially assumed 2 groups
            ans -= 2;
            
            bool leftFree = (mask & left) == 0;
            bool rightFree = (mask & right) == 0;
            bool middleFree = (mask & middle) == 0;
            
            if (leftFree && rightFree) {
                ans += 2;
            }
            else if (leftFree || rightFree || middleFree) {
                ans += 1;
            }
        }
        
        return ans;
    }
};