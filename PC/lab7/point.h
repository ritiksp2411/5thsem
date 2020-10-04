#ifndef K_MEANS_MIO_CPP_POINT_H
#define K_MEANS_MIO_CPP_POINT_H
#include <printf.h>
class Point {
public:
    Point(double x_c, double y_c){
        this->x_c = x_c;
        this->y_c = y_c;
        cluster_id = 0;
    }
    Point(){
        x_c = 0;
        y_c = 0;
        cluster_id = 0;
    }
    int get_cluster_id(){
        return cluster_id;
    }
    double get_x_c(){
        return this->x_c;
    }
    double get_y_c(){
        return this->y_c;
    }
    void set_cluster_id(int cluster_id){
        this->cluster_id = cluster_id;
    }
private:
    //Cluster id of this Point
    int cluster_id;
    double x_c;
    double y_c;
    
};
#endif