#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define ff 				first
#define ss 				second
#define sz(x) 				(int)(x).size()
#define all(x) 				begin(x), end(x)
#define rall(x) 			(x).rbegin(), (x).rend() 
#define rsz 				resize
#define ins 				insert 
#define ft 				front() 
#define bk 				back()
#define pf 				push_front 
#define pb 				push_back
#define eb 				emplace_back 
#define lb 				lower_bound 
#define ub 					upper_bound 
#define pqmax				priority_queue<int>
#define pqmin				priority_queue<int,vector<int>,greater<int>>
#define transup(x)			transform(x.begin(),x.end(),x.begin(),::toupper)
#define translow(x)			transform(x.begin(),x.end(),x.begin(),::tolower)
#define rep(i,a,b) 			for (int i = (a); i < (b); ++i)
#define per(i,a,b) 			for (int i = (b)-1; i >= (a); --i)
#define trav(a,x) 			for (auto a: x)

#define setbits(x)  			__builtin_popcountll(x)
#define zerobits(x)			__builtin_ctzll(x)

const ll mod = 1e9+7; // 998244353;
const ll inf = 1e18; 
const ld pie = acos((ld)-1);

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

unordered_map<int,vector<int>> mp;

void addedge(int x,int y){
    mp[x].pb(y);
    mp[y].pb(x);
}

vector<int> p(100001);//people living in the city
vector<int> h(100001);//happiness index of a city
vector<int> a(100001);//people visited a node
vector<int> good(100001);

bool dfs(int u,int par){

    a[u]=p[u];
    ll sum=0;
    for(auto x:mp[u]){

        if(x==par) continue;
        if(!dfs(x,u)) return false;
        sum+=good[x];
        a[u]+=a[x];
    }
    good[u]=(a[u]+h[u])/2;
    if((a[u]+h[u])%2!=0 || sum>good[u] || good[u]>a[u]) return false;

    return true;
}

void solve(){

	int n,m;
    cin>>n>>m;
    rep(i,0,n) cin>>p[i];
    rep(i,0,n) cin>>h[i];

    rep(i,0,n-1){
        int x,y;
        cin>>x>>y;
        x--;
        y--;
        addedge(x,y);
    }

    if(dfs(0,-1)){
        cout<<"YES\n";
    }else{
        cout<<"NO\n";
    }

    h.clear();
    p.clear();
    a.clear();
    good.clear();
    for(int i=0;i<n;++i){
        mp[i].clear();
    }
    mp.clear();
    return;
}


int main(){

	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
    	auto start = std::chrono::high_resolution_clock::now();
   	 /*start from here*/
    	
	    int t;
	    cin>>t;
	    while(t--){
		solve();
	    }

	auto stop = std::chrono::high_resolution_clock::now(); 
 	auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start); 
    
    // cerr << "Time taken : " << ((long double)duration.count())/((long double) 1e9) <<"s "<< endl;     

    return 0;

    /*STUFF TO LOOK:	
	1. Special cases/corner cases(n==0||n==1)
	2. Variables in loops
	3. Input ranges
	*/
}
