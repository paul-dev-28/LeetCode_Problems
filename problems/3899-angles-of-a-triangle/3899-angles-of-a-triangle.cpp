class Solution {
public:
    vector<double> internalAngles(vector<int>& sides){
        double a=sides[0],b=sides[1],c=sides[2];
        if(a+b<=c || a+c<=b || b+c<=a)
            return {};
        const double PI=acos(-1.0);
        double A=acos((b*b+c*c-a*a)/(2.0*b*c))*180.0/PI;
        double B=acos((a*a+c*c-b*b)/(2.0*a*c))*180.0/PI;
        double C=180.0-A-B;
        vector<double> ans={A,B,C};
        sort(ans.begin(),ans.end());
        return ans;
    }
};