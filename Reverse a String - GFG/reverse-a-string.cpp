//{ Driver Code Starts
//Initial Template for C++


#include<bits/stdc++.h>
using namespace std;


string reverseWord(string str);


int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
	string s;
	cin >> s;
	
	cout << reverseWord(s) << endl;
	}
	return 0;
	
}


// } Driver Code Ends


//User function Template for C++

string reverseWord(string str){
    
  //Your code here
  int n = str.size();
  int i=0;
  int j = n-1;
  while(i<j){
      int temp = str[i];
      str[i]=str[j];
      str[j]=temp;
      i++;
      j--;
  }
  return str;
  
}

