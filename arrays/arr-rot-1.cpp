/* Rotation of array by d.
 * Time Complexity: O(n)
 * - shifting in sets of gcd(n,d)
 * - block swap: https://www.geeksforgeeks.org/block-swap-algorithm-for-array-rotation/
 */

#include <iostream>
using namespace std;

void rev(int *a, int n)
{
    for(int i=0; i<n/2; i++)
        swap(a[i],a[n-i-1]);
}

void rotate(int *a, int n, int d)
{
    rev(a,d);
    rev(a+d,n-d);
    rev(a,n);
}


int main()
{
    int i,n,d,a[100];

    cin>>n;
    for(i=0; i<n; i++)
        cin>>a[i];

    cin>>d;

    d = d%n;
    rotate(a,n,d);

    for(i=0; i<n; i++)
        cout<<a[i]<<"  ";


    return 0;
}
