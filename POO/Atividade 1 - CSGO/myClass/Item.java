package myClass;

public class Item {
    private String tipo;
	private Double preco;
	private String nome;
	private String descricao;
	private String municao;
	private String ladoDaArma;

	public Item(String tipo, Double preco, String nome, String descricao, String municao, String ladoDaArma) {
		this.tipo = tipo;
		this.preco = preco;
		this.nome = nome;
		this.descricao = descricao;
		this.municao = municao;
		this.ladoDaArma = ladoDaArma;
	}

	@Override
    public String toString() {
        return this.nome + " " + this.preco + " " + this.descricao;
    }

	public String getTipo() {
		return tipo;
	}

	public void setTipo(String tipo) {
		this.tipo = tipo;
	}

	public Double getPreco() {
		return preco;
	}

	public void setPreco(Double preco) {
		this.preco = preco;
	}

	public String getNome() {
		return nome;
	}

	public void setNome(String nome) {
		this.nome = nome;
	}

	public String getDescricao() {
		return descricao;
	}

	public void setDescricao(String descricao) {
		this.descricao = descricao;
	}

	public String getMunicao() {
		return municao;
	}

	public void setMunicao(String municao) {
		this.municao = municao;
	}

	public String getLadoDaArma() {
		return ladoDaArma;
	}

	public void setLadoDaArma(String ladoDaArma) {
		this.ladoDaArma = ladoDaArma;
	}

	
}
