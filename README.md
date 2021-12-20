# Calculating the Wasted Area with given partition options

There are three functions that calculates the wasted area in a field by partitioning it with given partition options.
The first function is implemented recursively. 
The second one is more optimized version of the first, by storing certain wasted areas calculated before and then using these pre-calculated values, using memoization technique.
The third function is implemented by using dynamic programming approach. It calculates the wasted area for smaller fields and stores them to use in further steps.
Complexities of the second and the third functions is same but, the dynamic programming approach is more efficient by constants.
To run this functions, *main.cpp* will be provided soon.