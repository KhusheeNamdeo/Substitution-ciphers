#include <stdio.h>

void main() {
	int i, j, k;
	char c;
	int trigramscount[26*26*26];
	char trigrams[26*26*26][3];

	// initialize arrays to count bigrams
	for(i=0; i < 26; i++) {
		for(j=0; j < 26; j++) {
			for(k=0; k < 26; k++) {
				trigramscount[i*26*26 + j*26 + k] = 0;
				trigrams[i*26*26 + j*26 + k][0] = 'a' + i;
				trigrams[i*26*26 + j*26 + k][1] = 'a' + j;
				trigrams[i*26*26 + j*26 + k][2] = 'a' + k;
			}
		}
	}

	// read the input
	char pc = 0, ppc = 0;
	while((c=getchar()) != EOF) {
		if(c>='A' && c<='Z')
			c = c + 'a' - 'A';
		if(pc > 0 && ppc > 0 && c >= 'a' && c <= 'z' && pc >= 'a' && pc <= 'z' && ppc >= 'a' && ppc <= 'z') {
			i = ppc - 'a';
			j = pc - 'a';
			k = c - 'a';
			trigramscount[i*26*26 + j*26 + k]++;
		}
		ppc = pc;
		pc = c;
	}

	int max, t, maxpos;
	char tc;
	for(i=0; i<26*26*26; i++) {
		max = trigramscount[i]; maxpos = i;
		for(j=i+1; j<26*26*26; j++) {
			if(trigramscount[j] > max) {
				max = trigramscount[j];
				maxpos = j;
			}
		}
		if(maxpos != i) {
			t=trigramscount[i]; trigramscount[i] = trigramscount[maxpos]; trigramscount[maxpos]=t;
			tc=trigrams[i][0]; trigrams[i][0] = trigrams[maxpos][0]; trigrams[maxpos][0]=tc;
			tc=trigrams[i][1]; trigrams[i][1] = trigrams[maxpos][1]; trigrams[maxpos][1]=tc;
			tc=trigrams[i][2]; trigrams[i][2] = trigrams[maxpos][2]; trigrams[maxpos][2]=tc;
		}
	}

	printf("top 10 trigrams in order of frequency: ");
	for(i=0; i<10; i++) {
		printf("%c%c%c, ", trigrams[i][0], trigrams[i][1], trigrams[i][2]);
	}
	printf("\n");
}
