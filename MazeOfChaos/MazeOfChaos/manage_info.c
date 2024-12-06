#include "MOC.h"

void UpdateUserInfo() {
	FILE* temp = fopen("temp.txt", "w");
	FILE* read = fopen("Record.txt", "r");

	char arr[100];
	char num[100];

	while (1) {
		if (fscanf(read, "%s",arr) == EOF)
			break;

		fgets(num, 100, read);
		if (strcmp(arr, user_name) == 0) {
			int cnt = 1;
			fprintf(temp, "%s ", arr);
			for (int i = 0; i < 26; i++) {
				if (i == 0) {
					fprintf(temp, "%d ", user_coin);
				}
				else if (0 < i && i < 6) {
					fprintf(temp, "%d ", user_record[i]);
				}
				if (i > 6) {
					fprintf(temp, "%d ", user_skin[cnt]);
					cnt++;
				}
			}
			fprintf(temp, "\n");
		}
		else {
			fprintf(temp, "%s %s", arr, num);
			
		}
	}

	fclose(read);
	fclose(temp);
	remove("Record.txt");
	rename("temp.txt", "Record.txt");

}