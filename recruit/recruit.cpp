#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

struct student{
public:
    int ID;
    int COTE;
    student(int ID, int COTE): ID(ID), COTE(COTE){};
    bool operator<(const student& other) const{
        if(COTE != other.COTE){
            return COTE>other.COTE;
        }
        return ID>other.ID;
    }
};

struct GRAD_data{
    std::string GRAD;
    std::vector<student> Students;
    int total_COTE=0;
};


int main() {

    std::map<std::string,GRAD_data> student_db;
    int N,k;
    std::cin>>N>>k;

    int ID;
    std::string GRAD_code;
    int COTE;
    for(int i=0;i<N;i=i+1){
        std::cin>>GRAD_code>>ID>>COTE;
        if(GRAD_code=="POP"){
            //1. sorting
            std::vector<GRAD_data> canu_list;
            for(auto& pair: student_db){
                if(pair.second.Students.size()>=k){
                    canu_list.push_back(pair.second);
                }
            }

            std::sort(canu_list.begin(),canu_list.end(), [](GRAD_data a, GRAD_data b){
                if(a.Students.size() != b.Students.size()){
                    return a.Students.size() > b.Students.size();
                }
                return a.total_COTE>b.total_COTE;
            });

            // 2. printing
            std::vector<std::pair<std::string,student>> final_rank_list;
            int rank_in_grad=0;
            while (true){
                bool added=false;
                for(auto& it:canu_list){
                    if(rank_in_grad < it.Students.size()){
                        final_rank_list.emplace_back(it.GRAD,it.Students[rank_in_grad]);
                        added= true;
                    }
                }
                if(added== false){
                    break;
                }
                rank_in_grad=rank_in_grad+1;
            }

            std::vector<std::pair<std::string,student>> to_delete_list;
            for(int j=ID;j<=COTE;j=j+1){
                if(j-1<final_rank_list.size()) {
                    std::cout<<final_rank_list[j-1].second.ID<<" ";
                    to_delete_list.emplace_back(final_rank_list[j-1].first,final_rank_list[j-1].second);
                }
            }
            std::cout << '\n';


            //3 delete
            for(auto& del_info : to_delete_list){
                int id_delete=del_info.second.ID;
                std::string str_delete=del_info.first;

                auto& delete_students=student_db[str_delete].Students;

                auto it=std::remove_if(delete_students.begin(),delete_students.end(),[&] (student& s) {
                    if(s.ID==id_delete){
                        student_db[str_delete].total_COTE=student_db[str_delete].total_COTE-del_info.second.COTE;
                        return true;
                    }
                    return false;
                });
                delete_students.erase(it,delete_students.end());

            }




        }
        else{ //add
            student_db[GRAD_code].GRAD=GRAD_code;
            student_db[GRAD_code].Students.emplace_back(ID,COTE);
            student_db[GRAD_code].total_COTE+=COTE;
            std::sort(student_db[GRAD_code].Students.begin(),student_db[GRAD_code].Students.end()); // inner sorting
        }
    }




    return 0;
}
