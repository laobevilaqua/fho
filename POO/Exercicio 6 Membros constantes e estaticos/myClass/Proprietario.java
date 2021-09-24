package myClass;

public class Proprietario {
	private String nome;
	private String cpf;
	private String rg;
	private String dataNascimento;
	private Endereco endereco;

	public Proprietario(String nome, String cpf, String rg) {
		this.nome = nome;
		this.cpf = cpf;
		this.rg = rg;
	}

	public void exibirProprietario() {
		System.out.println("\nNome: " + this.nome);
		System.out.println("\nCPF: " + this.cpf);
		System.out.println("\nRG: " + this.rg);
		System.out.println("\n----------Endereco-----------\n");
		this.endereco.exibirEndereco();
	}

	public String getNome() {
		return nome;
	}

	public void setNome(String nome) {
		this.nome = nome;
	}

	public String getCpf() {
		return cpf;
	}

	public void setCpf(String cpf) {
		this.cpf = cpf;
	}

	public String getRg() {
		return rg;
	}

	public void setRg(String rg) {
		this.rg = rg;
	}

	public String getDataNascimento() {
		return dataNascimento;
	}

	public void setDataNascimento(String dataNascimento) {
		this.dataNascimento = dataNascimento;
	}

	public Endereco getEndereco() {
		return endereco;
	}

	public void setEndereco(Endereco endereco) {
		this.endereco = endereco;
	}

}
