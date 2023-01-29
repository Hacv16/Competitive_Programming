struct MinQ{
	int l, r;
	deque<pair<int, int>> q;

	MinQ(){ l = 1; r = 0; }

	void push(int x){
		while(q.size() && q.back().first >= x)
			q.pop_back();
		q.push_back({x, ++r});
	}

	void pop(){
		if(q.size() && q.front().second == l++)
			q.pop_front();
	}

	int getMin(){
		return q.front().first;
	}
};
