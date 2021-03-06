/*----------------------------------------------------*
 * लेखक --> अमित सिंह
 * संस्थान --> राष्ट्रीय प्रौद्योगिकी संस्थान, कुरुक्षेत्र
 *-----------------------------------------------------*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define w(t) \
  int t;     \
  cin >> t;  \
  while (t--)
#define fo(i, a, b) for (int i = a; i <= b; i++)
#define rfo(i, a, b) for (int i = b; i >= a; i--)
#define deb(x) cout << #x << " " << x << endl;
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
#define printv(v) \
  for (auto it = v.begin(); it != v.end(); it++) cout << *it << " ";
#define printg(v)                              \
  int row_sz = v.size(), col_sz = v[0].size(); \
  for (int i = 0; i < row_sz; i++) {           \
    for (int j = 0; j < col_sz; j++) {         \
      cout << v[i][j] << " ";                  \
    }                                          \
    cout << '\n';                              \
  }
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef map<int, int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;
int inv(int i) {
  if (i == 1) return 1;
  return (MOD - ((MOD / i) * inv(MOD % i)) % MOD) % MOD;
}
int MOD_mul(int a, int b) {
  a = a % MOD;
  b = b % MOD;
  return (((a * b) % MOD) + MOD) % MOD;
}
int MOD_add(int a, int b) {
  a = a % MOD;
  b = b % MOD;
  return (((a + b) % MOD) + MOD) % MOD;
}
int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
int ceil_div(int a, int b) { return a % b == 0 ? a / b : a / b + 1; }
int pwr(int a, int b) {
  a %= MOD;
  int res = 1;
  while (b > 0) {
    if (b & 1) res = res * a % MOD;
    a = a * a % MOD;
    b >>= 1;
  }
  return res;
}

void Tez() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

class SegTree{
	public:
	int n;
	vector<int>tree;
	vector<int>lazy;
	
	public:
	SegTree(vector<int>arr){
		n=arr.size()-1; // as arr[0] is useless 
		tree.resize(4*n,0);
		lazy.resize(4*n,0);
		build(arr,1,1,n);
	}
	int query(int ql,int qr){
		return query_helper(1,ql,qr,1,n);
	}
	int query(int ind){
		return query_helper(1,ind,1,n);
	}
	void pointUpdate(int ind,int val){
		pointUpdate_helper(1,1,n,ind,val);
	}
	void rangeUpdate(int ql,int qr,int val){
		rangeUpdate_helper(1,1,n,ql,qr,val);
	}
	
	private:
	void build(vector<int>&a,int node,int l,int r){
		if(l==r){
			tree[node]=a[l];
			return;
		}
		int mid=(l+r)/2;
		build(a,node*2,l,mid);  // left child
		build(a,node*2+1,mid+1,r); // right child
		recal(node); // depends on type of query
	}
	
	int query_helper(int node,int ql,int qr,int l,int r){
		if(lazy[node]!=0){
			tree[node]+=(r-l+1)*lazy[node];
			if(l!=r){
				lazy[node*2]+=lazy[node];
				lazy[node*2+1]+=lazy[node];
			}
			lazy[node]=0;
		}
		if(qr<l || ql>r) return 0; // if query is out of bounds
		if(l>=ql && r<=qr) return tree[node];// if query completely covers the range
		int mid=(l+r)/2;
		int leftVal=query_helper(node*2,ql,qr,l,mid);
		int rightVal=query_helper(node*2+1,ql,qr,mid+1,r);
		return leftVal+rightVal;
	}
	
	int query_helper(int node,int ind,int l,int r){
		if(lazy[node]!=0){
			tree[node]+=(r-l+1)*lazy[node];
			if(l!=r){
				lazy[node*2]+=lazy[node];
				lazy[node*2+1]+=lazy[node];
			}
			lazy[node]=0;
		}
		
		if(l==r){
			return tree[node];
		}
		int mid=(l+r)/2;
		if(ind<=mid){
			return query_helper(node*2,ind,l,mid);
		}else{
			return query_helper(node*2+1,ind,mid+1,r);
		}
	}
	
	void pointUpdate_helper(int node,int l,int r,int ind,int val){
		if(l==r){
			tree[node]=val;
			return;
		}
		int mid=(l+r)/2;
		if(ind<=mid){
			pointUpdate_helper(node*2,l,mid,ind,val);
		}else{
			pointUpdate_helper(node*2+1,mid+1,r,ind,val);
		}
		recal(node); // recalcuating values
	}
	
	void rangeUpdate_helper(int node,int l,int r,int ql,int qr,int val){
		if(lazy[node]!=0){
			tree[node]+=(r-l+1)*lazy[node];
			if(l!=r){
				// mark child as lazy
				lazy[node*2]+=lazy[node];
				lazy[node*2+1]+=lazy[node];
			}
			lazy[node]=0;
		}
		if(qr<l || ql>r) return; // if query is out of bounds
		if(ql<=l && r<=qr) {
			tree[node]+=(r-l+1)*val;
			if(l!=r){
				lazy[node*2]+=val;
				lazy[node*2+1]+=val;
			}
			return;
		}
		int mid=(l+r)/2;
		rangeUpdate_helper(node*2,l,mid,ql,qr,val);
		rangeUpdate_helper(node*2+1,mid+1,r,ql,qr,val);
		recal(node);
	}
	
	void recal(int node){
		tree[node]=tree[node*2]+tree[node*2+1];
	}
	
};

void solve() {
	int n,q;
	cin>>n>>q;
	vi v(n+1);
	fo(i,1,n) cin>>v[i];
	SegTree segtree=SegTree(v);
	fo(i,1,q){
		int tp,l,r,val;
		cin>>tp;
		if(tp==2){
			cin>>l>>r;
			int ans=segtree.query(l,r);
		    cout<<ans<<endl;
	    }else{
		    cin>>l>>r>>val;
		    segtree.rangeUpdate(l,r,val);
	    }
	}
	
}
int32_t main() {
  Tez();
  // w(t) { solve(); }
  solve();
  return 0;
}
