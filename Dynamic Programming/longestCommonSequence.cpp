#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
void longestCommonSeq(string s1, string s2){
    string s3="";
    //s1 is my row
    //s2 is my column
    int a[s1.length()+1][s2.length()+1];
    for(int i=0;i<s1.length()+1;i++){
        a[i][0]=0;
    }
    for(int j=0;j<s2.length()+1;j++){
        a[0][j]=0;
    }
    for(int i=1;i<s1.length()+1;i++){   //row
        for(int j=1;j<s2.length()+1;j++){   //column
            if(s1[i-1]==s2[j-1]){
                a[i][j]=a[i-1][j-1]+1;
            }
            else{
                a[i][j] = max(a[i-1][j],a[i][j-1]);
            }
        }
    }    
    //need backtracking for the longest seq string
    for(int i=s1.length();i>=0;){   //row
        for(int j=s2.length();j>=0;){   //column
            if(a[i][j]!=max(a[i-1][j],a[i][j-1])){
                if(i-1>=0){
                    s3+=s1[i-1];
                    // cout<<"Caught-"<<s1[i-1]<<endl;
                }
                else if(j-1>=0){
                    s3+=s2[j-1];
                // cout<<"Caught-"<<s2[j-1]<<endl;
                }
                i-=1;
                j-=1;
            }
            else if(a[i][j]==max(a[i-1][j],a[i][j-1])){
                if(i>0 && a[i-1][j]>a[i][j-1]){
                    i-=1;
                    }
                else if(j>0 && a[i-1][j]<a[i][j-1]){
                    j-=1;
                    }
                else if(a[i-1][j]==a[i][j-1]){   //
                        if(i>0){
                            i-=1;
                        }
                        else if(j>0){
                            j-=1;
                        }
                    }
                }
            }
        }

    // for(int i=0;i<s1.length()+1;i++){
    //     for(int j=0;j<s2.length()+1;j++){
    //         cout<<a[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }    
    reverse(s3.begin(), s3.end()); 
    cout<<s3<<endl;
    cout<<"Length-"<<s3.size()<<endl;
}
int main(){
    string s1,s2;
    cin>>s1;
    cin>>s2;
    longestCommonSeq(s1,s2);
    return 0;
}