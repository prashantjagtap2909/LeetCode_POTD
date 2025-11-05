class Solution {
public:
    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        using ll = long long;
        using pii = pair<int, int>;

        long long top_sum = 0;
        int n = nums.size();
        vector<long long> ans;

        set<pii> top, rest;
        unordered_map<int, int> freq;

        auto balance = [&]() {
            while ((int)top.size() < x && !rest.empty()) {
                auto it = prev(rest.end());
                top.insert(*it);
                top_sum += 1LL * it->first * it->second;
                rest.erase(it);
            }

            while (!top.empty() && !rest.empty() &&
                   (*prev(rest.end()) > *top.begin())) {
                auto it1 = top.begin();
                auto it2 = prev(rest.end());

                top.insert(*it2);
                rest.insert(*it1);

                top_sum += (1LL * it2->first * it2->second -
                            1LL * it1->first * it1->second);

                top.erase(it1);
                rest.erase(it2);
            }
        };

        auto insert = [&](int num) {
            pii currFreq = {freq[num], num};

            if (top.count(currFreq)) {
                top.erase(currFreq);
                top_sum -= 1LL * currFreq.first * currFreq.second;
            } else if (rest.count(currFreq)) {
                rest.erase(currFreq);
            }

            freq[num]++;
            pii newFreq = {freq[num], num};
            rest.insert(newFreq);
            balance();
        };

        auto remove = [&](int num) {
            pii currFreq = {freq[num], num};

            if (top.count(currFreq)) {
                top.erase(currFreq);
                top_sum -= 1LL * currFreq.first * currFreq.second;
            } else if (rest.count(currFreq)) {
                rest.erase(currFreq);
            }

            freq[num]--;
            if (freq[num] <= 0)
                freq.erase(num);
            else {
                pii newFreq = {freq[num], num};
                rest.insert(newFreq);
            }

            balance();
        };

        for (int i = 0; i < k; i++)
            insert(nums[i]);

        ans.push_back(top_sum);

        for (int i = k; i < n; i++) {
            insert(nums[i]);
            remove(nums[i - k]);
            ans.push_back(top_sum);
        }
        return ans;
    }
};
