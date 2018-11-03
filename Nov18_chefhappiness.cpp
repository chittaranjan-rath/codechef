#include<stdio.h>
#include<set>
#include<map>
#include<string.h>
#include<vector>
#include<iostream>
using namespace std;
vector<int> table(100005);
vector<set<int>> input(100005);
int arr[100005];	
int main(){
	int t;
	scanf("%d",&t);
	int n;
	while(t--){
		scanf("%d",&n);
		
		set<int> emptyset;
		fill(table.begin(),table.end(),-1);
		fill(input.begin(),input.end(),emptyset);
		for(int i=1;i<=n;i++){
			scanf("%d",&arr[i]);
			table[arr[i]]=1;
			input[arr[i]].insert(i);
		}
		/*for(int i=1;i<=10005;i++)
			if(table[i]!=-1)
				cout<<"index "<<i<<" "<<table[i]<<" ";
		cout<<endl<<endl<<"input size "<<input.size()<<endl;*/
		int flag=0;
		int sss= input.size();
		for(int i=1;i<=input.size();i++){
			set<int> temp = input[i];
			int cnt=0;
			//cout<<"for i = "<<i<<" set at i size "<<temp.size()<<" elems"<<endl;
			if(temp.size()>=2){
				for(auto si : temp){
					//cout<<si<<" ";
					
					if(si<=sss && table[si]==1)
						cnt++;
					if(cnt==2){
						flag = 1;
						break;
					}
						
				}
			if(flag)
				break;
			}
		}
		if(flag)
			printf("Truly Happy\n");
		else
			printf("Poor Chef\n");
	}
	return 0;
}
