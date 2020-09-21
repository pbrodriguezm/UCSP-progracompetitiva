#include<iostream>
#include<math.h>
#include<algorithm>

using namespace std;

int main()

{

    int x,y,n,max=0,c;



    
    cin>>n;
    for(int j=0; j<n; j++) {
    cin>>x>>y;

            if(x+y > max) {
                max = x+y;
            }
        

        
    }
    cout<<max<<endl;    

}