class Solution {
public:
    
    void f(int i,vector<string>&temp, vector<vector<string>>&ans, string s){
        if(i==s.length()){
            ans.push_back(temp);
            return;
        }
        
        for(int j=i;j<s.length();j++){
            if(is(i,j,s)==true){
                temp.push_back(s.substr(i,j-i+1));
                f(j+1,temp,ans,s);
                temp.pop_back();
            }
        }
    }
    
    bool is(int i,int j,string s){
        while(i<=j){
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>temp;
        f(0,temp,ans,s);
        return ans;
    }
};