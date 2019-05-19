
/******************************************************************************

 

 Online C++ Compiler.

 Code, Compile, Run and Debug C++ program online.

 Write your code in this editor and press "Run" button to compile and execute it.

 

 *******************************************************************************/



#include <iostream>

#include <stdio.h>

#include<map>

#include<vector>

#include <sstream>

#include <string>

#include <algorithm>





using namespace std;



int main()

{

    

    //freopen("data.in","r",stdin);

    //freopen("data.out","w",stdout);

    

    

    

    string mta;

    map<string, vector<string> > mtaMap;

    //read mta

    while(cin>>mta && mta!="*"){

        string key;

        int n;

        cin>>key;

        cin>>n;

        

        // cout<<mta<<endl;;

        // cout<<key<<endl;;

        

        for(int i=0;i<n;i++){

            string username;

            cin>>username;

            mtaMap[key].push_back(username);

            // cout<<username<<endl;;

            

        }

        

        

    }

    

    // return 0;

    

    

    

    while(1){

            //read sender and recievers

            string sender;

            string str;

            map<string,string> recievers;

            vector<string> dataArr;

            

            cin>>sender;

            if(sender=="*")

                break;

        

            stringstream ss1(sender);

            string sendeUsername;

            string senderDomain;

            getline(ss1, sendeUsername, '@');

            getline(ss1, senderDomain, '@');

            

            

            map<string, vector<string> > outputMTAs;

            vector<string> MTAorders;

            

            while(cin>>str && str!="*"){

                if(recievers.find(str)== recievers.end()){

                    //if not found(not duplicaterd

                    

                    recievers[str]=str;

                    //recievers.pushed_back(str);

                    

                    stringstream ss(str);

                    string username;

                    string domain;

                    getline(ss, username, '@');

                    getline(ss, domain, '@');

                    

                    

                    if(outputMTAs[domain].size()==0)

                        MTAorders.push_back(domain) ;

                    

                    //cout<<username<<" "<<domain<<endl;

                    outputMTAs[domain].push_back(username);

                

                }else{

                    ;

                }

                

            }

            getline(cin,str);

            

            

            

            //read DATA

            while(getline(cin,str) && str[0]!='*'){

                

                

                dataArr.push_back(str);

                

                //cout<<"data read:"<<str<<endl;

            }

            // cout<<endl;

            

            

            

            //output

            // cout<<MTAorders.size()<<endl;

            //for every mta

            for(int i=0;i<MTAorders.size();i++){

                string domain=MTAorders[i];

                

                

                cout<<"Connection between "<<senderDomain<<" and "<<domain<<endl;

                

                cout<<"     "<<"HELO "<<senderDomain<<endl;

                

                cout<<"     "<<"250"<<endl;

                

                cout<<"     "<<"MAIL FROM:<"<<sendeUsername+"@"+senderDomain+">"<<endl;

                

                cout<<"     "<<"250"<<endl;

                

                // cout<<domain<<endl;

                //cout<<"domain:"<<domain<<endl;

                

                

                bool atLeastOneExist=false;

                //for every username :

                for(int j=0;j<outputMTAs[domain].size();j++){

                    string username=outputMTAs[domain][j];

                    // cout<<outputMTAs[domain][j]<<" ";

                    

                    cout<<"     "<<"RCPT TO:<"<<username+"@"+domain+">"<<endl;

                    

                    //check user exist

                    bool exist;

                    vector<string> v=mtaMap[domain];

                    

                    if (find(v.begin(), v.end(), username) != v.end()){

                        exist=true;

                        atLeastOneExist=true;

                    }

                    else

                        exist=false;

                    

                    

                    if(exist)

                        cout<<"     "<<"250"<<endl;

                    else

                        cout<<"     "<<"550"<<endl;

                    

                }//endfor

                

                

                

                if(atLeastOneExist){

                    cout<<"     "<<"DATA"<<endl;

                    cout<<"     "<<"354"<<endl;

                

                

                    //output DATA

                    for(int m=0;m< dataArr.size(); m++){

                        cout<<"     "<< dataArr[m]<<endl;

                    }

                    

                    cout<<"     "<<"."<<endl;

                    cout<<"     "<<"250"<<endl;

                }

                

                

                

                

                cout<<"     "<<"QUIT"<<endl;

                cout<<"     "<<"221"<<endl;

                

                

            }

    }//end while

    

    

    //finished one case

    

    

    

    

    

    //cout<<"Hello World";

    

    return 0;

}