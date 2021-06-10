#ifndef MATERIAS_H_INCLUDED
#define MATERIAS_H_INCLUDED
#include <vector>
#include "iostream"
#include <string.h>
#include <list>
class materias {
private:
    int codigo;//codigo de la materia
    int creditos;//creditos de la materia
    string nombre;//nombre de la materia
    int coddoc;//codigo del docente que imparte la materia
public:
    bool activo;//estado de la materia
    materias(int cod, string nom, int cred);//constructor parametrizado
    materias(){};//constructor por defecto
    ~materias(){};//destructor por defecto
    bool registrarMat();//método para registrar una nueva materia
    void datosMat();//metodo para mostrar la informacion de la materia
    void modificaMat();//metodo para modificar la materia
    void eliminarMat(){};//metodo para eliminar la materia
    void borrarMat();//metodo para borrar la materia

    bool buscarMat(int id){
    if(id==codigo)
        return true;
    else
        return false;
    }
};
vector <materias> Vmaterias;//vector principal
materias::materias(int cod, string nom, int cred){
 codigo=cod;
 nombre=nom;
 creditos=cred;
 activo=true;
}
bool materias::registrarMat(){

    cout<<"Codigo de la materia:"<<endl;
    cin >>codigo;
        bool existe=false;
        for(int i = 0; i < Vmaterias.size(); i++)
        {
            //si el codigo ingresado coincide con alguno que se encuentre en la lista de materias existente se activa la bandera
            if (Vmaterias[i].buscarMat(codigo)==true)
            {
                btn.aviso("Esta materia ya existe");
                existe=true;
            }

        }
        if (existe!=true){
                //si aun no existe la materia entonces procede a pedir más información
            cout<<"Nombre de la materia:"<<endl;
            cin>>nombre;
            cout<<"Creditos de la materia:"<<endl;
            cin>>creditos;
            cout<<"Docente de la materia(codigo):"<<endl;
            cin>>coddoc;
            activo=true;
        }
   return existe;
}
void materias::datosMat(){
    cout<<"|Nombre:   |"<<nombre<<"\t|"<<endl;
    cout<<"|Codigo:   |"<<to_string(codigo)<<"\t|"<<endl;
    cout<<"|Creditos: | "<<to_string(creditos)<<"\t|"<<endl;
    cout<<"|Docente:  | "<<to_string(coddoc)<<"\t|"<<endl;
    cout<<"|-----------------------|"<<endl;
}
void materias::modificaMat(){
   int opc;
   btn.clean();
   datosMat();
    btn.boton("1.Nombre");
    btn.boton("2.Creditos");
    btn.boton("3.Codigo");
    btn.boton("4.Docente");
    cin>>opc;
    switch(opc){
        case 1:
            cout<<"Nuevo nombre: "<<endl;
            cin>>nombre;
            break;
        case 2:
            cout<<"Nuevo numero de creditos: "<<endl;
            cin>>creditos;
            break;
        case 3:
            cout<<"Nuevo codigo: "<<endl;
            cin>>codigo;
            break;
        case 4:
            cout<<"Nuevo codigo de docente: "<<endl;
            cin>>codigo;
            break;
        default:
            btn.aviso("Opcion no disponible");
            break;

    }
    btn.aviso("Cambios guardados con exito");
}
void materias::borrarMat(){
    activo=false;
    btn.aviso("La materia se ha eliminado");
}
void listarMat(){
    bool disponible;
    if (Vmaterias.empty())
        disponible = false;//si el vector de materias esta vacio no hay  materias disponibles
    else{
          for(int i = 0; i < Vmaterias.size(); i++)
          {
                //si la materia se encuentra activa muestra s informacion
                if(Vmaterias[i].activo==true)
                {
                    Vmaterias[i].datosMat();
                    disponible = true;//si al menos una materia esta activa significa que hay materias disponibles
                }

          }
    }
    if(disponible==false)
        btn.aviso("No existen materias disponibles" );
    btn.pausa();
}
void consultaxCodMat(){

if(Vmaterias.empty())
    btn.aviso("No existen materias dadas de alta");
else{
    int mat;
    cout<<"Ingresa el codigo de la materia a consultar"<<endl;
    cin >>mat;
        for(int i = 0; i < Vmaterias.size(); i++)
        {
            if (Vmaterias[i].buscarMat(mat)==true && Vmaterias[i].activo==true)
            {
                //si existe la materia y está activa entonces despliega la informacion y muestra las opciones
                Vmaterias[i].datosMat();
                int opc;
                btn.boton("1.Modificar");
                btn.boton("2.Eliminar");
                btn.boton("3.Volver");
                cin>>opc;
                if(opc==1)
                {
                    btn.clean();
                    Vmaterias[i].datosMat();
                    Vmaterias[i].modificaMat();
                }
                if(opc==2)
                {
                    Vmaterias[i].borrarMat();
                    break;
                }
            }
            else {
                if (Vmaterias[i].buscarMat(mat) == true && Vmaterias[i].activo == false)
                {
                    btn.aviso("La materia no se encuentra disponible");//si se encuentra una coincidencia pero no se encuentra activo
                    break;
                }
                if (Vmaterias[i].buscarMat(mat) == false && i == Vmaterias.size() - 1)
                    btn.aviso("La materia no se encuentra registrada");//si no se encontraron coincidencias y ya es el ultimo elemento de la lista
            }

        }

    }
    btn.pausa();
}
void nvaMat(){
    btn.titulo("Nueva materia:");
    materias mat;
    if(mat.registrarMat()!=true)
    {
        //sellama a funcion registrar materia y si no existia regresa un false para avisar que se puede agregar a la lista
        Vmaterias.push_back(mat);
        btn.aviso("Materia registrada con exito");
    }
    btn.pausa();
}


#endif // MATERIAS_H_INCLUDED
