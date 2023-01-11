class Solution {
public:
    string categorizeBox(int l, int b, int h, int m) {
        long long volume = (long long)l*b*h;
        bool isHeavy = m >= 100, isBulky = (volume >= 1e9 || l >= 10000 || b >= 10000 || h >= 10000);
        if(isHeavy && isBulky){
            return "Both";
        }
        if(isHeavy || isBulky){
            return isHeavy ? "Heavy" : "Bulky" ;
        }
        return "Neither";
    }
};