/*
动态规划思想
放第I个时考滤前I-1个时的最大价值。
问题分析：令V(i,j)表示在前i(1<=i<=n)个物品中能够装入容量为就j(1<=j<=C)的背包中的物品的最大价值，则可以得到如下的动态规划函数:
(1)   V(i,0)=V(0,j)=0 
(2)   V(i,j)=V(i-1,j)  j<wi  
      V(i,j)=max{V(i-1,j) ,V(i-1,j-wi)+vi) } j>wi

dp[n+1][c+1];
w[n+1];
v[n+1];
*/



#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>

#include<math.h>


using namespace std;



int main()
{
    int c,n;
    cin>>n>>c;               //n为物品数，c数最大容量
    int *w=new int[n+1];
    int *v=new int[n+1];
    int **dp=new int*[n+1];
    for(int i=0;i<=n;i++){
        dp[i]=new int[c+1];
    	memset(dp[i],0,(c+1)*sizeof(int));                    //必须初始化为0；
    	//cout<<sizeof(int)<<" ";
	}
	for(int i=1;i<n+1;i++){
		cin>>w[i]>>v[i];
	}
	for(int i=1;i<n+1;i++){
		for(int j=1;j<c+1;j++){
			if(j<w[i]){                                      //容量小的时候，不放
				dp[i][j]=dp[i-1][j];
			}else{
				dp[i][j]=max(dp[i-1][j],dp[i-1][j-w[i]]+v[i]);   //容量大的时候，放，比较放与不放的价值
			}
		}
	}
	cout<<dp[n][c]<<endl;
    return 0;
}