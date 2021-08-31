package myClass;

public class CarroCasual extends Carro {
    
    public CarroCasual() {
        this.setTipo("Carro Casual");
    }

    public CarroCasual(String modelo, String cor, Number qtdPortas) {
        this.setModelo(modelo);
        this.setCor(cor);
        this.setQtdPortas(qtdPortas);
        this.setTipo("Carro Casual");
    }
}
