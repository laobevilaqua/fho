package myClass;

public class Partida {
    private String tipo;
    private String inicio;
    private String fim;
	private String mapa;
	private Time TR;
	private Time CT;
	private Integer pontoTR = 0;
	private Integer pontoCT = 0;
	private Integer round = 1;
	private Boolean foiEmpate = false;
	private Time vencedor;
	private final Integer maxRodadas = 30;
	private final Integer pontosParaVencer = 16;

	public Partida(String inicio, String fim, String mapa, Time tR, Time cT) {
		this.inicio = inicio;
		this.fim = fim;
		this.mapa = mapa;
		TR = tR;
		CT = cT;
	}

	public void imprimePartida() {
		System.out.println("-----------------PARTIDA--------------");
		System.out.println("\nCT " + CT.getApelido() + " - " + pontoCT);
		System.out.println("\nTR " + TR.getApelido() + " - " + pontoTR);
		System.out.println("\nMapa: " + mapa);
		System.out.println("\nRodadas: " + round);
		System.out.println("\nInicio: " + inicio);
		System.out.println("\nFim: " + fim);
		String resultado = foiEmpate ? "\nTerminou empatada" : ("\nVencedor: " + vencedor.getApelido());
		System.out.println(resultado);
	}

	private void inverteLado() {
		Time aux = CT;
		CT = TR;
		TR = aux;
		
		Integer auxPonto = pontoCT;
		pontoCT = pontoTR;
		pontoTR = auxPonto;
	}

	private Boolean validaPartida() {
		if (pontoCT == pontosParaVencer || pontoTR == pontosParaVencer) {
			vencedor = pontoCT == pontosParaVencer ? CT : TR;
			System.out.println("Partida finalizada.");
			round++;
			
			return false;
		} else if (round == maxRodadas) {
			foiEmpate = true;
			System.out.println("Jogo finalizado empatado.");
			
			return false;
		}

		return true;
	}
	
	private void proximaRodada() {
		for(Jogador jogador : TR.getJogadores()){
            jogador.limparItens();
        }

		for(Jogador jogador : CT.getJogadores()){
            jogador.limparItens();
        }

		if (validaPartida()) {
			if(round == 15) {
				inverteLado();
			} else {
				round++;
			}
		}
	}

	private Boolean partidaIniciada() {
		System.out.println("A partida já foi iniciada e não pode ser alterada.");

		return round > 1;
	}

	public void vencedorDaRodada(String lado) {
		if (lado == "CT") {
			pontoCT++;
		} else if (lado == "TR") {
			pontoTR++;
		} else {
			throw new Error("\nLado ganhador do round desconhecido.");
		}

		proximaRodada();
	}

	public String getTipo() {
		return tipo;
	}

	public void setTipo(String tipo) {
		if (!partidaIniciada()) {
			this.tipo = tipo;
		}
	}

	public String getInicio() {
		return inicio;
	}

	public void setInicio(String inicio) {
		if (!partidaIniciada()) {
			this.inicio = inicio;
		}
	}

	public String getFim() {
		return fim;
	}

	public void setFim(String fim) {
		if (!partidaIniciada()) {
			this.fim = fim;
		}
	}

	public String getMapa() {
		return mapa;
	}

	public void setMapa(String mapa) {
		if (!partidaIniciada()) {
			this.mapa = mapa;
		}
	}

	public Time getTR() {
		return TR;
	}

	public void setTR(Time tR) {
		if (!partidaIniciada()) {
			TR = tR;
		}
	}

	public Time getCT() {
		return CT;
	}

	public void setCT(Time cT) {
		if (!partidaIniciada()) {
			CT = cT;
		}
	}

	public Integer getPontoTR() {
		return pontoTR;
	}

	public Integer getPontoCT() {
		return pontoCT;
	}

	public Integer getRodada() {
		return round;
	}

	public Time getVencedor() {
		return vencedor;
	}

	public Integer getMaxRodadas() {
		return maxRodadas;
	}

	public Integer getPontosParaVencer() {
		return pontosParaVencer;
	}

}
