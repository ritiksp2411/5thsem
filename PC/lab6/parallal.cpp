#include <bits/stdc++.h> 
using namespace std; 
using namespace std::chrono; 
int main(){ 
    fstream file;
    string word, t, q, filename;
    filename = "KittenRGB.txt";
    vector<vector<int>> v;
    vector<vector<double>> yiq;
    vector<double> gry;
    file.open(filename.c_str());
    while(file >> word){
        int R=stoi(word);
        file >> word;
        int G=stoi(word);
        file >> word;
        int B=stoi(word);
        v.push_back({R,G,B});
    }
    int n=v.size();
    auto t1=high_resolution_clock::now(); 
    for(int i=0; i<n; i++){
        gry.push_back(v[i][0]*0.21+v[i][1]*0.72+v[i][2]*0.07);
        yiq.push_back({ 0.299*v[i][0]+0.587*v[i][1]+0.114*v[i][2],0.596*v[i][0]-0.275*v[i][1]-0.321*v[i][2],0.212*v[i][0]-0.523*v[i][1]+0.311*v[i][2]});
    }
    auto t2=high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(t2 - t1);  
    cout << "Serial time : " << duration.count() << " microseconds"<< endl;
    gry={};
    yiq={};
    t1=high_resolution_clock::now(); 
    #pragma omp parallal for num_threads(16)
    for(int i=0; i<n; i++){
        gry.push_back(v[i][0]*0.21+v[i][1]*0.72+v[i][2]*0.07);
        yiq.push_back({ 0.299*v[i][0]+0.587*v[i][1]+0.114*v[i][2],0.596*v[i][0]-0.275*v[i][1]-0.321*v[i][2],0.212*v[i][0]-0.523*v[i][1]+0.311*v[i][2]});
    }
    t2=high_resolution_clock::now();
    duration = duration_cast<microseconds>(t2 - t1); 
    cout << "Parallal time : " << duration.count() << " microseconds"<< endl;
    // Mam - Below is the code for printing the data as data is so huge so i just commented it.
    // cout << "Gray sclae : " << endl;
    // for(int i=0; i<n; i++){
    //     cout << gry[i] << " ";
    // }
    // cout << "\nYIQ sclae : " << endl;
    // for(int i=0; i<n; i++){
    //     cout << yiq[i][0] << " " << yiq[i][1] << " " << yiq[i][2] << endl;
    // }
    return 0; 
}