//Ask1 One time pad 
char *key_gen(int length);
char *one_time_pad_encr(char *plaintext, char *key, int length);
char *one_time_pad_decr(char *ciphertext, char *key, int length);

//Ask2 Affine
char *affine_encr(char *plaintext);
char *affine_decr(char *ciphertext);

//Ask4 Trithemius
char *trithemius_encr(char *plaintext);
char *trithemius_decr(char *ciphertext);

//Ask5 Scytale
char *scytale_encr(char *plaintext, int rod_diam);
char *scytale_decr(char *ciphertext, int rod_diam);

//Ask6 Rail Fence
char *rail_fence_encr(char *plaintext, int rails);
char *rail_fence_decr(char *ciphertext, int rails);

