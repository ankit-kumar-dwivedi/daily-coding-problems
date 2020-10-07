// leetcode - https://leetcode.com/problems/longest-substring-without-repeating-characters/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        
        // in case of empty string
        if (n == 0) {
            return 0;
        }
        
        int current_len = 1;
        int max_len = 1;
        int visited[256];
        
        // mark all char as -1 or non visited
        for(int i=0; i<256; ++i) {
            visited[i] = -1;
        }
        
        // first character
        visited[s[0]]=0;
        for(int i=1; i<n; ++i) {
            // find last occurence of this char
            int last_occ = visited[s[i]];
            // if first occ, or last occ is out of window
            if(last_occ==-1 or i-current_len>last_occ) {
                current_len+=1;
            }
            else {
                if(current_len>max_len) {
                    max_len = current_len;
                }
                // now window is shrinked current index - last occ of this char
                current_len = i-last_occ;
            }
            visited[s[i]] = i;
        }
        if(current_len>max_len) {
            max_len = current_len;
        }    
        return max_len;
    }
};
