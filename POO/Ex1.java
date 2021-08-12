import java.util.Scanner;

public class Ex1 {
    public static void main(String[] args) throws Exception {
        
        Scanner ler = new Scanner(System.in);

        float A1, A2;

        System.out.printf("Informe um número\n");
        A1 = ler.nextFloat();
        System.out.printf("Informe outro número\n");
        A2 = ler.nextFloat();

        System.out.printf("A média do aluno foi : " + (A1 + (2*A2)) / 3);
    }
}
