#include <bits/stdc++.h>
using namespace std;

// Function to find length of
// longest increasing subarray with atmost 1 element change.
int seg(int a[], int n)
{
    vector<int>l(n); // longest increasing subarray ending at index i
    vector<int>r(n); // longest increasing subarray starting at index i
    l[0] = 1;
    r[n-1] = 1;
    for(int i=1;i<n;i++){
        if(a[i-1] < a[i]) l[i] = l[i-1]+1;
        else l[i] = 1;
    }
    
    for(int i=n-2;i>=0;i--){
        if(a[i+1] > a[i]) r[i] = r[i+1]+1;
        else r[i] = 1;
    }
    int ans = 0;
    // here we check every index (to change).
    for(int i=1;i<n-1;i++){
        //possible to merge ?
        if(a[i-1] < a[i+1]){
            ans = max(ans, 1 + l[i-1]+r[i+1]);
        }
        else{
            // take the max of both of the sides.
            ans = max(l[i-1]+1,ans);
            ans = max(r[i+1]+1,ans);
        }
    }
    // for index 0 we check only right.
    ans = max(ans,r[1]+1);
    //for index n-1 we check only left.
    ans = max(ans,l[n-2]+1);
    return ans;
}

// Driver code.
int main()
{
    int a[] = {9,4,5,1,13};
    int n = sizeof(a) / sizeof(a[0]);
  
    // Function call
    cout << seg(a, n);
    return 0;
}
