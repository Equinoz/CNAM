package cartes.carte;

import cartes.carte.enums.Atout;
import cartes.carte.enums.Valeur;

public abstract class CarteClassique extends Carte {

	private final Valeur valeur;
	private final Atout atout;

	public CarteClassique(String dos, Valeur valeur, Atout atout) {
		super(dos);
		this.valeur = valeur;
		this.atout = atout;
	}

	/**
	 * Carte32 c1 = new Carte32(...);
	 * Carte32 c2 = new Carte32(...);
	 * c1.estSuperieureOuEgale(c2);
	 	 */
	@Override
	public boolean estSuperieureOuEgale(ICarte carte) {
		boolean rep=false;
		try {
			CarteClassique carteClassique = (CarteClassique) carte;
			rep=this.valeur.ordinal()>=carteClassique.valeur.ordinal();
		} catch (ClassCastException e) {
			System.out.println("TODO DEBUG : problème de cast , ICarte comparée n'est pas une Carte Classique");
		}
		
		return rep;
	}

	@Override
	protected String getFace() {
		return "["+this.valeur.toString()+" "+this.atout.toString()+"]";
		
	}

}
