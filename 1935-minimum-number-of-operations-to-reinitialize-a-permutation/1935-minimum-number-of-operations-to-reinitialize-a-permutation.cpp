class Solution {
private:
void func(vector<int> original, vector<int> &vec1, vector<int> &vec2, int &cnt, int n)   {
        //variable for comparing original with next permutaion formed
        int val=0;

        for(int i=0; i<n; i++)  {
            //even index modification 
            if(i%2==0)  {
                vec2[i] = vec1[i/2];
                val += abs(vec2[i]-original[i]);
            }
            //odd index modification 
            else if(i%2==1) {
                vec2[i] = vec1[(n/2)+((i-1)/2)];
                val += abs(vec2[i]-original[i]);
            }
        }

        cnt++;

        //case for orginal permutation obtained.
        if(val==0)  {
            return;
        }
        //case for next permutation modifictaion needed.
        else {
            func(original,vec2,vec1,cnt,n);
        }

    }
public:
    int reinitializePermutation(int n) {
       //declarinh helping vectors & variables
        vector<int> vec1(n,0);
        for(int i=0; i<n; i++) vec1[i]=i;
        vector<int> vec2(n,0);
        int cnt = 0;

        //recurisve call
        func(vec1,vec1,vec2,cnt,n);

        return cnt;
    }
};