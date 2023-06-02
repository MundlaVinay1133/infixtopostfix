#include <bits/stdc++.h> 
int precedence(char c){
	if(c=='^')
{
	return 3;
}
else if(c=='*' ||c=='/')
{
	return 2;
}
if(c=='-' ||c=='+')
{
	return 1;
}
else{
	return -1;
}
}
string infixToPostfix(string exp){
	// Write your code here
	stack<char>st;
	string resultexp;
	for(int i=0;i<exp.length();i++){
		if(exp[i]=='(')
		{
			st.push(exp[i]);
		}
		else if((exp[i]>='a' && exp[i]<='z' || exp[i]>='A' && exp[i]<='Z') ||(exp[i]>='0' && exp[i]<='9')){
			resultexp+=exp[i];
		}
		else if(exp[i]==')'){
			while(st.top()!='(' && !st.empty()){
				resultexp+=st.top();
				st.pop();
			}
			if(!st.empty()){
				st.pop();
			}
		}
		else{
			while(!st.empty() && st.top()!='(' && precedence(st.top())>=precedence(exp[i])){
				resultexp+=st.top();
				st.pop();
			}
			st.push(exp[i]);
		}
	}
	while(!st.empty()){
		int i;
		resultexp+=st.top();
		st.pop();
	}
	return resultexp;
}