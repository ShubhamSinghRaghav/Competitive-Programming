#include<bits/stdc++.h>
using namespace std;
#define ll  long long
map<ll int,ll int> mapper;
ll int minn;
ll int mncount;
long long int ds(long int n){
	long res= 0;
        while(n>0){
            long int d= n%10;
            res += d;
            n /= 10;
        }
        return res;
}
void findmin(ll int num,ll int count,ll int d){
	    ll int num1= num;
        ll int c= 0;
        if(num1 > 9){
            c++;
            num1= ds(num1);
        }
        if(mapper.find(num1)==mapper.end()){
		//if(!mapper.containsKey(num1)){
            mapper.insert({num1, count + c});
            if(minn > num1) {
                minn= num1;
                mncount= count + c;
            }
            else if(minn == num1){
                if(mncount > (count+c)){
                    mncount= count + c;
                }
            }
            
            findmin(num+d, count+1, d);
            findmin(num1, count+c, d);
            mapper.erase(mapper.find(num1));
        }
}
int main(){
	int t;cin>>t;
//	map<int,int> mapper;
	while(t--){
		ll int n,d; cin>>n>>d;
		minn=LONG_MAX;
		mncount=LONG_MAX;
		findmin(n,0,d);
		cout<<minn<<" "<<mncount<<"\n";
	}
	return 0;
}
