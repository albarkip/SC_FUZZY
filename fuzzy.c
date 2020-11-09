// kodingan ini dibuat oleh:
//             = Albari Berki Pradhana (1806384)
//             = Adithya Kurniawan (1804814)

#include <stdio.h>
#include <string.h>

int main(){
    float suhu[5] = {0, 10, 20, 30, 40};
    float speedKipas[5] = {0, 55, 115, 175, 255};
    float derajat[5] = {0.00,0.00,0.00,0.00,0.00};
    char rule1[34] = "Jika terlalu dingin maka berhenti";
    char rule2[38] = "Jika agak dingin maka bergerak lambat";
    char rule3[33] = "Jika normal maka bergerak sedang";
    char rule4[36] = "Jika agak panas maka bergerak cepat";
    char rule5[42] = "Jika terlalu panas maka bergerak maksimal";
    float suhuInput;
    
    printf("Suhu saat ini : ");
    scanf("%f", &suhuInput);

    printf("\n===================\nDerajat Keanggotaan\n-------------------\n%.1f = [", suhuInput);
    //Derajat keanggotaan 1
    if(suhuInput <= suhu[0]){
        derajat[0] = 1;
        printf("%.1f, ", derajat[0]);
    }
    if(suhuInput > suhu[0] && suhuInput < suhu[1]){
        float pembilang = suhu[1] - suhuInput;
        float penyebut = suhu[1] - suhu[0];
        derajat[0] = pembilang / penyebut;
        printf("%.1f, ", derajat[0]);
    }
    if(suhuInput >= 0){
        printf("%.1f, ", derajat[0]);
    }


    //Derajat Keanggotaan 2
    if(suhuInput > suhu[0] && suhuInput <= suhu[1]){
        float pembilang = suhuInput - suhu[0];
        float penyebut = suhu[1] - suhu[0];
        derajat[1] = pembilang / penyebut;
        printf("%.1f, ", derajat[1]);
    }
    if(suhuInput > suhu[1] && suhuInput < suhu[2]){
        float pembilang = suhu[2] - suhuInput;
        float penyebut = suhu[2] - suhu[1];
        derajat[1] = pembilang / penyebut;
        printf("%.1f, ", derajat[1]);
    }
    if(suhuInput >= suhu[2] || suhuInput <= suhu[0]){
        printf("%.1f, ", derajat[1]);
    }


    //Derajat Keanggotaan 3
    if(suhuInput > suhu[1] && suhuInput <= suhu[2]){
        float pembilang = suhuInput - suhu[1];
        float penyebut = suhu[2] - suhu[1];
        derajat[2] = pembilang / penyebut;
        printf("%.1f, ", derajat[2]);
    }
    if(suhuInput > suhu[2] && suhuInput < suhu[3]){
        float pembilang = suhu[3] - suhuInput;
        float penyebut = suhu[3] - suhu[2];
        derajat[2] = pembilang / penyebut;
        printf("%.1f, ", derajat[2]);
    }
    if(suhuInput >= suhu[3] || suhuInput <= suhu[1]){
        printf("%.1f, ", derajat[2]);
    }


    //Derajat Keanggotaan 4
    if(suhuInput > suhu[2] && suhuInput <= suhu[3]){
        float pembilang = suhuInput - suhu[2];
        float penyebut = suhu[3] - suhu[2];
        derajat[3] = pembilang / penyebut;
        printf("%.1f, ", derajat[3]);
    }
    if(suhuInput > suhu[3] && suhuInput < suhu[4]){
        float pembilang = suhu[4] - suhuInput;
        float penyebut = suhu[4] - suhu[3];
        derajat[3] = pembilang / penyebut;
        printf("%.1f, ", derajat[3]);
    }
    if(suhuInput >= suhu[4] || suhuInput <= suhu[2]){
        printf("%.1f, ", derajat[3]);
    }


    //Derajat Keanggotaan 5
    if(suhuInput >= suhu[4]){
        derajat[4] = 1;
        printf("%.1f]\n", derajat[4]);
    }
    if(suhuInput > suhu[3] && suhuInput < suhu[4]){
        float pembilang = suhu[4] + suhuInput;
        float penyebut = suhu[4] - suhu[3];
        derajat[4] = pembilang / penyebut;
        printf("%.1f]\n", derajat[4]);
    }
    if(suhuInput <= suhu[3]){
        printf("%.1f]\n", derajat[4]);
    }

    //===============defuzzification=================
    int i;
    int stop = 0;
    int count = 0;
    int status = 0;
    int num1 = 0, num2 = 0, stop2 = 0;

    for(i = 0; i < 5; i++){
        if(derajat[i] == 1 && stop == 0){
            count = i;
            stop = 1;
            status = 1;
        }else if(stop != 1 && derajat[i] > 0){
            if(stop2 == 0){
                num1 = i;
                stop2 = 1;
            }else{
                num2 = i;
                stop = 1;
            }
        }
    }
    printf("\n================================\nRule yang berlaku :\n");
    if(num1 == 0 || num2 == 0){
        printf("    -%s\n", rule1);
    }
    if(num1 == 1 || num2 == 1){
        printf("    -%s\n", rule2);
    }
    if(num1 == 2 || num2 == 2){
        printf("    -%s\n", rule3);
    }
    if(num1 == 3 || num2 == 3){
        printf("    -%s\n", rule4);
    }
    if(num1 == 4 || num2 == 4){
        printf("    -%s\n", rule5);
    }


    if(status == 0){
        // printf("======================\nAverage Weight\n----------------------\n");
        float pembilang1 = derajat[num1] * speedKipas[num1];
        float pembilang2 = derajat[num2] * speedKipas[num2];
        float pembilang = pembilang1 + pembilang2;
        float penyebut = derajat[num1] + derajat[num2];
        float z = pembilang / penyebut;

        printf("================================\n\n+-------------------------+\nkecepatan kipas : %.0f rpm\n+-------------------------+\n", z);
    }else{
        printf("================================\n\n+-------------------------+\nkecepatan kipas : %.0f rpm\n+-------------------------+\n", speedKipas[count]);
    }

    return 0;
}