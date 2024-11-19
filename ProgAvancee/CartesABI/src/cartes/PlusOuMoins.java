package cartes;

import Controleur.Controleur;
import cartes.carte.ICarte;

/*
 * Le Pattern MVC n'est pas respecté pour ce petit exemple.
 * Cependant, toutes les interactions avec l'utilisateur sont regroupées ici.
 */
public class PlusOuMoins<T extends ICarte> {

	private static final int SCORE_INITIAL = 10;

	private static final int GAIN = 1;

	private static final int PERTE = -2;

	private Paquet<T> paquet;
	private int score = SCORE_INITIAL;

	public PlusOuMoins(Paquet<T> p) {
		this.paquet = p;
	}

	public Paquet<T> getPaquet() {
		return paquet;
	}

	public int getScore() {
		return score;
	}

	public void gain() {
		score += GAIN;
	}

	public void perte() {
		score += PERTE;
	}

	/* façade */
	public T get(int i) {
		return this.paquet.get(i);
	}
	
	public int size() {
		return this.paquet.size();
	}
	
	public static void main(String[] args) {
		new Controleur();
	}

}
