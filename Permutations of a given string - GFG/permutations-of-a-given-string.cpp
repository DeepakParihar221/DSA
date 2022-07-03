// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	    void solve(string s, int i, int n, vector<string> &ans, string temp, set<string> &mid){
	        if(i>n) return;
	        if(temp.size()==n){
	            if(mid.find(temp)==mid.end()){
    	            mid.insert(temp);
    	            ans.push_back(temp);
	            }
	            return;
	        }
	        
	        for(int index=i;index<n;index++){
	            swap(s[index], s[i]);
	            temp += s[i];
	            solve(s, i+1, n, ans, temp, mid);
	            temp.pop_back();
	            swap(s[index], s[i]);
	        }
	       // cout<<"H ";
	    }
		vector<string>find_permutation(string s)
		{
		    // Code here there
		    int n = s.length();
		    vector<string> ans;
		    set<string> mid;
		    solve(s, 0, n, ans, "", mid);
		    sort(ans.begin(), ans.end());
		    return ans;
		}
};



// { Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}
  // } Driver Code Ends