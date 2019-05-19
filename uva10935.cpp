
/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <sstream>
using namespace std;



void solve(int n){
    
    queue<int> q;
    string output="";
    for(int i=0;i<n;i++){
        q.push(i+1);
    }
    cout<<"Discarded cards:";
    while(q.size()!=1){
        int head = q.front(); q.pop();
        output=output+to_string(head)+", ";
        
        head=q.front();q.pop();
        q.push(head);
        
        
    }
    int remain=q.front();
    
    if( (int(output.length()) - 2) >=0 ){
       output=" "+output;
        if( output.substr(output.length()-2)==", ")
            output= output.substr(0, output.size()-2);    
    }    
        cout<<output<<endl<<"Remaining card: "<<remain<<endl;
    
    
    
}

int main()
{
 
    //freopen("data.in","r",stdin); 
   // freopen("data.out","w",stdout); 
   
    
    int n;
    
    while(cin>>n && n!=0){
        
        solve(n);   
    }
    
    
    
    
   

    return 0;
}

