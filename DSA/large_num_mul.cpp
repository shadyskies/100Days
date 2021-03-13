#include<bits/stdc++.h>
using namespace std;
#define ll long long


ll multiply_naive(ll  n1, ll n2)
{
    return n1*n2;
}

//returns number too long to fit into long long datatype
void multiply(string s1, string s2)
{
    int len1 = s1.size();
    int len2 = s2.size();
    if (len1 == 0 || len2 == 0)
        cout<<"0";
    else
    {
        vector<int> res(len1+len2, 0);
        for(int i=len2-1; i>=0; i--) //travering number 1 backwards
        {
            vector<int> tmp;
            int carry = 0;
            for(int j=len1-1; j>=0; j--) //traversing number 2 backwards
            {
                int a1 = s1[i] - '0';
                int a2 = s2[j] - '0';
                int val = a1*a2;
                if (carry!=0)
                {
                    val += carry;
                    carry = 0;
                }
                if (j == 0)
                {
                   tmp.insert(tmp.begin(), val%10);
                   tmp.insert(tmp.begin(), val/10);
                }
                else
                {
                    if(val>=10)
                    {
                        carry = val/10;
                        tmp.insert(tmp.begin(), val%10);
                    } 
                    else
                        tmp.insert(tmp.begin(), val);
                }
            }
            int carry1 = 0;
            int n1 = tmp.size(); //size of tmp vector
            //append to res vector
            for(int k=n1-1; k>=0; k--)
            {
                int val = res[k]+tmp[k];
                if (carry1==1)
                {
                    val++;
                    carry1 = 0;
                }
                if (val>=10)
                {
                    res[k] = val-10;
                    carry1 = 1;
                }
                else
                    res[k] = val;
            }
            res.insert(res.begin(), 0);
        }


        for(int i=0; i<res.size(); i++)
            cout<<res[i];
    }
}


int main()
{
    // cout<<multiply_naive(320230430284390, 23817498327928); //gives incorrect answer
    multiply("1221", "1221"); //gives incorrect answer
    
    return 1;
}