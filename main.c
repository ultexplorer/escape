#include <stdio.h>

#define LIM 10

void strbuild(char s1[]);
void str_copy(char s2[], char s1[]);
void escape(char s[], char t[]);

int main()
{
    char str1[LIM] = " ";
    char str2[LIM] = " ";
    char str3[LIM] = " ";
    
    strbuild(str1);      
    
    printf("%s\n", str1);

    str_copy(str2,str1); 

    printf("%s\n", str2);
    
    escape(str3, str2);

    printf("%s\n", str3);
    
    return 0;
}

void strbuild(char s1[]){
    int c, i;
    c=i=0;
    while((c=getchar())!=EOF && i<LIM-1)
    {
        s1[i]=c;
        i++;        
    }
    s1[i]='\0';
}

void str_copy(char s2[], char s1[])
{
    int i;
    while(s2[i++]=s1[i])
    {
        if(i==LIM-1){
           s2[i+1]='\0';
           break;
        }
    }
    /*if(i<LIM){
        s2[i+2]='\0';
    }*/
}

void escape(char s[], char t[]){
    int i, j;
    for(i=j=0; t[i]!='\0'; i++, j++){
        switch (t[i])
        {
        case '\t':
            s[j++]='\\';
            s[j]='t';
            break;
        case '\n':
            s[j++]='\\';
            s[j]='n';
            break;
        
        default:
            s[j]=t[i];
            break;
        }
    }
    if(j<(LIM-1)){
        s[LIM-1]='\0';
    }    
}