struct MaxQ{
	ll ini, fim, sum;
	deque<pair<ll, int>> q;
 
	MaxQ(){
		ini = 0, fim = 0, sum = 0;
		q = deque<pair<ll, int>> (0);
	}
 
	void pop() {
		if(q.size() && q.front().second == ini++)
			q.pop_front();
	}
 
	void push(int x) {
		while(q.size() && q.back().first < x - sum)
			q.pop_back();
		q.push_back(make_pair(x - sum, fim++));
	}
 
	void add(int val){ sum += val; }
	int getMax(){ return q.front().first + sum; }
	int size(){ return fim - ini; }
};
