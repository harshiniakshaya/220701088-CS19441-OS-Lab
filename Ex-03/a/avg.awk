{
	if($2>6000 && $3>4){
		print ($1,$2*$3)
		t+=$2*$3
		c++
	}
}
END{
	if(c>0){
		a=t/c
		print ("Total emp: ",c)
		print ("avg pay",a)
	}
	else{
		print("criteria not satisfied")
	}
}
