#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <deque>

int main() {

    std::map<std::set<int>,std::set<int>> GBIC;

    char R_Q;
    while(std::cin>>R_Q){
        if(R_Q=='$') break;

        std::string line;
        std::getline(std::cin>>std::ws,line);
        std::stringstream ss(line);


        std::set<int> gene_ID;
        int disease_ID;
        int num;
        while(ss>>num){
            if(num>0){
                gene_ID.insert(num);
            }
            else{
                disease_ID=num;
            }
        }


        if(R_Q=='R'){
            if(GBIC.count(gene_ID)){ // if have same key
                GBIC[gene_ID].insert(disease_ID);
            }
            else{
                GBIC[gene_ID]={disease_ID};
            }
        }
        else if(R_Q=='Q'){
            if(GBIC.count(gene_ID)){
                std::deque<int> reverse;
                for(auto it:GBIC[gene_ID]){
                    reverse.push_front(it);
                }
                for(auto it:reverse){
                    std::cout<<it<<" ";
                }
                std::cout<<std::endl;
            }
            else{
                std::cout<<"None"<<std::endl;
            }

        }
    }

    return 0;
}
