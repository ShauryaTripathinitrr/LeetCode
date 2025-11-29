#define ll long long
class Solution {
public:
    long long sumAndMultiply(int n) {
        if(n == 0){
            return 0;
        }
        ll a = 0;
        ll num = 0;
        string l = "";
        while(n != 0){
            if(n % 10 != 0){
                l += (char)((n % 10) + '0');
            }
            a += (n % 10);
            n /= 10;
        }
        reverse(l.begin() , l.end());
        num = stoll(l);
        return (num * a);
    }
};