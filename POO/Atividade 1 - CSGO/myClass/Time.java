package myClass;
import java.util.*;

public class Time {
    private String nome;
	private String apelido;
	private Tecnico tecnico;
	private String mapaFavorito;
	private Integer rankeamento;
	private Integer trofeus;
	private Jogador craque;
	private List<Patrocinador> patrocinadores = new ArrayList<Patrocinador>();
	private List<Jogador> jogadores = new ArrayList<Jogador>();
	private final Integer capacidadeJogadores = 5;

	public Time(String nome, String apelido, Tecnico tecnico, List<Jogador> jogadores) {
		if (jogadores.size() != capacidadeJogadores) {
			throw new Error("\nO time contém mais ou menos de 5 jogadores.");
		} 
		
		this.nome = nome;
		this.apelido = apelido;
		this.tecnico = tecnico;
		this.jogadores = jogadores;
	}

	public void imprimirTime() {
		System.out.println("\nTecnico: " + tecnico.getNome());
		System.out.println("Nome: " + nome);
		System.out.println("Apelido: " + apelido);
		System.out.println("Mapa favorito: " + (Boolean.parseBoolean(mapaFavorito)  ? mapaFavorito : "Não Informado"));
		try {
			System.out.println("Craque: " + craque.getNome());
		} catch (Exception e) {
			System.out.println("O time ainda não possui um craque");
		}

		System.out.println("\nJogadores: ");
		jogadores.forEach(System.out::println);

		if (patrocinadores.size() > 0) {
			System.out.println("\nPatrocinadores: ");
			patrocinadores.forEach(System.out::println);
		}
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

	public Tecnico getTecnico() {
		return tecnico;
	}

	public void setTecnico(Tecnico tecnico) {
		this.tecnico = tecnico;
	}

	public String getMapaFavorito() {
		return mapaFavorito;
	}

	public void setMapaFavorito(String mapaFavorito) {
		this.mapaFavorito = mapaFavorito;
	}

	public Integer getRankeamento() {
		return rankeamento;
	}

	public void setRankeamento(Integer rankeamento) {
		this.rankeamento = rankeamento;
	}

	public Integer getTrofeus() {
		return trofeus;
	}

	public void setTrofeus(Integer trofeus) {
		this.trofeus = trofeus;
	}

	public Jogador getCraque() {
		return craque;
	}

	public void setCraque(Jogador craque) {
		this.craque = craque;
	}

	public List<Patrocinador> getPatrocinadores() {
		return patrocinadores;
	}

	public void setPatrocinadores(List<Patrocinador> patrocinadores) {
		this.patrocinadores = patrocinadores;
	}

	public List<Jogador> getJogadores() {
		return jogadores;
	}

	public void setJogadores(List<Jogador> jogadores) {
		this.jogadores = jogadores;
	}

	public void setJogador(Jogador jogador) {
		this.jogadores.add(jogador);
	}
}
