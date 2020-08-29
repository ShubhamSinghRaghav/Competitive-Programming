/*
Set ith bit
*/
int turnOnIthBit(int n, int i){
    return (n | (1<<i));
}

// Unset ith bit

int turnOffIthBit(int n, int i){
    return (n & ~(1<<i)); 
}

// Find first set bit

int returnFirstSetBit(int n){
    if(n==0) return 0;
    int i=0;
    while((n&1)!=1){
        n=n>>1;
        i++;
    }
    return 1<<i;
}

// Clear All Bits From MSB

int clearAllBits(int n, int i){
    if(n==0) return 0;
    return n & ((1<<i)-1);
}





