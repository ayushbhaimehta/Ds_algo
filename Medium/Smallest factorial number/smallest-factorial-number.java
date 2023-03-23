//{ Driver Code Starts
//Initial Template for Java

import java.util.*;

public class GFG
{
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        
        int t = sc.nextInt();
        
        while (t-- > 0)
        {
            int n = sc.nextInt();
            
            System.out.println(new Solution().findNum(n));
        }
    }
}
// } Driver Code Ends


//User function Template for Java

class Solution
{
    int findNum(int n)
    {
        // Complete this function
        int low = 0, high = 5*n;

    
        while(low < high) {
            int mid = (low + high) / 2;
            int count = 0;
            for(int i=5; mid/i >= 1; i*=5) {
                count += mid/i;
            }
            if(count >= n) {
                high = mid;
            }
            else {
                low = mid+1;
            }
        }

        return low;
    }
}