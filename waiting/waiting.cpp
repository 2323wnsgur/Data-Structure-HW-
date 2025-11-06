#include <iostream>
#include <vector>

#include <algorithm>


int main() {
    int N,k;
    std::cin>>N>>k;

    std::vector<int> waiting_list;
    std::vector<int> idx_list={0};
    for(int i=0;i<N;i=i+1){
        char oper;
        int num;
        std::cin>>oper>>num;

        //////////////////////////
        if(oper=='+'){
            auto idx=std::lower_bound(waiting_list.begin(),waiting_list.end(),num);
            int dist=std::distance(waiting_list.begin(),idx);
            waiting_list.insert(idx,num);


            int sum=0;
            for(int j=0;j<idx_list.size();j=j+1){
                sum=sum+idx_list[j];
                if(sum>=dist){
                    idx_list[j]=idx_list[j]+1;
                    break;
                }
            }

            ///// split
            for(int j=0;j<idx_list.size();j=j+1){
                if(idx_list[j]==2*k){
                    idx_list[j]=k;
                    idx_list.insert(idx_list.begin()+j+1,k);
                }
            }

        }

        ////////////////////////
        else if(oper=='-'){
            auto idx=std::find(waiting_list.begin(),waiting_list.end(),num);
            if(idx!=waiting_list.end()){
                int dist=std::distance(waiting_list.begin(),idx);

                int sum=0;
                for(int j=0;j<idx_list.size();j=j+1){
                    sum=sum+idx_list[j];
                    if(sum>dist){
                        idx_list[j]=idx_list[j]-1;
                        if(idx_list[j]==0){
                            idx_list.erase(idx_list.begin()+j);
                        }
                        break;
                    }
                }
                waiting_list.erase(idx);





                if (waiting_list.empty() && idx_list.empty()) {
                    idx_list.push_back(0);
                }
                 

            }

        }
    }


    int x=0;
    for(auto it: idx_list){
        if(it==0){
            continue;
        }
        else {
            std::cout << waiting_list[x] << std::endl;
            x = x + it;
        }
    }


    return 0;
}
