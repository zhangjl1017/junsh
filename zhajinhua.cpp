#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<array>
using namespace std;

map<char,int> keep{{'J',11},{'Q',12},{'K',13},{'A',14}};

bool convert(const string &a,vector<int> &player){
    int i=0;
	while(i<a.size()){
		char c=a[i];
		if(keep.find(c)!=keep.end()){
			player.push_back(keep[c]);
		}else if(c=='1'&&a[i+1]=='0'){
			player.push_back(10);
			i++;
		}else if(c>='2'&&c<='9'){
			player.push_back(c-'0');
		}
		else{
			return false;
		}
		i++;
	}
	if(player.size()!=3){
		return false;
	}
	sort(player.begin(),player.end());
	return true;
}
int type(const vector<int> &play){
	//豹子：4
	if(play[0]==play[1]&&play[1]==play[2])
		return 4;
	//顺子：3
	if((play[0]+1==play[1] && play[1]+1==play[2])||(play == vector<int>{2,13,14})){
		return 3;
	}
	//对子：2
	if(play[0]==play[1]||play[1]==play[2])
		return 2;

	//普通：1
	return 1;
}


int main(){

	string a,b;
	while(cin>>a>>b){
		vector<int> play_1;
		vector<int> play_2;
		if(!convert(a,play_1)||!convert(b,play_2)){
			cout<<-2<<endl;
			continue;
		}
		//一副牌中不可能出现这种情况
		int type_a=type(play_1);
		int type_b=type(play_2);
		if( type_a==type_b && type_a==4 && play_1[0]==play_2[0]){
			cout<<-2<<endl;
			continue;
		}//不合法

		//所有平手情况
		if(play_1[0]==play_2[0]&&play_1[1]==play_2[1]&&play_1[2]==play_2[2]){
			cout<<0<<endl;
			continue;
		}

		//非平手
		if(type_a==type_b){
			if(type_a==4){
				if(play_1[0]<play_2[0]) cout<<-1<<endl;
				else cout<<1<<endl;
			}else if(type_a==3){
				//特殊情况 ：QKA,KA2
				if(play_1[2]==play_2[2]){
					if(play_1[0]<play_2[0]) cout<<1<<endl;
					else cout<<-1<<endl;
				}else if(play_1[2]<play_2[2])cout<<-1<<endl;
				else cout<<1<<endl;
			}else if(type_a==2){
				//比较play[1]即可   have problem;
				if(play_1[1]<play_2[1]) {
					cout<<-1<<endl;
				}else if(play_1[1]>play_2[1]) {
					cout<<1<<endl;
				}else{
					int a=play_1[1]==play_1[0]?play_1[2]:play_1[0];
					int b=play_2[1]==play_2[0]?play_2[2]:play_2[0];
					if(a>b) cout<<1<<endl;
					else cout<<-1<<endl;
				}
				
			}else{
				if(play_1[2]<play_2[2]||
					(play_1[2]==play_2[2]&&play_1[1]<play_2[1])||
					(play_1[2]==play_2[2]&&play_1[1]==play_2[1]&&play_1[0]<play_2[0]))
					cout<<-1<<endl;
				else
					cout<<1<<endl;
			}
		}else{
			if(type_a<type_b)
				cout<<-1<<endl;
			else
				cout<<1<<endl;
		}


	}



	cout<<" hello word!";
	getchar();
	return 0;
}