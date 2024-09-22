class Solution {
public:
    int findKthNumber(int n, int k, int start = 0) {
        if(k > 0) {
            for(int i = (start==0)?1:0; i <= 9; i++) { // append 0-9 to the prefix
                int count = numbersBeginWith(n, 10*start+i);
                if(k <= count) // if k <= count, the answer is begin with the prefix
                    return findKthNumber(n, k-1, 10*start+i);
                k -= count; // if the answer does not begin with the prefix, remove all the numbers begin with this prefix
            }
        }
        return start;
    }
    
    // return how many numbers are begin with the prefix and in the range of N
    int numbersBeginWith(int n, long long prefix) 
    {
        long long fac = 1;
        int count = 0;
        for(int digit = 1; digit <= 9; digit++) {
            long long min = prefix*fac;
            long long max = prefix*fac+fac-1;
            if(n < min)
                break;
            else if(min <= n && n <= max) {
                count += (n-min+1);
                break;
            }
            else
                count += fac;
            fac *= 10;
        }
        return count;
    }
};