class Solution {
public:
    bool is_bit_set(int n, int pos) {
        int mask = 1 << pos;
        if((n & mask) != 0) return true;
        return false;
    }

    int change_bit(int n, int pos) {
        int mask = 1 << pos;
        if(is_bit_set(n, pos)) {
            mask = 1 << pos;
            mask ^= INT_MAX;
            return n & mask;
        } else {
            mask = 1 << pos;
            return n | mask;
        }
    }

    vector<int> singleNumber(vector<int>& nums) {
        int n = nums.size();
        int global_xor = 0;
        vector<int> v;
        for(int i=0; i<n; i++) {
            global_xor ^= nums[i];
        }

        for(int i=0; i<32; i++) {
            if(is_bit_set(global_xor, i)) {
                int xor0 = 0, xor1 = 0;
                for(int j=0; j<n; j++) {
                    if(is_bit_set(nums[j], i)) {
                        xor1 ^= nums[j];
                    } else {
                        xor0 ^= nums[j];
                    }
                }
                v.push_back(xor0);
                v.push_back(xor1);
                break;
            }
        }

        return v;
    }
};