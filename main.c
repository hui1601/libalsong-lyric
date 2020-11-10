#include <openssl/rsa.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
unsigned char c[] =
    "\xdf\xbc\x1f\x3f\x4c\x10\xe1\x7e\x01\x12\xd7\x2e\x78\x91\x6d\xa5\x06\xed\xd5\x7d\xa0\x6e\xac\x6a\xe4\xf0\x0d\xd3\x01\x06\x71\x78\x05\x7b\xaa\x9b\xa9\x4e\xf6\xe6\x65\xbf\xb2\x9c\xee\x56\x7d\xe4\x08\x12\x49\xc0\xbe\x37\x6f\x98\x11\x38\x3c\xe6\xd1\x2b\xad\x74\x4a\x2f\x12\xfc\x16\x18\x9c\x3d\x6e\xc0\x41\x22\x2b\x45\x95\x41\x84\x16\x5f\x37\xd9\x8d\x18\x8e\xd5\xad\x15\x8f\xf8\xb5\x00\x4e\x8e\x71\x7f\x71\x4f\xc9\x62\xab\x7e\xb0\x2d\x58\x48\x19\x60\xd4\xd6\x2f\x09\xc0\xb6\x42\xe4\x96\xec\x70\x3e\xca\x1c"
    "e7K"
    "\xdf\xbc\x1f\x3f\x4c\x10\xe1\x7e\x01\x12\xd7\x2e\x78\x91\x6d\xa5\x06\xed\xd5\x7d\xa0\x6e\xac\x6a\xe4\xf0\x0d\xd3\x01\x06\x71\x78\x05\x7b\xaa\x9b\xa9\x4e\xf6\xe6\x65\xbf\xb2\x9c\xee\x56\x7d\xe4\x08\x12\x49\xc0\xbe\x37\x6f\x98\x11\x38\x3c\xe6\xd1\x2b\xad\x74\x4a\x2f\x12\xfc\x16\x18\x9c\x3d\x6e\xc0\x41\x22\x2b\x45\x95\x41\x84\x16\x5f\x37\xd9\x8d\x18\x8e\xd5\xad\x15\x8f\xf8\xb5\x00\x4e\x8e\x71\x7f\x71\x4f\xc9\x62\xab\x7e\xb0\x2d\x58\x48\x19\x60\xd4\xd6\x2f\x09\xc0\xb6\x42\xe4\x96\xec\x70\x3e\xca\x1c"
    "e7K";
//df bc 1f 3f 4c 10 e1 7e 01 12 d7 2e 78 91 6d a5 06 ed d5 7d a0 6e ac 6a e4 f0 0d d3 01 06 71 78 05 7b aa 9b a9 4e f6 e6 65 bf b2 9c ee 56 7d e4 08 12 49 c0 be 37 6f 98 11 38 3c e6 d1 2b ad 74 4a 2f 12 fc 16 18 9c 3d 6e c0 41 22 2b 45 95 41 84 16 5f 37 d9 8d 18 8e d5 ad 15 8f f8 b5 00 4e 8e 71 7f 71 4f c9 62 ab 7e b0 2d 58 48 19 60 d4 d6 2f 09 c0 b6 42 e4 96 ec 70 3e ca 1c
unsigned char *from;

int main() {
    printf("%s\n", c);
    unsigned char a[4] = "\x01\0\0";
    from = (unsigned char *)malloc(sizeof(unsigned char) * 31);
    sprintf((char *)from, "ALSONG_ANDROID%s", "_20201110_075621");
    printf("%s\n", from);
    RSA *enc = RSA_new();
    RSA_set0_key(enc, BN_bin2bn(c, 256, (BIGNUM *)0x0), BN_bin2bn(a, 3, (BIGNUM *)0x0), (BIGNUM *)0x0);
    RSA_set0_factors(enc, (BIGNUM *)0x0, (BIGNUM *)0x0);
    RSA_set0_crt_params(enc, (BIGNUM *)0x0, (BIGNUM *)0x0, (BIGNUM *)0x0);
    size_t size = RSA_size(enc), flen = strlen((char *)from);
    unsigned char *to = (unsigned char *)malloc(size * sizeof(unsigned char));
    memset(to, 0, size);
    printf("encrypt result: %d\n", RSA_public_encrypt(flen, from, to, enc, 1));
    printf("flen: %ld\n", flen);
    printf("size: %ld\n", size);
    for (int i = 0; i < size; i++) {
        if(!(to[i] / 10)) printf("0");
        printf("%x", to[i]);
    }
    printf("\n");
    RSA_free(enc);
    CRYPTO_cleanup_all_ex_data();
    char arr[] = "2EA8BAB21BA68D71D610F55AE6DB107D7209625E32977507911F503406194E4F9ACB4C2684F101C91CB41215574AB8FD7F24ABBBD37E20DC4B1B00C6117D665ECA8E18FE3990B7A1FF4722BCCA3639EB88C4989F6FACAE9E220D2E3232179621E21C8228EF05BF88CA52BB43659273313FA3303E3BA950E3AD199801A1018448";
    printf("%ld", strlen(arr));
    return 0;
}
/*
D AlsongNDK: C start!!
D AlsongNDK: plainText : ALSONG_ANDROID_20201110_062532
D AlsongNDK: before malloc
D AlsongNDK: before making array
D AlsongNDK: after making array
*/