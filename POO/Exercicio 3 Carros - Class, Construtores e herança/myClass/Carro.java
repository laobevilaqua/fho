package myClass;

public class Carro {
    private String tipo; 
    private String modelo; 
    private String cor; 
    private Number qtdPortas; 
    
    public Carro() {
    
    }

    public Carro(String modelo, String cor, Number qtdPortas) {
        this.modelo = modelo;
        this.cor = cor;
        this.qtdPortas = qtdPortas;
    }

    public String getModelo(){
        return this.modelo;
    }
    
    public void setModelo(String modelo){
        this.modelo = modelo;
    }
  
    public String getCor(){
        return this.cor;
    }
    
    public void setCor(String cor){
        this.cor = cor;
    }
  
    public Number getQtdPortas(){
        return this.qtdPortas;
    }
    
    public void setQtdPortas(Number qtdPortas){
        this.qtdPortas = qtdPortas;
    }

    public String getTipo(){
        return this.tipo;
    }
    
    protected void setTipo(String tipo){
        this.tipo = tipo;
    }
  
    public void imprimeCarro() {
        System.out.println("-------------------" + this.tipo + "-----------------------\n");
        System.out.println("Tipo: " + this.tipo + "\n");
        System.out.println("Cor: " + this.cor + "\n");
        System.out.println("Modelo: " + this.modelo + "\n");
        System.out.println("Quantidade de Portas: " + this.qtdPortas + "\n");
    }
}
