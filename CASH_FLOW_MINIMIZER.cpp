#include <bits/stdc++.h>
using namespace std;
//input be like first line n number of people
//next n rows are cash n rows
int min_val(vector<int>& amount){
int ans=0;
for( int i=1;i<amount.size();i++){
if(amount[i]<amount[ans])
ans=i;
}
return ans;
}
int max_val(vector<int>& amount){
int ans=0;
for( int i=1;i<amount.size();i++){
if(amount[i]>amount[ans])
ans=i;
}
return ans;
}
void minimize_cash_flow(vector<int>& amount){
//finding the min and max value index
int minval=min_val(amount);
int maxval=max_val(amount);
//base condition
if(amount[maxval]==0 && amount[minval]==0)return ;
//decide what amount one can maximaly give or take
int val_to_reduce=min((-1*amount[minval]),amount[maxval]);
amount[maxval]-=val_to_reduce;
amount[minval]+=val_to_reduce;
cout<<"person "<<minval<<" pays "<<val_to_reduce<<" to "<<maxval<<endl;
//recursive call
minimize_cash_flow(amount);
return;
}
int main() {
int n;
cin>>n;
vector<vector<int>> cash(n,vector<int>(n));
//who has to pay whom and how much
//i has to pay to y
for (int i=0;i<n;i++)
{
for (int j=0;j<n;j++){
cin>>cash[i][j];
}
}
//what is the absolute cash credit-debit of a person
vector<int> amount(n);
for(int i=0;i<n;i++){
for (int j=0;j<n;j++)
{
amount[i]+=(cash[j][i]-cash[i][j]);
}
}
minimize_cash_flow(amount);
return 0;
}


// Example input
// 3
// 0 2000 3000
// 0 0 5000
// 0 0 0
// Output is
// Person 0 pays 5000 to 2
// Person 1 pays 3000 to 2
// Time complexity->O(n^2)
// Space complexity->O(n^2)