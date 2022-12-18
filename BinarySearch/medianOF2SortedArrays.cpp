#include <bits/stdc++.h>

using namespace std;

double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{
    int n1 = nums1.size();
    int n2 = nums2.size();
    int n = n1 + n2;

    int p = n / 2;
    bool isEven = n % 2 == 0;

    int l = 0;
    int h = n1;

    int l1, l2, r1, r2;

    while (l <= h)
    {
        int m = l + (h - l) / 2;
        int r = (n + 1) / 2 - m;

        l1 = m == 0 ? INT_MIN : nums1[m - 1];
        l2 = r == 0 ? INT_MIN : nums2[r - 1];

        r1 = m == n1 ? INT_MAX : nums1[m];
        r2 = r == n2 ? INT_MAX : nums2[r];

        if (l1 <= r2 && l2 <= r1)
        {
            if (isEven)
                return double(max(l1, l2) + min(r1, r2)) / 2;
            return max(l1, l2);
        }
        else if (l1 > r2)
            h = m - 1;
        else if (l2 > r1)
            l = m + 1;
    }

    return 0.0;
}

int main()
{
    int n1, n2;
    cin >> n1 >> n2;
    vector<int> nums1(n1), nums2(n2);

    for (int i = 0; i < n1; i++)
        cin >> nums1[i];

    for (int i = 0; i < n2; i++)
        cin >> nums2[i];

    cout << findMedianSortedArrays(nums1, nums2);
    return 0;
}