#include <stdio.h>
#include <stdbool.h>

bool isValid(char* s){
	
	int rounOpend = 0;
	int rounClosed = 0;
	int squereOpend = 0;
	int squereClosed = 0;
	int curvedOpend = 0;
	int curvedClosed = 0;
	
	for(int i = 0; s[i] != '\0'; i++) {
		switch(s[i]) {
			case '(': rounOpend++; break;
			case ')': rounClosed++;  break;
			
			case '[': squereOpend++; break;
			case ']': squereClosed++;  break;
			
			case '{': curvedOpend++; break;
			case '}': curvedClosed++;  break;
		}
		/**printf("%c\n", s[i]);
		printf("round %d : %d\n", rounOpend, rounClosed);
		printf("squere %d : %d\n", squereOpend, squereClosed);
		printf("curved %d : %d\n", curvedOpend, curvedClosed);
		**/
	}
	
	return rounOpend == rounClosed && squereOpend == squereClosed && curvedOpend == curvedClosed;
}

void test_equals_int(int result, int actual, int line){
	if(result == actual){
		printf("Test pass in Line %d.\n", line);
	} else {
		printf("expected [%d] differs from [%d] in Line %d.\n", actual, result, line);
	}
}

int main() {
	char* str0 = "(){}[]";
	test_equals_int(isValid(str0), 1, __LINE__);
	char* str1 = "(]";
	test_equals_int(isValid(str1), 0, __LINE__);
	char* str2 = "({[){}]";
	test_equals_int(isValid(str2), 0, __LINE__);
	char* str3 = "(){[()]{}}";
	test_equals_int(isValid(str3), 1, __LINE__);
	
	return 0;
}