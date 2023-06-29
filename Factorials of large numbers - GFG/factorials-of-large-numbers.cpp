//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
public:
class Node{
  public:
  int data;
  Node* prev;
  Node(int data){
      this->data=data;
      this->prev=NULL;
  }
};
    vector<int> factorial(int N){
        // code here
        Node* tail = new Node(1);
        for(int i=2; i<=N; i++){
            Node* temp = tail;
            Node* prevNode = tail;
            int carry=0;
            while(temp!=NULL){
                int num = temp->data;
                num = num*i + carry;
                temp->data=num%10;
                carry=num/10;
                prevNode = temp;
                temp = temp->prev;
            }
            while(carry!=0){
               prevNode->prev = new Node(1);
               prevNode=prevNode->prev;
               prevNode->data = carry%10;
               carry/=10;
            }
        }
        vector<int> ans;
        Node* temp=tail;
        while(temp!=NULL){
            ans.push_back(temp->data);
            temp=temp->prev;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        vector<int> result = ob.factorial(N);
        for (int i = 0; i < result.size(); ++i){
            cout<< result[i];
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends