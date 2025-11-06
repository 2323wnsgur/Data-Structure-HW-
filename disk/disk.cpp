#include <iostream>
#include <list>
#include <string>



using namespace std;
class file{
public:
    string fa;
    int sa;
    file(string fa, int sa) : fa(fa) , sa(sa) {};
};

void write(string fa,int sa,list<file>& disk){
    int disk_sizeCanUse=0;
    int file_size=sa;

    for(auto it=disk.begin();it!=disk.end();it++){
        if(it->fa=="empty"){
            disk_sizeCanUse=disk_sizeCanUse+it->sa;
            if(it->sa>file_size){
                it->sa=it->sa-sa;
                disk.insert(it,file(fa,sa));
                return;
            }
        }
    }


    if(disk_sizeCanUse<sa) {
        cout<<"diskfull"<<endl;
        return;
    }

    for(auto it=disk.begin();it!=disk.end();it++){
        if(it->fa=="empty") {
            if(it->sa<file_size){
                it->fa = fa;
                file_size = file_size - it->sa;
            }
               else if(it->sa == file_size){
                   it->fa = fa;
                   break;
               }
               else if (it->sa>file_size){
                   it->sa=it->sa-file_size;
                   disk.insert(it,file(fa,file_size));
                   break;
               }
        }
    }

};

void deletefile(string fa, list<file>& disk){

    bool has_fa=false;
    for(auto it=disk.begin();it!=disk.end();it++){
        if(it->fa==fa){
            it->fa="empty";
            has_fa=true;
        }
    }

    if(has_fa==false){
        cout<<"error"<<endl;
        return;
    }

    for(auto it=disk.begin();it!=disk.end();it++){
        if(it==disk.begin()) continue;
        if(it->fa=="empty" and prev(it)->fa=="empty"){
            it->sa=it->sa+prev(it)->sa;
            disk.erase(prev(it));
        }
    }

}

void showfile(string fa, list<file>& disk){

    bool isthere=false;
    int n=0;
    for(auto it=disk.begin();it!=disk.end();it++){
        if(it->fa==fa) {
            cout << n << " ";
            isthere = true;
        }
        n=n+it->sa;
    }
    cout<<endl;
    if(isthere==false){
        cout<<"error"<<endl;
    }

}

void compact(int V,list<file>& disk){
    list<file> new_disk;
    new_disk.emplace_back("empty",V);

    for(auto it=disk.begin();it!=disk.end();it++){
        if(it->fa != "empty"){
            write(it->fa,it->sa,new_disk);
        }
    }

    for(auto it=new_disk.begin();it!=new_disk.end();it++){
        if(it==disk.begin()) continue;
        if(it->fa==prev(it)->fa ){
            it->sa=it->sa+prev(it)->sa;
            new_disk.erase(prev(it));
        }
    }
    disk=new_disk;

}


int main() {
    int V;
    cin>>V;

    list<file> disk;
    disk.push_back(file("empty",V));

    string order;
    string fa;
    int sa;

    while(true){
        cin>>order;
        if(order=="end") break;

        if(order=="write"){
            cin>>fa>>sa;
            write(fa,sa,disk);
        }
        else if(order=="delete"){
            cin>>fa;
            deletefile(fa,disk);
        }
        else if(order=="show"){
            cin>>fa;
            showfile(fa,disk);
        }
        else if(order=="compact"){
            compact(V,disk);
        }

    }



    return 0;
}
