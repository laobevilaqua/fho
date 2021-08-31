package myClass;

public class CarroEsportivo extends CarroCasual {
    private Boolean tem4x4 = true;
    
    public CarroEsportivo() {
        this.setTipo("Carro Esportivo");
    }

    public CarroEsportivo(String modelo, String cor, Number qtdPortas, Boolean tem4x4) {
        this.setModelo(modelo);
        this.setCor(cor);
        this.setQtdPortas(qtdPortas);
        this.setTem4x4(tem4x4);
        this.setTipo("Carro Esportivo");
    }

    public void setTem4x4(Boolean tem4x4){
        this.tem4x4 = tem4x4;
    }

    public Boolean getTem4x4(){
        return this.tem4x4;
    }

    @Override
    public void imprimeCarro() {
        super.imprimeCarro();

        String tem4x4 = this.getTem4x4() ? "Possui" : "Não possui";
        System.out.println("Tem tração 4x4: "+ tem4x4 + "\n");
    }
}
