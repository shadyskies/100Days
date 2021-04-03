#include<bits/stdc++.h>
using namespace std;

bool mulof3(long long n)
{
    if (n==0)
        return false;
    if (n==1)
        return true;
    else
    {
        int odd_count = 0;
        int even_count = 0;
        while(n)
        {
            if(n & 1)
                odd_count++;
            if(n & 2)
                even_count++;
            n >>= 2;
        }
        if (abs(odd_count - even_count)%3==0)
            return true;
        else
            return false;
    }
}

int main()
{
    long long int n = 36936396396936    ;
    cout<<((mulof3(n))?("True"):("False"));
}