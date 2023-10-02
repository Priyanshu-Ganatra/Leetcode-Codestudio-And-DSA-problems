#include <bits/stdc++.h>
using namespace std;

bool isPossibleSol(int A[], int N, int M, int maxPagesToAllocate)
{
    int pageSum = 0;
    int cnt = 1;
    for (int i = 0; i < N; i++)
    {
        if (A[i] > maxPagesToAllocate)
        {
            return false;
        }
        // if the current student's total pages of all allocated books sum > maxPagesToAllocate
        // then allocate the remaining books to further students
        if (pageSum + A[i] > maxPagesToAllocate)
        {
            cnt++;
            pageSum = A[i];
            if (cnt > M)
            {
                return false;
            }
        }
        else
        {
            pageSum += A[i];
        }
    }
    return true;
}

// Function to find minimum number of pages.
int findPages(int A[], int N, int M)
{
    if (M > N)
        return -1;
    int start = 0;
    int end = accumulate(A, A + N, 0); // 0 is the initial sum
    int ans = -1;

    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (isPossibleSol(A, N, M, mid))
        {
            ans = mid;
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return ans;
}

int main()
{
    int t;
    cout << "Enter the number of test cases: ";
    cin >> t;
    while (t--)
    {
        int N, M;
        cin >> N >> M;
        int A[N];
        for (int i = 0; i < N; i++)
        {
            cin >> A[i];
        }
        cout << findPages(A, N, M) << endl;
    }
    return 0;
}