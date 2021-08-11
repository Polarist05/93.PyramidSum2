#include<stdio.h>
#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;
int a,mx=INT_MIN;
vector<vector<int>> v;
int sum;
vector<int> ans;
void depth(int _a, int _b) {
	static vector<int> check;
	sum += v[_a][_b];
	check.push_back(v[_a][_b]);
	if (_a < a - 1){
		depth(_a + 1, _b);
		depth(_a + 1, _b+1);
	}
	else {
		if (mx <  sum) {
			mx = sum;
			ans = check;	
		}
	}
	sum -= v[_a][_b];
	check.pop_back();
}
int main() {
	cin >> a;
	for (int i = 0; i < a; i++) {
		v.push_back(vector<int>());
		for (int j = 0; j <= i; j++) {
			int b;
			cin >> b;
			v[i].push_back(b);
		}
	}
	depth(0,0);
	printf("%d", ans[0]);
	for (int i = 1;i<ans.size();i++) {
		printf(" + %d", ans[i]);
	}
	printf(" = %d",mx);
}