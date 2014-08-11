/* 
 * print_int.c 
 * A system call to print an integer 
 */
#define BUFF 20
void print_int(int n){
    char buff[BUFF], zero='0';
    int i=0, saveN, j, k, bytes;

    saveN = n;
    if(n == 0) buff[i++]=zero;
    else{
       if(n < 0) {
          buff[i++]='-';
          n = -n;
       }
       while(n){
          int dig = n%10;
          buff[i++] = (char)(zero+dig);
          n /= 10;
       }
       if(buff[0] == '-') j = 1;
       else j = 0;
       k=i-1;
       while(j<k){
          char temp=buff[j];
          buff[j++] = buff[k];
          buff[k--] = temp;
       }
    } 
    buff[i]='\n';
    bytes = i+1;

    __asm__ __volatile__ (
          "movl $4, %%eax \n\t"
          "movl $1, %%ebx \n\t"
          "int $128 \n\t"
          :
          :"c"(buff), "d"(bytes)
    ) ;  // $4: write, $1: on stdin
}


