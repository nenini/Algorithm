#include<stdio.h>
#include<string.h>
char word[1000000];
int count[26]={0};
int num;
int max=0;
char result;
int main(void)
{
    scanf("%s", word);
    int len = strlen(word);
    for (int i = 0; i < len;i++){
        if(word[i]>='A'&&word[i]<='Z'){
            num = word[i] - 'A';
            count[num]++;
        }
        if(word[i]>='a'&&word[i]<='z'){
            num = word[i] - 'a';
            count[num]++;
        }
    }
    for (int i = 0; i<26;i++){
        if(max<count[i]){
            max = count[i];
            result = i + 'A';
        }
        else if(max==count[i]){
            result = '?';
        }
    }
    printf("%c\n", result);
}