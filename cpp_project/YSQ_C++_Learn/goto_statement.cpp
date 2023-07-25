#include<iostream>
float mysquare(float &value);
int main(){
    float value;
    std::cout << "please input the value" << std::endl;
    std::cin >> value;
    std::cout<<mysquare(value);
    return 0;
}


float mysquare(float &value){
    float result = 0.1f;
    if(value>=1.0f||value<=0){
        std::cout<< "The input is out of range." << std::endl;
        goto EXIT_ERROR;
    }
    result = value * value;
    return result;


    EXIT_ERROR:
    return 0.0f;
}