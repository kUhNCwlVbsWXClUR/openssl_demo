#include <openssl/evp.h>
#include <stdio.h>


// https://my.oschina.net/zmlblog/blog/209017
// https://www.shangmayuan.com/a/7fd9b80f9ae847708746e58c.html

// 编码方式一
int main1(){
	EVP_ENCODE_CTX * ectx = NULL;
	ectx = EVP_ENCODE_CTX_new();

	int outl = 0;
	unsigned char out[800];
	unsigned char in[] = "347814 3143";

	// 编码

	EVP_EncodeInit(ectx);

	EVP_EncodeUpdate(ectx, out, &outl, in, sizeof(in));

	EVP_EncodeFinal(ectx, out+outl, &outl);

	printf("out  = %s\n", out);

	// 解码
	unsigned char out2[800];
	unsigned char in2[] = "MzE3ODM0YWZqa2ExMzc0OGFrZGZrOw==";
	int out2l = 0;
	EVP_ENCODE_CTX *dctx = NULL;
	dctx = EVP_ENCODE_CTX_new();
	EVP_DecodeInit(dctx);

	EVP_DecodeUpdate(dctx, out2, &out2l, in2, sizeof(in2));

	EVP_DecodeFinal(dctx, out2+out2l, &out2l);

	printf("out2 = %s\n", out2);


	return 0;
}

// 编码方式二
int main(){
	unsigned char msg[]  = "3143143";

	int encoded_length = sizeof(msg);
	unsigned char base64msg[100] = {0};

	// 编码
	EVP_EncodeBlock((unsigned char*)base64msg, (const unsigned char*)msg, encoded_length);
	printf("%s\n", base64msg);

	// 解码
	unsigned char out[100] = {0};
	EVP_DecodeBlock((unsigned char*)out, (const unsigned char*)base64msg, sizeof(base64msg));
	printf("%s\n", out);

}
