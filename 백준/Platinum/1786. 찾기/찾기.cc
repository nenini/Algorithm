#include<iostream>
#include<string>
#include<vector>
#define SIZE 1000000
using namespace std;

string text;
string pattern;
vector<int> pos;

int pi[SIZE];

void get_pi() {
	int j = 0;
	for (int i = 1; i < pattern.size(); i++) {
		while (j > 0 && pattern[i] != pattern[j]) {
			j = pi[j - 1];
		}
		if (pattern[i] == pattern[j]) {
			j++;
			pi[i] = j;
		}
	}
}

int kmp() {
	int j = 0;
	int count = 0;
	for (int i = 0; i < text.size(); i++) {
		while (j > 0 && text[i] != pattern[j]) {
			j = pi[j - 1];
		}
		if (text[i] == pattern[j]) {
			if (j == pattern.size() - 1) {
				count++;
				pos.push_back(i - pattern.size() + 2);
				j = pi[j];
			}
			else {
				j++;
			}
		}
	}
	return count;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	getline(cin, text);
	getline(cin, pattern);

	get_pi();

	cout<< kmp()<<"\n";
	for (int i = 0; i < pos.size(); i++) {
		cout << pos[i]<<" ";
	}
}