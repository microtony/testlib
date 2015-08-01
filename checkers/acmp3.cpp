#include "testlib.h"
#include <cmath>

using namespace std;

const double EPS = 0.00101;

int main(int argc, char * argv[])
{
    setName("compare two sequences of doubles, max absolute error = %.5f", EPS);
    registerTestlibCmd(argc, argv);

    int n = 0;
    double j = 0, p = 0;

    while (!ans.seekEof()) 
    {
        n++;
        j = ans.readDouble();
        p = ouf.readDouble();
        if (fabs(j - p) > EPS)
        {
            quitf(_wa, "%d%s numbers differ - expected: '%.5f', found: '%.5f', error = '%.5f'",
                n, englishEnding(n).c_str(), j, p, fabs(j - p));
        }
    }

    if (n == 1)
        quitf(_ok, "found '%.5f', expected '%.5f', error '%.5f'", p, j, fabs(j - p));
    
    quitf(_ok, "%d numbers", n);
}
