package cartes.carte.enums;

public enum Valeur {
	DEUX("02"),TROIS("03"),QUATRE("04"),CINQ("05"),SIX("06"),
	SEPT("07"),HUIT("08"),NEUF("09"),DIX("10"),
	VALET("VA"),DAME("DA"),ROI("RO"),AS("AS");

	private String deuxLettres;

	private Valeur(String deuxLettres) {
		this.deuxLettres=deuxLettres;
	}

	public String toString() {
		return deuxLettres;
	}
	
	public static Valeur get(int i) {
		return Valeur.values()[i];
	}
	
}
