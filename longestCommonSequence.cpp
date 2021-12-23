#include <iostream>
#include <string.h>
using namespace std;

int lcs(char* a, char* b, char* soln){
    int i,j;
    int len_a = strlen(a);
    int len_b = strlen(b);
    cout << len_a << endl;
    int mem[len_a+1][len_b+1];
    for(i=0;i<=len_a;i++){
        for(j=0;j<=len_b;j++){
            if(i==2 && j ==1){
                cout << a[i] << " " << b[j] << " ";
                cout << "--------------------- i-1,j: " << mem[i-1][j] << " i,j-1: " << mem[i][j-1] << endl;  
            }
            if(!i || !j)
                mem[i][j] = 0;
            else if(a[i-1] != b[j-1])
                mem[i][j] = mem[i-1][j] > mem[i][j-1] ? mem[i-1][j] : mem[i][j-1];
            else if(a[i-1] == b[j-1])
                mem[i][j] = 1 + mem[i-1][j-1];
        }
    }
    return mem[len_a][len_b];
}

int main(){
    char str1[6] = "stone";
    char str2[8] = "longest";
    char* soln;
    int l = lcs(str1,str2,soln);
    cout << "Length of longest common sequence: " << l << endl; 
}