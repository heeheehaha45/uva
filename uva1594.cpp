

/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <sstream>
using namespace std;


int diff(int a,int b){
    if(a>b)
        return a-b;
    else 
        return b-a;
    
}

//return new seqence 
vector<int> generateNextSeq(vector<int>seq){
    vector<int> result;
    int n=seq.size();
    
    for(int i=0;i<=n-1;i++){
        if(i!=n-1)
            result.push_back( diff(seq[i],seq[i+1])  );
        else
            result.push_back( diff(seq[i],seq[0])  );
    }
    
    
    return result;
    
}


string seqToString( vector<int> seq){
      
      int n=seq.size();
      string result="";
      
      for(int i=0; i<n; i++){
          if(i==n-1)
            result=result+to_string(seq[i]);
          else
            result=result+to_string(seq[i])+",";
      }
      
      return result;
      
}

bool allZero(vector<int> seq){
      int n=seq.size();
     for(int i=0; i<n; i++){
         if(seq[i]!=0)
            return false;
     }
    
    return true;
}

void solve(vector<int> originSeq){
    map<string,bool> seqCollection;
   


    vector<int> nextSeq;
    
    for(nextSeq=originSeq; ;nextSeq=generateNextSeq(nextSeq)){


        string nextSeqStr=seqToString(nextSeq);
        //cout<<"seq:"<<nextSeqStr<<endl;
        
        if(seqCollection.count(nextSeqStr)!=0){
        //if key is  found
            cout<<"LOOP"<<endl;
            return ;
        }
        else if(allZero(nextSeq)){
            cout<<"ZERO"<<endl;
            return;
        }
        
        seqCollection[nextSeqStr]=true;
        
        
    }
    
    
}

int main()
{
 
//    freopen("data.in","r",stdin); 
   // freopen("data.out","w",stdout); 
    
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n;
        cin>>n;
        vector<int> arr;
        for(int j=0;j<n;j++){
            int a;
            cin>>a;
            arr.push_back(a);
        
        }
        solve(arr);
    }
    
    
    
    
    
    
   

    return 0;
}

