#define ll long long
class Solution {
private:
string decToBinary(int n){string s="";int i = 0;while (n > 0) {s =to_string(n % 2)+s;n = n / 2;i++;}return s;}
ll binaryToDecimal(string n){string num = n;ll dec_value = 0;int base = 1;int len = num.length();for(int i = len - 1; i >= 0; i--){if (num[i] == '1')dec_value += base;base = base * 2;}return dec_value;}
 
public:
    int minChanges(int n, int k) {
        
        if(n==k)
        {
            return 0;
        }
        
        if(k%2==1 && n%2==0)
        {
            return -1;
        }
        string a=decToBinary(n);
        string b=decToBinary(k);
        
        int cnt=0;
        int jam=__builtin_popcount(n);
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        int a1=a.length();
        int b1=b.length();
        if(a1!=b1)
        {
            if(a1>b1)
            {
                for(int i=1;i<=a1-b1;i++)
                {
                    b.push_back('0');
                }
            }
            else
            {
                for(int i=1;i<=b1-a1;i++)
                {
                    a.push_back('0');
                }
            }
        }
         cout<<a<<" "<<b<<endl;
        for(int i=0;i<b.length();i++)
        {
            if(a[i]=='1')jam--;
            if(a[i]!=b[i] && a[i]=='1')
            {
                cnt++;
            }
            else if(a[i]!=b[i] && a[i]=='0')
            {
                return -1;
            }
        }
        return cnt+jam;
    }
};