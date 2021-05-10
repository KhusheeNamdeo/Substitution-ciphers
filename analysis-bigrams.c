#include <stdio.h>

void main() {
	int i, j;
	char c;
	int bigramscount[26*26];
	char bigrams[26*26][2];

	// initialize arrays to count bigrams
	for(i=0; i < 26; i++) {
		for(j=0; j < 26; j++) {
			bigramscount[i*26 + j] = 0;
			bigrams[i*26 + j][0] = 'a' + i;
			bigrams[i*26 + j][1] = 'a' + j;
		}
	}

	// read the input
	char pc = 0;
	while((c=getchar()) != EOF) {
		if(c>='A' && c<='Z')
			c = c + 'a' - 'A';
		if(pc > 0 && c >= 'a' && c <= 'z' && pc >= 'a' && pc <= 'z') {
			i = pc - 'a';
			j = c - 'a';
			bigramscount[i*26 + j]++;
		}
		pc = c;
	}

	int max, t, maxpos;
	char tc;
	for(i=0; i<26*26; i++) {
		max = bigramscount[i]; maxpos = i;
		for(j=i+1; j<26*26; j++) {
			if(bigramscount[j] > max) {
				max = bigramscount[j];
				maxpos = j;
			}
		}
		if(maxpos != i) {
			t=bigramscount[i]; bigramscount[i] = bigramscount[maxpos]; bigramscount[maxpos]=t;
			tc=bigrams[i][0]; bigrams[i][0] = bigrams[maxpos][0]; bigrams[maxpos][0]=tc;
			tc=bigrams[i][1]; bigrams[i][1] = bigrams[maxpos][1]; bigrams[maxpos][1]=tc;
		}
	}

	printf("top 10 bigrams in order of frequency: ");
	for(i=0; i<10; i++) {
		printf("%c%c, ", bigrams[i][0], bigrams[i][1]);
	}
	printf("\n");
}
