//{ Driver Code Starts
 
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	

int isPalindromeUtil(string & s, int left, int right) {

    // Base case
    if (left >= right) 
        return 1;
    
    // If the characters at the current positions are not equal,
    // it is not a palindrome
    if (s[left] != s[right]) 
        return 0;

    // Move left pointer to the right
    // and right pointer to the left
    return isPalindromeUtil(s, left + 1, right - 1);
}
	
int isPalindrome(string s){
    int left = 0, right = s.length() - 1;
    return isPalindromeUtil(s, left, right);
}

};

//{ Driver Code Starts.

int main() 
{
   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

   	    Solution ob;

   		cout << ob.isPalindrome(s) << "\n";
   	}

    return 0;
}
// } Driver Code Ends
