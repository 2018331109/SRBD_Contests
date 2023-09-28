#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define no cout<<"NO"<<endl;
#define yes cout<<"YES"<<endl;
#define neg cout<<-1<<endl;

const int mod=1e9+7;

void solve()
{
    int b, y;
    cin>>b>>y;

    int l=0, r=100;
    int ans=0;

    while(l<r)
    {
        int mid=l+(r-l)/2;
        int aa=mid/2;
        int bb=mid-aa;
        int cost=(aa*aa)+(bb*bb)+(mid*y);
        if(cost<=b)
        {
            ans=mid;
            l=mid+1;

        }
        else
        {
            r=mid;
        }

    }

    //cout<<ans<<endl;


    int res=1;
    int i=0;
    while(i<ans)
    {
        res*=2;
        i++;
    }
    cout<<res<<endl;
}



signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int test=1;
    cin>>test;
    for(int t=1; t<=test; t++)
    {
        solve();
    }

}

