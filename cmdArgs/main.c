#include<stdio.h>
#include<string.h>

int main(int argc, char *argv[])
{
    int max=0, pos=0, count;
    for(count=1; count<argc; count++)
    {
        if(strlen(argv[count])>max)
        {
            max=strlen(argv[count]);
            pos=count;
        }
    }

    printf("\n Task #1 \n %s\n", argv[pos]);

    pos=0;
    count=0;
    int maxVow=0;
    for(count=1;count<argc;count++)
    {
        int c2, maxTemp=0;
        for(c2=0;c2<strlen(argv[count]);c2++)
        {
            char *str=argv[count];
            if((int)str[c2]=='a'||(int)str[c2]=='e'||(int)str[c2]=='i'||(int)str[c2]=='o'||(int)str[c2]=='u'||(int)str[c2]=='A'||(int)str[c2]=='E'||(int)str[c2]=='I'||(int)str[c2]=='O'||(int)str[c2]=='U')
            {
                maxTemp++;
            }
        }
        if(maxTemp>maxVow)
        {
            maxVow=maxTemp;
            pos=count;
        }
    }

    printf("\n Task # 2 \n %s\n", argv[pos]);
    return 0;
}