#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int T;

int main(){
    cin>>T;
    string s;
    for(int i=1;i<=T;i++){

        cin>>s;
        int l,r;  //我们要把ABC这个分界点找到，l为左端点，r为右端点
        for(r=s.size()-1;r>=0&&(s[r]=='l'||s[r]=='q'||s[r]=='b');r--);

        if (r<=0)   cout<<"Yes"<<endl;   //字符串仅有l,q,b字符，Yes

        else{

            for(l=0;l<r&&(s[l]=='l'||s[l]=='q'||s[l]=='b');l++);
            string tmp = s.substr(l,r-l+1);         //把B部分拿出来
            reverse (tmp.begin(),tmp.end());        //通过翻转后是否一样来判断回文
            if (tmp!=s.substr(l,r-l+1))   cout<<"No"<<endl;

            else {
                for(;l>=0&&r<=s.size()&&s[l]==s[r];l--,r++); //看一下A的序列是否和C前缀一样
                if (l==-1)  cout<<"Yes"<<endl;
                else cout<<"No"<<endl;
            }
        }
    }
    return 0;
}