
#include <iostream>
int myif(int a) {
    if (a > 67){
        return 67;
    } else {
        return a;
    }
    
}
int main(){

    int q = myif(5);
    return q;
}