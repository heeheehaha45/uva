
/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm> 
using namespace std;




struct Dot{
    int x;
    int y;
    
    bool operator==(const Dot& a)
    {
        return a.x==x&&a.y==y;/* your comparison code goes here */
    }
};

bool by_x(const Dot& a, Dot& b) { return a.x < b.x; }



int solve(vector<Dot> dots){
    
    sort(dots.begin(), dots.end(), by_x);

    vector<int> flattened;
    int m;
    double lineX;
    
    //find lineX
    
    for(int i=0;i<dots.size();i++)
        flattened.push_back(dots[i].x);
    
    m = unique(flattened.begin(), flattened.end() ) - flattened.begin() ;
    
    if( m%2==0 )
        lineX=((double)flattened[m/2]+(double)flattened[m/2-1])/2;
    else
        lineX=(double)flattened[m/2];
        
    
    //for every dot
    for(int i=0;i<dots.size();i++){
        int x=dots[i].x;
        int y=dots[i].y; 
        Dot symDot;
        symDot.y=y;
        
        if(x>lineX)
            symDot.x= lineX + (lineX-x) ;    
        else
            symDot.x= lineX - (x-lineX) ;    
         
        if ( find(dots.begin(), dots.end(), symDot) != dots.end() ) 
            ;   //found
        else 
            return -1;
         
    }
    
    return 1;
    
}


int main()
{
   
  //  freopen("data.in","r",stdin);
    
    int t;
    cin>>t;
    
    for(int i=0;i<t;i++){
        
        int n;
        cin>>n;
        vector <Dot> dots;
        
        for(int j=0;j<n;j++){
            Dot d;
            cin>>d.x;
            cin>>d.y;
            
            dots.push_back(d);
            
        }
        
       int result= solve(dots);
        if(result==1){
            cout<<"YES"<<endl;
        }else
            cout<<"NO"<<endl;
        
    }//endfor each case
   
  
    
    
    

    return 0;
}







