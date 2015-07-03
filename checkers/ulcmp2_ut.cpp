#include "testlib.h"
#include <string>
#include <vector>
#include <sstream>

using namespace std;

#define UNORDERED_TOKENS true
#define CASE_INSENSITIVE false

void insertLine(string a, string b, vector<string>& vc, vector<string>& vd)
{
    vector<string> va, vb;
    stringstream sa;
    
    sa << a;
    string cur;
    while (sa >> cur) {
        if (CASE_INSENSITIVE) {
            cur = upperCase(cur);
        }
        va.push_back(cur);
    }

    stringstream sb;
    sb << b;
    while (sb >> cur) {
        if (CASE_INSENSITIVE) {
            cur = upperCase(cur);
        }
        vb.push_back(cur);
    }

    if (UNORDERED_TOKENS) {
        sort(va.begin(), va.end());
        sort(vb.begin(), vb.end());
    }

    string c, d;
    for (size_t i = 0; i < va.size(); i++) {
        c += va[i] + " ";
    }
    for (size_t i = 0; i < vb.size(); i++) {
        d += vb[i] + " ";
    }
    vc.push_back(c);
    vd.push_back(d);
}

int main(int argc, char * argv[])
{
    setName("compare files as sequence of tokens in unordered lines");
    registerTestlibCmd(argc, argv);

    std::string strAnswer;
    
    vector<string> vc, vd;

    int n = 0;
    while (!ans.eof()) 
    {
        std::string j = ans.readString();

        if (j == "" && ans.eof())
          break;
        
        std::string p = ouf.readString();
        strAnswer = p;

        n++;

        insertLine(j, p, vc, vd);
    }

    sort(vc.begin(), vc.end());
    sort(vd.begin(), vd.end());

    for (int i = 0; i < n; i++) {
        if (vc[i] != vd[i]) {
            quitf(_wa, "%d%s sorted lines differ - expected: '%s', found: '%s'", i, englishEnding(i).c_str(), compress(vc[i]).c_str(), compress(vd[i]).c_str());    
        }
    }

    if (n == 1)
        quitf(_ok, "single line: '%s'", compress(strAnswer).c_str());
    
    quitf(_ok, "%d lines", n);
}
