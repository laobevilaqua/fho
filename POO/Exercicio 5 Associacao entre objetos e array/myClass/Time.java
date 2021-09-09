package myClass;
import java.util.*;

public class Time {
    private String nome;
	private String apelido;
	private String liga;
	private String rival;
	private String nomeTorcidaOrganizada;
	private Double patrimonio;
	private String aniversario;
	private Tecnico tecnico;
	private Presidente presidente;
	private Estadio estadio;
	private List<Jogador> jogadores = new ArrayList<Jogador>();

	public Time(Tecnico tecnico, Presidente presidente, Estadio estadio, Jogador jogador) {
		this.tecnico = tecnico;
		this.presidente = presidente;
		this.estadio = estadio;
		this.jogadores.add(jogador);
	}

	public void imprimirTime() {
		System.out.println("Tecnico: " + tecnico.getNome());
		System.out.println("\nEstadio: " + estadio.getNome());
		System.out.println("\nJogadores: ");

		jogadores.forEach(System.out::println);
		System.out.println("\nEstadio: " + estadio.getNome());
		System.out.println("\nNome: " + nome);
		System.out.println("\nApelido: " + apelido);
		System.out.println("\nLiga: " + liga);
		System.out.println("\nRival: " + rival);
		System.out.println("\nNome da Torcida: " + nomeTorcidaOrganizada);
	}

	public String getNome() {
		return nome;
	}
	
	public void setNome(String nome) {
		this.nome = nome;
	}

	public String getApelido() {
		return apelido;
	}
	
	public void setApelido(String apelido) {
		this.apelido = apelido;
	}

	public String getLiga() {
		return liga;
	}
	
	public void setLiga(String liga) {
		this.liga = liga;
	}

	public String getRival() {
		return rival;
	}
	
	public void setRival(String rival) {
		this.rival = rival;
	}

	public String getNomeTorcidaOrganizada() {
		return nomeTorcidaOrganizada;
	}
	
	public void setNomeTorcidaOrganizada(String nomeTorcidaOrganizada) {
		this.nomeTorcidaOrganizada = nomeTorcidaOrganizada;
	}

	public Double getPatrimonio() {
		return patrimonio;
	}
	
	public void setPatrimonio(Double patrimonio) {
		this.patrimonio = patrimonio;
	}

	public String getAniversario() {
		return aniversario;
	}
	
	public void setAniversario(String aniversario) {
		this.aniversario = aniversario;
	}

	public Tecnico getTecnico() {
		return tecnico;
	}
	
	public void setTecnico(Tecnico tecnico) {
		this.tecnico = tecnico;
	}

	public Estadio getEstadio() {
		return estadio;
	}
	
	public void setEstadio(Estadio estadio) {
		this.estadio = estadio;
	}

	public Presidente getPresidente() {
		return this.presidente;
	}
	
	public void setPresidente(Presidente presidente) {
		this.presidente = presidente;
	}

	public List<Jogador> getJogador() {
		return this.jogadores;
	}
	
	public void setJogador(Jogador jogador) {
		this.jogadores.add(jogador);
	}
}
