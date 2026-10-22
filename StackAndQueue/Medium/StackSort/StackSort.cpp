#include<iostream>
#include<stack>
#include<vector>
using namespace std;
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int a[n];
	    for(int i = 0 ;i<n ; i++)
	    {
	        cin>>a[i];
	    }
	    stack<int>st;
	    vector<int>b;
	    for(int i = 0 ;i<n ; i++)
	    {
	       while(!st.empty() && st.top()<=a[i])
	       {
	           b.push_back(st.top());
	           st.pop();
	       }
	       st.push(a[i]);
	    }
	    while(!st.empty())
	    {
	        b.push_back(st.top());
	        st.pop();
	    }
	    int flag =1;
	    for(int i = 0 ;i<b.size()-1;i++)
	    {
	        if(b[i]>b[i+1])
	        {
	           flag =0;
	            break;
	        }
	    }
	    if(flag==0) cout<<"NO"<<endl;
	    else cout<<"Yes"<<endl;
	}
return 0;
}
