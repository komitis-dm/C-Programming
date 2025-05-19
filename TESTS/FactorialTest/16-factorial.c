/*
Όνομα: factorial
Είσοδος: Θετικός ακέραιος αριθμός n (τύπου int)
Έξοδος: Ακέραιος a με το αποτέλεσμα του n παραγοντικού (τύπου long int)
Perigrafi: Η συνάρτηση paragontiko χρησιμοποιεί τον αναδρομικό τύπο n!=n*(n-1)!
           και καλεί αναδρομικά τον εαυτό της.
*/
#include <stdio.h>

/* Δήλωση Συνάρτησης */
long int factorial(int n);

main(){
        int n;
    long int a; /* Στη μεταβλητή a αποθηκεύεται το αποτέλεσμα */
    printf("Dwse thetiko akeraio:");
    scanf("%d",&n);
    /* Κλήση συνάρτησης paragontiko */
    a=factorial(n);
    printf("To paragontiko tou %d einai %ld\n",n,a);
    system("pause");
}

/* Επιστρέφει το παραγοντικό ενός ακέραιου αριθμού*/
long int factorial(int n){
    long int a;
    if(n==1) a=1;
    else a=n*factorial(n-1); /* αναδρομική κλήση */
    return a;
}
