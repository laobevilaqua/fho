import myClass.Data;

public class Main {

    public static void main(String[] args) {
      System.out.println("\nData manual");
      Data dataManual = new Data(25, 12, 2021);
      dataManual.apresentaData(true);

      System.out.println("\nData do sistema");
      Data dataAtual = new Data();
      dataAtual.apresentaData(true);

      System.out.println("\nData cujo pula 1 dia");
      Data dataProximoAno = new Data(31, 12, 2021);
      dataProximoAno.apresentaData();
      dataProximoAno.pularDia();
      dataProximoAno.apresentaData();

      System.out.println("\nData pulando 4 dias");
      Data dataAddDia = new Data(29, 12, 2021);
      dataAddDia.apresentaData();
      dataAddDia.adicionarDias(4);
      dataAddDia.apresentaData();

    }
  }