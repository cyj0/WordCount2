#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void charCount(char *file);
void wordCount(char *file);
int main(int argc, char*argv[])
{
    //�Բ�������ƥ�䣬��Ϊ"c"��ͳ���ַ���Ŀ����Ϊ"w"��ͳ�Ƶ�����Ŀ�����������򱨴�
    if(!strcmp(argv[1],"-c")){
            charCount(argv[2]);
        }

        else if(!strcmp(argv[1], "-w")){
            wordCount(argv[2]);
        }
        else{
            printf("��������!");
        }
    }
void wordCount(char *file){
	char c; //�������ַ� 
	int flag= 0; // �ϸ��ַ��Ƿ��ǿո�򶺺� 
	int wordCount=0; //������ 
	int i;
	FILE *fp;  
	if((fp=fopen(file,"rb"))==NULL){
		printf("�ļ����ܴ�\n");
		exit(0);  //�������˳� 
	}
	c=fgetc(fp); //��ȡ�ļ���һ���ַ� 
	while(c != EOF){
		if(c==' ' || c==','){
			if(flag==0){
				wordCount++;
			} //��ǰ�ַ�Ϊ�ո�򶺺ţ���ǰһ���ַ����ǿո�򶺺�����Ϊǰ����һ������ 
			flag=1;
		}else{
			flag=0;  
		}
		c=fgetc(fp);  //�����жϺ�����ַ� 
	}
	if(flag==0){
		wordCount++;  //�����һ���ַ����ǿո�򶺺ţ�����Ϊ�ǵ��� 
	}
	printf("��������%d\n",wordCount);
}
void charCount(char *file){
	char c; //�������ַ� 
	int flag= 0; // �ϸ��ַ��Ƿ��ǿո���߶��� 
	int charCount=0;
	int i;
	FILE *fp;
	if((fp=fopen(file,"rb"))==NULL){
		printf("�ļ����ܴ�\n");
		exit(0); //�������˳�
	}
	c=fgetc(fp); //��ȡ�ļ���һ���ַ� 
	while(c != EOF){
		charCount++; // ���з��Ŷ����ַ� 
		c=fgetc(fp); // �����жϺ�����ַ� 
	}
	printf("�ַ�����%d\n",charCount);
}
