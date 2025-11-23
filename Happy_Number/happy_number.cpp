class Solution {
public:
    bool isHappy(int n) {
        int slow = n;
        int fast = n;

        do {
            slow = digitsSquared(slow);
            fast = digitsSquared(digitsSquared(fast));
        } while (fast != slow);

        return (fast == 1);
    }

    int digitsSquared(int n) {
        int sum = 0;
        int digit = 0;


        while (n) {
            digit = n % 10;
            sum += digit * digit;
            n /= 10;

        }

        return sum;

    }
};




