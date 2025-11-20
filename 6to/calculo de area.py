import math

class Figura:
    def area(self):
        print('Esta figura no tiene area')
        return None
    def pedirNum(self, mensaje):
        while True:
            valor=input(mensaje)
            if valor.replace('.','',1).isdigit():#asi puedo incluir decimales
                return float(valor)
            print('Ingrese numero valido')
            valor=input(mensaje)

class Circulo(Figura):
    def __init__(self):#los self e init son necesarios para clases
        self.radio=self.pedirNum('Radio de Circulo--> ')
    def area(self):
        return 3.14159 * (self.radio**2)

class Rectangulo(Figura):
    def __init__(self):
        self.ancho=self.pedirNum('Ancho de Rectangulo--> ')
        self.largo=self.pedirNum('Largo de Rectangulo--> ')
    def area(self):
        return self.ancho*self.largo

class Triangulo(Figura):
    def __init__(self):
        self.base=self.pedirNum('Base de triangulo--> ')
        self.altura=self.pedirNum('Altura de triangulo--> ')
    def area(self):
        return (self.base*self.altura) / 2

class Cuadrado(Rectangulo):
    def __init__(self):
        lado=self.pedirNum('Lado del cuadrado--> ')
        self.ancho=lado
        self.largo=lado

opciones={
    '1':('Circulo', Circulo),
    '2':('Rectangulo', Rectangulo),
    '3':('Triangulo', Triangulo),
    '4':('Cuadrado', Cuadrado),
    '5':('Salir', None)
}#me hago un diccionario

def menu():
    print('\n--- Calculo de areas ---')
    for key, valor in opciones.items():#recorre el diccionario con la clave y el valor asociado
        nombre =valor[0] #la clave es numero y el valor es tupla (nombrefig, classfig)
        print(key, '.', nombre) #.items para que devuelva 1 por uno
    op=input('\nElija la opcion:\n-->')
    if op in opciones: return op
    print('Opcion invalida')
    return None


while True:
    op=menu()
    if op is None:
        continue
    nombre, clase=opciones[op]#devuelve la tupla que le corresponde a lo elejido
    if op == '5': #ejem: ('Rectangulo', Rectangulo = 2)
        print('Saliendo...')
        break
    figura=clase()
    resultado=figura.area()
    print('\nArea', str(resultado))

