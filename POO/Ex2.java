import java.util.Scanner;

public class Ex2 {
    public static void main(String[] args) throws Exception {
        
        Scanner ler2 = new Scanner(System.in);

        float A1, A2, Media;
        int Presenca;
        
        System.out.printf("Informe sua presença\n");
        Presenca = ler2.nextInt();
        System.out.printf("Informe um número\n");
        A1 = ler2.nextFloat();
        System.out.printf("Informe outro número\n");
        A2 = ler2.nextFloat();
        Media = ((A1 + (2*A2)) / 3);

        System.out.printf("A média do aluno foi : " + Media + "\n");

        if((Presenca>=75) && Media >=5 ){
            System.out.printf("Aprovado\n");
        }else if((Presenca>=75) && 3<=Media && Media <5){
            System.out.printf("RE\n");
        }else{
            System.out.printf("Reprovado\n");
        }
    }
        
    
}
