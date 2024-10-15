#include <iostream>
using namespace std;

pair<char, char> node[26];
int n;

void preorder(char c)
{
	if (c == '.')
		return;

	cout << c;
	preorder(node[c - 'A'].first);
	preorder(node[c - 'A'].second);
}

void inorder(char c)
{
	if (c == '.')
		return;

	inorder(node[c - 'A'].first);
	cout << c;
	inorder(node[c - 'A'].second);
}

void postorder(char c)
{
	if (c == '.')
		return;

	postorder(node[c - 'A'].first);
	postorder(node[c - 'A'].second);
	cout << c;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		char m, l, r;
		cin >> m >> l >> r;

		node[m - 'A'].first = l;
		node[m - 'A'].second = r;
	}


	preorder('A');
	cout << '\n';
	inorder('A');
	cout << '\n';
	postorder('A');

	return 0;
}