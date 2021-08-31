import myClass.CarroCasual;
import myClass.CarroEsportivo;
import myClass.CarroLuxo;

public class Main {

    public static void main(String[] args) {
       CarroCasual carroCasual = new CarroCasual("Corsa", "rosão", 4);
       carroCasual.imprimeCarro();
       
       CarroEsportivo carroEsportivo = new CarroEsportivo("Hilux", "Azulão", 4, true);
       carroEsportivo.imprimeCarro();
       
       CarroEsportivo carroEsportivo2 = new CarroEsportivo("Civic", "Prata", 4, false);
       carroEsportivo2.imprimeCarro();
       
       CarroLuxo carroLuxuoso = new CarroLuxo("RS6 AVANT", "cinza chumbo", 2, true, true, true);
       carroLuxuoso.imprimeCarro();
    }
  }