#include<bits/stdc++.h>
using namespace std;

// https://ide.geeksforgeeks.org/VbPQJnxSLt

// arrange positive and negative number alternately

int main(int argc, char const *argv[])
{
	int x;
	cin>>x;
	int a[x];
	for(int i = 0; i < x; ++i)
			cin>>a[i];	

	int n = 0, p = 0, p_found = 0, n_found = 0;
	for(int i = 0; i < x; ++i){
		if(a[i] < 0){
			n = i;
			n_found = 1;
			break;
		}
	}
	for(int i = 0; i < x; ++i){
		if(a[i] >= 0){
			p = i;
			p_found = 1;
			break;
		}
	}
	int tmp;
	while(n_found && p_found){
		if(p < n){
			p_found = 0;
			if(p % 2 != 0){
				tmp = a[p];
				a[p] = a[n];
				a[n] = tmp;
				n_found = 0;
				for(int i = n + 1; i < x; ++i){
					if(a[i] < 0){
						n = i;
						n_found = 1;
						break;
					}
				}
			} 
			for(int i = p + 1; i < x; ++i){
				if(a[i] >= 0){
					p = i;
					p_found = 1;
					break;
				}
			}
		} else {
			n_found = 0;
			if(n % 2 == 0){
				tmp = a[p];
				a[p] = a[n];
				a[n] = tmp;
				p_found = 0;
				for(int i = p + 1; i < x; ++i){
					if(a[i] >= 0){
						p = i;
						p_found = 1;
						break;
					}
				}
			}
			for(int i = n + 1; i < x; ++i){
				if(a[i] < 0){
					n = i;
					n_found = 1;
					break;
				}
			}
		}
	}
	for(int i = 0; i < x; ++i)
		cout<<a[i]<<" ";
	return 0;
}