/*
Name:anoitowers
Dedomena: Treis pinakes A,B,C poy paristanoun toys styloys kai arxika oi n diskoi
(pou paristanontai me tous arithmous apo 1 ews n) briskontai ston A stylo (pinaka)
se fthinousa seira (diladi katw brisketai o megalyteros diskos).
Apotelesma: Oi n diskoi metafrontai ston C pinaka (stylo) se fthinousa seira
Perigrafi: O algorithmos lynei anadromika to problima twn pyrgwn tou Anoi
*/

#include <stdio.h>
#define N 3

/*Dilwsi synartisis*/
void anoitowers(int A[],int start1,int n,int C[],int start2);

main(){
    int A[]={10,9,8};
    int C[N];
    int i;
    /*klisi synartisis*/
    anoitowers(A,0,N,C,0);
    /* Ektypwsi apotelesmatwn*/
    printf("C=[");
    for(i=0;i<N;i++)
        printf("%d ",C[i]);
    printf("]\n");
    system("pause");
}

/*Synartisi pou lynei anadromika to problima twn pyrgwn Anoi
Arxika o pinakas (stylos) A periexei tous arithmous 1 ews N
se fthinousa seira (diskoi anoi).
start1 einai i prwti trexousa thesi tou pinaka A me arxiki timi 0
n einai to plithos twn diskwn
C einai o pinakas (stylos) opou tha topouthetithous oi diskoi
start2 einai to katw meros tou stylou proorismou C (prwti daithesimi thesi)
*/
void anoitowers(int A[],int start1,int n,int C[],int start2){
    int B[N]; /*Boithitikos stylos(pinakas)*/

    if (n<=1) /* An exei meinei enas diskos to bazoume ston stylo C*/
        C[start2]=A[start1];
    else {
        /* metaferoume olous tous dikous ektos tou prwtou ston boithitiko stylo B*/
        anoitowers(A,start1+1,n-1,B,0);
        /* Ton disko pou emeine apo ton A ton bazoume ston C*/
        C[start2]=A[start1];
        /*Lynoume to problima metaferontas tous ypoloipous diskous apo
        to stylo B ston stylo C*/
        anoitowers(B,0,n-1,C,start2+1);
    }
}
