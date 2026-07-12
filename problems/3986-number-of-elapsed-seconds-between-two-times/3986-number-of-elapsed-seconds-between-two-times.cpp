class Solution {
public:
    int seconds(string s)
    {
        int h=stoi(s.substr(0,2));
        int m=stoi(s.substr(3,2));
        int secs=stoi(s.substr(6,2));
        return h*3600+m*60+secs;
    }
    int secondsBetweenTimes(string startTime, string endTime) {
        return seconds(endTime)-seconds(startTime);
    }
};