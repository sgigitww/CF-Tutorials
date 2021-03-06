#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

typedef long long ll;
typedef long double ld;

typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define ff first
#define ss second
#define rsz resize
#define ins insert 
#define mp make_pair
#define pf push_front 
#define pb push_back
#define eb emplace_back 
#define lb lower_bound 
#define ub upper_bound
#define ft front() 
#define bk back()
#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define deb(x) cout<<#x<<" "<<x<<'\n';

#define pqmax priority_queue<int>
#define pqmin priority_queue<int,vector<int>,greater<int>>

#define transup(x) transform(x.begin(),x.end(),x.begin(),::toupper)
#define translow(x) transform(x.begin(),x.end(),x.begin(),::tolower)

#define rep(i,a,b) for (int i = (a); i < (b); ++i)
#define per(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define trav(a,x) for (auto a: x)

#define setbits(x) __builtin_popcountll(x)
#define zerobits(x) __builtin_ctzll(x)

const int RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();
struct chash {
    int operator()(int x) const { return x ^ RANDOM; }
};

template<class T> ostream& operator<<(ostream &os, vector<T> V) {
    os << "[ "; for(auto v : V) os << v << " "; return os << "]";
}

template<class T> istream& operator>>(istream &is, vector<T>& V) {
    for(auto &e : V)is >> e;return is;
}

template<class T> ostream& operator<<(ostream &os, set<T> S){
    os << "{ ";for(auto s:S) os<<s<<" ";return os<<"}";
}

template<class T> ostream& operator<<(ostream &os, unordered_set<T> S){
    os << "{ ";for(auto s:S) os<<s<<" ";return os<<"}";
}

template<class T> ostream& operator << (ostream& os, multiset<T> S){
    os << "{ ";for(auto s:S) os<<s<<" ";return os<<"}";
}

template<class L, class R> ostream& operator<<(ostream &os, pair<L,R> P) {
    return os << "(" << P.first << "," << P.second << ")";
}

template<class L, class R> ostream& operator<<(ostream &os, map<L,R> M) {
    os << "{ ";for(auto m:M) os<<"("<<m.first<<"->"<<m.second<<") ";return os<<"}";
}

template<class L, class R, class chash = std::hash<R>> ostream& operator<<(ostream &os, unordered_map<L,R,chash> M) {
    os << "{ ";for(auto m:M) os<<"("<<m.first<<":"<<m.second<<") ";return os<<"}";
}
template<class L, class R, class chash = std::hash<R> > ostream& operator<<(ostream &os, gp_hash_table<L,R,chash> M) {
    os << "{ ";for(auto m:M) os<<"("<<m.first<<":"<<m.second<<") ";return os<<"}";
}

template<typename... T>
void read(T&... args){
	((cin>>args),...);
}

template<typename... T>
void write(T&&... args){
	((cout<<args<<" "),...);
	cout<<'\n';
}

const ll mod = 1e9+7;
const ll inf = 1e18; 
const ld pie = acos((ld)-1);

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

template<typename T>
int dig(T x){

	T sum=0;
	T cnt=0;
	while(x>0){
		T r=x%10;
		sum+=r;
		x/=10;
		cnt++;
	}
	return sum;
}

void solve(){
	
	ll n,s,temp;
	scanf("%lld%lld",&n,&s);
	temp=n;
	if(dig(n)<=s){
		printf("0\n");
		return;
	}

	ll cur=1;
	for(int i=0;i<=18;++i){

		ll ld = (n/cur)%10;
		ll cnt = (10-ld)*cur;
		n+=cnt;
		if(dig(n)<=s){
			break;
		}
		cur*=10;
	}
	
	printf("%lld\n",n-temp);
	return;
}

int main(){
    
	int t=1;
	cin>>t;
	while(t--){
		solve();
	}

	return 0;

	/*STUFF TO LOOK:	
		1. Check the constraints
		2. Corner cases(n==0||n==1)
		3. Variables in loops
		4. Make sure two ints aren’t multiplied to get a long long
		5. Don't use scanf or printf while using ios_base
		6. using the local variable of the same name when global variable was required to be used
	*/
}
