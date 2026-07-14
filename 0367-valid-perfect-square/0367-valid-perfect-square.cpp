class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num == 1)
            return true;
        long long low = 1, high = num;
        while (low <= high) {
            long long mid = (low + high) / 2;
            long long square = mid * mid;

            if (square == num)
                return true;

            else if (square < num)
                low = mid + 1;

            else
                high = mid - 1;
        }
        return false;
    }
};