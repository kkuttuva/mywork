#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

void printVector(vector<int> inp)
{
    for (vector<int>::iterator i = inp.begin(); i != inp.end(); i++)
         cout << *i << " ";
    cout << "\n";
}

void genCombinations(vector<int> source, int index, vector<vector<int> >& results,
                     vector<int>& curResult, int k)
{
    int len = source.size();

    if (k == len)
    {
        vector<int> *t = new vector<int>(source);
        results.push_back(*t);
        return;
    }

    if (k <= 0)
    {
        vector<int> *t = new vector<int>(curResult);
        results.push_back(*t);
        return;
    }

    for (int i = index; i < len; i++)
    {
        curResult.push_back(source[i]);
        genCombinations(source, i + 1, results, curResult, k - 1);
        curResult.pop_back();
    }
}

int main()
{
    vector<int> input, result;
    vector<vector<int> > results;

    input.clear();
    results.clear();
    input.push_back(1);
    input.push_back(2);
    input.push_back(3);
    input.push_back(4);
    input.push_back(5);

    printVector(input);
    genCombinations(input, 0, results, result, 3);
    for (vector<vector <int> >::iterator i = results.begin(); i != results.end(); i++)
         printVector(*i);

    return 0;
}


/*
 *

class Solution {
private:
    void genCombinations(int n, int index, vector<vector<int> >& results,
                     vector<int>& curResult, int k)
    {
        int len = n;

        if (k <= 0)
        {
            vector<int> *t = new vector<int>(curResult);
            results.push_back(*t);
            return;
        }

        for (int i = index; i < len; i++)
        {
            curResult.push_back(i + 1);
            genCombinations(n, i + 1, results, curResult, k - 1);
            curResult.pop_back();
        }
    }

public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> input, result;
        vector<vector<int> > results;

        genCombinations(n, 0, results, result, k);

        return results;
    }
};
*/
