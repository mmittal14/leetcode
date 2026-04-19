class Solution {
public:
    // Function to calculate total hours needed at speed k
    long long calculateHours(vector<int>& piles, int k) {
        long long hours = 0;
        for (int pile : piles) {
            hours += (pile + k - 1) / k; // ceil(pile/k)
        }
        return hours;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        
        int ans = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            long long requiredHours = calculateHours(piles, mid);

            if (requiredHours <= h) {
                ans = mid;        // possible answer
                high = mid - 1;  // try smaller k
            } else {
                low = mid + 1;   // need larger k
            }
        }

        return ans;
    }
};