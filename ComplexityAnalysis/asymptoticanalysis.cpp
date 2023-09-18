#include <iostream>
using namespace std;
//On entering a large input,sum2 will execute faster than sum
void sum(double n) // linear behaviour of time wrt input
{
    double sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum = sum + i;
    }
    cout << "Sum=" << sum << endl;
}

void sum2(double n) // constant time behaviour
{
    cout << "Sum=" << (n * (n + 1)) / 2 << endl;
    ;
}
int main()
{
    cout << "Enter the value of n upto where you want the sum:";
    double n;
    cin >> n;
    sum(n);
    sum2(n);
    return 0;
}