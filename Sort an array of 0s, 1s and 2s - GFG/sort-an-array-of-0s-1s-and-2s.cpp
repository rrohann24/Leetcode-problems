//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    void swap(int i,int j,int a[], int n){
        int temp = a[i];
        a[i]=a[j];
        a[j]=temp;
    }
    void sort012(int a[], int n)
    {
        // code here 
        int i=0;
        int j=0;
        while(j<n){
            if(a[j]==0){
                swap(i,j,a,n);
                i++;
            }
            j++;
        }
        j=i;
        while(j<n){
            if(a[j]==1){
                swap(i,j,a,n);
                i++;
            }
            j++;
        }
        j=i;
        while(j<n){
            if(a[j]==2){
                swap(i,j,a,n);
                i++;
            }
            j++;
        }
    }
    
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }

        Solution ob;
        ob.sort012(a, n);

        for(int i=0;i<n;i++){
            cout << a[i]  << " ";
        }

        cout << endl;
        
        
    }
    return 0;
}


// } Driver Code Ends