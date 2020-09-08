#include<iostream>
#include<cmath>
#define ll long long
using namespace std;

void solve(){
	
	ll a,b,c,d;
	cin>>a>>b>>c>>d;
	if(b>=a){
		
		cout<<b<<'\n';
	}
	
	else if(d>=c){
		cout<<-1<<'\n';
	}
	
	else{
		
		ll ans=((a-b + c-d -1)/(c-d))*c;
		cout<<b+ans<<'\n';
	}
	
	return;
	
}

int main(){
	
	int t;
	cin>>t;
	
	while(t--){
		
		solve();
	}
	
	return 0;
}
