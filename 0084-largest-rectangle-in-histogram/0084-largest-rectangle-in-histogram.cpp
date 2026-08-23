class Solution {
public:

vector<int>prevsmaller(vector<int>&a)
{   int n=a.size();
    stack<int>st;
    vector<int>res(n);
    for(int i = 0; i < n; i++){
    while(!st.empty() && a[st.top()] >= a[i])
    {
        st.pop();
    }
    if(st.empty())
    {
       res[i]=-1;
    }
    else
    {
        res[i]=st.top();
        
    }
    st.push(i);
    }
return res;
    
}

vector<int>nextsmaller(vector<int>&b)
{
    int n=b.size();
    stack<int>st;
    vector<int>res(b.size());
    
    for(int i = n-1; i >= 0; i--){
    while(!st.empty() && b[st.top()] >=b[i])
    {
        st.pop();
    }
    if(st.empty())
    {
       res[i]=n;
    }
    else
    {
        res[i]=st.top();
       
    }
     st.push(i);
     }
return res;
    
}



    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int>left=prevsmaller(heights);
        vector<int>right=nextsmaller(heights);

        int ans=0;
        for(int i = 0; i < n; i++)
        {
            int width= right[i]-left[i]-1;
            int area=width*heights[i];
            ans=max(ans,area);
        }
        return ans;


    }
};