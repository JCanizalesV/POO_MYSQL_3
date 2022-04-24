#pragma once

#include <mysql.h>
#include <iostream>
#include <string>
#include "ConexionBD.h"
#include "Datos.h"

using namespace std;

class Proveedor : Datos {

private: string nit;

public:
	Proveedor() {
	}
	Proveedor(string dor, int tel, string dir, string n) : Datos(dor, tel, dir) {
		nit = n;
	}

	void crear() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string t = to_string(telefono);
			string insert = "INSERT INTO programacion.proveedores(proveedor,nit,direccion,telefono) VALUES('" + proveedo +"','" + nit + "','" + direccion + "'," + t + ");";
			const char* i = insert.c_str();
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado){
				cout << "El ingreso se realizo con exito...." << endl;
			}
			else{
				cout << "El ingreso produjo un error vuelva a intentarlo...." << endl;
			}

		}
		else {
			cout << "-----...ERROR EN LA CONEXION...-----" << endl;
		}
		cn.cerrar_conexion();
	}

	void mostrar() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();

		if (cn.getConectar()) {
			string consulta = "select * from programacion.proveedores";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());

				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << "," << fila[1] << "," << fila[2] << "," << fila[3] << "," << fila[4] << endl;
				}
			}
			else {
				cout << "----...Error al solicitar los datos...----" << endl;
			}
		}
		else {
			cout << "-----...ERROR EN LA CONEXION...-----" << endl;
		}
		cn.cerrar_conexion();
	}


	void actualizar() {
		int q_estado;
		int ac;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {

			cout << "INGRESE EL DATO QUE DESEA ACTUALIZAR:    ";
			cin >> ac;

			string t = to_string(telefono);
			string a = to_string(ac);

			string actualizar = "UPDATE programacion.proveedores SET proveedor = '" + proveedo + "', nit = '" + nit + "', direccion = '" + direccion + "', telefono = " + t + " WHERE idProveedores = " + a + "";
			const char* i = actualizar.c_str();
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "El dato se actualizo con exito....";
			}
			else {
				cout << "El actualizado presento un error...." << endl;
			}

		}
		else {
			cout << "-----...ERROR EN LA CONEXION...-----" << endl;
		}
		cn.cerrar_conexion();
	}

	void borrar() {
		int q_estado;
		int ac;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {

			cout << "INGRESE EL DATO QUE DESEA BORRAR:    ";
			cin >> ac;

			string t = to_string(telefono);
			string a = to_string(ac);

			string borrar = "DELETE FROM programacion.proveedores WHERE idProveedores="+ a +"";
			const char* i = borrar.c_str();
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "El dato se borro con exito....";
			}
			else {
				cout << "Se presento un error a la hora de eliminar el dato...." << endl;
			}
		}
		else {
			cout << "-----...ERROR EN LA CONEXION...-----" << endl;
		}
		cn.cerrar_conexion();
	}
};