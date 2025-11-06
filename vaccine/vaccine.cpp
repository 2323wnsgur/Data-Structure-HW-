#include <iostream>
#include <vector>
int main() {
    std::vector<int> OLD_male;
    std::vector<int> OLD_female;
    std::vector<int> ADULT_male;
    std::vector<int> ADULT_female;
    std::vector<int> CHILD;

    int N;
    std::cin>>N;

    int ID;
    int age;
    char sex;
    for(int i=0;i<N;i=i+1){
        std::cin>>ID>>age>>sex;
        if(age>=61){
            if(sex=='M'){
                OLD_male.push_back(ID);
            }
            else{
                OLD_female.push_back(ID);
            }
        }
        else if(age>=16){
            if(sex=='M'){
                ADULT_male.push_back(ID);
            }
            else{
                ADULT_female.push_back(ID);
            }
        }
        else{
            CHILD.push_back(ID);
        }
    }


    std::vector<std::vector<int>> vaccine_list;
    vaccine_list.push_back(OLD_male);
    vaccine_list.push_back(OLD_female);
    vaccine_list.push_back(CHILD);
    vaccine_list.push_back(ADULT_female);
    vaccine_list.push_back(ADULT_male);

    for(auto& it: vaccine_list){
        for(int gl: it){
            std::cout<<gl<<std::endl;
        }
    }


    return 0;
}
