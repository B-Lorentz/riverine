#include <fstream>
#include <iostream>
#include <cassert>

#include "sph.hpp"
#include "three_dimension.hpp"
using namespace thd;
using namespace sph;
using namespace std;

void test_W(){
    ofstream out1;
   
    auto v0 = PVector(0.1, 0.2, 0.3);
    v0.Normalize();
    double h = 1.0;
    for (int i=1; i<100;i++){
        double l = h*i/100;
        auto v = l*v0;
        auto v2 = v;
        cout << h << v;
        cout << W(v, h);
        cout << gradW(v, h) << endl;
        assert(v == v2);
    }
}

int main(){
    test_W();
    
    return 0;
}
