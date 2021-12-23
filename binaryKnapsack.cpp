#include <iostream>


int binaryKnapsack(int m, int n, int* weights, int* profits, int* soln){
    int mem[n+1][m+1];
    int i,w;
    for(i=0;i<=n;i++){
        for(w=0;w<=m;w++){
            if(i==0 || w==0)//weight or capacity is equal to zero
                mem[i][w] = 0;
            else if(w < weights[i])// capacity is not enough to carry new object, profit is same as the previous object.
                mem[i][w] = mem[i-1][w];
            else //profit is equal to max(previous profit, new profit with i'th object)
                mem[i][w] = mem[i-1][w] > profits[i] + mem[i-1][w-weights[i]] ? mem[i-1][w] : profits[i] + mem[i-1][w-weights[i]];
        }
    }
    
    //write the solution to soln array
    i=n;
    w=m;
    while(i && w){
        if(mem[i][w]==mem[i-1][w]){
            soln[i] = 0;
            i--;
        }
        else{
            soln[i] = 1;
            i--;
            w -= weights[i+1];
        }
    }
    return mem[n][m];
}

int main(){
    int n=6;
    int m=30;
    int soln[7];
    int weights[7] = {0,2,3,5,8,13,16};
    int profits[7] = {0,1,2,3,5,7,10};

    int p = binaryKnapsack(m,n,weights,profits,soln);
    
    std::cout << "Max profit: " << p <<  std::endl;
    std::cout << "Solution: (";
    for(int i=1;i<n;i++)
        std::cout << soln[i] << ",";
    std::cout << soln[n] << ")";
        

}