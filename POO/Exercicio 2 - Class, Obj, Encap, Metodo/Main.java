import myClass.Aluno;

public class Main {

    public static void main(String[] args) {
        Aluno aluno1 = new Aluno();
        aluno1.setRA(1);
        aluno1.setNome("Nicolas");
        aluno1.setNotaA1(10.0);
        aluno1.setNotaA2(8.5);
        aluno1.setFrequenciaAula(77.77);
        aluno1.CalcularMedia();
        aluno1.ImprimeAluno();
        
        Aluno aluno2 = new Aluno();
        aluno2.setRA(2);
        aluno2.setNome("Daniel");
        aluno2.setNotaA1(2.0);
        aluno2.setNotaA2(9.5);
        aluno2.setFrequenciaAula(8.77);
        aluno2.CalcularMedia();
        aluno2.ImprimeAluno();

        Aluno aluno3 = new Aluno();
        aluno3.setRA(3);
        aluno3.setNome("Lucas");
        aluno3.setNotaA1(10.0);
        aluno3.setNotaA2(9.5);
        aluno3.setFrequenciaAula(51.77);
        aluno3.CalcularMedia();
        aluno3.ImprimeAluno();

        Aluno aluno4 = new Aluno();
        aluno4.setRA(4);
        aluno4.setNome("Diegao da massa");
        aluno4.setNotaA1(2.0);
        aluno4.setNotaA2(3.2);
        aluno4.setFrequenciaAula(43.77);
        aluno4.CalcularMedia();
        aluno4.ImprimeAluno();

        Aluno aluno5 = new Aluno();
        aluno5.setRA(5);
        aluno5.setNome("Mikey");
        aluno5.setNotaA1(2.0);
        aluno5.setNotaA2(7.5);
        aluno5.setFrequenciaAula(75.77);
        aluno5.CalcularMedia();
        aluno5.ImprimeAluno();


    }
  }