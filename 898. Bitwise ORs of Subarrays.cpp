class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> res;
        unordered_set<int> cur;
        
        for (int a : arr) {
            unordered_set<int> next;
            next.insert(a);
            for (int b : cur) {
                next.insert(a | b);
            }
            cur = next;
            for (int x : cur) {
                res.insert(x);
            }
        }
        
        return res.size();
    }
};

