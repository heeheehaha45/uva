

/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <map>
#include <queue>
#include <vector>
#include <string>
#include <algorithm> 
using namespace std;

 // erase the first 3 elements:
  //myvector.erase (myvector.begin(),myvector.begin()+3);
  
 bool existHigherJob(queue <int> q,int curJobPriority){
     
     q.pop();
     
     while(!q.empty()){
         int elem=q.front();q.pop();
    
         if(elem/10 > curJobPriority/10)
            return true;
         
    }
     return false;
     
 } 
 
 void printQueue(queue <int> q){
     while(!q.empty()){
         
        int elem=q.front();q.pop();
        cout<<elem<<" ";
         
         
    }
    cout<<endl;
     
 }
  
int solve(queue <int> q,int myPos){
     int curJobPriority;
     string output="";
     int count=0;
     for(int i=0; ;i++){
        
        curJobPriority=q.front();
            
        if( existHigherJob(q,curJobPriority) ){
            q.pop();
            q.push(curJobPriority);
            
        }
        else{
           // "print" the job from the printer
           // cout<<"the head need to be poped out:"<<endl;
           // printQueue(q);
            //cout<<curJobPriority/10<<endl;
           
           
            q.pop();
            count++;
            
         
           
            
            if(curJobPriority%10==1){
                
                return count;
            }
        
            
        }
            
    
     }
    
}


int main()
{
   
   // freopen("data.in","r",stdin);
    
    int t;
    cin>>t;
    
    for(int i=0;i<t;i++){
      
        queue <int> q;
        int n;
        int myPos;
        
        cin>>n;
        cin>>myPos;
        for(int j=0;j<n;j++){
            int a;
            cin>>a;
            
            if(j==myPos)
                a=a*10+1;
            else
                a=a*10;
                
            q.push(a);
        }
        
        
        /*
        while(!q.empty()){
            cout<<q.front()<<" ";
            q.pop();
        }
        cout<<endl;
        */
        //cout<<"case i:"<<endl;
        if(i==t-1)
            cout<< solve(q,myPos)<<endl;
        else
           cout<< solve(q,myPos)<<endl;
        
        //cout<<endl;
        
        
       
        
        
    }//endfor
 
   
  
    
    
    

    return 0;
}







