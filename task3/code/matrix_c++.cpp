#include<iostream>
#include<iomanip>
#include<vector>

using Matrix=std::vector<std::vector<double>>;
int main(){
    int r1, c1, r2, c2;
    std::cout<<"Rows and columns of the first matrix: ";
    std::cin>>r1>>c1;
    std::cout<<"Rows and columns of the second matrix: ";
    std::cin>>r2>>c2;

    if(c1 != r2){
        std::cout<<"The columns of the first matrix must be equal to the rows of the second matrix for multiplication."<<std::endl;
        return 0;
    }
    Matrix X(r1, std::vector<double>(c1));
    Matrix Y(r2, std::vector<double>(c2));

    std::cout<<"\nX: \n";
    for(int i=0; i<r1; i++){
        for(int j=0; j<c1; j++){
            std::cin>>X[i][j];
        }
    }
    std::cout<<"\nY: \n";
    for(int i=0; i<r2; i++){
        for(int j=0; j<c2; j++){
            std::cin>>Y[i][j];
        }
    }
    Matrix Z(r1, std::vector<double>(c2, 0.0));
    for(int i=0; i<r1; i++){
        for(int k=0; k<c1; k++){
            for(int j=0; j<c2; j++){
                Z[i][j] +=X[i][k]*Y[k][j];
            }
        }
    }
    std::cout<<"\nZ: \n";
    for(int i=0; i<r1; i++){
        for(int j=0; j<c2; j++){
            std::cout<<std::setw(10)<<Z[i][j]<<" ";
        }
        std::cout<<"\n";

    }
    return 0;

}