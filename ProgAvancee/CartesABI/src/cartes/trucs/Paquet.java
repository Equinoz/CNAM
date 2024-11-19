package cartes;

import java.util.Collections;
import java.util.List;

import cartes.carte.ICarte;

public abstract class Paquet<T extends ICarte> implements IPaquet<T>{

	/*
	 * Patron de conception façade : on agrège une instance de List<T> plutôt que d'implémenter
	 * List<T>. On conserve également la possibilité de faire un extends d'une de nos propres
	 * classes et on ne rédéfinit que les méthodes qui nous intéressent. Nous ne sommes pas
	 * obligés d'implémenter toute l'interface List<T> 
	 */
	protected List<T> cartes;
	
	protected abstract void creerPaquet();
	
	
	
	public Paquet() {
		super();
		this.creerPaquet();
		this.shuffle();
	}

	/*
	 * façade : redéfinition de la méthode size
	 */
	public int size() {
		return this.cartes.size();
	}
	
	/*
	 * façade : redéfinition de la méthode add qui retourne un booléen toujours true
	 */
	public boolean add(T uneCarte) {
		return cartes.add(uneCarte);
	}
	
	/*
	 * façade : redéfinition de la méthode get
	 */
	public T get(int i) {
		T carte = cartes.get(i);
		return carte;
	}
	
	protected String toString(int nbColonnes) {
		String rep="";
		for (int i = 0; i < this.size(); i++) {
			T elem = cartes.get(i);
			rep+=elem.toString();
			if (i%nbColonnes==(nbColonnes-1)) {
				rep+="\n";
			}
		}
		return rep;
	}
	
	@Override
	public String toString() {
		return this.toString(5);
	}
	
	public void shuffle() {
		Collections.shuffle(cartes);
	}
	
}
