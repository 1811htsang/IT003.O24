#include <bits/stdc++.h>
using namespace std;

int uT( char c ){ // tra ve muc do uu tien cua cac toan tu
	if( c == '(') return 0;
	if( c == '+' || c == '-' ) return 1;
	if( c == '*' || c == '/' || c == '%' ) return 2;
	if( c == '^' ) return 3;
}

void hauTo(string sample){ // chuyen bthuc trung to sang hau to.
	stack<char> s;
	string str1 = "";
	int i = 0;
	while( i < sample.length() ){ 
		char c = sample.at(i);
		if( c != ' ' ){ // neu c khac khoang trang
			if('0' <= c && c <= '9' || isalpha(c) ) str1 += c; // neu c la so hoac la chu cai
			else{
				cout<< str1 << " ";
				str1 = "";
				if( c == '(') s.push(c); // neu c la dau mo ngoac
				else{
					if( c == ')') { // neu c la dau dong ngoac
						while( s.top()!= '('){ // lay toan tu trong stack cho den khi gap dau mo ngoac
							cout<< s.top();
							s.pop();
						}
						if(s.top() == '(' ) s.pop(); // xoa dau mo ngoac trong stack
					}
					else{
						while( !s.empty() && uT(c) <= uT(s.top())){ // neu c co muc do uu tien <= toan tu tren cung cua stack
							cout<< s.top();
							s.pop();
						}
						s.push(c);
					}
				}
			}
		}
		i++;
	}
	if( str1 != "" ) cout<< str1 << " ";
	while(!s.empty()){ 
		if(s.top()!= '(') cout<< s.top();
		s.pop();
	}
}

int main(){
    //give a string with spaces between characters
    //ex: ( A + B ) * C - ( D - E ) * ( F + G )
    string str = "(2 + 3)^2 - (41)*(15/5)";
	hauTo(str);
	return 0;
}