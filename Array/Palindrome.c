bool isPalindrome(int x){
    long int palindrome_number=0;
    long int given=x;
    if(x<0)
        return false;
    while(given>0){
        palindrome_number = ((palindrome_number*10) + given%10);
        given = given/10;
    }
    if(palindrome_number == x)
        return true;
    return false;

}