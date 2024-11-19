package cartes.carte;

import cartes.carte.enums.Atout;
import cartes.carte.enums.Valeur;

public class Carte32 extends CarteClassique {

	private static final String DOS_CARTE="[****]";
	

	public Carte32(Valeur valeurCarte, Atout couleurCarte) {
		super(DOS_CARTE, valeurCarte, couleurCarte);
		// vérification simple de la valeur
		if (valeurCarte.ordinal()<Valeur.SEPT.ordinal()) {
			System.out.println("PROBLEME Carte 32, Valeur non autorisée");
		}
	}

	
	

}
