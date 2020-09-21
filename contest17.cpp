
#include <stdio.h> 
#include <iostream>
using namespace std;

int main(){

	int T;cin>>T;
	while(T--) {
          int a,b,c,d;cin>>a>>b>>c>>d;
    if(b>=a){
        cout<<b<<endl;
        return 0;
    }
	if(d>=c){
        cout<<"-1\n";
        return 0;
        }
	cout<<b+(a-b+c-d-1)/(c-d)*c<<endl;
    }
return 0;
}
