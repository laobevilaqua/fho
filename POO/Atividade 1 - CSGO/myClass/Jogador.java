package myClass;
import java.util.*;

public class Jogador {
    private String nome;
	private String nick;
	private Double salario;
	private List<Item> itens = new ArrayList<Item>();

	public Jogador(String nome, String nick, Double salario) {
		this.nome = nome;
		this.nick = nick;
		this.salario = salario;
		this.addItensDefault();
	}

	private void addItensDefault() {
		this.itens.add(new Item("Utilitarias", 0.00, "Faquinha do mal", "Faca de passar manteiga", "1", "Ambos"));
		this.nome.toString();
	}

	@Override
    public String toString() {
        return this.nome + " " + this.nick;
    }

	public void limparItens() {
		this.itens.clear();
		this.addItensDefault();
	}

	public String getNome() {
		return nome;
	}
	
	public void setNome(String nome) {
		this.nome = nome;
	}

	public String getNick() {
		return nick;
	}
	
	public void setNick(String nick) {
		this.nick = nick;
	}
	
	public Double getSalario() {
		return salario;
	}
	
	public void setSalario(Double salario) {
		this.salario = salario;
	}

	public List<Item> getItens() {
		return itens;
	}

	public void setItem(Item item) {
		this.itens.add(item);
	}
}
