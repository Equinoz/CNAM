package cartes.carte.enums;

public enum Atout {
	// Il faut être en UTF-8 avec Eclipse (preference-general-content type-text / projet-propriétés-ressources )
	PIQUE("♠"), COEUR("♥"), CARREAU("♦"), TREFLE("♣");

	//PIQUE("PIK"), COEUR("COE"), CARREAU("CAR"), TREFLE("TFL");

	private final String visuel;
	
	private Atout(String visuel) {
		this.visuel = visuel;
	}

	@Override
	public String toString() {
		return visuel;
	}
	
}
