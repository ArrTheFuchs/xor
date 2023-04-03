#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int encrypt(char *input_file, char *key_file){
    int fd_inp = open(input_file, O_RDONLY, 0777);
    char arr[10000];
    int amount_read = read(fd_inp, arr, 10000);
    close(fd_inp);

    int fd_key = open(key_file, O_RDONLY, 0777);
    char key[10000];
    read(fd_key, key, 10000);
    close(fd_key);

    int k = 0; //index for key
    int i = 0; //index for text
    int fd_out = open("output_file", O_CREAT|O_WRONLY, 0777);

    char final[amount_read];
    while(i < amount_read){
        if(key[k]){
            arr[i] ^= key[k];
            printf("%c", arr[i]);

            i++;
            k++;
        }
        else{
            k = 0;
        }
    }
    printf("\n");
    write(fd_out, arr, amount_read);
    close(fd_out);

}
int main(int argc, char *argv[]){
    encrypt(argv[1], argv[2]);

}
