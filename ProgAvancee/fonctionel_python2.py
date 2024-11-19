# Suite exercices fonctionnels python

#4)
def returnNumbers(min, max, predicat):
  return [x for x in range(min, max) if predicat(x)]

print("ReturnNumbers", returnNumbers(3, 37, lambda x: x % 4  == 0)) # Renvoie les multiples de 4 du nombre 3 inclus à 37 exclus

#5)
# [4, 9] deux fois, la première fois je me suis fait avoir avec la compréhension de liste j'avais donc répondu:
# 4
# 9
# [4, 9]


#6)
def nbVoyelles(text):
  VOYELLES_FR = "AaÀàEeÈèÉéIiOoUuÙùYy"
  return len([x for x in text if x in VOYELLES_FR])

print("nbVoyelles", nbVoyelles("Ceci est ma phrase de test qui doit renvoyer 16"))

#7)
def f(func):
  return lambda x, y: func(func(x, y), func(x, y))

def multiply(a, b):
  return a * b
  
print("multiply", f(multiply)(2, 4)) # 2 x 4 x 2 x 4 renvoie 64