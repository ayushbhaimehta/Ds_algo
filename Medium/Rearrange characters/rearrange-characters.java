//{ Driver Code Starts
import java.util.*;
import java.lang.*;
import java.io.*;

class GFG {
	public static void main (String[] args) {
		try {
			BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
			int t = Integer.parseInt(br.readLine());
			while (t-- > 0) {
				String str = br.readLine();
				Solution ob= new Solution();
				String str1 = ob. rearrangeCharacters(str);
				
        		int flag=1;
        	    int[] c = new int[26];
        	    Arrays.fill(c,0);
        	    for(int i=0; i<str.length(); i++)
        	        c[str.charAt(i)-'a']+=1;
        	    int f = 0;
        	    int x = (str.length()+1)/2;
        	    for(int i=0; i<26; i++)
        	    {
        	        if(c[i]>x)
        	            f = 1;
        	    }
        	    if(f == 1)
        	    {
        	        if(str1=="-1")
        	            System.out.println(0);
            	    else
            	        System.out.println(1);
        	    }
        	    else
        	    {
            	    int[] a = new int[26];
        	        Arrays.fill(a,0);
            	    int[] b = new int[26];
        	        Arrays.fill(b,0);
            	    for(int i=0; i<str.length(); i++)
            	        a[str.charAt(i)-'a']+=1;
            	    for(int i=0; i<str1.length(); i++)
            	        b[str1.charAt(i)-'a']+=1;
            	        
            	    for(int i=0; i<26; i++)
            	        if(a[i]!=b[i])
            	            flag = 0;
            	    
            	    for(int i=0;i<str1.length();i++)
            	    {
            		    if(i>0)
            		        if(str1.charAt(i-1)==str1.charAt(i))
            			        flag=0;
            	    }
            	    if(flag==1)
            		    System.out.println(1);
            	    else
            	        System.out.println(0);
        	    }
			}
		} catch (Exception e) {

		}
	}
}
// } Driver Code Ends


class Solution
{
	public static String rearrangeCharacters(String str) {
	
		//code here
		HashMap<Character, Integer> map = new HashMap<>();
		StringBuilder sb = new StringBuilder();
		
		for(int i=0;i<str.length();i++) {
		    map.put(str.charAt(i), map.getOrDefault(str.charAt(i), 0)+1);
		}
		
		PriorityQueue<Character> pq = new PriorityQueue<>((a,b) -> map.get(b)-map.get(a));
		pq.addAll(map.keySet());
		
		while(pq.size()>1) {
		    
		    char current = pq.remove();
		    char next = pq.remove();
		    
		    sb.append(current);
		    sb.append(next);
		    
		    map.put(current, map.get(current)-1);
		    map.put(next, map.get(next)-1);
		    
		    if(map.get(current)>0){
		        pq.add(current);
		    }
		    if(map.get(next)>0){
		        pq.add(next);
		    }
		}
		
		if(!pq.isEmpty()) {
		    char last = pq.remove();
		    
		    if(map.get(last)>1){
		        return "-1";
		    }
		    sb.append(last);
		}
		
		return sb.toString();
	}
}