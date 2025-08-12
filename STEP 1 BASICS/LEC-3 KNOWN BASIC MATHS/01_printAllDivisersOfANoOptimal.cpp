#include <bits/stdc++.h>
using namespace std;

vector<int> findDivisers(int n)
{
    vector<int> ans;
    int sqr = sqrt(n);
    for (int i = 1; i <= sqr; i++)
    {
        if (n % i == 0)
        {
            ans.push_back(i);

            if (i != n / i)
            {
                ans.push_back(n / i);
            }
        }
    }
    return ans;
}
int main()
{
    int n = 12;
    vector<int> divisers = findDivisers(n);
    cout << "divisers are: ";
    for (auto it : divisers)
    {
        cout << it << " ";
    }
    cout << "\n";
    return 0;
}