// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
void swap(int &a ,int &b)
{ //call by reference - & here
// call by address means - * pointer here for formal params,  & for actual params from main
    int t;
    t=a;
    a=b;
    b=t;
}

void heapify(int a[],int i,int n)
{
    int l,r,largest;

    l= 2*i+1;
    r= 2*i+2;//cout <<l <<"land r"<<r;
     if (l<=n-1 and r<=n-1){ 
         //cout<<"l="<<l<<"r="<<r;

        if (a[i]> a[l] && a[i] > a[r])
        {
            //largest = a[i];--simply do nothing -- 
        }
        else if (a[l]>a[i] && a[l]> a[r])
        {
            swap (a[i],a[l]);
            heapify(a,l,n);
            
        }else 
        {
            if (a[r]>a[i] && a[r] >a[l])
            {
                swap(a[r],a[i]);
                 heapify(a,r,n);
               
/*10
20  12
30,17 25,40

40
30  10
20,17 25,12

This 10 ,25, 12 needs to consider to identify highest, so for the swapping index, we need to consider to check heapify property for that index again

40
30  25
20,17  10 12*/
            }
        }
      // cout<<i << a[i] ;//<< a[l] << a[r]<<"\n"; 
      
     }
    
}
void print(int a[],int n)
{
    int i; 
    
    for(i=0;i<n;i++)
    { //  cout<<"print";
        cout<<a[i];
    }
  //OP: create heap from array40302520171012  
}
int main() {
    // Write C++ code here
  //  cout << "HEAP";
    cout<< "create heap from array/ build max heap from array/ heapify algorithm";
    int a[7]={10,20,12,30,17,25,40};
    int n,i;
    n=sizeof(a)/sizeof(a[0]);
    //cout<< n;
    for(i=n-1;i>=0;i--)
    {//cout <<"loop"<<i;
    heapify(a,i,n);}
    print(a,n);
    return 0;
}