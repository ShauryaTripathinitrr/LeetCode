class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        sort(prices.begin(),prices.end());
        int kap=money;
        int cnt=0;
        int jap=prices[0]+prices[1];
        money=money-jap;
        if(money<0)
        {
            return kap;
        }
        else
        {
            return money;
        }
    }
};