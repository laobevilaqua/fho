package myClass;
import java.time.LocalDateTime;  

public class Data {
    private int dia; 
    private int mes; 
    private int ano; 

    public Data() {
        LocalDateTime now = LocalDateTime.now();  
        this.dia = now.getDayOfMonth();
        this.mes = now.getMonthValue();
        this.ano = now.getYear();
    }
    
    public Data(int dia, int mes, int ano) {
        this.dia = validaDia(dia);
        this.mes = validaMes(mes);
        this.ano = ano;
    }

    public void apresentaData() {
        System.out.println("Data:" +this.dia + "/" + this.mes + "/" + this.ano);
    }
    
    public void apresentaData(boolean isEstacaoCompleta) {
        this.apresentaData();
        if(isEstacaoCompleta) {
            this.getEstacao();
        }
    }

    public void adicionarDias(int dias) {
        do {
            this.pularDia();
            dias--;
        } while (dias > 0);
    }

    public void pularDia() {
        if(this.dia == 31) {
           this.dia = 1;
           this.mes++;
        } else {
            this.dia++;
        }
        if(this.mes > 12) {
            this.mes = 1;
            this.ano++;
        }
    }

    public void getEstacao() {
        if ( mes == 12 || mes == 1 || mes == 2 ){
            System.out.println("É verão\n");
            
        }
        else if(mes == 3 || mes == 4 || mes == 5){
            System.out.println("Outono\n");
         }
        else if(mes == 6 || mes == 7 || mes == 8){
            System.out.println("Inverno\n");
          }
        else {
            System.out.println("Primavera\n");
        }
    }

    protected int validaDia(int dia) {
        return dia >=1 && dia <= 31 ? dia : 28;
    }

    protected int validaMes(int mes) {
        return mes >=1 && mes <= 12 ? mes : 9;
    }

    public int getDia() {
        return this.dia;
    }

    public void setDia(int dia) {
        this.dia = dia;
    }

    public int getMes() {
        return this.mes;
    }

    public void setMes(int mes) {
        this.mes = mes;
    }

    public int getAno() {
        return this.ano;
    }

    public void setAno(int ano) {
        this.ano = ano;
    }
   

}
