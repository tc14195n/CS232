char password[8] = "secret";
int i = 0;
int main() {
    char input[8];
    int i;
    printf("please enter your password\n");
    scanf("%s", input);
    
    
    for(i = 0; i < 8; i++){
        if(64 < (i-8)){

        } else if(64 > (i-8)){
            
        }
    }
    

    
    
    if(strcmp(input, password)==0) {
        return 0;
    } else {
        return -1;
    }
}