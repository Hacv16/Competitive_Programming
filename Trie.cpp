const int ALP = 30; 		//tamanho da alfabeto (normalmente 26)
const int MAX = 2e6 + 15;   	//numero de prefixos

int trie[MAX][ALP], cnt;
bool end[MAX]; 			//marca se um prefixo eh fim de alguma palavra

void add(string& s){
	int cur = 0;

	for(int i = 0; i < s.size(); i++){
		int id = s[i] - 'a';

		if(trie[cur][id] == 0)
			trie[cur][id] = ++cnt;

		cur = trie[cur][id];
	}

	end[cur] = true;
}

bool search(string& s){ //retorna se ha alguma palavra com prefixo s
	int cur = 0;

	for(int i = 0; i < s.size(); i++){
		int id = s[i] - 'a';

		if(trie[cur][id] == 0)
			return false;

		cur = trie[cur][id]
	}

	return true;
}
