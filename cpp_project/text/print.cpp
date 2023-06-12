#include<iostream>
using namespace std;
int mul(int &a, int &b){
	return a*b;
}

int add(int &a,int &b){
	return a+b;
}
int sub(int &a,int&b){
	return a-b;
}




int main(){
	int a,b;
	cin>>a>>b;
	cout<<a<<"*"<<b<<"="<<mul(a,b)<<endl;
	cout<<a<<"+"<<b<<"="<<add(a,b)<<endl;
	cout<<a<<"-"<<b<<"="<<sub(a,b)<<endl;
	return 0;
}