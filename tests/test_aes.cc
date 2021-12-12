#include<string.h>
#include <openssl/evp.h>
#include <openssl/rsa.h>
#include <openssl/engine.h>

#include <openssl/core_names.h>

int main (){

	unsigned char key[32] = {1, 'F', '1', 'B'};
	unsigned char iv[16] = {0, 'C',36, 'A','b','F'};
	
	const unsigned char msg[] = "XXXXXXXdjfakjdjfaueirjadfjaeirtthisAAAAAthisAAAAAthisAAAAAthisAAAAAhisAAAAA is test string";
	// int inLen = 0;
	// inLen = (int) strlen(msg);
	int encLen = 0;
	int outlen = 0;
	unsigned char encData[1024];

	printf("source: %s\n",msg);

	//加密
	EVP_CIPHER_CTX *ctx = NULL;
	EVP_CIPHER *cipher = NULL;
	ctx = EVP_CIPHER_CTX_new();

	cipher = EVP_CIPHER_fetch(NULL, "AES-256-CBC-CTS", NULL);
	EVP_CipherInit_ex(ctx, cipher, NULL, key, iv, 1);
	
	EVP_CipherUpdate(ctx, encData, &outlen, msg, sizeof(msg));
	encLen = outlen;
	EVP_CipherFinal(ctx, encData+outlen, &outlen);
	encLen += outlen;
	EVP_CIPHER_CTX_free(ctx);

	printf("encrypt: %s\n", encData);


	//解密
	int decLen = 0;
	outlen = 0;
	unsigned char decData[1024];
	EVP_CIPHER_CTX *ctx2;
	EVP_CIPHER *cipher2 = NULL;
	ctx2 = EVP_CIPHER_CTX_new();

	cipher2 = EVP_CIPHER_fetch(NULL, "AES-256-CBC-CTS", NULL);
	EVP_CipherInit_ex(ctx2, cipher2, NULL, key, iv, 0);
	
	EVP_CipherUpdate(ctx2, decData, &outlen, encData, encLen);
	decLen = outlen;
	EVP_CipherFinal(ctx2, decData+outlen, &outlen);
	decLen += outlen;
	EVP_CIPHER_CTX_free(ctx2);

	decData[decLen] = '\0';
	printf("decrypt: %s\n",decData);
}
