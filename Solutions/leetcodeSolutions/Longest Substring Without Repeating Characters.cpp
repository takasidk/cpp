//problem NO-3 in leetcode
/*Given a string s, find the length of the longest substring without repeating characters.

Example 1:
Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:
Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:
Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
Example 4:
Input: s = ""
Output: 0 
Constraints:
0 <= s.length <= 5 * 104
s consists of English letters, digits, symbols and spaces.*/
// sliding window technique
class Solution {
   
public:
    int lengthOfLongestSubstring(string s) {
        int ans=0; //intial length
        int n=s.length();
       set<char> ss;   //set data structure is taken because it doesnt allow repeated characters and insert,find, remove operations are done in O(log(n))-worst case 
        int i=0,j=0;   //two iterators are taken intialised to 0
        while(i<n && j<n){ // while i and j doesnt go out of string bounds
            if(ss.find(s[j])==ss.end()){ // here if the char at j position is not found in our set and increment the iterator
                                         // then add it into the set and increase the length of ans by checking whether its greater then the previous len
                
                ss.insert(s[j++]);
                ans=std::max(ans,j-i);
            }
            else     // else erase from starting till the jth element is found in our set
            {
                ss.erase(s[i]);
                i++;
            }
        }
        return ans;
    }
};