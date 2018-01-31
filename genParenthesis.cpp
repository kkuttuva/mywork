#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string genBraces(int n, string& curStr, int pos, int ocount, int ccount, vector<string>& result)
{

   if (pos == (n * 2))
   {
      result.push_back(curStr);
      return "";
   }

   if (ccount >= n)
   {
       return "";
   }

   if (ocount < n)
   {
       curStr[pos] = '(';
       genBraces(n, curStr, pos + 1, ocount + 1, ccount, result);
   }

   if (ccount < ocount)
   {
       curStr[pos] = ')';
       genBraces(n, curStr, pos + 1, ocount, ccount + 1, result);
   }
   return curStr;
}

void print(vector<string>& vs)
{
   for (vector<string>::iterator it = vs.begin(); it != vs.end(); it++) {
       cout << *it << "\n";
   }
   cout << "done\n";
}

int main()
{
   vector<string> result;
   string cur;

   cur.resize(64);

   genBraces(3, cur, 0, 0, 0, result);
   print(result);
   result.clear();

#if 0
   genBraces(4, cur, 0, 0, 0, result);
   print(result);
   result.clear();

   genBraces(5, cur, 0, 0, 0, result);
   print(result);
   result.clear();

   genBraces(6, cur, 0, 0, 0, result);
   print(result);
   result.clear();
#endif
}
