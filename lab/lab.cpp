#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

struct Student{
public:
    string name;
    int att;
    int sum_of_scores;
    int min_of_scores=101;
    int max_of_scores;
    int score_100;

    Student(string& name, vector<int>& scores): name(name){
        att=scores.size()- count(scores.begin(), scores.end(),0);
        sum_of_scores= accumulate(scores.begin(), scores.end(),0);
        max_of_scores=*max_element(scores.begin(),scores.end());
        score_100=count(scores.begin(), scores.end(),100);


        for(int it:scores){
            if(it<min_of_scores and it!=0) min_of_scores=it;
        }
    }
};
auto get(const Student& a, int k){
    switch (k) {
        case 1: return a.att;
        case 2: return a.sum_of_scores;
        case 3: return a.min_of_scores;
        case 4: return a.max_of_scores;
        case 5: return a.score_100;
    }
    return 0;
}
vector<int> ind_order(5);
auto sorting_algoritm(const Student& a, const Student& b){
    for(int k: ind_order){
        int va=get(a,k);
        int vb=get(b,k);
        if(va!=vb){
            return va>vb;
        }
    }
    return a.name<b.name;
}
int main() {
    int N,k;
    cin>>N>>k;
    for (int& x : ind_order) cin >> x;

    vector<Student> score_map;
    for(int i=0;i<N;i=i+1){
        string name;
        cin>>name;
        vector<int> scores(k);
        for (int& x : scores) cin >> x;
        score_map.push_back(Student(name,scores));
    }
    std::sort(score_map.begin(),score_map.end(), sorting_algoritm);
    for(auto it: score_map){
        std::cout<<it.name<<std::endl;
    }

    return 0;
}
