#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const long long B = (rand() % 31) + 17;
const long long MOD1 = 1417504009, MOD2 = 1866965459;

struct Hashing{
	ll n; string s; 
	vector<ll> Hash1, P1, Hash2, P2;

	Hashing () : n(0) {}

	Hashing (string _s) : n(_s.size()), s(_s), Hash1(n), P1(n), Hash2(n), P2(n) {	
		P1[0] = P2[0] = 1;

		for(int i = 1; i < n; i++){
			P1[i] = (B * P1[i - 1]) % MOD1;
			P2[i] = (B * P2[i - 1]) % MOD2;
		}

		Hash1[0] = Hash2[0] = (s[0] - 'a' + 1);

		for(int i = 1; i < n; i++){
			Hash1[i] = (Hash1[i - 1] * B + (s[i] - 'a' + 1)) % MOD1;
			Hash2[i] = (Hash2[i - 1] * B + (s[i] - 'a' + 1)) % MOD2;
		}
	}

	ll subHash(int i, int j){
		if(i == 0) return (Hash1[j] << 30) | (Hash2[j]);
		ll ret1 = ((Hash1[j] - (Hash1[i - 1] * P1[j - i + 1])) % MOD1 + MOD1) % MOD1;
		ll ret2 = ((Hash2[j] - (Hash2[i - 1] * P2[j - i + 1])) % MOD2 + MOD2) % MOD2;
		return (ret1 << 30) | (ret2);
	}

	ll hash(void) { return subHash(0, n - 1); }
};
