/*
 * A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given an encoded message containing digits, determine the total number of ways to decode it.

For example,
Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).

The number of ways decoding "12" is 2.
*/

class Solution {
public:
    int numDecodingsH(string s, int pos, int len) {
       int count1 = 0, count2 = 0;

       if (pos == len)
           return 1;

       if (pos > len)
           return 0;

       if (s[pos] == '0')
           count1 = 0;
       else if (s[pos] > 2)
           count1 = numDecodingsH(s, pos + 1, len);
       else {
           count1 = numDecodingsH(s, pos + 1, len);
           if (s[pos] == 1)
               count2 = numDecodingsH(s, pos + 2, len);
           else if ((pos + 1) < len) && (s[pos + 1] <= '6'))
               count2 = numDecodingsH(s, pos + 2, len);
           count1 += count2;
        }
        return count1;
    }


    int numDecodings(string s) {
       return numDecodingsH(s, 0, s.length());        
    }
};
