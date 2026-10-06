import numpy as np
def main():
    
    row, col = map(int, input("Input dimensions (rows columns): ").split())
    
    X = np.array([list(map(float, input(f"Row {i+1} of X: ").split())) for i in range(row)])
    
    
    s1 = int(input("Enter start row: ")) #s1 - means start 1
    e1 = int(input("Enter end row: "))    #e1 means end 1
    s2 = int(input("Enter start column: "))
    e2 = int(input("Enter end column: "))

    
    
    sliced_matrix = X[s1:e1, s2:e2]
    np.savetxt("numpy_result.txt", sliced_matrix, fmt="%.0f")
    np.savetxt("original_matrix.txt", X, fmt="%.0f")
   
    

    print(X)
    print()
    print("matrix after slicing:")
    print()
    print(sliced_matrix)


main()