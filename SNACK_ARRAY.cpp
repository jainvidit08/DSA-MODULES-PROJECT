#include <bits/stdc++.h>
using namespace std;

//input is like:-
//only 1 line 
//first line input is n and m dimension of graphs

//function to get the snack order
vector<vector<int>> func(int row,int column)
{
    vector<vector<int>> ans(row,vector<int>(column,0));
    
    //flag for direction
    bool flag=true;
    int count=1;
    
    //outer loop for rows
    for(int i=0;i<row;i++)
    {
        //inner loop for colums
        for(int j=0;j<column;j++)
        {
            //true then left to right
            if(flag){
                ans[i][j]=count;
                count++;
            } 
            else{
                ans[i][column-j-1]=count;
                count++;
            }
        }
        flag=(!flag);
    }
    return ans;
}

int main() {
	//input symbols
	int row,column;
	cin>>row>>column;
	
	//calling function for snack array 
	vector<vector<int>> Snack_array=func(row,column);
    
    //printing array
    for( int i=0;i<row;i++){
        for( int j=0;j<column;j++){
            cout<<Snack_array[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
