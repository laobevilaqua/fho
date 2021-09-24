package myClass;

public class Carro {
	private String modelo;
	private String cor;
	private Integer ano;
	private Marca marca;
	private String chassi;
	private Proprietario proprietario;
	private Double velocidadeMáxima;
	private Double velocidadeAtual;
	private Integer nrPortas;
	private Boolean temTetoSolar;
	private Integer nrMarchas;
	private Boolean temCambioAutomático;
	private Double volumeCombustível;
	private String marcha;

	public Carro(Proprietario proprietario) {
		this.proprietario = proprietario;
	}

	public void exibirDados() {
		System.out.println("\n----------Poprietario-----------\n");
		this.proprietario.exibirProprietario();
	}

	public void acelera() {
		this.velocidadeAtual += 1;
	}

	public void freia() {
		this.velocidadeAtual -= 1;
	}

	public Double autonomia(Double autonomiaPorKm) {
		return autonomiaPorKm / this.velocidadeAtual;
	}

	public void trocaMarcha() {
		if (this.marcha == "R") {
			this.marcha = "1";
		} else if(this.nrMarchas > Integer.parseInt(this.marcha)){
			this.marcha = Integer.toString(Integer.parseInt(this.marcha) + 1);
		}
	}

	public void reduzMarcha() {
		if (this.marcha == "1" && this.velocidadeAtual == 0) {
			this.marcha = "R";
		} else if(this.marcha != "R") {
			this.marcha = Integer.toString(Integer.parseInt(this.marcha) - 1);
		}
	}

	public String getMarcha() {
		return marcha;
	}

	public void setMarcha(String marcha) {
		this.marcha = marcha;
	}

	public String getModelo() {
		return modelo;
	}

	public void setModelo(String modelo) {
		this.modelo = modelo;
	}

	public String getCor() {
		return cor;
	}

	public void setCor(String cor) {
		this.cor = cor;
	}

	public Integer getAno() {
		return ano;
	}

	public void setAno(Integer ano) {
		this.ano = ano;
	}

	public Marca getMarca() {
		return marca;
	}

	public void setMarca(Marca marca) {
		this.marca = marca;
	}

	public String getChassi() {
		return chassi;
	}

	public void setChassi(String chassi) {
		this.chassi = chassi;
	}

	public Proprietario getProprietario() {
		return proprietario;
	}

	public void setProprietario(Proprietario proprietario) {
		this.proprietario = proprietario;
	}

	public Double getVelocidadeMáxima() {
		return velocidadeMáxima;
	}

	public void setVelocidadeMáxima(Double velocidadeMáxima) {
		this.velocidadeMáxima = velocidadeMáxima;
	}

	public Double getVelocidadeAtual() {
		return velocidadeAtual;
	}

	public void setVelocidadeAtual(Double velocidadeAtual) {
		this.velocidadeAtual = velocidadeAtual;
	}

	public Integer getNrPortas() {
		return nrPortas;
	}

	public void setNrPortas(Integer nrPortas) {
		this.nrPortas = nrPortas;
	}

	public Boolean getTemTetoSolar() {
		return temTetoSolar;
	}

	public void setTemTetoSolar(Boolean temTetoSolar) {
		this.temTetoSolar = temTetoSolar;
	}

	public Integer getNrMarchas() {
		return nrMarchas;
	}

	public void setNrMarchas(Integer nrMarchas) {
		this.nrMarchas = nrMarchas;
	}

	public Boolean getTemCambioAutomático() {
		return temCambioAutomático;
	}

	public void setTemCambioAutomático(Boolean temCambioAutomático) {
		this.temCambioAutomático = temCambioAutomático;
	}

	public Double getVolumeCombustível() {
		return volumeCombustível;
	}

	public void setVolumeCombustível(Double volumeCombustível) {
		this.volumeCombustível = volumeCombustível;
	}
}
