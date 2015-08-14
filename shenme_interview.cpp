



int help(int num){
	if(num==0 || num==1)
		return 1;
	
	for(int i=i;i<=num;i++){
		if(!res[i-1]){
			res[i-1] = help(i-1);
		}
		if(!res[n-i]){
			res[n-i] = help(n-i);
		}
		sum += res[i-1]*res[n-i];
	}
	delete[] res;
	return sum;
}

