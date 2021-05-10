#include <stdio.h>

void main() {
	char subst[] = "zyxwvutsrqponmlkjihgfedcba";
	char c;

	while((c = getchar()) != EOF) {
		if(c >= 'A' && c <= 'Z') {
			printf("%c", subst[c - 'A']);
		}
		else if(c >= 'a' && c <= 'z') {
			printf("%c", subst[c - 'a']);
		}
		else if(c >= 32 || c == '\n' || c == '\r') {
			printf("%c", c);
		}
	}
}
