#include<iostream>

using namespace std;

int main()
{
    unsigned char buf[sizeof(int)*2];
    
    //placement new
    int *pInt = new(buf)int(3);    
    int *qInt = new(buf+sizeof(int)) int(5);

    int *pBuf = (int*)(buf+0);
    int *qBuf = (int *)(buf+sizeof(int));
    
    cout<<"Buff add         Int Addr"<<endl;
    cout<<pBuf<<"        "<<pInt<<endl;
    cout<<qBuf<<"        "<<qInt<<endl;
    cout<<"--------------------------"<<endl;
    cout<<"first int"<<"          "<<"second int"<<endl;
    cout<<*pInt<<"                "<<*qInt<<endl;

    return 0;
}

