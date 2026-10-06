import numpy as np
import time

def matrix_multiplication(X, Y):
    return np.dot(X,Y)

def main():
    r1, c1 = map(int, input("Rows and columns of first matrix: ").split())
    r2, c2 = map(int, input("Rows and columns of second matrix: ").split())
    
    if c1 != r2:
        print("The columns of the first matrix must be equal to the rows of the second matrix for multiplication.")
        return
    else:
        print("X:")
        X = np.array([list(map(float, input(f"Row {i+1} of X: ").split())) for i in range(r1)]) 
        print(X)
          
        print("Y:")
        Y = np.array([list(map(float, input(f"Row {i+1} of Y: ").split())) for i in range(r2)])
        print(Y)
        
        start = time.perf_counter()
        
        Z = matrix_multiplication(X, Y)
        
        end=time.perf_counter()
        print("Result: ", Z)
        print(f"Execution time in seconds: {end-start:.10f}")
        
main()