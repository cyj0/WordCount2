#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void charCount(char *file);
void wordCount(char *file);
int main(int argc, char*argv[])
{
    //对参数进行匹配，若为"c"则统计字符数目，若为"w"则统计单词数目，若都不是则报错
    if(!strcmp(argv[1],"-c")){
            charCount(argv[2]);
        }

        else if(!strcmp(argv[1], "-w")){
            wordCount(argv[2]);
        }
        else{
            printf("参数错误!");
        }
    }
void wordCount(char *file){
	char c; //读到的字符 
	int flag= 0; // 上个字符是否是空格或逗号 
	int wordCount=0; //单词数 
	int i;
	FILE *fp;  
	if((fp=fopen(file,"rb"))==NULL){
		printf("文件不能打开\n");
		exit(0);  //出错则退出 
	}
	c=fgetc(fp); //获取文件第一个字符 
	while(c != EOF){
		if(c==' ' || c==','){
			if(flag==0){
				wordCount++;
			} //当前字符为空格或逗号，若前一个字符不是空格或逗号则认为前面有一个单词 
			flag=1;
		}else{
			flag=0;  
		}
		c=fgetc(fp);  //继续判断后面的字符 
	}
	if(flag==0){
		wordCount++;  //若最后一个字符不是空格或逗号，则认为是单词 
	}
	printf("单词数：%d\n",wordCount);
}
void charCount(char *file){
	char c; //读到的字符 
	int flag= 0; // 上个字符是否是空格或者逗号 
	int charCount=0;
	int i;
	FILE *fp;
	if((fp=fopen(file,"rb"))==NULL){
		printf("文件不能打开\n");
		exit(0); //出错则退出
	}
	c=fgetc(fp); //获取文件第一个字符 
	while(c != EOF){
		charCount++; // 所有符号都算字符 
		c=fgetc(fp); // 继续判断后面的字符 
	}
	printf("字符数：%d\n",charCount);
}
