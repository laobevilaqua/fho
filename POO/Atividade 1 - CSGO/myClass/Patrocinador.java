package myClass;

public class Patrocinador {
    private String nome;
	private Double patrimonio;

	@Override
    public String toString() {
        return this.nome;
    }

	public String getNome() {
		return nome;
	}
	
	public void setNome(String nome) {
		this.nome = nome;
	}

	public Double getPatrimonio() {
		return patrimonio;
	}

	public void setPatrimonio(Double patrimonio) {
		this.patrimonio = patrimonio;
	}

}
