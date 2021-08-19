package myClass;

public class Aluno {
    private String Nome; 
    private Number RA;
    private Double NotaA1; 
    private Double NotaA2;
    private Double Media; 
    private Double FrequenciaAula;
    
    public Aluno() {
    }

    public String getNome(){
        return Nome;
    }
    
    public void setNome(String nome){
        Nome = nome;
    }
    
    public Number getRA(){
        return RA;
    }
    
    public void setRA(Number ra){
        RA = ra;
    }

    public Double getNotaA1(){
        return NotaA1;
    }
    
    public void setNotaA1(Double notaA1){
        NotaA1 = notaA1;
    }

    public Double getNotaA2(){
        return NotaA2;
    }
    
    public void setNotaA2(Double notaA2){
        NotaA2 = notaA2;
    }

    public Double getFrequenciaAula(){
        return FrequenciaAula;
    }
    
    public void setFrequenciaAula(Double frequenciaAula){
        FrequenciaAula = frequenciaAula;
    }

    public Double CalcularMedia() {
        Media = (NotaA1 + (2 * NotaA2)) / 3;
        return Media;
    }

    public void ImprimeAluno() {
        System.out.printf("Nome: " + Nome + "\n");
        System.out.printf("RA: " + RA + "\n");
        System.out.printf("Nota A1: " + NotaA1 + "\n");
        System.out.printf("Nota A2: " + NotaA2 + "\n");
        System.out.printf("Média: " + String.format("%.2f", Media) + "\n");
        System.out.printf("Frequencia da Aula: " + FrequenciaAula + "\n");
        System.out.printf("Situação do Aluno: ");
        SituaçãoAluno();
        System.out.printf("\n\n");
    }

    public void SituaçãoAluno() {
        if((FrequenciaAula >=75) && Media >=5 ){
            System.out.printf("Aprovado\n");
        } else if((FrequenciaAula >=75) && 3<=Media && Media <5){
            System.out.printf("RE\n");
        } else{
            System.out.printf("Reprovado\n");
        }
    }

    
}
