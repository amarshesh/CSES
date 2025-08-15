#include<bits/stdc++.h>
using namespace std;

int main (){
    int n ; cin>>n;
    int k ; cin>>k;
    int x, a, b, c; cin>>x>>a>>b>>c;
    vector<long long > elements(n);
    elements[0] = x;
    for (int i = 1; i < n; i++) {
        long long val = a * elements[i-1] + b;
        val = val % c;
        elements[i] = val;
    }
    long long sum = 0;
    for( int i = 0; i<k; i++){
        sum+=elements[i];
    }
    long long xorElement = sum;
    for(int j = k; j<n; j++){
        sum+=elements[j];
        sum-=elements[j-k];
        xorElement ^= sum;
    }
    cout<<xorElement<<" ";
}


