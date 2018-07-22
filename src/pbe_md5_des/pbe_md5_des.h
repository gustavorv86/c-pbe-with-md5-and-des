
#ifndef PBE_H
#define PBE_H

#include <stdio.h>

/**
 * Encrypt for PBEWithMD5AndDES
 * <br><br>
 * <b>Note: </b>Remember to free "out"
 *
 * @param *msg message for encrypt
 * @param msg_len lenght of msg
 * @param *passwd password for encrypt
 * @param passwd_len lenght of password
 * @param **out pointer to encrypt buffer, malloc() during encryption
 *
 * @return *out, which is encrypt Base64 string or NULL if failed
 */
char * pbe_md5_des_encrypt(char *msg, size_t msg_len, char *passwd, size_t passwd_len, char **out);

/**
 * Decrypt for PBEWithMD5AndDES
 * <br><br>
 * <b>Note: </b>Remember to free "out"
 *
 * @param *str Encrypt Base64 string, terminated with '\0'
 * @param *passwd password for decrypt
 * @param passwd_len lenght of password
 * @param **out pointer to decrypt buffer, terminated with '\0' (*out[*len], won't affect content) malloc() during decryption
 * @param *len length of out, set to 0 if failed
 *
 * @return *out, which points to buffer or NULL if failed
 */
char * pbe_md5_des_decrypt(char *str, char *passwd, size_t passwd_len, char **out, size_t *len);

#endif
