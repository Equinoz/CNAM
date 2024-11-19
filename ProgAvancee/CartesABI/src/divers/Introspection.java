package divers;

import cartes.carte.Carte;
import cartes.carte.Carte32;
import cartes.carte.enums.Atout;
import cartes.carte.enums.Valeur;

public class Introspection {

	/**
	 * Vous pouvez ici mettre vos tests pour l'introspection
	 * @param args
	 */
	public static void main(String[] args) {
		Carte32 c32 = new Carte32(Valeur.AS, Atout.CARREAU);
		Carte c = (Carte) c32;
		System.out.println(c32.getClass());
		System.out.println(c.getClass());

	}

}
