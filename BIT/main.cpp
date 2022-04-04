#include <bits/stdc++.h>
using namespace std;
int d [500007];
int n,m;
inline int lowbit(int n){
    return -n & n;
}
int ask(int n){
    long long res = 0;
    while(n){
        res += d[n];
        n -= lowbit(n);
    }
    return res;
}
void add(int x, int k){
    while(x<=n){
        d[x] += k;
        x += lowbit(x);
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=1,a;i<=n;i++){
        cin>>a;
        add(i,a);
    }
    for(int i=1;i<=m;i++) {
        int tp, x, k;
        cin>>tp>>x>>k;
        if (tp == 1){
            add(x,k);
        }
        else{
            cout<<ask(k)- ask(x-1)<<"\n";
        }
    }
    return 0;
}
