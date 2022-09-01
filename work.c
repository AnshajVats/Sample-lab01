#include <stdlib.h>
#include <stdio.h>
#include <string.h>

enum type {Binary,decimal,Hexadecimal};
typedef enum type Type;


Type check_type(char * number) {
	if (number[0] == '0' && number[1] == 'x') {
		number++;
		number++;
		return Hexadecimal;
	} 
	else if (number[0] == '0' && number[1] == 'b') {
		
		return Binary;
	} 
	return decimal;
}

Type check_conversion_type(char * number) {
	if(number[0] == '2') {
		return Binary;
	}
	else if(number[0] == '1' && number[1] == '6') {
		return Hexadecimal;
	}
	return decimal;
}

int check_bin(char *number) {
	char *name = number;
	int len = strlen(name);
	int placeVal = 1;
	int count = 0;
	int rv = 0;
	int base = 2;
	for (int  i = len -1; i >= 0; i--) {
		if(name[i] != '0' && name[i] != '1') {
			printf("Bad input\n");
			exit(1);
		}
	}
		
	for (int  i = len -1; i >= 0; i--) {
		count = name[i] - 48;
		rv += (count * placeVal);
		placeVal *= base;
	}

	return rv;
}

int check_Hex(char *number) {
	char *name = number;
	int len = strlen(name);
	int placeVal = 1;
	int count = 0;
	int rv = 0;
	int base = 16;
				
	for (int  i = len -1; i >= 0; i--) {
		if (name[i]=='a' || name[i]=='b' || name[i]=='c'|| name[i]=='d'|| name[i]=='e'|| name[i]=='f') {
				count = -97 + name[i];
				count += 10;
		} else if (name[i]=='A' || name[i]=='B' || name[i]=='C'|| name[i]=='D'|| name[i]=='E'|| name[i]=='F') {
					count = -65 + name[i];
					count += 10;
		}
		else {	
				count = name[i] - 48;
		}
		rv += (count * placeVal);
		placeVal *= base;
	}

	return rv;
}

int checkInt(char * number) {
	char *name = number;
	int len = strlen(name);
	int placeVal = 1;
	int count = 0;
	int rv = 0;
	int base = 10;
			
	for (int  i = len -1; i >= 0; i--) {
		count = name[i] - 48;
		rv += (count * placeVal);
		placeVal *= base;
	}
	
	return rv;
}

int converter(char *number, Type num) {
	
	if (num == Binary) {
		number++;
		number++;
		return check_bin(number);
	}
	else if  (num == Hexadecimal) {
		number++;
		number++;
		return check_Hex(number);
	}
	return checkInt(number);
}


void reverseString(char * s) {
	int length, c;
	    char *begin, *end, temp;
	    length = strlen(s);
	    begin  = s;
	    end    = s;
	 
	    for (c = 0; c < length - 1; c++)
	        end++;
	 
	    for (c = 0; c < length/2; c++) {        
	        temp   = *end;
	        *end   = *begin;
	        *begin = temp;
	        begin++;
	        end--;
	    }
}

void printHex(unsigned  result) {
	char hexaDeciNum[64];
	char bin[32];
	int g =0;
	unsigned n = result;
	int i = 0;
	while (n != 0) {
		   unsigned temp = 0;
		
		   temp = n % 16;
		 
		      // check if temp < 10
		   if (temp < 10) {
		       hexaDeciNum[i] = temp + 48;
		       i++;
		   }
		   else {
		       hexaDeciNum[i] = temp + 55;
		       i++;
		   }
		 
		   n = n / 16;
	}
	hexaDeciNum[i] = 'x';
	i++;
	hexaDeciNum[i] = '0';
	i++;
	hexaDeciNum[i] = '\0';
	reverseString(hexaDeciNum);

	printf("%s\n", hexaDeciNum);
}

char* itoa(unsigned long long value, char* buffer) {
	unsigned long long n = value;
	int i = 0;
	while (n) {
        unsigned long long r = n % 10;
        buffer[i++] = 48 + r;
        n = n / 10;
    }
    if (i == 0) {
        buffer[i++] = '0';
    }
    buffer[i] = 'b';
    i++;
    buffer[i] = '0';
    i++;
    buffer[i] = '\0'; // null terminate string
    reverseString(buffer);
    return buffer;
}

void decToBinary(int n)
{
    // array to store binary number
    char binaryNum[32];
    char ch[64];
    int  k  = 2;
    ch[0] = '0';
    ch[1] = 'b';
  
    // counter for binary array
    int i = 0;
    while (n > 0) {
        // storing remainder in binary array
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }
    for (int j = i - 1; j >= 0; j--) {
    	ch[k] = binaryNum[j] + '0';
    	k++;
    }

    ch[k] = '\0';
    printf("%s\n", ch);
    
}

void printBin(unsigned  result, Type number_type) {
	unsigned n;
	char bin2[64];
	n = result;
	char ch[64];
	int count = 0;

	if(number_type == decimal) {
    	while (n != 0) {
       	 	n = n / 10;
        	++count;
    	}
    }

    if(count > 4 ) {
    	decToBinary(result);
    	exit(0);
    }

    n = result;

	long long bin = 0;
	long long rem, i = 1;	
	while (n!=0) {
		rem = n % 2;
		n /= 2;
		bin += rem * i;
		i *= 10;
	}

	

	itoa(bin, ch);

	printf("%s\n", ch);

}	
void printInt(unsigned  result) {
	unsigned n = result;
	char intSringNum[64];
	

	int  i = 0;
	unsigned rem = 0, tmp = 0;
	
	while (n != 0) {
		tmp = n % 10;
		intSringNum [i] = tmp + 48;
		i++;
		n = n/10;
	}
	intSringNum[i] = '\0';
	reverseString(intSringNum);
	printf("%s\n", intSringNum);
}

int main(int argc, char *argv[]) {
	char *number_to_convert = argv[1];
	char *type_of_conversion = argv[3];

 
	Type number_type = check_type(number_to_convert);
	Type convert_to = check_conversion_type(type_of_conversion);

	
	int converted_number = converter(number_to_convert, number_type);

	if(convert_to == Hexadecimal) {
		printHex(converted_number);
	}
	else if(convert_to == Binary) {
		printBin(converted_number, number_type);
	} else if (convert_to == decimal) {
		printInt(converted_number);
	}
	return 0;
}
