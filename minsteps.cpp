#include<bits/stdc++.h>
using namespace std;
//# MIN STEPS TO 1
//BRUTE FROCE
int minsteps(int n){
if(n==1){
    return 0;
}
int x=minsteps(n-1);
int y=INT_MAX, z=INT_MAX;
if(n%2==0){
    z=minsteps(n/2);
}
if(n%3==0){
    y=minsteps(n/3);
}
return min(x, min(y,z))+1;
}
//better approch by memoization
int minstepsmemo(int n,  int *ans){
    if(n==1){
        ans[n]=0;
        return 0;
    }
ans[n-1]=minstepsmemo(n-1,  ans);
int y=INT_MAX,z=INT_MAX;
if(n%2==0){
    if(ans[n/2]==-1){
        ans[n/2]=minstepsmemo(n/2,  ans);
    }
    y=ans[n/2];
}
if(n%3==0){
    if(ans[n/3]==-1){
        ans[n/3]=minstepsmemo(n/3,  ans);
    }
    z=ans[n/3];
}
ans[n]=min(ans[n-1],  min(y,z))+1;

return ans[n];

}
int minstepmemodriv(int n){
int *ans=new int [n+1];
for(int i=0; i<=n; i++)ans[i]=-1;
return minstepsmemo(n,  ans);
}

// write driver code here
