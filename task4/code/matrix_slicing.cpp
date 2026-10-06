#include<iostream>
#include<vector>
#include<fstream>
using Matrix=std::vector<std::vector<double>>;
int main(){
    int row, col;
    std::cout<<"Input dimensions (row column): ";
    std::cin>>row>>col;
    Matrix X(row, std::vector<double>(col));

     std::cout<<"\nX: \n";
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            std::cin>>X[i][j];
        }
    }

    int s1, s2, e1, e2;
    std::cout<<"Enter start row: ";
    std::cin>>s1;
    std::cout<<"Enter end row: ";
    std::cin>>e1;
    std::cout<<"Enter start column: ";
    std::cin>>s2;
    std::cout<<"Enter end column: ";
    std::cin>>e2;

    std::cout<<"\nSliced Matrix: \n";
    for(int i=s1; i<e1; i++){
        for(int j=s2; j<e2; j++){
            std::cout<<X[i][j]<<" ";

        }
        std::cout<<"\n";

    }

    std::ofstream file("task4/code/cpp_result.txt");
    for(int i=s1; i<e1; i++){
        for(int j=s2; j<e2; j++){
            file<<X[i][j]<<" ";
        }
        file<<"\n";
    }

    file.close();

    return 0;


}