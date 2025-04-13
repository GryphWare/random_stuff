#include <stdio.h>
#include <openssl/sha.h>
#include <string.h>
#include <stdlib.h>

void clear(){
    int c;
    while((c = getchar()) != '\n' && c != EOF);
}

void to_hex_string(unsigned char *hash, char *out){
    for(size_t i = 0; i < SHA256_DIGEST_LENGTH; i++){
        sprintf(out + (i * 2), "%02x", hash[i]);
    }
    out[64] = '\0'; // Đảm bảo chuỗi được kết thúc đúng cách
}

int main(void){
    // user have to input user's username
    char *name = NULL;
    size_t len = 0;
    ssize_t read;

    // input
    printf("Nhap user: ");
    read = getline(&name, &len, stdin);

    // xoa \n
    if (read == -1) {
        perror("Khong nhan duoc User nhap gi");
        clear();
        return EXIT_FAILURE;
    }
    name[strcspn(name, "\n")] = '\0';  // Xóa ký tự newline nếu có

    unsigned char hash[SHA256_DIGEST_LENGTH];  // SHA256 sử dụng 32 byte (256 bit)
    char out[65];  // 64 ký tự cho SHA256 và 1 ký tự kết thúc chuỗi

    // SHA256 will hash all word in "name" and store in hash
    SHA256((const unsigned char*)name, strlen(name), hash);

    // this function will executed
    to_hex_string(hash, out);

    // In kết quả băm dưới dạng hexa
    printf("SHA-256 Hash: %s\n", out);

    // Giải phóng bộ nhớ của name
    free(name);

    return EXIT_SUCCESS;
}
