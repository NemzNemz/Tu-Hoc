/*
void pointer and Casting
You are writing a utility function that adds two values — but the values can be either:
int, or
float
You will be given void* pointing to the first and second value and a 
char type specifier: 'i' for int, 'f' for float.
Your task is to:
Cast the void* to appropriate type based on the specifier
Perform the addition
Print the result (as integer or float)
Use proper void* casting and dereferencing logic
*/
#include <stdio.h>

void add_and_print(void *a, void *b, char type) {
    switch(type){
        case 'i':
        {
            int *ptr_int_a;
            int *ptr_int_b;
            ptr_int_a = (int*)a;
            ptr_int_b = (int*)b;
            printf("%d", *(ptr_int_a) + *(ptr_int_b));
        }
        break;

        case 'f':
        {
            float *ptr_f_a;
            float *ptr_f_b;
            ptr_f_a = (float*)a;
            ptr_f_b = (float*)b;
            printf("%.1f", *(ptr_f_a) + *(ptr_f_b));
        }
        break;
        
        default:
            printf("Nah ah");
        break;
    }
}

int main() {
    char type;
    scanf(" %c", &type);

    if (type == 'i') {
        int x, y;
        scanf("%d %d", &x, &y);
        add_and_print(&x, &y, type);
    } else if (type == 'f') {
        float x, y;
        scanf("%f %f", &x, &y);
        add_and_print(&x, &y, type);
    }

    return 0;
}