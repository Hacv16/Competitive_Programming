const ll B = 79;
const ll MOD[] = {1417504009, 1866965459};

struct Hashing{
	vector<ll> Hash;

	Hashing(string& s) {
		ll Hash1 = 0, Hash2 = 0, n = s.size(), pow0 = B, pow1 = B;

		Hash.resize(n);

		for(int i = 0; i < n; i++){
			Hash1 = (Hash1 + (s[i] - 'a' + 1) * pow0) % MOD[0];
			Hash2 = (Hash2 + (s[i] - 'a' + 1) * pow1) % MOD[1];

			pow0 = (pow0 * pow0) % MOD[0];
			pow1 = (pow1 * pow1) % MOD[1];

			Hash[i] = ((Hash1 << 30) | Hash2); 
		}
	}

	bool operator == (Hashing other){
		return (Hash.back() == other.Hash.back());
	}
};
