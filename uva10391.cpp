

/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;






int main()
{
   
   //read dictionary
   
   // freopen("data.in","r",stdin);
    
    string word;
    map<string,string> dict;
    
    while( cin>>word ){
        dict[word]=word;
        
        
    }
    
    
    vector<string> output;
    
    for(  map<string,string>::const_iterator it = dict.begin(); it != dict.end(); ++it ){
        string key = it->first;
        string value = it->second;
        //cout<<key<<endl;
        
        string word=key;
        int n=key.length();
        
        if(n>1)
            for(int i=1; i<=n-1; i++){
                string a=word.substr(0,i);
                string b=word.substr(i,n-i);
                
               // cout<<a<<" "<<b<<endl;
                
                if(dict.count(a)==1 && dict.count(b)==1){
                 
                    //found
                    
                 
                    output.push_back(word);
                    break;
                
                }
            }
        
        
    }
    for(int i=0;i<output.size();i++){
        cout<<output[i]<<endl;
    }
  

    return 0;
}







