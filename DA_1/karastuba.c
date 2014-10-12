 #include <stdio.h>
#include <math.h>

int karastuba(int number_1, int number_2, int count){
	//ToDo : Finish this function
	int ac, bd, adbc, number_1_1, number_1_2, number_2_1,number_2_2, divisor, value, multiplier;
	if(count==1){
			return number_1*number_2;
	}
	multiplier = (int) pow(10, count);
	divisor = (int) pow(10, count/2);
	number_1_1 = number_1/divisor;
	number_1_2 = number_1%divisor;
	number_2_1 = number_2/divisor;
	number_2_2 = number_2/divisor;
	ac = karastuba(number_1_1, number_2_1, count/2);
	bd = karastuba(number_1_2, number_2_2, count/2);
	adbc = karastuba((number_1_1+number_1_2), (number_2_1+number_2_2), count/2) - ac - bd;
	value = multiplier*ac + divisor*adbc + bd;
	return value;

}
int main(){
	int number_1, number_2, result, number, count = 0;
	printf("Enter first number:\n");
	scanf("%d", &number_1);
	printf("Enter second number:\n");
	scanf("%d", &number_2);
	number = number_1;
	while(number>0){
		++count;
		number=number%10;
	}
	result = karastuba(number_1, number_2, count);
	printf("Result: %d\n", result);
	return 0;
}
