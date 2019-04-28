#include <stdio.h>

/* substitution cipher text encryption and decryption key */
const char substitution_enc[26] = "QWERTYUIOPASDFGHJKLZXCVBNM";
const char substitution_dec[26] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

/* encrypt msg using rotate cipher */
void rotate_cipher_enc(char msg[], int key) {
    int i = 0;
    while (msg[i] != '\0') {
        //convert lowercase to uppercase
        if (msg[i] >= 'a' && msg[i] <= 'z')
            msg[i] = msg[i] - 'a' + 'A';
        //encrypt
        if (msg[i] >= 'A' && msg[i] <= 'Z') {
            msg[i] = msg[i] + key;
            //check if need to rotate
            if (msg[i] > 'Z')
                msg[i] -= 26;
        }
        i++;
    }
}

/* decrypt msg using rotate cipher */
void rotate_cipher_dec(char msg[], int key) {
    int i = 0;
    while (msg[i] != '\0') {
        //convert lowercase to uppercase
        if (msg[i] >= 'a' && msg[i] <= 'z')
            msg[i] = msg[i] - 'a' + 'A';
        //decrypt
        if (msg[i] >= 'A' && msg[i] <= 'Z') {
            msg[i] = msg[i] - key;
            //check if need to rotate
            if (msg[i] < 'A')
                msg[i] += 26;
        }
        i++;
    }
}

/* encrypt msg using substitution array */
void sub_cipher_enc(char msg[]) {
    int i = 0;
    while (msg[i] != '\0') {
        //convert lowercase to uppercase
        if (msg[i] >= 'a' && msg[i] <= 'z')
            msg[i] = msg[i] - 'a' + 'A';
        //encrypt using substitution
        if (msg[i] >= 'A' && msg[i] <= 'Z') {
            msg[i] = substitution_enc[msg[i] - 'A'];
        }
        i++;
    }
}

/* decrypt msg using substitution array */
void sub_cipher_dec(char msg[]) {
    int i = 0;
    while (msg[i] != '\0') {
        //convert lowercase to uppercase
        if (msg[i] >= 'a' && msg[i] <= 'z')
            msg[i] = msg[i] - 'a' + 'A';
        //decrypt using substitution
        if (msg[i] >= 'A' && msg[i] <= 'Z') {
            msg[i] = substitution_dec[msg[i] - 'A'];
        }
        i++;
    }
}

/* encrypt msg using rotate cipher key=13 */
void rotate_cipher_enc_nkey(char msg[]) {
    rotate_cipher_enc(msg, 13);
}

/* decrypt msg using rotate cipher key=13 */
void rotate_cipher_dec_nkey(char msg[]) {
    rotate_cipher_dec(msg, 13);
}

/* print menu to user */
void menu() {
    printf("\n======================================\n");
    printf("Enter valid choice:\n");
    printf("1. Encrypt a message using rotation cipher\n");
    printf("2. Decrypt a message using rotation cipher\n");
    printf("3. Encrypt a message using rotation cipher no key\n");
    printf("4. Decrypt a message using rotation cipher no key\n");
    printf("5. Encrypt a message using substitution cipher\n");
    printf("6. Decrypt a message using substitution cipher\n");
    printf("7. Exit\n");
    printf(">>>> ");
}

int main() {
    char msg[256]; //define array for message
    int choice; // user choice
    int key; // rotation key
    do {
        //print menu and read choice
        menu();
        scanf("%d", &choice);
        getchar();
        //read message if choice 1-6
        if (choice >= 1 && choice <= 6) {
            printf("Enter message: ");
            int i = 0;
            msg[i] = getchar();
            while (msg[i] != '\n') {
                i++;
                msg[i] = getchar();
            }
            msg[i] = '\0'; // reset line end character
        }
        //switch user choice
        switch (choice) {
            case 1:
                printf("Enter key [0-25]: ");
                scanf("%d", &key);
                rotate_cipher_enc(msg, key); // encrypt
                printf("Encrypted message: %s", msg); //print message
                break;
            case 2:
                printf("Enter key [0-25]: ");
                scanf("%d", &key);
                rotate_cipher_dec(msg, key); // decrypt
                printf("Decrypted message: %s", msg); //print message
                break;
            case 3:
                rotate_cipher_enc_nkey(msg); // encrypt
                printf("Encrypted message: %s", msg); //print message
                break;
            case 4:
                rotate_cipher_dec_nkey(msg); // decrypt
                printf("Decrypted message: %s", msg); //print message
                break;
            case 5:
                sub_cipher_enc(msg); // encrypt
                printf("Encrypted message: %s", msg); //print message
                break;
            case 6:
                sub_cipher_dec(msg); // decrypt
                printf("Decrypted message: %s", msg); //print message
                break;
            case 7: // exit
                break;
        }
    } while (choice != 7);
    return 0;
}
