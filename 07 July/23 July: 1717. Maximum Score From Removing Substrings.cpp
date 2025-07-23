class Solution {
public:
    int maximumGain(string s, int x, int y) {
        stack<char> st;
        int ans = 0;
        if(x > y) {
            for(int i = 0; i < s.size(); i++) {
                char ch = s[i];
                if(!st.empty() && (st.top() == 'a' && ch == 'b')) {
                    ans += x;
                    st.pop();
                }
                else {
                    st.push(ch);
                }
            }
            string str = "";
           while(!st.empty()) {
                if(str.empty()) {
                    str += st.top(); st.pop();
                }
                else {
                    if(!st.empty()) {
                        if(str.back() == 'a' && st.top() == 'b') {
                            ans += y;
                            str.pop_back(); 
                            st.pop();
                        }
                        else {
                            str += st.top(); st.pop();
                        }
                    }
                    else {
                        break;
                    }
                }
            }
        }
        else {
            for(int i = 0; i < s.size(); i++) {
                char ch = s[i];
                if(!st.empty() && (st.top() == 'b' && ch == 'a')) {
                    ans += y;
                    st.pop();
                }
                else {
                    st.push(ch);
                }
            }
            string str = "";
            while(!st.empty()) {
                if(str.empty()) {
                    str += st.top(); st.pop();
                } 
                else {
                    if(!st.empty()) {
                        if(str.back() == 'b' && st.top() == 'a') {
                            ans += x;
                            str.pop_back(); 
                            st.pop();
                        }
                        else {
                            str += st.top(); st.pop();
                        }
                    }
                    else {
                        break;
                    }
                }
            }
        }
        return ans;
    }
};
