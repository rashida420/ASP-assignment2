#include<iostream>
#include<vector>
#include<cassert>
using Matrix=std::vector<std::vector<double>>;

Matrix matrix_multiplication(Matrix X, Matrix Y){
    int r1=X.size();
    int c1=X[0].size();
    int c2=Y[0].size();

    Matrix Z(r1, std::vector<double>(c2, 0.0));
    for(int i=0; i<r1; i++){
        for(int k=0; k<c1; k++){
            for(int j=0; j<c2; j++){
                Z[i][j] +=X[i][k]*Y[k][j];
            }
        }
    }
    return Z;
}

// unit tests

//test case 1 : checking the square matix multiplication
void test_square_matrix(){
    Matrix X={{2, 2}, {3, 4}};
    Matrix Y={{1, 1}, {4, 5}};
    Matrix expected_result = {{10, 12}, {19, 23}};
    assert (matrix_multiplication(X, Y)== expected_result);
    std::cout<<"Test case 1 -Square matrix multiplication passed."<<std::endl;
}

void test_different_size_matrix(){
    Matrix X={{1, 2, 3}, {0, 5, 2}};
    Matrix Y={{4, 5}, {9, 2}, {1, 6}};
    Matrix expected_result = {{25, 27}, {47, 22}};
    assert (matrix_multiplication(X, Y)== expected_result);
    std::cout<<"Test case 2 -Different size matrix multiplication passed."<<std::endl;
}

void test_zero_matrix(){
    Matrix X={{0, 0}, {0, 0}};
    Matrix Y={{1, 1}, {3, 3}};
    Matrix expected_result = {{0, 0}, {0, 0}};
    assert (matrix_multiplication(X, Y)== expected_result);
    std::cout<<"Test case 3 -Zero matrix multiplication passed."<<std::endl;
}

void run_all_tests(){
    std::cout<<"Running all test cases"<<std::endl;
    test_square_matrix();
    test_different_size_matrix();
    test_zero_matrix();
    std::cout<<"All test cases passed successfully."<<std::endl;
}

int main(){
    run_all_tests();
    return 0;
}
