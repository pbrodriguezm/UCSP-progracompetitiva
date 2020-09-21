#include<iostream>
#include<math.h>
#include<algorithm>

using namespace std;

int main()

{

    int k,n,t;

    cin>>t;
    for(int j=0; j<t; j++) {
    cin>>n>>k;
        if(n<k)
        {
        cout<<k-n<<endl;  
        }
        else if ((n-k)%2 >= 0) {
            cout <<(n-k)%2<< endl;
        }
        
        

        
    }
}