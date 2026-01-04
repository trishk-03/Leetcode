class Solution {
private:
    int check(int n) {
        int count = 0;
        int sum = 0;

        for (int i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                int d1 = i;
                int d2 = n / i;

                if (d1 == d2) { // perfect square
                    count++;
                    sum += d1;
                } else {
                    count += 2;
                    sum += d1 + d2;
                }

                if (count > 4) return 0; // early stop
            }
        }

        return (count == 4) ? sum : 0;
    }

public:
    int sumFourDivisors(vector<int>& nums) {
        int ans = 0;
        for (int x : nums) {
            ans += check(x);
        }
        return ans;
    }
};

class bruteSolution {
private:
    int check(int n){
        int ans =0;
        int count =0;
        for(int i =1; i<=n;i++){
            if(n%i == 0){
            count ++;
            ans += i;
            }
        }

        if(count == 4)
        return ans;
        return 0;
    }
public:
    int sumFourDivisors(vector<int>& nums) {
       int ans =0;
       for(int i =0; i<nums.size();i++){
       ans += check(nums[i]);
       }
       return ans; 
    }
};