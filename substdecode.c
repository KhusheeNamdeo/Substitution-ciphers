#include <stdio.h>

void computeranks(int count, int freq[], int rank[], int topten[]) {
	int i, j;
	for(i = 0; i < count; i++) {
		for(j = 0; j < count; j++) {
			if(i != j)
				if(freq[j] < freq[i])
					rank[i]++;
		}
	}
	for(i = 0; i < count; i++) {
		if(rank[i] >= count - 10)
			topten[count - rank[i] - 1] = i;
	}
}

void main() {
	int topalpha[10];
	int topbigram[10];
	int toptrigram[10];
	int inputalphafreq[26], inputalpharank[26];
	int inputbigramfreq[26*26], inputbigramrank[26*26];
	int inputtrigramfreq[26*26*26], inputtrigramrank[26*26*26];
	char data[100000], c, pc, ppc;
	int i, j, k, datacount;

	for(i = 0; i < 26; i++) {
		inputalphafreq[i] = 0;
		inputalpharank[i] = 0;
		for(j = 0; j < 26; j++) {
			inputbigramfreq[i*26+j] = 0;
			inputbigramrank[i*26 + j] = 0;
			for(k = 0; k < 26; k++) {
				inputtrigramfreq[i*26*26 + j*26 + k] = 0;
				inputtrigramrank[i*26*26 + k*26 + k] = 0;
			}
		}
	}

	i = 0;
	pc = 0; ppc = 0;
	while((c = getchar()) != EOF) {
		data[i++] = c;
		if(c >= 'a' && c <= 'z') {
			inputalphafreq[c - 'a']++;
			if(pc > 0 && pc >= 'a' && pc <= 'z') {
				inputbigramfreq[(pc - 'a')*26 + c - 'a']++;
				if(ppc > 0 && ppc >= 'a' && ppc <= 'z') {
					inputtrigramfreq[(ppc - 'a')*26*26 + (pc - 'a')*26 + c - 'a']++;
				}
			}
		}
		ppc = pc;
		pc = c;
	}
	datacount = i;

	computeranks(26, inputalphafreq, inputalpharank, topalpha);
	computeranks(26*26, inputbigramfreq, inputbigramrank, topbigram);
	computeranks(26*26*26, inputtrigramfreq, inputtrigramrank, toptrigram);

	printf("top ten alphabets:\t");
	for(i = 0; i < 10; i++)
		printf(" %c  ", topalpha[i] + 'a');
	printf("\n\t\t\t[e] [a   t] [i   o   n] [s   r   h] [l   d]\n");

	printf("\ntop ten bigrams:\t");
	for(i = 0; i < 10; i++)
		printf(" %c%c  ", topbigram[i] / 26 + 'a', topbigram[i] % 26 + 'a');
	printf("\n\t\t\t[th] [he   in] [an   er   on] [re   ed   nd   ou]\n");
	
	printf("\ntop ten trigrams:\t");
	for(i = 0; i < 10; i++)
		printf(" %c%c%c  ", toptrigram[i] / (26*26) + 'a', 
			(toptrigram[i] - (toptrigram[i] / (26*26)) * 26*26) / 26 + 'a', toptrigram[i] % 26 + 'a');
	printf("\n\t\t\t[the] [ing   and] [ion   hat] [tha] [ent] [tio]\n");



//	for(i = 0; i < datacount; i++) {
//		if(data[i] >= 'a' && data[i] <= 'z') {
//			printf("%c", alphafreq[25 - inputrank[data[i] - 'a']]);
//		}
//		else {
//			printf("%c", data[i]);
//		}
//	}

}
