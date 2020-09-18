class Solution {
public:
    int balancedStringSplit(string s) 
    {
        int ret = 0;
        int helper = 0;

        // 方法1 使用栈来实现
        stack<char> st;
        
        for(int i = 0 ; i < s.size();i++)
        {
            if(st.empty() || s[i] == st.top())
            {
                st.push(s[i]);
            }
            else
            {
                st.pop();
            }

            if(st.empty())
            {
                ret++;
            }
        }

        return ret;
    }
};
