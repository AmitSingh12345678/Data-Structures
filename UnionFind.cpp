/*----------------------------------------------------*
* लेखक --> अमित सिंह
* संस्थान --> राष्ट्रीय प्रौद्योगिकी संस्थान, कुरुक्षेत्र
*-----------------------------------------------------*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define w(t) int t; cin>>t; while(t--)
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define rfo(i,a,b) for(int i=b;i>=a;i--)
#define deb(x) cout<<#x<<" "<<x<<endl;
#define mem(a, b) memset(a, (b), sizeof(a))
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.end(), cont.begin()
#define sz(a) int((a).size())
#define MP make_pair
#define PB push_back
#define F first
#define S second
#define endl '\n'
#define MOD (int)1000000007
#define INF (int)1e18
#define PI 3.1415926535897932384626433832795
#define printv(v) for(auto it = v.begin(); it != v.end();it++) cout<<*it<<" ";
#define printg(v) int row_sz = v.size(),col_sz = v[0].size(); for(int i=0;i<row_sz;i++){\
	for(int j=0;j<col_sz;j++){\
		cout<<v[i][j]<<" ";\
	}\
	cout<<'\n';\
} 
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef map<int, int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;
typedef priority_queue<int>pq;
int inv(int i) {if (i == 1) return 1; return (MOD - ((MOD / i) * inv(MOD % i)) % MOD) % MOD;}
int MOD_mul(int a, int b) {a = a % MOD; b = b % MOD; return (((a * b) % MOD) + MOD) % MOD;}
int MOD_add(int a, int b) {a = a % MOD; b = b % MOD; return (((a + b) % MOD) + MOD) % MOD;}
int gcd(int a, int b) { if (b == 0) return a; return gcd(b, a % b);}
int ceil_div(int a, int b) {return a % b == 0 ? a / b : a / b + 1;}
int pwr(int a, int b) {a %= MOD; int res = 1; while (b > 0) {if (b & 1) res = res * a % MOD; a = a * a % MOD; b >>= 1;} return res;}


void Tez() {
   ios::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
}
class UnionFind{
	public:
	vector<int>parent;
	vector<int>size;
	int n;
	
	UnionFind(int n){
		this->n=n;
		parent.resize(n+1);
		size.resize(n+1);
		for(int i=1;i<=n;i++){
			parent[i]=i;
			size[i]=1;
		}
	}
	
	int findParent(int i){
	   	// we are using this so that we don't have to update parent [] unneccessarily
	   	  if(parent[i]==i) return i;
	   	  return parent[i]=findParent(parent[i]);
	   }
	void merge(int a,int b){
		 a=findParent(a);
		 b=findParent(b);
		  
		 if(a==b) return;
		 if(size[a]<size[b]) swap(a,b);
		 
		 size[a]+=size[b];
		 parent[b]=a;
	  }
	bool same(int a,int b){
		return findParent(a)==findParent(b);
	}
	
};

void solve(){
	 
}
int32_t main() {
   Tez();
   // w(t){
   	 solve();
   // }
   return 0;
}