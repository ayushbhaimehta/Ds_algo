//{ Driver Code Starts
//Initial Template for Java

import java.io.*;
import java.util.*;

class GFG{
    
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        
        int t = Integer.parseInt(sc.next());
        while(t>0)
        {
            int n = Integer.parseInt(sc.next());
            Solution T = new Solution();
            List<String> ans = T.AllParenthesis(n);
            String[] sequences = ans.toArray(new String[0]);
            Arrays.sort(sequences);
            int k = sequences.length;
            for(int i=0;i<k;i++)
            {
                System.out.println(sequences[i]);
            }
            
            t--;
            
        }
    }
}

// } Driver Code Ends


//User function Template for Java

class Solution {
    
    List<String> ans=new ArrayList<>();
    
    
    public List<String> AllParenthesis(int n) 
    {
        // Write your code here
        String s="";
        fun(0,0,s,n);
        return ans;
        
    }
    public void fun(int open,int close,String s,int n)
    {
        if(open+close==(2*n)){
            ans.add(s);
            return;
        }
        if(open<n){
            fun(open+1,close,s+"(",n);
        }
        if(close<open){
            fun(open,close+1,s+")",n);
        }
        
        
    }
}