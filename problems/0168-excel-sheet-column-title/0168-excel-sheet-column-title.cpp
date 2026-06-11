class Solution {
public:
    string convertToTitle(int columnNumber) {
        string column="";
        while(columnNumber>0)
        {
            columnNumber--;
            char ch='A'+(columnNumber%26);
            column=ch+column;
            columnNumber/=26;
        }
        return column;
    }
};