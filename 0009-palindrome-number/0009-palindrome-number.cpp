class Solution {
public:
    bool isPalindrome(int x) {
        long long n=x;long long k=0;if(x<0)return false;
 while(n!=0){long long dig=n%10;k=k*10+dig;n=n/10;}return (k==x); }
};