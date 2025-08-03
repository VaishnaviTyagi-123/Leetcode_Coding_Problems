class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
             int n = fruits.size();
        vector<int> positions(n), prefix(n + 1);

        for (int i = 0; i < n; ++i) {
            positions[i] = fruits[i][0];
            prefix[i + 1] = prefix[i] + fruits[i][1];
        }

        auto getFruitSum = [&](int left, int right) {
            auto l = lower_bound(positions.begin(), positions.end(), left) - positions.begin();
            auto r = upper_bound(positions.begin(), positions.end(), right) - positions.begin();
            return prefix[r] - prefix[l];
        };

        int maxFruits = 0;

    
        for (int x = 0; x <= k; ++x) {
            int left = startPos - x;
            int rem = k - 2 * x;
            if (rem < 0) continue;
            int right = startPos + rem;
            maxFruits = max(maxFruits, getFruitSum(left, right));
        }

        for (int x = 0; x <= k; ++x) {
            int right = startPos + x;
            int rem = k - 2 * x;
            if (rem < 0) continue;
            int left = startPos - rem;
            maxFruits = max(maxFruits, getFruitSum(left, right));
        }

        return maxFruits;
  
    }
};
