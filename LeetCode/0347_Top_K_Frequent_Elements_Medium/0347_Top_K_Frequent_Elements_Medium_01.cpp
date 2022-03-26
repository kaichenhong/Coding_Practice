/*
 *  Results:    AC (12 ms [95.37%];  13.9 MB [21.74%])
 */


class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> nums_cnt;
        map<int, vector<int>> buckets;
        vector<int> res;
        int max_cnt = 1;

        for (const auto &num : nums)
            max_cnt = std::max(max_cnt, ++nums_cnt[num]);

        for (const auto &key : nums_cnt)
            buckets[key.second].push_back(key.first);

        for (int i = max_cnt; i > 0; --i) {
            auto iter = buckets.find(i);

            if (iter == buckets.end())
                continue;

            res.insert(res.end(), iter->second.begin(), iter->second.end());
            if (res.size() == k)
                break;
        }

        return res;
    }
};

