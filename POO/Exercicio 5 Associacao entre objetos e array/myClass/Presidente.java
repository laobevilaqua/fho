package myClass;

public class Presidente {
    private String nome;
	private String sobrenome;
	private String nacionalidade;
	private Integer idade;
	private Double salarioOficial;
	private Double dinheiroLavado;


	public String getNome() {
		return nome;
	}
	
	public void setNome(String nome) {
		this.nome = nome;
	}

	public String getSobrenome() {
		return sobrenome;
	}
	
	public void setSobrenome(String sobrenome) {
		this.sobrenome = sobrenome;
	}
	
	public String getNacionalidade() {
		return nacionalidade;
	}
	
	public void setNacionalidade(String nacionalidade) {
		this.nacionalidade = nacionalidade;
	}
	
	public Integer getIdade() {
		return idade;
	}
	
	public void setIdade(Integer idade) {
		this.idade = idade;
	}
	
	public Double getSalarioOficial() {
		return salarioOficial;
	}
	
	public void setSalarioOficial(Double salarioOficial) {
		this.salarioOficial = salarioOficial;
	}
	
	public Double getDinheiroLavado() {
		return dinheiroLavado;
	}
	
	public void setDinheiroLavado(Double dinheiroLavado) {
		this.dinheiroLavado = dinheiroLavado;
	}
}
