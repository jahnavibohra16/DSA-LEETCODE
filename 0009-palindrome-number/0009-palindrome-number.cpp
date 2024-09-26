class Solution {
public:
    bool isPalindrome(int x) {
        int rev=0;
        int o=x;
        while(x>0){
            int last=x%10;
             if ((rev > INT_MAX / 10) || (rev < INT_MIN / 10)) {
            return 0;
            }
            rev=(rev*10)+last;
            x=x/10;   
        }
        if(o==rev){ return true;}
        else {return false;}
    }
};