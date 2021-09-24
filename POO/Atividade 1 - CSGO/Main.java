import myClass.*;
import java.util.*;

public class Main {

    public static void main(String[] args) {
      Item awp = new Item("Arma", 4750.00, "AWP", "Arma do falen, tira o olho.", "7", "Ambos");
      Item tecoTeco = new Item("Arma", 5000.00, "TECO TECO", "Arma do teco teco", "10", "Ambos");
      Item granadaDeLuz = new Item("Utilitarias", 100.00, "Granada de luz", "Deixa o amigo cego assim como o inimigo", "1", "TR");

      Tecnico gauGau = new Tecnico();
      Jogador fallen = new Jogador("Gabriel toledo", "Fallen", 500000.00);
      fallen.setItem(awp);
      fallen.setItem(granadaDeLuz);
      
      Jogador simple = new Jogador("Oleksandr Olegovich Kostyliev", "S1mple", 100000000.00);
      simple.setItem(tecoTeco);
      simple.setItem(granadaDeLuz);
      
      Jogador magisk = new Jogador("Emil Reif", "magisk ", 2500000.00);
      magisk.setItem(tecoTeco);
      magisk.setItem(granadaDeLuz);
      
      Jogador dev1ce = new Jogador("Nicolai Hvilshøj Reedtz", "Dev1ce", 200000000.00);
      dev1ce.setItem(tecoTeco);
      dev1ce.setItem(granadaDeLuz);
      
      Jogador junior = new Jogador("Paytyn ", "Junior", 45000000.00);
      junior.setItem(tecoTeco);
      junior.setItem(granadaDeLuz);
      
      Tecnico patife = new Tecnico();
      
      Jogador coldzera = new Jogador("Marcelo Augusto David", "coldzera", 500000.00);
      coldzera.setItem(tecoTeco);
      coldzera.setItem(granadaDeLuz);
      
      Jogador art = new Jogador("Артём Шевченко", "Art", 100000000.00);
      art.setItem(tecoTeco);
      art.setItem(granadaDeLuz);
      
      Jogador kennyS = new Jogador("Kenny Schrub", "KennyS ", 2500000.00);
      kennyS.setItem(awp);
      kennyS.setItem(granadaDeLuz);
      
      Jogador f0rest = new Jogador("Patrik Lindberg", "F0rest", 200000000.00);
      f0rest.setItem(tecoTeco);
      f0rest.setItem(granadaDeLuz);
      
      Jogador gla1ve = new Jogador("Lukas Egholm Rossander", "Gla1ve", 45000000.00);
      gla1ve.setItem(tecoTeco);
      gla1ve.setItem(granadaDeLuz);

      Time time1 = new Time("RIP Heroic", "RHC", gauGau, Arrays.<Jogador>asList(fallen, simple, magisk, dev1ce, junior));
      Time time2 = new Time("Immortals", "IML", patife, Arrays.<Jogador>asList(coldzera, art, kennyS, f0rest, gla1ve));

      Partida partida = new Partida("28/09/2021 15:45", "28/09/2001 17:00", "Trem", time1, time2);

      Campeonato campeonato = new Campeonato("Campeonato dos Falidos", "Muito dinheiro", "Brazil", 200, "28/09/2021", Arrays.<Time>asList(time1, time2));

      System.out.println("TIME 1");
      time1.imprimirTime();

      System.out.println("\nTIME 2");
      time2.imprimirTime();

      for (int i = 0; i < 15; i++) {
        partida.vencedorDaRodada("TR");
      }
      partida.vencedorDaRodada("CT");
      partida.imprimePartida();
      
      campeonato.setVencedor(partida.getVencedor());
      campeonato.imprimeCampeonato();
    }
  }