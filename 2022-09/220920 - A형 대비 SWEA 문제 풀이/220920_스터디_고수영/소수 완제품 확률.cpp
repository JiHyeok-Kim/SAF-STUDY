#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

int T;
int sosu[7] = { 2,3,5,7,11,13,17 };

double Fct(double A)
{
    if (A == 1) return 1;
            
    return A*Fct(A-1);
}

int main()
{
cin >> T;
for (int t = 1; t < T + 1; t++)
{
    double MA, MB;
    cin >> MA >> MB;
    double result = 0;
    double tmpA = 0, tmpB = 0;

if (MA == 0 && MB == 0)
{result = 0.000000;
    cout<<fixed;
    cout.precision(6);
    cout <<"#"<<t<<" "<<result<<"\n";
}
else
{
    for (int i = 0; i < 7; i++)
    {
        double pA1 = pow((MA / 100), sosu[i]);
        double fA1 = (Fct(18)  / ((Fct(sosu[i]) * Fct(18 - sosu[i]))));
        double pA2 = pow(((100 - MA) / 100), 18 - sosu[i]);
        tmpA += (pA1*fA1*pA2);

        double pB1 = pow((MB / 100), sosu[i]);
        double fB1 = (Fct(18) / (Fct(sosu[i]) * Fct(18 - sosu[i]))) ;
        double pB2 = pow(((100 - MB) / 100), 18 - sosu[i]);

        tmpB += (pB1*fB1*pB2);

    }
        
    result = 1-((1-tmpA)*(1-tmpB));
    
    cout <<"#"<<t<<" "<<result<<"\n";


    }
}
return 0;
}
