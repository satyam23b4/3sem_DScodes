#include<stdio.h>
void main()
{
    char a[]="Gur cnffjbeq vf WIAOOSFzMjXXBC0KoSKBbJ8puQm5lIEi";
    int i=0;
    while(a[i]!='\0')
    {
        if(a[i]==' ')
        {
            i++;
            continue;
        }
        else if(a[i]>='a' && a[i]<= 'z')
        {
            a[i]=(a[i]-'a'+13)%26 + 'a';
        }
        else if(a[i]>='A' && a[i]<='Z')
        {
            a[i]=(a[i]-'A'+13)%26 + 'A';
        }
        i++;
    }
    printf("%s", a);
}
