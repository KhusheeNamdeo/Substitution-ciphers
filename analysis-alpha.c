#include <stdio.h>

void main() {
	int alphacount[26];
	char alpha[26];
	int i;
	char c;

	// initialize arrays to count the alphabets
	for(i=0; i<26; i++) {
		alphacount[i] = 0;
		alpha[i] = 'a' + i;
	}

	// read the input
	while((c=getchar()) != EOF) {
		if(c>='a' && c<='z')
			alphacount[c-'a']++;
		if(c>='A' && c<='Z') 
			alphacount[c-'A']++;
	}

	int max, j, t, maxpos;
	char tc;
	for(i=0; i<26; i++) {
		max = alphacount[i]; maxpos = i;
		for(j=i+1; j<26; j++) {
			if(alphacount[j] > max) {
				max = alphacount[j];
				maxpos = j;
			}
		}
		if(maxpos != i) {
			t=alphacount[i]; alphacount[i] = alphacount[maxpos]; alphacount[maxpos]=t;
			tc=alpha[i]; alpha[i] = alpha[maxpos]; alpha[maxpos]=tc;
		}
	}

	printf("alphabets in order of frequency: ");
	for(i=0; i<26; i++) {
		printf("%c", alpha[i]);
	}
	printf("\n");
}
