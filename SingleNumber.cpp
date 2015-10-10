class Solution {
public:
    int singleNumber(int A[], int n) {
        int out=A[0],i=1;
        while(i<n){
            out^=A[i];
			i++;
        }
		return out;
    }
};