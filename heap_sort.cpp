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
{// i is which index to check for heapify
    int l,r,largest=i;

    l= 2*i+1;
    r= 2*i+2;//cout <<l <<"land r"<<r;
    // if we have like this, then is 1 child node not there then
    //thst wont check heapify for the only 1 child node, so commente //belwo code
    /*if (l<=n-1 and r<=n-1){ 
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
20,17  10 12
            }
        }
      // cout<<i << a[i] ;//<< a[l] << a[r]<<"\n"; 
      
     }*/
     // If left child is larger than root
    if (l < n && a[l] > a[largest])
        largest = l;
 
    // If right child is larger than largest so far
    if (r < n && a[r] > a[largest])
        largest = r;
 
    // If largest is not root
    if (largest != i) {
        swap(a[i], a[largest]);
 
        // Recursively heapify the affected sub-tree
        heapify(a, largest, n);
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
void insert(int a[], int ins, int &n)
{// as we change size n, we need &
    int i;
    n=n+1;
    a[n-1] =ins;//cout<<n;
   for(i=n-1;i>=0;i--)
    {heapify(a,i,n);}//bottom up approach
}
void delete_root(int a[], int &n)
{//dedletes root always. like removing fresh apples at top from vege shop. simply delete is a keyword, so rename fn
    a[0]=a[n-1];
    n=n-1;
    //for(int i=n-1;i>=0;i--)
    heapify(a,0,n);//top down approach
    
}
void heap_sort(int a[],int n)
{
    //1. swap root & last 2. then heapify root so to avoid that max element beeb swapped reduce the array size
   
    for(int i=n-1;i>=0;i--){
    swap(a[0],a[i]);
    heapify(a,0,i);

  } 
}
int main() {
    // Write C++ code here
  //  cout << "HEAP";
    cout<< "insert node and delete node";
    int a[6]={10,20,12,30,17,25};
    int n,i;
    n=sizeof(a)/sizeof(a[0]);
    //cout<< n;
    print(a,n);
    cout<<"1st:Make max heap from array";
    for(i=n-1;i>=0;i--)
    {//cout <<"loop"<<i;
    heapify(a,i,n);}
    print(a,n);
    cout<<"2nd:insert 40";
    insert(a,40,n);
     print(a,n);
     cout<<"3rd delete";
     delete_root(a,n);
    print(a,n);
    cout<<"heap sort";
    heap_sort(a,n);
    print(a,n);
    return 0;
}

/*insert node and delete node1020123017251st:Make max heap from array3020251017122nd:insert 40402030101712253rd delete302025101712heap sort101217202530

=== Code Execution Successful ===*/