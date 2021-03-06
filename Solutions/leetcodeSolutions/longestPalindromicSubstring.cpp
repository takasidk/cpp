//leetcode problem NO:5 Longest Palindromic Substring
/*Given a string s, return the longest palindromic substring in s.
Example 1:
Input: s = "babad"
Output: "bab"
Note: "aba" is also a valid answer.
Example 2:
Input: s = "cbbd"
Output: "bb"
Example 3:
Input: s = "a"
Output: "a"
Example 4:
Input: s = "ac"
Output: "a"
Constraints:
1 <= s.length <= 1000
s consist of only digits and English letters (lower-case and/or upper-case),*/
class Solution {
    int max_len=1;   //global variables for this class
      int st=0,end=0;
    void getLen(string s,int l,int r){
        int len=1;
        while(l>=0 && r<s.length()){
            if(s[l]==s[r]){
                l--;
                r++;
            }
            else break;
        }

       len=r-l-1;
            if (max_len<len){
                max_len=len;
            st=l+1;
            end=r-1;}
    }
public:
    string longestPalindrome(string s) {//for odd and even length substring the traversals will be diff
        int n=s.length();
        if(n<=1) return s; // if length of string less then 1 return string itself
        for(int i=0;i<n;i++){
            int l=i,r=i;
            getLen(s,l,r);//for odd length substring ex:"cbabad" here ans is "bab"odd length 
            getLen(s,l,r+1);//for even length substring ex:"abb" here ans:"bb" even length
        }
        return s.substr(st,max_len);//inbuilt substring fn which takes start pos and length of substring
    }
};
