package cartes.carte;

public abstract class Carte implements ICarte {

	private final String dos; 
	private boolean visible=false;

	protected abstract String getFace();	
	
	public Carte(String dos) {
		super();
		this.dos = dos;		
	}

	@Override
	public void tourner() {
		visible = ! visible;
	}	
	
	@Override
	public String toString() {
		String rep;
		if (!visible) {
			rep=dos;
		}
		else {
			rep=this.getFace();
		}
		return rep;
	}

	
	

}
