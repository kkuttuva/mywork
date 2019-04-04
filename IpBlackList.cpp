#include <iostream>

using namespace std;

struct TreeNode {
    TreeNode *next[2];
    TreeNode() { next[0] = next[1] = NULL;}
};

class IPBlackList {
    TreeNode root;

    public:
       IPBlackList() : root() {
       }
       void insert(int ip, int maskLen) {
          unsigned int pos = (1<<31);
          TreeNode *iter = &root;
          while(maskLen) {
                bool bit = ip & pos;
 //               cout << pos << " " << bit << endl;
                if(iter && iter->next[bit]) {
                   iter = iter->next[bit];
                } else {
                   TreeNode *n = new TreeNode();
                   iter->next[bit] = n;
                   iter = n;
                }
                maskLen--;
                pos = pos >> 1;
          }
       }
       bool isBlackList(int ip) {
            TreeNode *iter = &root;
            unsigned int pos = (1<<31);
            while(pos) {
                bool bit = ip & pos;
                iter = iter->next[bit];
//                cout << pos << " " << bit << " " << iter << endl;
                 if(iter == NULL) {
                     return false;
                 }
                if((iter->next[0] == NULL) && (iter->next[1] == NULL)) {
                    return true;
                }
                pos = pos >> 1;
            }
            return false;
        }
};

int main() {
    IPBlackList ipLib;
    ipLib.insert(0x01020300, 16);
    ipLib.insert(0x01030400, 24);
    cout << "1.2.3.4 " << ipLib.isBlackList(0x1020304) << endl;
    cout << "1.2.3.255 " << ipLib.isBlackList(0x10203ff) << endl;
    cout << "1.2.4.4 " << ipLib.isBlackList(0x1020404) << endl;
    cout << "1.5.4.4 " << ipLib.isBlackList(0x1050404) << endl;
    cout << "1.3.4.4 " << ipLib.isBlackList(0x1030404) << endl;
}
