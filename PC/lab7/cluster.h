#ifndef K_MEANS_MIO_CPP_CLUSTER_H
#define K_MEANS_MIO_CPP_CLUSTER_H
#include <bits/stdc++.h>
#include "point.h"
#include <omp.h>
class Cluster {
public:
    Cluster(double x_c, double y_c){
        new_x_c = 0;
        new_y_c = 0;
        size = 0;
        this->x_c = x_c;
        this->y_c = y_c;
    }
    Cluster(){
        new_x_c = 0;
        new_y_c = 0;
        size = 0;
        this->x_c = 0;
        this->y_c = 0;
    }
    void add_point(Point point){
        #pragma omp atomic
        new_x_c += point.get_x_c();
        #pragma omp atomic
        new_y_c += point.get_y_c();
        #pragma omp atomic
        size++;
    }
    double get_y_coord(){
        return this->y_c;
    }
    void free_point(){
        this->new_x_c = 0;
        this->new_y_c = 0;
        this->size = 0;
    }
    double get_x_coord(){
        return this->x_c;
    }
    bool update_coords(){
        if(this->x_c == new_x_c/this->size && this->y_c == new_y_c/this->size) return false;
        this->x_c = new_x_c/this->size;
        this->y_c = new_y_c/this->size;
        return true;
    }
private:
    double x_c;
    double y_c;
    //Number of points inside this Cluster
    int size;
    //Accumulate the Point coords here
    double new_x_c;
    double new_y_c;
};
#endif