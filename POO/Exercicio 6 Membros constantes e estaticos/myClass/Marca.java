package myClass;

public class Marca {
	private String nome;
	private Integer nrDeModelos;
	private Integer anoDeLançamento;
	private Integer codigoIdentificador;

	public Marca() {
	
	}

	public Marca(String nome, Integer nrDeModelos, Integer anoDeLançamento, Integer codigoIdentificador) {
		this.nome = nome;
		this.nrDeModelos = nrDeModelos;
		this.anoDeLançamento = anoDeLançamento;
		this.codigoIdentificador = codigoIdentificador;
	}

	public String getNome() {
		return nome;
	}

	public void setNome(String nome) {
		this.nome = nome;
	}

	public Integer getNrDeModelos() {
		return nrDeModelos;
	}

	public void setNrDeModelos(Integer nrDeModelos) {
		this.nrDeModelos = nrDeModelos;
	}

	public Integer getAnoDeLançamento() {
		return anoDeLançamento;
	}

	public void setAnoDeLançamento(Integer anoDeLançamento) {
		this.anoDeLançamento = anoDeLançamento;
	}

	public Integer getCodigoIdentificador() {
		return codigoIdentificador;
	}

	public void setCodigoIdentificador(Integer codigoIdentificador) {
		this.codigoIdentificador = codigoIdentificador;
	}
}
