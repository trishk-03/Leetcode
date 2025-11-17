class Solution {
  bool isPalindrome(int x) {
    int n =x;

    if(x<0) return false;
    int reverse =0;
    while(n>0){
        int digit = n%10;
        reverse = reverse*10 +digit;
        n = n ~/10 ;
    }
    if(reverse == x) return true;
    return false;
  }
}