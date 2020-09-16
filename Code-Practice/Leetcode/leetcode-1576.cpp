class Solution {
public:
    string modifyString(string s) 
    {
        int len = s.size();
        for(int i = 0;i < len; i++)
        {
            if(s[i] == '?')
            {
                char charc = 'a';

                if( i == 0 )
                {
                   while( (i+1) < len && charc == s[i+1])
                   {
                       charc += 1;
                   }
                }
                else if(i == len-1)
                {
                    while((i-1 >= 0 && charc == s[i-1]))
                    {
                        charc += 1;
                    }
                }
                else
                {
                    while(charc == s[i-1]|charc == s[i+1])
                    {
                        charc += 1;
                    } 
                }

                s[i] = charc;
            }
        }
        return s;
    }
};