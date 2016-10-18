// cryptoDemo.cpp : Defines the entry point for the console application.
// Windows: cl cryptoDemo.cpp
// Linux: gcc -o cryptoDemo cryptoDemo.cpp -lcrypto

//陈坦访
//SA15011010
//网络安全 文件加解密程序

#include <memory.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#include "aes.h"

#pragma comment(lib,"libeay32.lib")


int encrypt_file(char inString[], char passwd[],char* enString){

    int i,j, len, nLoop, nRes;
    unsigned char buf[16];
    unsigned char buf2[16];    
    unsigned char aes_keybuf[32];
    AES_KEY aeskey;
    int pwdLen=strlen(passwd);
    int inLen=strlen(inString);

    // 准备32字节(256位)的AES密码字节
    memset(aes_keybuf,0x90,32);

    if(pwdLen<32){ len=pwdLen; } else { len=32;}
    for(i=0;i<len;i++) aes_keybuf[i]=passwd[i];

    // 输入字节串分组成16字节的块	
    nLoop=inLen/16; nRes = inLen%16;
    // 加密输入的字节串
    AES_set_encrypt_key(aes_keybuf,256,&aeskey);
    for(i=0;i<nLoop;i++){
        memset(buf,0,16);
        for(j=0;j<16;j++) 
            buf[j]=inString[i*16+j];
        AES_encrypt(buf,buf2,&aeskey);
        for(j=0;j<16;j++) 
            enString[i*16+j]=buf2[j];
    }
    if(nRes>0){
        memset(buf,0,16);
        for(j=0;j<nRes;j++) 
            buf[j]=inString[i*16+j];
        AES_encrypt(buf,buf2,&aeskey);
        for(j=0;j<16;j++)
            enString[i*16+j]=buf2[j];
        //puts("encrypt");
    }
    enString[i*16+j]=0;

    return 0;
}

int decrypt_file(char enString[], char passwd[],char* deString){

    int i,j, len, nLoop, nRes;
    unsigned char buf[16];
    unsigned char buf2[16];
    unsigned char aes_keybuf[32];
    AES_KEY aeskey;

    int pwdLen=strlen(passwd);
    int inLen=strlen(enString);
    // 准备32字节(256位)的AES密码字节
    memset(aes_keybuf,0x90,32);
    if(pwdLen<32){ len=pwdLen; } else { len=32;}
    for(i=0;i<len;i++) aes_keybuf[i]=passwd[i];
    // 输入字节串分组成16字节的块	
    nLoop=inLen/16; nRes = inLen%16;

    AES_set_decrypt_key(aes_keybuf,256,&aeskey);
    for(i=0;i<nLoop;i++){
        memset(buf,0,16);
        for(j=0;j<16;j++) buf[j]=enString[i*16+j];
        AES_decrypt(buf,buf2,&aeskey);
        for(j=0;j<16;j++) deString[i*16+j]=buf2[j];
    }
    if(nRes>0){
        memset(buf,0,16);
        for(j=0;j<16;j++) buf[j]=enString[i*16+j];
        AES_decrypt(buf,buf2,&aeskey);
        for(j=0;j<16;j++) deString[i*16+j]=buf2[j];
        //puts("decrypt");
    }
    deString[i*16+nRes]=0;

    return 0;
}

int encryptCmd(char cmd[], char inString[], char passwd[],char* res){
    if(0==strcmp(cmd,"enc")){
        encrypt_file(inString, passwd,res);
    }
    else if(0==strcmp(cmd,"dec")){
        decrypt_file(inString, passwd,res);
    }
    return 0;
}




int main(int argc, char* argv[])
{

    char inString[20];	
    char outString[20];
    char filename[200]="inString.txt";
    char passwd[55] = "012345678";

    memset(inString,0,sizeof(inString));
    memset(outString,0,sizeof(outString));

    char cmd[10];

    printf("请输入操作类型(enc or dec): ");
    while(EOF!=scanf("%s",cmd)){
        memset(inString,0,sizeof(inString));
        memset(outString,0,sizeof(outString));
        printf("请输入需要加解密的文件名: ");
        scanf("%s",filename);


        printf("请输入密钥: ");
        scanf("%s",passwd);

        //读取文件
        FILE* infile=fopen(filename,"rb");
        fseek(infile,0,SEEK_END);
        long infile_len=ftell(infile);

        char outfilename[50]="";
        strcpy(outfilename,cmd);
        strcat(outfilename,filename);
        FILE* outfile=fopen(outfilename,"wb");

        //fseek(infile,0,SEEK_SET);
        rewind(infile);
        int block_size=16;
        int nloop=(infile_len)/block_size;
        int nRes=(infile_len)%block_size;
        for(int nloopi=1;nloopi<nloop;nloopi++){
            fread((void*)inString, sizeof(char),block_size,infile);            
            //根据选择进行操作
            encryptCmd(cmd,inString,passwd,outString);
            //写结果
            fwrite((void*)outString, sizeof(char),block_size,outfile);
        }
        
        fread((void*)inString, sizeof(char),block_size,infile);            
        if(!strcmp("enc",cmd)){
            //根据选择进行操作
            encryptCmd(cmd,inString,passwd,outString);
            //写结果
            fwrite((void*)outString, sizeof(char),block_size,outfile);

            if(nRes>0){
                fread((void*)inString, sizeof(char),block_size,infile);            
                //根据选择进行操作
                for(int i=nRes;i<block_size;i++){
                    inString[i]=1;
                }
                encryptCmd(cmd,inString,passwd,outString);
                fwrite((void*)outString, sizeof(char),block_size,outfile);
            }
            printf("加密结果输出在%s文件中\n",outfilename);
        }
        else if(!strcmp("dec",cmd)){
            encryptCmd(cmd,inString,passwd,outString);
            for(int i=0;i<block_size;i++){
                if(outString[i]==1){
                    outString[i]=0;
                    nRes=i;
                    break;
                }
            }
            fwrite((void*)outString, sizeof(char),nRes,outfile);

            printf("加密结果输出在%s文件中\n",outfilename);
        }

        fclose(infile);
        fclose(outfile);


        printf("\n\n请输入操作类型(enc or dec): ");
        system(outfilename);
    }
    system("pause");
    return 0;
}
