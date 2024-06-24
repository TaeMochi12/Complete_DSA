// remove 'a' from a given string

#include<bits/stdc++.h>
using namespace std ;

string updateString(int index,string str,string ans)
{
    if(index>=str.length()) return ans;
    if(str[index]!='a') ans+=str[index];
    return updateString(index+1,str,ans);
}

int main() {
    string str="bachah";
    string ans="";
    ans=updateString(0,str,ans);
    cout<<ans<<endl;
    return 0 ;
}

// 2nd way

// #include<bits/stdc++.h>
// using namespace std ;

// void updateString(int index,string str,string &ans)
// {
//     if(index>=str.length()) return;
//     if(str[index]!='a') ans+=str[index];
//     updateString(index+1,str,ans);
// }

// int main() {
//     string str="bachah";
//     string ans="";
//     updateString(0,str,ans);
//     cout<<ans<<endl;
//     return 0 ;
// }