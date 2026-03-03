class Solution {
    public char findKthBit(int n, int k) {
        if (n==1)
            return '0';
        String s = "0";
        for (int i = 2; i <= n; i++) 
        {
            s=s+"1"+reverse(s);
        }
        return s.charAt(k - 1);
    }
    public String reverse(String s)
    {
        String k="";
        for(int j=s.length()-1;j>=0;j--)
        {
            if (s.charAt(j)=='1')
                k+="0";
            else
                k+="1";
        }
        return k;
    }
}