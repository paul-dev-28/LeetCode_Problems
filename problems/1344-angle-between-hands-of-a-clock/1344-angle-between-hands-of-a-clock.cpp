class Solution {
public:
    double angleClock(int hour, int minutes) {
        hour%=12;
        double mindeg=6.0*minutes;
        double hourdeg=hour*30.0+minutes*0.5;
        double diff=abs(mindeg-hourdeg);
        return min(diff,360.0-diff);
    }
};