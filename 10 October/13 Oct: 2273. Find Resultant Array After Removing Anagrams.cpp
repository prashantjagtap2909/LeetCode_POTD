class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> res;
        string prev = words[0];
        sort(prev.begin(), prev.end());
        res.push_back(words[0]);
        for (int i = 0; i < words.size(); i++){
            string str = words[i];
            sort(str.begin(), str.end());
            if (prev != str){
                res.push_back(words[i]);
                prev = str;
            }
        }
        return res;
    }
};
