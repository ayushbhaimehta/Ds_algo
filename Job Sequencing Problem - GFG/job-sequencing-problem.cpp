//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


// } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    
    static bool comp(struct Job a,Job b){
        if(a.profit>b.profit) return true;
        else if(a.profit<b.profit) return false;
        else if(a.dead<b.dead) return true;
        return false;
    }
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // So our intuition is to apply greedy
        // and to apply it we need to sort the data
        // in decreasing order of profit and
        // when profit is equal less deadline is preffered
        
        // your code here
        // sort the arr using a custom made comparator
        sort(arr,arr+n,comp);
        
        int maxi=0;
        for(int i=0;i<n;i++){
            maxi=max(maxi,arr[i].dead);
        }
        
        // maintaining an arr for job performed
        int slot[maxi+1];
        for(int i=0;i<=maxi;i++){
            slot[i]=-1;
        } 
    
        int countJobs=0,jobProfit=0;
    
        for(int i = 0;i<n;i++){
            for(int j=arr[i].dead;j>0;j--){
                if(slot[j] == -1) {
                    slot[j] = i;
                    countJobs++;
                    jobProfit += arr[i].profit;
                    break;
                }
            }
        }
        
        vector<int>ans(2,0);
        ans[0]=countJobs,ans[1]=jobProfit;
        
        return ans;
    } 
};

//{ Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}



// } Driver Code Ends