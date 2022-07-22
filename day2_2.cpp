// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution
{
public:
    int firstBadVersion(long long int n)
    {
        long long int low = 0, high = n, mid = n / 2;
        while (high > low)
        {
            mid = (high + low) / 2;
            if (isBadVersion(mid))
            {
                high = mid;
            }
            else
            {
                low = mid + 1;
            }
        }
        return low;
    }
};