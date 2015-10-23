char* convertToTitle(int n) {
  char *r;
	int i;
	i = 6;
	r = (char *)calloc(8,sizeof(char));
	while (n >0) {
		r[i] =65 + (n-1) % 26;
		i--;
		n = (n-1)/26;
	}
	return r+i+1;
}
