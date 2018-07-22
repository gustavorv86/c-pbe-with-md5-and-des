
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "pbe_md5_des.h"

#define STR_SIZE 512

int main() {

	char * pass;
	char * orig;
	char * dest;
	size_t len_orig;
	
	pass = calloc(STR_SIZE, sizeof(char));
	strncpy(pass, "pA5sW0rD", STR_SIZE);
	
	orig = calloc(STR_SIZE, sizeof(char));
	strncpy(orig, "Hello, this is a PBE with MD5 and DES test example.", STR_SIZE);
	printf("original text (%ld): '%s'\n", strlen(orig), orig);
	
	dest = pbe_md5_des_encrypt(orig, strlen(orig), pass, strlen(pass), &dest);
	if(dest != NULL) {
		printf("encode (%ld): '%s'\n", strlen(dest), dest);
	} else {
		printf("ERROR: cannot encrypt message\n");
		return 1;
	}
	
	free(orig);
	
	strncpy(pass, "BaD_pA5sW0rD", STR_SIZE);
	orig = pbe_md5_des_decrypt(dest, pass, strlen(pass), &orig, &len_orig);
	if(orig != NULL) {
		printf("decode with bad password (%ld): '%s'\n", strlen(orig), orig);
		free(orig);
	}
	
	strncpy(pass, "pA5sW0rD", STR_SIZE);
	orig = pbe_md5_des_decrypt(dest, pass, strlen(pass), &orig, &len_orig);
	if(orig != NULL) {
		printf("decode with good password (%ld): '%s'\n", strlen(orig), orig);
		free(orig);
	}
	
	free(dest);
	free(pass);
	
	return (EXIT_SUCCESS);
}
