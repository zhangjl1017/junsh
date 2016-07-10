/*
这个递推方程的意思是，在求以ai为末元素的最长递增子序列时，找到所有序号在L前面且小于ai的元素aj，即j<i且aj<ai。如果这样的元素存在，
那么对所有aj,都有一个以aj为末元素的最长递增子序列的长度f(j)，把其中最大的f(j)选出来，那么f(i)就等于最大的f(j)加上1，即以ai为
末元素的最长递增子序列，等于以使f(j)最大的那个aj为末元素的递增子序列最末再加上ai；如果这样的元素不存在，那么ai自身构成一个
长度为1的以ai为末元素的递增子序列。
//按照身高求最大上升子序列
    	int dp2[N+1];  //申请空间
		int max=0;
		dp2[0]=1;
		 for(int i=1;i<N;i++){
		 	dp2[i]=1;
		 	for(int j=0;j<i;j++){
		 		if(p[j].h<=p[i].h && dp2[j]+1>dp2[i])  //j位置的元素比i位置的元素小，且dp[j]+1>dp2[i],换
		 		dp2[i]=dp2[j]+1;
			 }
		 }
    	 for(int i=0;i<N;i++)
		 	if(max<dp2[i])
		 		max=dp2[i];
		 cout<<max<<endl;



*/



#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct player{
    int w;
	int h;
};

bool com_w(player p1,player p2){
	//按照体重从小到大排序
	if(p1.w!=p2.w)
	return p1.w<=p2.w;
	else return p1.h<=p2.h;
	//在体重相等的条件下，身高高的在前（在上） 
}

int main(){
	int N;
	int h;
	int w;
	int index;
	vector<player> p;
	while(cin>>N){
		p.clear();
		for(int i=0;i<N;i++){
			player pt;
			cin>>index>>w>>h;
			pt.w=w;
			pt.h=h;
			p.push_back(pt);
		}
		sort(p.begin(),p.end(),com_w);
		//按照身高求最大上升子序列
		int dp2[N+1];
		int max=0;
		dp2[0]=1;
		 for(int i=1;i<N;i++){
		 	dp2[i]=1;
		 	for(int j=0;j<i;j++){
		 		if(p[j].h<=p[i].h&&dp2[j]+1>dp2[i])
		 		dp2[i]=dp2[j]+1;
			 }
		 }
		 for(int i=0;i<N;i++)
		 	if(max<dp2[i])
		 		max=dp2[i];
		 cout<<max<<endl;
	}
	system("pause");
	return 0;
}