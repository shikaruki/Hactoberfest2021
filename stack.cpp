

vector<int> ngor(vector<int> arr){
stack<int> st;

vector<int> ans(arr.length,-1);

for(int i=0;i<arr.length;i++)
{
     while(st.size()!=0)
     {
     	if(arr[i]>arr[st.top()])
     	{
           arr[st.top]=arr[i];
           st.pop();
     	}
     }

     st.push(arr[i]);
}
}