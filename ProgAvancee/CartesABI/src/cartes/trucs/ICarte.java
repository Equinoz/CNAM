package cartes.carte;

import java.awt.Dimension;

public interface ICarte {
	
	public static final Dimension DIMENSION = new Dimension(59,91);
	
	public void tourner();

	public default boolean estSuperieureOuEgale(ICarte carte) {
		this.tourner();
		return false;
	}
}
