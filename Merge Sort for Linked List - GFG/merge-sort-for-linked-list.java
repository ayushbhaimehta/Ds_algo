//{ Driver Code Starts
//Initial Template for Java

import java.util.*;
import java.lang.*;
import java.io.*;

class Node
{
    int data;
    Node next;
    Node(int key)
    {
        data = key;
        next = null;
    }
}

class Driverclass
{
    
    public static void main (String[] args) 
    {
        Scanner sc= new Scanner(System.in);
        int t = sc.nextInt();
        
        while(t-- > 0)
        {
            int n = sc.nextInt();
            Node head = new Node(sc.nextInt());
            Node tail = head;
            while(n-- > 1){
		        tail.next = new Node(sc.nextInt());
		        tail = tail.next;
		    }
		   
		      head = new Solution().mergeSort(head);
		     printList(head);
		    System.out.println();
        }
    }
    public static void printList(Node head)
    {
        if(head == null)
           return;
           
        Node temp = head;
        while(temp != null)
        {
            System.out.print(temp.data + " ");
            temp = temp.next;
        }
    }
}



// } Driver Code Ends


//User function Template for Java
/*
class Node
{
    int data;
    Node next;
    Node(int key)
    {
        this.data = key;
        next = null;
    }
} */

class Solution
{
    //Function to sort the given linked list using Merge Sort.
    public static Node findmid(Node head){
        Node sp = head;
        Node fp = head.next;
        while(fp!=null && fp.next!=null){
            sp = sp.next;
            fp = fp.next;
        }
        return sp;
    }
    public static Node merge(Node left, Node right){
      
        Node head = null;
        Node temp = head;
        while(left!=null && right!=null){
            if(left.data<right.data){
                if(head == null){
                    head = left;
                    temp = head;
                    left = left.next;
                }
                else{
                    temp.next = left;
                    left = left.next;
                    temp = temp.next;
                }
            }
            else{
                if(head == null){
                    head = right;
                    temp = head;
                    right = right.next;
                }
                else{
                    temp.next = right;
                    right = right.next;
                    temp = temp.next;
                }
            }
        }
        if(left!=null){
            temp.next = left;
        }
        if(right!=null){
            temp.next = right;
        }
        return head;
    }
    static Node mergeSort(Node head) {
        if(head == null || head.next == null){
            return head;
        }
        Node left = head;
        Node right = findmid(head);
        Node tmp = right;
        tmp = tmp.next;
        right.next = null;
        right = tmp;
        left = mergeSort(left);
        right = mergeSort(right);
        return merge(left,right);
    }
}


