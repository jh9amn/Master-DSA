// https://www.spoj.com/problems/CHI_BINARY/

#include <bits/stdc++.h>
using namespace std;

long long binary_to_int(string t){
	long long val = 0;
	for(auto ch : t){
		val = (val << 1) + (ch - '0');
	}
	return val;
}

string int_to_binary(long long n){
	if (n == 0) return "0";
    string res = "";
    while (n > 0) {
        res = char('0' + (n & 1)) + res;
        n >>= 1;
    }
    return res;
}

long long bitwise_add(long long a, long long b){
	while(b != 0){
		long long carry = a & b;
		a = a ^ b;
		b = carry << 1;
	}
	return a;
}

long long bitwise_sub(long long a, long long b){
	while(b != 0){
		long long borrow = (~a) & b;
		a = a ^ b;
		b = borrow << 1;
	}
	return a;
}


long long bitwise_mul(long long a, long long b){
	long long ans = 0;
	while(b > 0){
		if(b & 1) ans = bitwise_add(ans, a);
		a <<= 1;
		b >>= 1;
	}
	return ans;
}

pair<long long, long long> bitwise_div(long long a, long long b){
	if(b == 0) return {0, 0};
	
	long long quotient = 0, remainder = 0;
	
	for(int i=63; i>=0; i--){
		remainder <<= 1;
		remainder |= (a >> i) & 1;
		if(remainder >= b){
			remainder = bitwise_sub(remainder, b);
			quotient |= (1LL << i);
		}
	}
	
	return {quotient, remainder};
}

string bitwise_greater(long long a, long long b){
	return a > b ? "1" : "0";
}

string processOperation(string op, string A, string B) {
	long long a = binary_to_int(A);
	long long b = binary_to_int(B);
	
	 
	if(op == "0") {
		// return a > b ? "1" : "0";
		return bitwise_greater(a, b);
	}
	
	else if(op == "1") {
		// return int_to_binary(a+b);
		return int_to_binary(bitwise_add(a, b));
	}
	
	else if(op == "10"){
		if(a < b){
			long long n = 0;
			long long temp = 0;
			long long maxi = max(a,b);
			while(temp <= maxi){
				temp = (1LL << n++);
			}
			// return int_to_binary((temp+a )- b);
			a = bitwise_add(temp, a);
		}
		// return int_to_binary(a - b);
		return int_to_binary(bitwise_sub(a, b));
	}
	
	
	else if(op == "11") {
		// return int_to_binary(a * b);
		return int_to_binary(bitwise_mul(a, b));
	}
	
	
	else {
		// if(b == 0) return "0 0";
		// return int_to_binary(a / b) + " " + int_to_binary(a % b);
		
		auto [q, r] = bitwise_div(a, b);
		return int_to_binary(q) + " " + int_to_binary(r);
	}
	return "";
}



int main() {
	
	vector<string> data;
	string x;
	while (cin>>x){
		data.push_back(x);
	}
	
	long long test = binary_to_int(data[0]);
	long long idx = 1;
	
	while(test--) {
		if (idx + 2 >= data.size()) break;
		string op = data[idx];
		string a = data[idx+1];
		string b = data[idx+2];
		
		idx += 3;
		cout<<processOperation(op, a, b)<<"\n";
	}

	return 0;
}