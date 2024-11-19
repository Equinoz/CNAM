package cartes;

import java.util.ArrayList;

import cartes.carte.Carte52;
import cartes.carte.enums.Atout;
import cartes.carte.enums.Valeur;

public class Paquet52 extends Paquet<Carte52> {

	// instance privée agrégée pour le singleton
	private static Paquet52 instance=null;
	
	// méthode publique getInstance pour le singleton
	public static Paquet52 getInstance() {
		if (instance==null) {
			instance = new Paquet52();
		}
		return instance;
	}
	
	//constructeur privé pour le singleton
	private Paquet52() {
		super();
	}
	
	protected void creerPaquet() {
		super.cartes= new ArrayList<Carte52>(52);
		for (Atout atout : Atout.values()) {
			for (Valeur valeur : Valeur.values()) {
				super.add(new Carte52(valeur, atout));
			}
		}		
	}

	@Override
	public String toString() {		
		return super.toString(6);
	}
	
}
