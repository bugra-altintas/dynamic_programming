#include <iostream>
#include <climits>
using namespace std; 
int matrixChainProduct(int* matrices, int n){
    int c[n][n];
    for(int i=1;i<n;i++) c[i][i] = 0;
    int chain,i,j,k;
    for(chain = 2;chain<n;chain++){
        for(i=1;i<=n-chain;i++){
            j=i+chain-1;
            int min = INT_MAX;
            for(k=i;k<j;k++){
                int p = c[i][k] + c[k+1][j] + matrices[i-1]*matrices[k]*matrices[j];
                min = min < p ? min : p;
            }
            c[i][j] = min;
        }
    }
    return c[1][n-1];
}


int main(){
    int matrices[5] = {10, 20, 30, 40, 30} ;
    cout << "Minimum number of multiplications: " << matrixChainProduct(matrices,5);
}