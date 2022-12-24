#include<iostream>
using namespace std;
int main() 
{
    int n, i=0;
	cin>>n;
	for (; i*(i+1)*(i+2)/6 <= n; i++);
	cout<<i-1;
}