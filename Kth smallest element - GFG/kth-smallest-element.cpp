// { Driver Code Starts
//Initial function template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
    public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int partition(int nums[], int l, int r){
        int pi = nums[r];
        int x = l-1;
        for(int i=l;i<r;i++){
            if(nums[i]<pi){
                x++;
                swap(nums[x], nums[i]);
            }
        }
        swap(nums[x+1], nums[r]);
        return x+1;
    }
    int kthSmallest(int nums[], int l, int r, int k) {
        //code here
        if(r-l>=k-1){
            int pi = partition(nums, l, r);
            if(pi-l==k-1) return nums[pi];
            
            if(pi-l>k-1)
            return kthSmallest(nums, l, pi-1, k);
            else
            return kthSmallest(nums, pi+1, r, k-1-(pi - l));
        }
        // for(int i=0;i<=r;i++) cout<<nums[i]<<" ";
        return 0;
    }
};

// { Driver Code Starts.
 
int main()
{
    int test_case;
    cin>>test_case;
    while(test_case--)
    {
        int number_of_elements;
        cin>>number_of_elements;
        int a[number_of_elements];
        
        for(int i=0;i<number_of_elements;i++)
            cin>>a[i];
            
        int k;
        cin>>k;
        Solution ob;
        cout<<ob.kthSmallest(a, 0, number_of_elements-1, k)<<endl;
    }
    return 0;
}  // } Driver Code Ends