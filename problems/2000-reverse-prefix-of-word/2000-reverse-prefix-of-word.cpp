class Solution {
public:
    string reversePrefix(string word, char ch) {
        if (word.size()==1 && word[0]==ch)
            return word;
        stack<char> c;
        int i=0;
        while(i<word.size())
        {
            if (word[i]!=ch)
                c.push(word[i]);
            if (word[i]==ch)
            {
                c.push(word[i]);
                break;
            }
            i++;
            if (i==word.size())
                return word;
        }
        string nword;
        while(!c.empty())
        {
            nword+=c.top();
            c.pop();
        }
        nword+=word.substr(i+1,word.size()-1);
        return nword;
    }
};