#include<bits/stdc++.h>
using namespace std;

int dfs( int n ){
    if( n == 0 ) return 1;
    int ans = 0;
    for( int i = 1; i<=6; i++){
        if( n - i >0){
            ans = 1 + dfs( n - i);
        }
    }
    return ans;
}
int main(){
    int n; cin>>n;
    int ans = 0;
    ans = dfs( n);
    cout<<ans<<endl;
}