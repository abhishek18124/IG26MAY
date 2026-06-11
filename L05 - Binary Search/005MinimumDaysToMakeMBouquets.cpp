class Solution {
public:

    // time : O(n)

    bool f(vector<int> bloomDay, int m, int k, int timeLimit) {
        // can I make 'm' bouquets of 'k' adjacent flowers
        // in 'timeLimit' no. of days ?
        int cnt = 0;
        for (int day : bloomDay) {
            if (day <= timeLimit) {
                cnt++;
                if (cnt == k) {
                    m--;
                    cnt = 0;
                    if (m == 0) {
                        return true;
                    }
                }
            } else {
                cnt = 0;
            }
        }

        return false;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {

        int n = (int)bloomDay.size();
        int ans = -1;

        int lo = *min_element(bloomDay.begin(), bloomDay.end());
        int hi = *max_element(bloomDay.begin(), bloomDay.end());

        while (lo <= hi) { // time : log(hi-lo) * n
            int mid = lo + (hi - lo) / 2;
            // can I make 'm' bouquets of 'k' adjacent flowers
            // in 'mid' no. of days ?
            if (f(bloomDay, m, k, mid)) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }

        return ans;

    }
};