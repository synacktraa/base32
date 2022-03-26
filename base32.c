//=================================================_
//  Base32 Encoding and Decoding Algorithm         |_ 
//      Author: SynAcktraa [Mikey]                  |_
// (Cli Wizard) base32 algorithm implemented in C.   |_
//     © This tool is based on ASCII charset.         |_
//=======================================================


#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"base32_utils.h"


void encode(char*string){

    int string_len = Strlen(string);

    int base32_val_space = (0.65*(string_len+1))+string_len+2;
    int bin_dump_space = (string_len * 8)+1;

    char *base32_val = (char*)malloc(sizeof(char) * base32_val_space);
    char *bin_dump = (char*)malloc(sizeof(char) * bin_dump_space);

    char five_bit_bin[10], Ox49_val_bin[10];

    int i, j, k, bin_dump_len;

    memset(Ox49_val_bin, 0, Strlen(Ox49_val_bin));
    memset(bin_dump, 0, Strlen(bin_dump));

    for(i=0; *(string+i) != '\0'; ++i){
        strcpy(Ox49_val_bin, decToBin(*(string+i)));
		while(Strlen(Ox49_val_bin)%8 != 0){
        	k = insert(Ox49_val_bin, 0, '0', Strlen(Ox49_val_bin), Strlen(Ox49_val_bin)+1);
        	Ox49_val_bin[k] = '\0';
    }
        strcat(bin_dump, Ox49_val_bin);
        memset(Ox49_val_bin, 0, Strlen(Ox49_val_bin));
    }

    bin_dump_len = Strlen(bin_dump);
    while(bin_dump_len%5 != 0)
        bin_dump_len = insert(bin_dump, bin_dump_len, '0', bin_dump_len, Strlen(bin_dump)+1);

    i = 0, j = 0;
    while(*(bin_dump+i)!='\0'){

        memset(five_bit_bin, 0, Strlen(five_bit_bin));
        memmove(five_bit_bin, bin_dump+i, 5);
        int ascii_val = binToDec(five_bit_bin);
        if(ascii_val>=0 && ascii_val<=25)
            base32_val[j] = ascii_val+65;
        else if(ascii_val>=26 && ascii_val<=31)
            base32_val[j] = ascii_val+24;
        j++; i += 5;

    }
    base32_val[j] = '\0';
    free(bin_dump);

    while(Strlen(base32_val)%4 != 0)
        insert(base32_val, Strlen(base32_val), 0x3d, Strlen(base32_val), base32_val_space);
    fwrite(base32_val, 1, Strlen(base32_val), stdout);
    free(base32_val); 


}


void decode(char*base32Data){

    int i, j, data_len = Strlen(base32Data);

    int decData_val_space = (data_len+2)-(0.12*data_len);
    int bin_dump_space = (data_len * 6)+1;

    char Ox49_val_bin[10], byte_bin[10];
    char *bin_dump = (char*)malloc(sizeof(char) * bin_dump_space);
    char *decodeData = (char*)malloc(sizeof(char) * decData_val_space);

	while(*(base32Data+(data_len-1)) == 0x3D){
		data_len = delete(base32Data, data_len-1, data_len);
	}

    if(data_len == 1)
        exit(1);

    for(i=0; base32Data[i]!=0; ++i){
        
        if(isLower(base32Data[i]) || base32Data[i]=='0' || 
        base32Data[i]==0x31 || base32Data[i]==0x38 || base32Data[i]==0x39){
            fprintf(stderr, "Error: Invalid base32 characters\n");
            exit(1);
        }
    }
    
    memset(bin_dump, 0, Strlen(bin_dump));
    memset(Ox49_val_bin, 0, Strlen(Ox49_val_bin));

    for(i=0; base32Data[i]!=0; ++i){

        if(base32Data[i]>='B' && base32Data[i]<='Z'){
            strcpy(Ox49_val_bin, decToBin(base32Data[i]-65));
        } else if(base32Data[i]>='2' && base32Data[i]<='7'){
            strcpy(Ox49_val_bin, decToBin(base32Data[i]-24));
        } else if(base32Data[i] == 'A')
            strcpy(Ox49_val_bin, "00000");


        int k = Strlen(Ox49_val_bin);
        while(Strlen(Ox49_val_bin)%5 != 0)
            k = insert(Ox49_val_bin, 0, '0', k, sizeof(Ox49_val_bin));
        Ox49_val_bin[k] = '\0';

        strcat(bin_dump, Ox49_val_bin);
        memset(Ox49_val_bin, 0, Strlen(Ox49_val_bin));
    }

    int bin_dump_len = Strlen(bin_dump);

    while(Strlen(bin_dump)%8 != 0)
        bin_dump_len = insert(bin_dump, bin_dump_len, '0', bin_dump_len, bin_dump_space);
    *(bin_dump+bin_dump_len) = '\0';

    i = 0, j = 0;
    while(*(bin_dump+i)!='\0'){

        memset(byte_bin, 0, Strlen(byte_bin));
        memmove(byte_bin, bin_dump+i, 8);
        decodeData[j] = binToDec(byte_bin);
        j++; i += 8;
    }
    decodeData[j] = '\0';
    free(bin_dump);

    if(*(decodeData) < ' ' || *(decodeData) > '~'){
        fprintf(stderr, "Error: The string to be decoded is not correctly encoded.\n");
        exit(1);

    } else {
        data_len = Strlen(decodeData);
        for(i=1; decodeData[i] != '\0'; ++i){
            if(decodeData[i]< ' ' || decodeData[i]> '~'){
                data_len = delete(decodeData, i, data_len);
            }
        }
    }
    fputs(decodeData, stdout);
    free(decodeData);
    exit(0);


}
int main(int argc, char**argv){
	
    if(argc==2){
        if(!strcmp(argv[1], "-h")){
            fprintf(stdout, "\nNote: Put space separated data in quotes.\
            \nUsage: %s -e/-d <data>\n|CLI options|:-\
            \n\t-e - Encodes the data string\
            \n\t-d - Decodes the data string\n", basename(argv[0]));

        }
    }else if(argc==3){
		if(!strcmp(argv[1], "-e")){
			encode(argv[2]);
		} else if(!strcmp(argv[1], "-d")){
			decode(argv[2]);
		}
	} else{
        fprintf(stderr, "\nUsage: %s -e/-d <data>\
        \nFor more, check help section:\
        \n    %s -h\n\n", basename(argv[0]), basename(argv[0]));
    }
}

