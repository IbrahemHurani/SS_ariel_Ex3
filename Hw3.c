#include<stdio.h>
#include <string.h>
#define TXT 1024
#define WORD 30
char word[WORD];
char text[TXT];

void inputword(){
	int i = 0;
	do {
		scanf("%c", &word[i]);
		i++;
	} while ((word[i - 1] != ' ') && (word[i-1]!='\t') && (word[i-1]!='\n'));
	word[i++]='\0';
}
void inputTxt(){
	int j = 0;
	do {
		scanf("%c", &text[j]);
		j++;
	} while (text[j - 1] != '~');
	text[j++] = '\0';
}
int Check_char(char ch) {
	if (ch >= 'a'&&ch <= 'z') {
		return ch - 'a' + 1;
	}
	else if (ch >= 'A'&&ch <= 'Z') {
		return ch - 'A' + 1;
	}
	return 0;
}

int geomrtria() {
	int i = 0;
	int GeoWords = 0;
	int GeoTxt = 0;
	int flag = 0;
	while (word[i] != '\0') {
		GeoWords += Check_char(word[i]);
		i++;
	}
	i = 0;
	int j = 0, k = 0;
	printf("Gematria Sequences: ");
	while (text[i] != '\0') {
		if ((text[i] >= 'a' && text[i] <= 'z' )|| (text[i] >= 'A' && text[i] <= 'Z')) {
			j = i;
			GeoTxt = 0;
			while (text[j] != '\0') {
				GeoTxt += Check_char(text[j]);
				if (GeoTxt == GeoWords) {
					if (flag > 0) {
						printf("~");
					}
					k = i;
					while (k <= j) {
						printf("%c", text[k]);
						k++;
					}
					flag++;
					break;
				}

				j++;
			}

		}
		i++;
	}
	printf("\n");
	return 0;
}
char Reverse(char ch) {
	if (ch >= 'a'&&ch <= 'z') {
		return 'z' - (ch - 'a');

	}
	else if (ch >= 'A'&&ch <= 'Z') {
		return 'Z' - (ch - 'A');
	}
	return ' ';

}
int check_word(int index, char *Rword, char *txt) {
	int i = 0, count = 0;
	while (txt[index] != 0) {
		if (Rword[i] != '\0'&&Rword[i] == txt[index]) {
			count++;
			i++;
			index++;
		}
		else {
			break;
			count = 0;
		}
	}
	return count;
}

int atbash()
{
	char Reword[WORD], RReword[WORD];
	int i = 0, j = 0, k = 0, flag = 0;
	printf("Atbash Sequences: ");
	while (word[i] != '\0') {
		Reword[j] = Reverse(word[i]);
		i++;
		j++;
	}
	Reword[j - 1] = '\0';
	i = 0;
	while (Reword[i] != '\0') {
		k++;
		i++;
	}
	i = 0;
	while (k >= 0) {
		if ((Reword[k] >= 'a' && Reword[k] <= 'z') || (Reword[k] >= 'A' && Reword[k] <= 'Z')) {
			RReword[i] = Reword[k];
			i++;
		}
		k--;
	}
	RReword[i] = '\0';
	i = 0;
	while (text[i] != '\0') {
		if (text[i] == Reword[0]) {
			int count = check_word(i, Reword, text);
			if (count == strlen(Reword)) {
				if (flag > 0) printf("~");
				while (count != 0) {
					printf("%c", text[i]);
					i++;
					count--;
				}
				flag++;
			}

		}
		else if (text[i] == RReword[0]) {
			int count = check_word(i, RReword, text);
			if (count == strlen(RReword)) {
				if (flag > 0)printf("~");
				while (count != 0) {
					printf("%c", text[i]);
					i++;
					count--;
				}
				flag++;
			}
		}
		i++;
	}
	printf("\n");
	return 0;
}
int foud(char ch, char *word) {
	int i = 0;
	while (word[i] != '\0') {
		if (word[i] == ch)
			return 1;
		i++;
	}
	return 0;
}
int equal_Array(int *check, int *arrtemp) {
	for (int i = 0; i < 26; i++) {
		if (check[i] != arrtemp[i])
			return 0;
	}
	return 1;
}

int Anagram() {
	int i = 0, p = 0;
	int arrtemp[26] = { 0 };
	int flag = 0;
	while (word[i] != '\0') {
		if (word[i] >= 'a'&&word[i] <= 'z') {
			arrtemp[word[i] - 'a']++;
		}
		else if (word[i] >= 'A' && word[i] <= 'Z') {
			arrtemp[word[i] - 'A']++;
		}
		i++;
	}
	printf("Anagram Sequences: ");
	i = 0;
	while (text[i] != '\0') {
		if ((text[i] >= 'a' && text[i] <= 'z') || ( text[i] >= 'A' && text[i] <= 'Z')) {
			int check[26] = { 0 };
			if (text[i] == ' ') { i++; }
			p = i;
			for (int j = 0; j < strlen(word); j++) {
				if (foud(text[p], word) == 1) {
					if (text[p] >= 'a'&&text[p] <= 'z') {
						check[text[p] - 'a']++;
					}
					else if (text[p] >= 'A'&&text[p] <= 'Z') {
						check[text[p] - 'A']++;
					}
					p++;
				}
				else {
					break;
				}
			}
			if (equal_Array(check, arrtemp) == 1) {
				if (flag > 0)printf("~");
				int k = i, j = 0;
				while (j < strlen(word)-1) {
					if ((text[k] >= 'a' && text[k] <= 'z') || (text[k] >= 'A' && text[k] <= 'Z')) {
						printf("%c", text[k]);
						k++;
					}
					j++;
				}
				flag++;

			}
		}

		i++;
	}
	printf("\n");
	return 0;
}
int main() {
	inputword();
	inputTxt();
	geomrtria();
	atbash();
	Anagram();

}
