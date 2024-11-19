# Exercices fermetures python

#1)
def diviseListePar(divider):
  if divider == 0:
    raise NameError('Division by zero')
  return lambda listToDivide: [x / divider for x in listToDivide]

diviseListePar2 = diviseListePar(2)
print(diviseListePar2(range(20)))    


#2)
def compterNombre(value):
  return lambda listToSearch: len([x for x in listToSearch if x == value])

compterNombre2 = compterNombre(2)
print(compterNombre2([0,1,2,3,4,5,4,3,2,1,0])==2)
