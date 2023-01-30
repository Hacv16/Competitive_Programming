vector<int> pi(string& s){
    vector<int> p(sz(s));
 
    for(int i = 1, j = 0; i < sz(s); i++) {
        while(j > 0 && s[j] != s[i]){
            j = p[j - 1];
        }
 
        if(s[j] == s[i]) j++;
        p[i] = j;
    }
 
    return p;
}
 
vector<int> kmp(string& t, string& s){
    vector<int> p = pi(t), mtc;
 
    for(int i = 0, j = 0; i < sz(t); i++){
        while (j > 0 && s[j] != t[i]){
            j = p[j - 1];
        }
        
        if(s[j] == t[i]) j++;
        
        if(j == s.size()){
            mtc.pb(i - j + 2), j = p[j - 1];
        }
    }
 
    return mtc;
}
 
