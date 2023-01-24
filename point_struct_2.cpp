struct pt{
	int x, y; 
	pt(int a = 0, int b = 0){ x = a; y = b; }

	pt operator + (pt other) { return pt(x + other.x, y + other.y); } //soma
	pt operator - (pt other) { return pt(x - other.x, y - other.y); } //subtracao

	int operator * (pt other) { return x * other.x + y * other.y;   } //dot (cos)
	int operator % (pt other) { return x * other.y - other.x * y;   } //cross (sen)

	bool operator == (pt other) { return (x == other.x) && (y == other.y ); }
	bool operator < (pt other)  { return (x == other.x ? y < other.y : x < other.x); }

	int dist(pt other) { return (x - other.x) * (x - other.x) + (y - other.y) * (y - other.y); } //dist ^ 2
};