

/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

string opposite(string key){
    string str=key;
  
   //string str("abc:def");
   char split_char = ' ';

   // work
   std::istringstream split(str);
   std::vector<std::string> tokens;
   for (std::string each; std::getline(split, each, split_char); tokens.push_back(each));

    string a=tokens[0];
    string b=tokens[1];
    
    return b+" "+a;
    
    
    
}

int main()
{
    
    //freopen("data.in","r",stdin); 

    int n;
    
    //for each case    
    while(cin>>n && n!=0){
       
        map<string,int> Map;
        int result=0;
        
        
       //read values to map
        for(int i=0;i<n;i++){
            int a;
            int b;
            cin>>a;
            cin>>b;
            //cout<<a<<" "<<b<<endl;
            
            string key=to_string(a)+" "+to_string(b);
            if(Map.count(key)==0)   //if it is new key
                Map[key]=0;
            else
                Map[key]++;
                
         
            
                
        }
       
        
        //for every key in Map
        for (map<string,int>::iterator it=Map.begin(); it!=Map.end(); ++it){
            // std::cout << it->first << " => " << it->second << '\n';
            string key = it->first ;
            int value = it->second;
            
            if(Map.count(opposite(key))==0){
                result=-1;
                break;   
            }
            
            if(Map[key]==Map[opposite(key)])
                ;
            else{
                result=-1;
                break;   
                
            }
            
        }//end for
        
        
        if(result==-1)
            cout<<"NO"<<endl;
        else
            cout<<"YES"<<endl;
    }
    
    
    
   
    return 0;
}

