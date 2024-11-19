package cartes;

import cartes.carte.ICarte;

public interface IPaquet<T extends ICarte> {

	public boolean add(T uneCarte) ;
	public T get(int i);
	public void shuffle();

	public default int size() {
		return 0;
	}
	
}
