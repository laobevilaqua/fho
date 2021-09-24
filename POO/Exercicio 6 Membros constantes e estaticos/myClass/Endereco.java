package myClass;

public class Endereco {
	private String Rua;
	private String Complemento;
	private String Bairro;
	private String Cidade;
	private String Estado;
	private String Cep;

	public Endereco(String rua, String bairro, String cidade, String estado, String cep, String complemento) {
		Rua = rua;
		Bairro = bairro;
		Cidade = cidade;
		Estado = estado;
		Cep = cep;
		Complemento = complemento;
	}

	public void exibirEndereco() {
		System.out.println("Rua:" + this.Rua);
		System.out.println("\nComplemento:" + this.Complemento);
		System.out.println("\nBairro:" + this.Bairro);
		System.out.println("\nCidade:" + this.Cidade);
		System.out.println("\nEstado:" + this.Estado);
		System.out.println("\nCep:" + this.Cep);
	}

	public String getRua() {
		return Rua;
	}

	public void setRua(String rua) {
		Rua = rua;
	}

	public String getBairro() {
		return Bairro;
	}

	public void setBairro(String bairro) {
		Bairro = bairro;
	}

	public String getCidade() {
		return Cidade;
	}

	public void setCidade(String cidade) {
		Cidade = cidade;
	}

	public String getEstado() {
		return Estado;
	}

	public void setEstado(String estado) {
		Estado = estado;
	}

	public String getCep() {
		return Cep;
	}

	public void setCep(String cep) {
		Cep = cep;
	}

	public String getComplemento() {
		return Complemento;
	}
	
	public void setComplemento(String complemento) {
		Complemento = complemento;
	}
}
