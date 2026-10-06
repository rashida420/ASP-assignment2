import numpy as np
import matplotlib.pyplot as plt

numpy_result = np.loadtxt("numpy_result.txt", ndmin=2)
cpp_result = np.loadtxt("cpp_result.txt", ndmin=2)
X = np.loadtxt("original_matrix.txt", ndmin=2)
fig, axes = plt.subplots(1, 3, figsize=(10, 3))
axes[0].imshow(X, cmap="PRGn")
axes[0].set_title("Original Matrix")
axes[0].set_xticks(np.arange(X.shape[1]))
axes[0].set_yticks(np.arange(X.shape[0]))

axes[1].imshow(numpy_result, cmap="PRGn")
axes[1].set_title("Numpy Sliced Matrix")
axes[1].set_xticks(np.arange(numpy_result.shape[1]))
axes[1].set_yticks(np.arange(numpy_result.shape[0]))

axes[2].imshow(cpp_result, cmap="PRGn")
axes[2].set_title("C++ Sliced Matrix")
axes[2].set_xticks(np.arange(cpp_result.shape[1]))
axes[2].set_yticks(np.arange(cpp_result.shape[0]))

plt.show()