package myClass;

public class CarroLuxo extends CarroEsportivo {
    private Boolean temBancoDeCouro = true;
    private Boolean temArCondicionado = true;
    
    public CarroLuxo() {
        this.setTipo("Carro Luxo");
    }

    public CarroLuxo(String modelo, String cor, Number qtdPortas, Boolean tem4x4, Boolean temBancoDeCouro, Boolean temArCondicionado) {
        this.setModelo(modelo);
        this.setCor(cor);
        this.setQtdPortas(qtdPortas);
        super.setTem4x4(tem4x4);
        this.setTemBancoCouro(temBancoDeCouro);
        this.setTemArCondicionado(temArCondicionado);
        this.setTipo("Carro Luxo");
    }

    public void setTemBancoCouro(Boolean temBancoDeCouro){
        this.temBancoDeCouro = temBancoDeCouro;
    }

    public Boolean getTemBancoCouro(){
        return this.temBancoDeCouro;
    }

    public void setTemArCondicionado(Boolean temArCondicionado){
        this.temArCondicionado = temArCondicionado;
    }

    public Boolean getTemArCondicionado(){
        return this.temArCondicionado;
    }

    @Override
    public void imprimeCarro() {
        super.imprimeCarro();
        String temBancoDeCouro = this.getTemBancoCouro() ? "Possui" : "Não possui";
        String temArCondicionado = this.getTemArCondicionado() ? "Possui" : "Não possui";
        System.out.println("Tem banco de couro: " + temBancoDeCouro + "\n");
        System.out.println("Tem ar condicionado: " + temArCondicionado + "\n");
    }
}
