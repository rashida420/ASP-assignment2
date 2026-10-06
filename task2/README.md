
# Experimenting with Python __sizeof()__
## Task introduction
This report examine the memory usage of Python tuple and list with experimentation using Python's __sizeof__() method. It focuses on the comparison of memory sizes of these data structures and how memory usage differs as the number of elements changes.

#Experimenting with Python __sizeof()__
##Task introduction
This report examine the memory usage of Python tuple and list with experimentation using Python's __sizeof__() method. It focuses on the comparison of memory sizes of these data structures and how memory usage differs as the number of elements changes.
## Initial experiment
###Tuple
Tuples  are immutable, and the data within them cannot be
changed once they have been created.To find the memory usage of tuple we can use 
```python
__sizeof__() function of python.
tpl = (1,2,3)
print(tpl.__sizeof__())
```
if I run the code this will give me 48. __sizeof__ returns the size of an object in bytes. In the official documentation it is describes as "Only the memory consumption directly attributed to the object is accounted for, not the memory consumption of objects it refers to". this means that 48 bytes represnt the memory used by the tuple object itself. It doesn't mean that it also includes the memory size of individual elements inside of the tuple. Instead, the tuple stores references to these objects.For instance the first position of the tuple contains a reference to the object  that represnts 1, the second contains a reference to 2 and so on.
To understand further I tested the ```python__sizeof()__ ```on an empty tuple.
```python
empty_lst=()
print(empty_lst.__sizeof__())
```
The output is 24 bytes. The difference between this and the previous experience is 48-24=24. Because there is no elements inside ```python__sizeof()__ ``` inly calculates the memory size of the object itself wothout any references. 
###Lists
Lists are mutable meaning that its elements can be changed after it's created. When we implement __sizeof()__ on lists we get 72 bytes. Similar to tuple, this result represnts the memory used by the list ibject itself and its stored references. Additionally, the size of memory occupied by an empty list is 40;
empty_tlp=()
print(empty_tpl.__sizeof__())
output:40

To explain the memory size of a reference to an object we have to consider that it completely depends on the arhitecture of the Python the tasks runs on. I checked that using this piece of code:
import platform
print(platform.architecture())
Output:('64bit', 'WindowsPE')
My Python enviroment is 64-bit, therefore the reference to an object contains 8bytes(64/8bits=8bytes).
But question arises from here which is "Why the difference is not same for the tuple and the list?"
for tuple:48-24=24
for list:72-40=32
Due to mutability, lists have some additional overhead which is for future addition. On the other hand once the tuple is created it size is fixed. In the experiment 3 references requires 24 bytes. (8*3=24). In the list 32-24=8 bytes is considered additional overhead.
## Second Experiment:Comparing memory growth of tuple and list.
Since we can't add new elements to the tuple we can implement this by creating new tuples everytime that contains more elements. For the list we can add new elements using append.
```python

from tabulate import tabulate
tpl = (1, 2, 3)
lst = [1, 2, 3]

result=[]

for i in range(3, 20):
    tpl = tuple(range(i))
    lst.append(i)
    result.append((len(tpl), tpl.__sizeof__(), lst.__sizeof__()))

print(tabulate(result, headers=["Number of elements", "Tuple Size", "List Size"], tablefmt="github"))
```
After running the code I got this result.

|   Number of elements |   Tuple Size |   List Size |
|----------------------|--------------|-------------|
|                    3 |           48 |          72 |
|                    4 |           56 |         104 |
|                    5 |           64 |         104 |
|                    6 |           72 |         104 |
|                    7 |           80 |         104 |
|                    8 |           88 |         168 |
|                    9 |           96 |         168 |
|                   10 |          104 |         168 |
|                   11 |          112 |         168 |
|                   12 |          120 |         168 |
|                   13 |          128 |         168 |
|                   14 |          136 |         168 |
|                   15 |          144 |         168 |
|                   16 |          152 |         232 |
|                   17 |          160 |         232 |
|                   18 |          168 |         232 |
|                   19 |          176 |         232 |
|                   20 |          184 |         232 |

The size of tuple increases exactly 8 bytes for each new element. On the other hand list  allocates additional memory in advance as new elements are added. this means no need to allocate memory everytime a new element is added.






