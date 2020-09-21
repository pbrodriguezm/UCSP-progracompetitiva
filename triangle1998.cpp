#include<iostream>
#include<math.h>
#include<algorithm>

using namespace std;

int main()

{

    int x,y,n,max=0,c;



    
    cin>>n;
    for(int j; j<n; j++) {


        for(int i=0; i<n; i++)
        {
          cin>>x>>y;

            if(x+y > 0) {
                max = x+y;
            }
        }

        cout<<max<<endl;    
 }

}