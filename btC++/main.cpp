#include <iostream>
#include <math.h>
#include <random>
#include <ctime>
#include <cstdlib>
#include <vector>
using namespace std;

class Sinhvien{
public:
    string Hoten;
    float Diem;
    string Nganhnop;
    
};

void Sapxep(vector<Sinhvien>&a){
    int m;
    for(int i=0;i<a.size()-1;i++){
        for(int k=1;k<a.size()-i;k++){
            if(a[i].Diem<a[i+k].Diem){
                m=a[i].Diem;
                a[i].Diem=a[i+k].Diem;
                a[i+k].Diem=m;
        }
        
        }
    }
}
void Ketqua(vector<Sinhvien>&a){
    Sapxep(a);
    if(a.size()<300){
        cout<<"Diem chuan du kien: "<<a[a.size()-1].Diem;
    }else if(a.size()>=300){
        cout<<"Diem chuan du kien: "<<a[299].Diem<<endl;
    }
}
vector<Sinhvien> Nop(Sinhvien a,vector<Sinhvien>&sv){
    Sinhvien m;
    cout<<"Ho va ten sinh vien: "<<a.Hoten<<"\n";
    cout<<"Diem thi cua sinh vien: "<<a.Diem<<"\n";
    cout<<"Nganh nop: "<<a.Nganhnop<<"\n";
    if(a.Nganhnop=="maytinh"){
        m.Hoten=a.Hoten;
        m.Diem=a.Diem;
        m.Nganhnop=a.Nganhnop;
        cout<<"Da them vao danh sach sinh vien nop ho so vao nganh May tinh"<<endl;
        sv.push_back(m);
    }else cout<<"Khong them vao danh sach sinh vien nop ho so vao nganh May tinh"<<endl;
    
    return sv;
}
vector<Sinhvien> Rut(Sinhvien a,vector<Sinhvien>&sv){
    Sinhvien m;
    int i=0;
    cout<<"Ho va ten sinh vien rut: "<<a.Hoten<<"\n";
    for(Sinhvien ele:sv){
        
    if(a.Nganhnop==ele.Nganhnop && a.Diem==ele.Diem && a.Hoten==ele.Hoten){
        sv.erase(sv.begin()+i);
        break;
    }
        i++;
    }
    
    return sv;
}


int main(){
    int n;
    string a,b;
    vector<Sinhvien>k;
    bool kq=false;
    
    
    Sinhvien A;
    do{
        kq=false;
        cout<<"1.Nop ho so"<<"\n";
        cout<<"2.Rut ho so"<<"\n";
        cout<<"3.Diem chuan"<<"\n";
        cin>>n;
    switch (n) {
        case 1:
            cout<<"Nhap ho va ten sinh vien:"<<"\n";
            cin>>A.Hoten;
            cout<<"Diem thi cua sinh vien:"<<"\n";
            cin>>A.Diem;
            cout<<"Nganh sinh vien nop vao:"<<"\n";
            cin>>A.Nganhnop;
            Nop(A,k);
            break;
            
        case 2:
            cout<<"Nhap ho va ten sinh vien:"<<"\n";
            cin>>A.Hoten;
            cout<<"Diem thi cua sinh vien:"<<"\n";
            cin>>A.Diem;
            cout<<"Nganh sinh vien nop vao:"<<"\n";
            cin>>A.Nganhnop;
            Rut(A,k);
            break;
            
        case 3:
            
            Ketqua(k);
            kq=true;
            break;
    }}while(kq!=true);
    return 0;
    
    
}
