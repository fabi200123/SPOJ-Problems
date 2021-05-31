#include <bits/stdc++.h>

using namespace std;

bool sPlus1(string &s, int i)
{
	for (; i >= 0 && '9' == s[i]; i--)
        s[i] = '0';
	if (i < 0){
		s[0] = '1';
		return true;
	}
	else s[i]++;

	return false;
}

string nextPalindrom(string &palin){
	int l_cen = 0, r_cen = 0;
	if (palin.size() % 2) {
		l_cen = r_cen = (palin.size()>>1);
	}
	else{
		r_cen = (palin.size()>>1);
		l_cen = r_cen-1;
	}

	int i = l_cen, j = r_cen;
	for ( ; i >= 0 && j < palin.size(); i--, j++)
		if (palin [i] != palin [j]) break; // this is not turned> is =!

	bool extra1 = false;
	if (i >= 0 && palin[j] < palin[i])
		palin[j]++;
	else   extra1 = sPlus1(palin, l_cen);

	if (extra1){
		j = r_cen == l_cen ? r_cen+1 : r_cen;
		for (; j < palin.size(); j++)
            palin[j] = '0';
		palin.push_back('1');
	}
	else{
		i = l_cen, j = r_cen;
		for (; j < palin.size(); i--, j++)
            palin[j] = palin[i];
	}
	return palin;
}



int main(){

    int t;
    cin >> t;
    string str;
    while(t--){
        cin >> str;
        cout << nextPalindrom(str) << '\n';
    }

    return 0;
}
