#include<stdio.h>
#include<string.h>

void parse(char *string){
    int inside=0,index=0;
    for (int  i = 0; i < strlen(string); i++)
    {
        if(string[i] == '<')
        {
            inside = 1;
            continue;
        }
        else if(string[i] == '>')
        {
            inside = 0;
            continue;
        }

        if(inside == 0)
        {
            string[index] = string[i];
            index++;
        }   
    }
    string[index] = '\0';
    while(string[0] == ' ')
    {
       for (int i = 0; i < strlen(string); i++)
       {
           string[i] = string[i+1];
       }
       
    }

    while(string[strlen(string) - 1] == ' '){
        string[strlen(string) - 1] = '\0';
    }
}

int main(){
    char string[100];
    printf("Enter the HTML CODE : ");
    gets(string);
    parse(string);
    printf("My string : %s ",string);
    return 0;
}