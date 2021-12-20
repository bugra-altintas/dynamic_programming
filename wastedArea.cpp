#include <climits>
#include <cmath>
#include <iostream>

int recursiveMethod(int W, int L, bool** partitions, int* numberOfCalls){//recursive
    *numberOfCalls += 1;
    if(partitions[W][L])
        return 0;
    int wastedArea = W*L;
    int m,n,res;
    int min=W*L;
    for(m = 1; m<=W/2; m++){
        res = recursiveMethod(W-m, L, partitions, numberOfCalls) + recursiveMethod(m, L, partitions, numberOfCalls);
        min = res < min ? res : min; 
    }
    int vertical = min;
    min = W*L;
    for(n = 1; n<=L/2; n++){
        res = recursiveMethod(W, L-n, partitions, numberOfCalls) + recursiveMethod(W, n, partitions, numberOfCalls);
        min = res < min ? res : min;
    };
    int horizontal = min;
    return std::min(wastedArea, std::min(vertical ,horizontal));
}

int mem_util(int W, int L, bool** partitions, int * numberOfCalls, int** mem){//utilizer for memization method
    *numberOfCalls += 1;
    if(mem[W][L]!=-1)
        return mem[W][L];
    if(partitions[W][L]){
        mem[W][L] = 0;
        return 0;
    }
    int wastedArea = W*L;
    int m,n,res;
    int min=W*L;
    for(m = 1; m<=W/2; m++){
        res = mem_util(W-m, L, partitions, numberOfCalls, mem) + mem_util(m, L, partitions, numberOfCalls, mem);
        min = res < min ? res : min; 
    }
    int vertical = min;
    min = W*L;
    for(n = 1; n<=L/2; n++){
        res = mem_util(W, L-n, partitions, numberOfCalls, mem) + mem_util(W, n, partitions, numberOfCalls, mem);
        min = res < min ? res : min;
    };
    int horizontal = min;
    mem[W][L] = std::min(wastedArea, std::min(vertical, horizontal));
    return mem[W][L];
}

int memizationMethod(int W, int L, bool** partitions, int* numberOfCalls){//memoization
    int** mem;
    int i,j;
    *numberOfCalls += 1;
    mem = new int*[W+1];
    for(i=0;i<W+1;i++)
        mem[i] = new int[L+1];
    for(i=0;i<W+1;i++){
        for(j=0;j<L+1;j++)
            mem[i][j]=-1;
    }
	return mem_util(W,L,partitions,numberOfCalls,mem);
}



int bottomUpMethod(int W, int L, bool** partitions, int* numberOfIterations){//dynamic programming
    if(!partitions[W][L]){
        int mem[W+1][L+1];
        int i,j;
        for(i=0;i<=W;i++) mem[i][0] = 0;
        for(i=0;i<=L;i++) mem[0][i] = 0;
        for(i=1;i<=W;i++){
            for(j = 1; j<=L;j++)
                mem[i][j] = INT_MAX;
        }
        int l,w,min,res1,res2;
        for(i=1;i<=W;i++){
            for(j=1;j<=L;j++){
                if(partitions[i][j]){
                    mem[i][j]=0;
                    continue;
                }
                min = i*j;
                for(w=1;w<=i;w++){
                    *numberOfIterations += 1;
                    res1 = mem[w][j] + mem[i-w][j];
                    min = res1 < min ? res1 : min;
                }
                res1 = min;
                min = i*j;
                for(l=1;l<=j;l++){
                    *numberOfIterations += 1;
                    res2 = mem[i][l] + mem[i][j-l];
                    min = res2 < min ? res2 : min;
                }
                res2 = min;
                mem[i][j] = std::min(i*j,std::min(res1,res2));
            }
        }
        
    	return mem[W][L];
    }
    return 0;
}
