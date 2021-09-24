package myClass;
import java.util.*;

public class Campeonato {
	private String nome;
	private String premio;
	private String localizacao;
	private Integer pontos;
    private String data;
    private Time vencedor;
	private List<Time> times = new ArrayList<Time>();
	
	public Campeonato(String nome, String premio, String localizacao, Integer pontos, String data, List<Time> times) {
		this.nome = nome;
		this.premio = premio;
		this.localizacao = localizacao;
		this.pontos = pontos;
		this.data = data;
		this.times = times;
	}

	public void imprimeCampeonato() {
		System.out.println("-----------------CAMPEONATO--------------");
		System.out.println("\nNome " + nome);
		System.out.println("\nPremio " + premio);
		System.out.println("\nLocalização: " + localizacao);
		System.out.println("\nPontos: " + pontos);
		System.out.println("\nData: " + data);
		System.out.println("\nVencedor: " + vencedor.getNome());
	}

	public String getNome() {
		return nome;
	}

	public void setNome(String nome) {
		this.nome = nome;
	}

	public String getPremio() {
		return premio;
	}

	public void setPremio(String premio) {
		this.premio = premio;
	}

	public String getLocalizacao() {
		return localizacao;
	}

	public void setLocalizacao(String localizacao) {
		this.localizacao = localizacao;
	}

	public Integer getPontos() {
		return pontos;
	}

	public void setPontos(Integer pontos) {
		this.pontos = pontos;
	}

	public List<Time> getTimes() {
		return times;
	}

	public void setTimes(List<Time> times) {
		this.times = times;
	}

	public String getData() {
		return data;
	}

	public void setData(String data) {
		this.data = data;
	}

	public Time getVencedor() {
		return vencedor;
	}

	public void setVencedor(Time vencedor) {
		this.vencedor = vencedor;
	}
}
