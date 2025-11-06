#include <iostream>
#include <cmath>


int main() {
    double x1, y1, r1;
    double x2, y2, r2;

    std::cin >> x1 >> y1 >> r1;
    std::cin >> x2 >> y2 >> r2;

    if (r1 < r2) {
        std::swap(r1, r2);
    }  //set 1 as the bigger radious

    double dist_betw=sqrt(pow((x1-x2),2)+pow((y1-y2),2));
    double gaduri_length=sqrt(pow(dist_betw,2)-pow((r1-r2),2));
    double gaduri_radian=2*acos((r1-r2)/dist_betw);
    double full_length=2*gaduri_length+r1*(2*M_PI-gaduri_radian)+r2*gaduri_radian;
    double full_area=(r1+r2)*gaduri_length+0.5*r1*r1*(2*M_PI-gaduri_radian)+0.5*r2*r2*gaduri_radian;


    std::cout<<(int)full_area<<" "<<(int)full_length<<std::endl;





    return 0;
}
