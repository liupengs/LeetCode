uint32_t reverseBits(uint32_t n) {
   uint32_t temp=0,t=0;
    int i;
    for(i=0;i<32;i++){
        t=n&1;
        temp+=(t<<(31-i));
        n>>=1;
    }
    return temp;
}
