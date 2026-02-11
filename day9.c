#include <stdio.h>
#include <string.h>


void mirror(char str[], int start, int end) {
    if (start >= end)
        return;

    
    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;

    
    mirror(str, start + 1, end - 1);
}

int main() {
    char str[100];
    scanf("%s", str);

    int len = strlen(str);
    mirror(str, 0, len - 1);

    printf("%s", str);
    return 0;
}
