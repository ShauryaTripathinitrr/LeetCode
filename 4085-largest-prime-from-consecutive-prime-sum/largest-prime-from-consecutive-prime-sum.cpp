class Solution {
public:
    bool isPrime(long long n) {
    if (n < 2) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;

    for (long long i = 3; i * i <= n; i += 2)
        if (n % i == 0)
            return false;

    return true;
}
    int largestPrime(int n) {
        long long sum = 0;
        long long ans = 0;
        for(long long i = 2 ; i <= (n + 1) ; i++){
            if(isPrime(i)){
                if( (sum + i) > n){
                    return ans;
                }else{
                    if(isPrime(sum + i)){
                        ans = max(ans , (sum + i));
                    }
                    sum += i;
                }
            }
        }
        return -1;
    }
};