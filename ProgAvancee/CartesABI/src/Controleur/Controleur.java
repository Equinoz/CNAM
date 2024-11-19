package Controleur;

import cartes.Paquet52;
import cartes.PlusOuMoins;
import cartes.carte.Carte52;
import cartes.carte.ICarte;
import ihm.IOKeyBoardConsole;

public class Controleur {
	
	private PlusOuMoins<Carte52> jeu = new PlusOuMoins<Carte52>(Paquet52.getInstance());
	
	public Controleur() {
		super();
		Paquet52 paquet = Paquet52.getInstance();
		jeu = new PlusOuMoins<Carte52>(paquet);
		this.jouer();
	}
	
	
	public void jouer() {
		IOKeyBoardConsole.print("Bienvenue au jeu du plus ou moins");
		String rep = IOKeyBoardConsole.readAString("jouer o/n ?");
		int indice = 0;
		int taille = jeu.size();
		boolean fini = (rep.equals("n") || (indice>(taille-1)));
		boolean coupGagnant=true;
		ICarte carteCourante=jeu.get(0);
		carteCourante.tourner();
		while (!fini) {
			rep = lireComparaison();
			ICarte prochaineCarte = jeu.get(indice+1); // indice < taille-1
			prochaineCarte.tourner();
			IOKeyBoardConsole.print(jeu.getPaquet());			
			switch (rep) {
			case "q":
				fini = true;
				IOKeyBoardConsole.print("au revoir");
				break;
			case "+":
				coupGagnant=prochaineCarte.estSuperieureOuEgale(carteCourante);
				break;
			case "-":
				coupGagnant=carteCourante.estSuperieureOuEgale(prochaineCarte);
				break;
			default:
				IOKeyBoardConsole.print("choix interdit");
				coupGagnant = false;
			}

			if(!fini) {
				if (coupGagnant) {
					IOKeyBoardConsole.print("coup gagnant");
					jeu.gain();
				} else {
					IOKeyBoardConsole.print("coup perdant");
					jeu.perte();
				}
				carteCourante.tourner(); // on cache la carte précédente, la prochaine carte est toujours visible
				indice++;
				fini = (jeu.getScore()== 0) || (indice == taille-1); // si la carte courante est la dernière, c'est fini
				if (!fini) {
					carteCourante=jeu.get(indice);
				}
			}
			IOKeyBoardConsole.print("score = "+jeu.getScore());
		}
	}

	private String lireComparaison() {
		String rep;
		IOKeyBoardConsole.print(jeu.getPaquet());
		rep = IOKeyBoardConsole.readAString("la prochaine carte est-elle supérieure + ou inférieure - ? q pour quitter");
		return rep;
	}


}
