You have two fruit baskets containing n fruits each. You are given two 0-indexed integer arrays basket1 and basket2 representing the cost of fruit in each basket. You want to make both baskets equal. To do so, you can use the following operation as many times as you want:

Chose two indices i and j, and swap the ith fruit of basket1 with the jth fruit of basket2.
The cost of the swap is min(basket1[i],basket2[j]).
Two baskets are considered equal if sorting them according to the fruit cost makes them exactly the same baskets.

Return the minimum cost to make both the baskets equal or -1 if impossible.

 

Example 1:

Input: basket1 = [4,2,2,2], basket2 = [1,4,1,2]
Output: 1
Explanation: Swap index 1 of basket1 with index 0 of basket2, which has cost 1. Now basket1 = [4,1,2,2] and basket2 = [2,4,1,2]. Rearranging both the arrays makes them equal.
Example 2:

Input: basket1 = [2,3,4,1], basket2 = [3,2,5,1]
Output: -1
Explanation: It can be shown that it is impossible to make both the baskets equal.
 

class Solution {
public:

long long minCost(vector<int>& basket1, vector<int>& basket2) {
    map<int, int> freq;
    for (int x : basket1) freq[x]++;
    for (int x : basket2) freq[x]++;

    for (auto& [k, v] : freq) {
        if (v % 2 != 0) return -1;
    }

    map<int, int> count1, count2;
    for (int x : basket1) count1[x]++;
    for (int x : basket2) count2[x]++;

    vector<int> surplus;
    for (auto& [k, _] : freq) {
        int diff = count1[k] - freq[k] / 2;
        if (diff > 0) {
            surplus.insert(surplus.end(), diff, k);
        }
        else if (diff < 0) {
            surplus.insert(surplus.end(), -diff, k);
        }
    }

    sort(surplus.begin(), surplus.end());
    int min_val = min(*min_element(basket1.begin(), basket1.end()),
                      *min_element(basket2.begin(), basket2.end()));

    long long cost = 0;
    int n = surplus.size();
    for (int i = 0; i < n / 2; ++i) {
        cost += min(surplus[i], 2 * min_val);
    }

    return cost;
}
};
