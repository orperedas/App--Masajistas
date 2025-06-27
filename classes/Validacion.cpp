#include <iostream>
#include <string>
#include <cctype>

using namespace std;
/*
class Validacion{
    public:
        bool empiezaConMayuscula(std::string* cadena){
            if(!isupper(cadena[0])){
                std::cerr << "Error: debe comenzar con letra mayúscula." << endl;
                return false;
            }

            return true;
        }

        bool esImprimible(std::string* cadena){
            for(int i = 0; cadena[i]; i++){
                if(!isprint(cadena[i])){
                    std::cerr << "Error: contiene caracteres no imprimibles." << endl;
                    return false;
                }
            }

            return true;
        }

        bool contieneArrobaYPunto(std::string* cadena){
            std::string* arroba = strchr(cadena, '@');
            std::string* punto = strchr(cadena, '.');

            if(!arroba){
                std::cerr << "Error: falta el carácter '@' en el email." << endl;
                return false;
            }

            if(!punto){
                std::cerr << "Error: el email debe contener un '.' después del '@'." << endl;
                return false;
            }

            return true;
        }

        bool longitudEntre(std::string* cadena, int maxLongitud, int minLongitud){
            if(strlen(cadena) == minLongitud){
                std::cout << "El campo no puede estar vacío." << endl;
                return false;
            }

            if(strlen(cadena) > maxLongitud){
                std::cerr << "Ha excedido el máximo de caracteres permitidos \"50\"." << endl;
                return false;
            }

            return true;
        }

        bool longitudFija(std::string* cadena, int longitud){
            if(strlen(cadena) != longitud){
                std::cerr << "Error: debe tener exactamente " << longitud << " dígitos." << endl;
                return false;
            }

            return true;
        }

        bool soloDigitos(std::string* cadena){
            for(int i = 0; cadena[i]; i++){
                if(!isdigit(cadena[i])){
                    std::cerr << "Error: el valor ingresado debe contener solo caracteres numéricos." << endl;
                    return false;
                }
            }

            return true;
        }

        bool soloLetras(std::string* cadena){
            for(int i = 0; cadena[i]; i++){
                if(!isalpha(cadena[i])){
                    std::cerr << "Error: el valor ingresado debe contener solo letras." << endl;
                    return false;
                }
            }

            return true;
        }

        bool valorFloatEntre(float valor, float valorMinimo, float valorMaximo){
            if(valor <= valorMinimo){
                std::cerr << "Error: El valor no puede ser menor a " << valorMinimo << endl;
                return false;
            }

            if(valor > valorMaximo){
                std::cerr << "El valor máximo no puede ser mayor a " << valorMaximo << endl;
                return false;
            }

            return true;
        }

        bool valorIntEntre(int valor, int valorMinimo, int valorMaximo){
            if(valor <= valorMinimo){
                std::cerr << "El servicio no puede tener menos de " << valorMinimo << " horas." << endl;
                return false;
            }

            if(valor > valorMaximo){
                std::cerr << "El servicio no puede tener más de " << valorMaximo << " horas." << endl;
                return false;
            }

            return true;
        }



        bool validarApellido(std::string* apellido){
            if(!longitudEntre(apellido, 1, 20)) return false;
            if(!soloLetras(apellido)) return false;
            if(!empiezaConMayuscula(apellido)) return false;
            return true;
        }

        bool validarCuit(std::string* cuit){
            if(!soloDigitos(cuit)) return false;
            if(!longitudFija(cuit, 11)) return false;
            return true;
        }

        bool validarDescripcion(std::string* descripcion){
            if(!longitudEntre(descripcion, 1, 200)) return false;
            if(!esImprimible(descripcion)) return false;
            return true;
        }

        bool validarDireccion(std::string* direccion){
            if(!longitudEntre(direccion, 1, 50)) return false;
            if(!esImprimible(direccion)) return false;
            return true;
        }

        bool validarDni(std::string* dni){
            if(!longitudFija(dni, 8)) return false;
            if(!soloDigitos(dni)) return false;
            return true;
        }

        bool validarEmail(std::string* email){
            return contieneArrobaYPunto(email);
        }

        bool validarHoras(int horas){
            return valorIntEntre(horas, 2, 10);
        }

        bool validarModalidad(std::string* modalidad){
            if(!longitudEntre(modalidad, 1, 20)) return false;
            if(!soloLetras(modalidad)) return false;
            return true;
        }

        bool validarNombre(std::string* nombre){
            if(!soloLetras(nombre)) return false;
            if(!empiezaConMayuscula(nombre)) return false;
            return true;
        }


        bool validarTelefono(std::string* telefono){
            if(!longitudEntre(telefono, 10, 15)) return false;
            if(!soloDigitos(telefono)) return false;
            return true;
        }

        bool validarValorHora(float valorHora){
            return valorFloatEntre(valorHora, 1000.00, 100000.00);
        }
};
*/
