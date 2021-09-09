import myClass.*;

public class Main {

    public static void main(String[] args) {

      Tecnico tecnico1 = new Tecnico();
      tecnico1.setNome("Sylvinho");
      tecnico1.setSobrenome("Louco");
      tecnico1.setNacionalidade("Brasileiro");
      tecnico1.setIdade(42);

      Estadio estadio1 = new Estadio();
      estadio1.setCapacidade(49000);
      estadio1.setNome("Neo quimica Arena");
      estadio1.setLocalizacao("São paulo, Brasil");

      Presidente presidente1 = new Presidente();
      presidente1.setNome("Craque");
      presidente1.setSobrenome("Neto");
      presidente1.setIdade(45);
      presidente1.setNacionalidade("Brasileiro");
      presidente1.setSalarioOficial(50000.00);
      presidente1.setDinheiroLavado(580000000.00);
      
      Jogador jogador1 = new Jogador();
      jogador1.setNome("Craque");
      jogador1.setSobrenome("Neto");
      jogador1.setIdade(45);
      jogador1.setNacionalidade("Brasileiro");
      jogador1.setNumeroCamisa(10);
      jogador1.setPosicao("Meia articulador que voava livre bater de falta nato");
      
      Jogador jogador2 = new Jogador();
      jogador2.setNome("Dentinho");
      jogador2.setSobrenome("");
      jogador2.setIdade(40);
      jogador2.setNacionalidade("Brasileiro");
      jogador2.setNumeroCamisa(10);
      jogador2.setPosicao("Atacante");

      Time time1 = new Time(tecnico1, presidente1, estadio1, jogador1);
      time1.setNome("Corinthians");
      time1.setApelido("Timão");
      time1.setAniversario("10/02/1876");
      time1.setLiga("Liga do Brasil");
      time1.setNomeTorcidaOrganizada("Gaviões da fiel");
      time1.setPatrimonio(2000000000.00);
      time1.setRival("São Paulo");
      time1.setJogador(jogador2);

      time1.imprimirTime();
    }
  }