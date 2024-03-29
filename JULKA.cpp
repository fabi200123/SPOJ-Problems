#include <bits/stdc++.h>

using namespace std;

vector<int> add(vector<int> x, vector<int> y) {
    // Reverse the numbers so that we can add them from units place
    reverse(x.begin(), x.end());
    reverse(y.begin(), y.end());

    vector<int> ans;		// Our final answer
    int len = min(x.size(), y.size()), carry = 0;
    for(int i = 0; i < len; i++) {
	// Add the digits at the i_th pos from x and y and add the prev carry
        int val = x[i] + y[i] + carry;
        carry = val/10;
        ans.push_back(val%10); 		// Push the sum of digits to ans
    }

    if (x.size() > len) {		// If any digits remain in x, add them to ans
        for(int i = len; i < x.size(); i++) {
            int val = x[i] + carry;
            carry = val/10;
            ans.push_back(val%10);
        }
    }

    if (y.size() > len) {	// If any digits remain in y, add them to ans
        for(int i = len; i < y.size(); i++) {
            int val = y[i] + carry;
            carry = val/10;
            ans.push_back(val%10);
        }
    }

    // While there is still some carry left-over, add new digits to ans
    while (carry) {
        ans.push_back(carry%10);
        carry /= 10;
    }

    // Reverse ans to get back actual answer and return.
    reverse(ans.begin(), ans.end());
    return ans;
}

vector<int> sub(vector<int> x, vector<int> y) {
    // Assuming x >= y
    reverse(x.begin(), x.end());
    reverse(y.begin(), y.end());

    vector<int> ans;
    int len = y.size();
    for(int i = 0; i < len; i++) {
        if (x[i] < y[i]) {		// If we have 1 - 2 ==> 10 + 1 - 2
            x[i+1]--;			// Borrow from next 10's place
            ans.push_back(10+x[i]-y[i]);
        } else
            ans.push_back(x[i]-y[i]);	// Simply subtract and push the result
    }

    if (x.size() > len) {    // If there are any digits left in x, just add them to ans
        for(int i = len; i < x.size(); i++) {
	    // x[i] can be zero if we had borrowed 1 from x[i] to x[i-1]
	    if(x[i] < 0) {
    		x[i+1]--;
		ans.push_back(10+x[i]);
            } else {
	        ans.push_back(x[i]);
	    }
	}
    }

    reverse(ans.begin(), ans.end());

    vector<int> arr;
    int i = 0;
    while (ans[i] == 0) i++;		// Omit the leading zeros and return result
    for (; i < ans.size(); i++)
		arr.push_back(ans[i]);
    return arr;
}

vector<int> divBy2(vector<int> x) {
    vector<int> ans;
    int val = 0;             // val stores any previous remainders from division
    for(int i = 0; i < x.size(); i++) {
        if (val) {
            // If there are remainders, then add them in current division
            // eg : 38/2 ==> 3/2 = 1, rem = 1 ==> val = 1*10 + 8 = 18 ==> 18/2
            val = val*10 + x[i];
            ans.push_back(val/2);
            val = val % 2;
        }
        else {               // No remainders from prev division
            if (x[i] < 2) {  // If digit < 2, add 0 to result and put the digit as rem
                val += x[i];
                ans.push_back(0);
            } else {         // Just divide!
                val = x[i]%2;
                ans.push_back(x[i]/2);
            }
        }
    }

    vector<int> arr;
    int i = 0;
    while (ans[i] == 0) i++;        // Omit leading zeros and return ans
    for (; i < ans.size(); i++)
        arr.push_back(ans[i]);
    return arr;
}

int main(){
    for(int t = 0; t < 10; t++) {
        string S_s, D_s;
        cin >> S_s >> D_s;
        vector<int> S, D, sum, div, diff;
        for(int i = 0; i < S_s.length(); i++) S.push_back(S_s[i]-'0');
        for(int i = 0; i < D_s.length(); i++) D.push_back(D_s[i]-'0');

        sum = add(S, D);            // sum of S and D
        div = divBy2(sum);          // num1 = (S+D)/2
        for(int i = 0; i < div.size(); i++) cout << div[i];
        cout << '\n';

        diff = sub(S, div);         // num2 = S - num1
        for(int i = 0; i < diff.size(); i++) cout << diff[i];
        cout << '\n';
    }
    return 0;
}
