import myClass.*;

public class Main {

    public static void main(String[] args) {
      Proprietario p1 = new Proprietario("Diegao", "111.111.111-11", "22.222.222-2");
      Endereco e1 = new Endereco("Entre as ruas 9 e 6", "Kinquiskov", "Hogwarts", "Inglaterra", "22541Ere", "Estacao");
      p1.setEndereco(e1);

      Marca m1 = new Marca("Expresso de Hogwarts", 2, 1826, 855745);
      Carro c1 = new Carro(p1);
      c1.setMarca(m1);
      c1.exibirDados();      
    }
  }