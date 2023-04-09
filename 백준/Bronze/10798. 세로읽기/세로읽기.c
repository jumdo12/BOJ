#include <stdio.h>
#include <string.h>

int main() {
	char arr[5][15] = {0};
    
	for (int i = 0; i < 5; i++) {
		scanf("%s", arr[i] , sizeof(arr));
	}

	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 5; j++) {
			if (arr[j][i]) {
				printf("%c", arr[j][i]);
			}
		}
	}

	return 0;
}