/* Searching in a sorted rotated array
 * without finding pivot
 * find sorted side, if ele on that side, bsearch, else recurse on non-sorted side
 */

#include <iostream>
using namespace std;

/*
int bsearch(int *a, int start, int end, int ele)
{
    int mid;
    while(start <= end)
    {
        mid = (start+end)/2;

        if(a[mid] == ele)
            return mid;

        if(a[mid] >= ele)
            end = mid-1;
        else
            start = mid+1;
    }
    return -1;
}
*/

int rotsearch(int *a, int start, int end, int ele)
{
    if (start > end) return -1;

    int mid = (start+end)/2;

    if(a[mid] == ele)
        return mid;

    if(a[start] < a[mid])   //first half of array is sorted
    {
        if(ele >= a[start] && ele < a[mid])
            return rotsearch(a,start,mid-1,ele);

        return rotsearch(a,mid+1,end,ele);
    }
    else                   //second half of array is sorted
    {
         if(ele <= a[end] && ele > a[mid])
            return rotsearch(a,mid+1,end,ele);

        return rotsearch(a,start,mid-1,ele);
    }
}

int main()
{
    int val,i,n,a[100];

    cin>>n;
    for(i=0; i<n; i++)
        cin>>a[i];

    cin>>val;

    cout<<rotsearch(a,0,n-1,val);

    return 0;
}
