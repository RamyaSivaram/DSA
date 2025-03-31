// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
#include <unordered_set>

bool subset (int a[], int b[])
{
    unordered_set<int> hs; // when only we need unique value
    int i=0;
    for( i=0;i<5;i++)
     hs.insert(a[i]); // if gng to use array , then go for insert
    for(i=0;i<3;i++)
    {
        if ( hs.find(b[i]) == hs.end())
        {
            return false;
        }
    }
    return true;
     
}
int main() {
    // Write C++ code here
    cout << "Check if an array is subset of another array";
    int a[5], b[3] , i=0;
    for(i=0;i<5;i++)
     cin >> a[i];
    for (i=0;i<3;i++)
     cin >> b[i];
    bool var= subset(a,b); 
    if (var)
    cout << "subset";
    else
    cout << "not a subset";
    return 0;
}

/*Check if an array is subset of another array2
3
4
5
6
3
4
6
subset

=== Code Execution Successful ===
time: o(m+n) space: o(m)*/