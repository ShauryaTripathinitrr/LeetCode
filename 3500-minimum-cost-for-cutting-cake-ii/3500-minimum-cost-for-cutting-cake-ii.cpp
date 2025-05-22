#define ll long long
class Solution
{
public:
    long long minimumCost(int m, int n, vector<int>& h, vector<int>& v) 
    {
        ll i=0,j=0;
        ll numofhorizon=1,numofvertic=1;
        sort(h.rbegin(),h.rend());
        sort(v.rbegin(),v.rend());
        n=h.size(),m=v.size();
        ll ans=0;
        while(i<n && j<m)
        {
            if(h[i]>=v[j])
            {
                ans+=numofvertic*h[i];
                i++;
                numofhorizon++;
            }
            else
            {
                ans+=numofhorizon*v[j];
                j++;
                numofvertic++;
            }
        }
        while(i<n)
        {
            ans+=numofvertic*h[i];
            i++;
            numofhorizon++;
        }
        while(j<m)
        {
            ans+=numofhorizon*v[j];
            j++;
            numofvertic++;
        }
        return ans;
    }
};