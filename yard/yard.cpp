#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
bool find_delete_Cont(std::vector<std::vector<int>>& Shipping_yard){
    int Cont=-1;
    int yard_len=1;
    int Have_to_resizeLine;
    std::vector<int> size_vec;

    for(auto& it:Shipping_yard){
        int len=it.size();
        size_vec.push_back(len);
    }


    for(int i=0;i<size_vec.size();i=i+1){
        if(size_vec[i]>yard_len){
            Cont=Shipping_yard[i].back();
            yard_len=size_vec[i];
            Have_to_resizeLine=i;
        }
        else if(size_vec[i]==yard_len){
            if(Shipping_yard[i].back()>Cont){
                Cont=Shipping_yard[i].back();
                yard_len=size_vec[i];
                Have_to_resizeLine=i;
            }
        }
    }

    Shipping_yard[Have_to_resizeLine].pop_back();
    --size_vec[Have_to_resizeLine];


    ////////////////////

    yard_len=99999;
    int Have_to_inputLine;
    for(int i=0;i<size_vec.size();i=i+1){
        if(size_vec[i]<yard_len){
            Have_to_inputLine=i;
            yard_len=size_vec[i];
        }
    }
    size_vec[Have_to_inputLine]++;
    Shipping_yard[Have_to_inputLine].push_back(Cont);

    auto it=std::minmax_element(size_vec.begin(),size_vec.end());
    if(abs(*it.second-*it.first)<=1){
        return false;
    }


    return true;

}

int main() {

    std::vector<std::vector<int>> Shipping_yard;
    int N;
    std::cin>>N;


    for(int i=0;i<N;i=i+1){
        int Si;
        std::cin>>Si;
        std::vector<int> one_yard;
        for(int j=0;j<Si;j=j+1){
            int ID;
            std::cin>>ID;
            one_yard.push_back(ID);
        }
        Shipping_yard.push_back(one_yard);
    }


    while(find_delete_Cont(Shipping_yard)) {}

    for(auto& vec:Shipping_yard){
        if(vec.empty()){
            std::cout<<0<<" ";
        }
        else {
            for (int p: vec) {
                std::cout << p << " ";
            }
        }
        std::cout<<'\n';
    }








    return 0;
}
