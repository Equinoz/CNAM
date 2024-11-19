package cartes;

import java.util.ArrayList;

import cartes.carte.Carte32;
import cartes.carte.enums.Atout;
import cartes.carte.enums.Valeur;

public class Paquet32 extends Paquet<Carte32> {
	
	// instance privée agrégée pour le singleton
	private static Paquet32 instance=null;
	
	// méthode publique getInstance pour le singleton
	public static Paquet32 getInstance() {
		if (instance==null) {
			instance = new Paquet32();
		}
		return instance;
	}
	
	//constructeur privé pour le singleton
	private Paquet32() {
		super();
	}

	protected void creerPaquet() {
		super.cartes= new ArrayList<Carte32>(32);
		for (Atout atout : Atout.values()) {
			for (int i = Valeur.SEPT.ordinal();
					i <= Valeur.AS.ordinal(); i++) {
				Valeur valeur = Valeur.get(i);
				super.add(new Carte32(valeur, atout));
			}
		}		
	}

	@Override
	public String toString() {		
		return super.toString(4);
	}
	
}
