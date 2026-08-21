class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        if (a.size() > b.size())
            return findMedianSortedArrays(b, a);

        int m = a.size();
        int n = b.size();

        int low = 0, high = m;

        while (low <= high) {
            int i = (low + high) / 2;
            int j = (m + n + 1) / 2 - i;

            int leftA  = (i == 0) ? INT_MIN : a[i - 1];
            int rightA = (i == m) ? INT_MAX : a[i];

            int leftB  = (j == 0) ? INT_MIN : b[j - 1];
            int rightB = (j == n) ? INT_MAX : b[j];

            if (leftA <= rightB && leftB <= rightA) {
                if ((m + n) % 2)
                    return max(leftA, leftB);

                return (max(leftA, leftB) +
                        min(rightA, rightB)) / 2.0;
            }

            if (leftA > rightB)
                high = i - 1;
            else
                low = i + 1;
        }

        return 0.0;
    }
};