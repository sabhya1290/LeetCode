class Solution {
public:
    string convert(string s, int numRows) 
    {
        int n = s.size();
        if(numRows == 1 || numRows >= n)
        {
            return s;
        }    

        vector<string> str(numRows);
        int i = 0, index = 0;
        bool dir = true;

        while(i < n)
        {
            str[index].push_back(s[i]);

            if(index == numRows - 1)
            {
                dir = false;
            }
            if(index == 0)
            {
                dir = true;
            }

            if(dir)
            {
                index++;
            }
            else
            {
                index--;
            }

            i++;
        }

        string ans = "";
        for(auto& st : str)
        {
            ans += st;
        }

        return ans;
    }
};