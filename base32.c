//=================================================_
//  Base32 Encoding and Decoding Algorithm         |_ 
//      Author: HackitMikey [Mikey]                 |_
// (Cli Wizard) base32 algorithm implemented in C.   |_
//     © This tool is based on UTF-8 charset.          |_
//=======================================================


#include<stdio.h>
#include<stdlib.h>
#include"utils.h"

void encode(char*string){

    char five_bit_bin[10], base32_val[400];
    char Ox49_val_bin[10], bin_dump[800];
    int i, j, k, bin_dump_len, ascii_val;

    memreset(Ox49_val_bin, Strlen(Ox49_val_bin));
    memreset(bin_dump, Strlen(bin_dump));

    for(i=0; *(string+i) != '\0'; ++i){
        decToBin(*(string+i), Ox49_val_bin);
		while(Strlen(Ox49_val_bin)%8 != 0){
        	k = insert(Ox49_val_bin, 0, 0x30, Strlen(Ox49_val_bin), sizeof(Ox49_val_bin));
        	Ox49_val_bin[k] = '\0';
    }
        Strcat(bin_dump, Ox49_val_bin);
        memreset(Ox49_val_bin, Strlen(Ox49_val_bin));
    }

    bin_dump_len = Strlen(bin_dump);
    while(bin_dump_len%5 != 0)
        bin_dump_len = insert(bin_dump, bin_dump_len, 0x30, bin_dump_len, sizeof(bin_dump));

    i = 0, j = 0;
    while(*(bin_dump+i)!='\0'){

        bin_dump_len = Strncut(five_bit_bin, bin_dump, 5);
        ascii_val = binToDec(five_bit_bin);
        if(ascii_val>=0x0 && ascii_val<=0x19)
            base32_val[j] = ascii_val+0x41;
        else if(ascii_val>=0x1A && ascii_val<=0x1F)
            base32_val[j] = ascii_val+0x18;
        j++; i = 0;

    }
    base32_val[j] = '\0';
    while(Strlen(base32_val)%4 != 0)
        insert(base32_val, Strlen(base32_val), 0x3d, Strlen(base32_val), sizeof(base32_val));
    printf("%s", base32_val);

}

void decode(char*base32Data){

	int i, j, k, data_len = Strlen(base32Data);
    char bin_dump[500], Ox49_val_bin[10], byte_bin[10], decodeData[100], temp_hold[100];

	while(*(base32Data+(data_len-1)) == 0x3D){
		data_len = delete(base32Data, data_len-1, data_len);
	}

    for(i=0; *(base32Data+i)!=0; ++i){
        
        if(isLower(*(base32Data+i)) || *(base32Data+i)==0x30 || *(base32Data+i)==0x31 || *(base32Data+i)==0x38 || *(base32Data+i)==0x39){
            fprintf(stderr, "Error: Invalid base32 characters");
            exit(1);
        }
    }
    
    if(data_len == 1)
        exit(1);

    memreset(bin_dump, Strlen(bin_dump));

    for(i=0; *(base32Data+i)!=0; ++i){

        if(*(base32Data+i)>=0x42 && *(base32Data+i)<=0x5A){
            decToBin(*(base32Data+i)-0x41, Ox49_val_bin);
        } else if(*(base32Data+i)>=0x32 && *(base32Data+i)<=0x37){
            decToBin(*(base32Data+i)-0x18, Ox49_val_bin);
        } else if(*(base32Data+i) == 0x41)
            Strcpy(Ox49_val_bin, "00000");

        k = Strlen(Ox49_val_bin);
        while(Strlen(Ox49_val_bin)%5 != 0)
            k = insert(Ox49_val_bin, 0, 0x30, k, sizeof(Ox49_val_bin));
        *(Ox49_val_bin+k) = '\0';
        Strcat(bin_dump, Ox49_val_bin);
        memreset(Ox49_val_bin, Strlen(Ox49_val_bin));
    }

    data_len = Strlen(bin_dump);

    while(Strlen(bin_dump)%8 != 0)
        data_len = insert(bin_dump, data_len, 0x30, data_len, sizeof(bin_dump));
    *(bin_dump+data_len) = '\0';

    i = 0, j = 0;
    while(*(bin_dump+i)!='\0'){

        data_len = Strncut(byte_bin, bin_dump, 8);
        *(decodeData+j) = binToDec(byte_bin);
        j++; i = 0;
    }
    *(decodeData+j) = '\0';

    if(*(decodeData)<0x20 || *(decodeData)>0x7e){
        fprintf(stderr, "Error: The string to be decoded is not correctly encoded.");
        exit(1);
    }else if(*(decodeData)>=0x20 && *(decodeData)<=0x7e){
        data_len = Strlen(decodeData);
        for(i=1; *(decodeData+i) != '\0'; ++i){
            if(*(decodeData+i)<0x20 || *(decodeData+i)>0x7e){
                data_len = delete(decodeData, i, data_len);
            }
        }
    }
    Strcpy(temp_hold, decodeData);
    j = 3;
    while((*(temp_hold)>=0x20 && *(temp_hold)<=0x7e)){
        j+=3;
        delete(temp_hold, 0, Strlen(temp_hold));
    }
    if((*(temp_hold)<0x20 || *(temp_hold)>0x7e) && *(temp_hold) != 0x0){
        fprintf(stderr, "Error: Decoded data is not valid UTF-8.\nPartial data after reading %d bytes: %s", j, decodeData);
        exit(1);
    } else 
    printf("%s\n", decodeData);

}

    

int main(int argc, char* argv[]){
	
    if(argc==2){
        if(!Strcmp(argv[1], "--help") || !Strcmp(argv[1], "-h")){
            fprintf(stdout, "\nUsage: %s --<mode> <data>\n|CLI options|:-\
            \n\t<data> = A data string which will be manipulated.\
            \n\t<mode>:\n\t\t-e, --encode = Encodes the data string\
            \n\t\t-d, --decode = Decodes the data string\n\n", argv[0]);
        }
    }else if(argc==3){
		if(!Strcmp(argv[1], "--encode") || !Strcmp(argv[1], "-e")){
			encode(argv[2]);

		} else if(!Strcmp(argv[1], "--decode") || !Strcmp(argv[1], "-d")){
			decode(argv[2]);
		}
	} else{
        fprintf(stderr, "Usage: %s --encode/--decode \"data\"", argv[0]);
    }
}
