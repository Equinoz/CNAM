#1)
results = {}

def fibo(n):
  result = 0
  if n in results.keys():
    result = results[n]
  elif n > 30:
    result = None
  elif n < 1:
    result = (0, 1)
  elif n < 3:
    result = (1, 1)
  else:
    (firstValue, nbIterations1) = fibo(n-1)
    (secondValue, nbIterations2) = fibo(n-2)
    result = (firstValue + secondValue, nbIterations1 + nbIterations2)

  results[n] = result
  return result


#2)
add = lambda x, y: x + y
substract = lambda x, y: x - y
multiply = lambda x, y: x * y
divide = lambda x, y: x / y

#3)
isPair = lambda x: x % 2 == 0
isMultipleOf42 = lambda x: x % 42 == 0