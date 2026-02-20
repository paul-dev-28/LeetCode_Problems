class Solution {
public:
    vector<double> convertTemperature(double celsius) {
        double kelvin = celsius + 273.15;
        double fahrenheit = celsius * 9.0 / 5.0 + 32;
        return {kelvin, fahrenheit};
    }
};