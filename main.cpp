/*
 * main.cpp
 *
 *  Created on: 8 abr. 2020
 *      Author: amaia
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits>
#include <iostream>
using namespace std;
#include "Users/Runner.h"
#include "Users/Participant.h"
#include "Users/Employee.h"
using namespace users;
#include "Race/race.h"
using namespace race;
#include "SQLite/sqlite3.h"
#include "SQLite/DBManager.h"

void cleanBuffer()
{
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
int main(void)
{
	//Variables para los ficheros
	FILE *f;
	int num;
	bool find = false;

	//Variables para navegar a traves de los menus
	char opcionIni;
	char opcionAdmin;
	char back;

	//Variable para iniciar sesion como Admin
	char *passAdmin;

	//Variable para la contraseña de corredor
	char *passRunner;
	char pass[100];
	int intentosRunner = 0;
	char opcionCorredor;

	//Variable para contraseña de trabajador
	int intentosWorker = 0;
	char opcionWorker;

	//Variable para no leer caracteres de más
	char str[50];
	string s;
	char desc[100];

	//Variable para modificación de datos del corredor
	char *dni;

	int number;
	//Variables para la creación/modificación/eliminación de carreras
	int id;
	Employee employee;
	Employee organizer;
	Runner runner;
	Race *races;
	Race rc;

	//Variables para alta/baja de un trabajador
	char *nss;

	do
	{
		cout << "\nINICIO DE SESION" << endl;
		cout << "----------------" << endl;
		cout << "Iniciar sesion como:" << endl;
		cout << "1.- Corredor." << endl;
		cout << "2.- Trabajador." << endl;
		cout << "3.- Administrador." << endl;
		cout << "4.- Registarse como corredor." << endl;
		cout << "Pulsar 'q' para salir." << endl;

		scanf("%c", &opcionIni);
		cleanBuffer();
		Runner r;
		switch (opcionIni)
		{
		case '1':
			intentosRunner = 0;
			while (intentosRunner != 3 || opcionCorredor != '5')
			{
				cout << "\nIntroduzca el dni de corredor: " << endl;
				cin >> str;
				dni = new char[strlen(str) + 1];
				strcpy(dni, str);
				cleanBuffer();
				cout << "Introduzca contrase�a: " << endl;
				cin >> str;
				passRunner = new char[strlen(str) + 1];
				strcpy(passRunner, str);
				cleanBuffer();

				if (getPassword(dni, pass) != SQLITE_OK)
				{
					cout << "No se encuentra el DNI." << endl;
					break;
				}
				if (strcmp(passRunner, pass) == 0)
				{
					do
					{
						cout << "\nMENU CORREDORES" << endl;
						cout << "------------------" << endl;
						cout << "1.- Apuntarte a carrera." << endl;
						cout << "2.- Desapuntarte a carrera." << endl;
						cout << "3.- Editar tus datos." << endl;
						cout << "4.- Ver tus estadisticas." << endl;
						cout << "5.- Atrás." << endl;

						scanf("%c", &opcionCorredor);
						cleanBuffer();
						switch (opcionCorredor)
						{
						case '1':
							cout << "\nMENU" << endl;
							cout << "----" << endl;
							cout << "1.- Listado de carreras." << endl;
							cout << "2.- Apuntarse de carrera." << endl;
							cout << "3.- Atrás." << endl;
							scanf("%c", &opcionCorredor);
							cleanBuffer();
							switch (opcionCorredor)
							{
							case '1':
								showAllRaces();
								break;
							case '2':
								cout << "Cual es el id de la carrera a la que te quieres apuntar:" << endl;
								scanf("%i", &id);
								cleanBuffer();
								cout << "Introduzca el n�mero del dorsal: "
									 << endl;
								cin >> number;
								cleanBuffer();
								joinRace(dni, id, number);
								break;
							case '3':
								break;
							}
							break;
						case '2':
							cout << "\nMENU" << endl;
							cout << "----" << endl;
							cout << "1.- Listado de carreras." << endl;
							cout << "2.- Desapuntarse de carrera." << endl;
							cout << "3.- Atrás." << endl;

							scanf("%c", &opcionCorredor);
							cleanBuffer();
							switch (opcionCorredor)
							{
							case '1':
								showJoinedRaces(dni);
								break;
							case '2':
								cout << "Cual es el id de la carrera de la que te quieres desapuntar:" << endl;
								scanf("%i", &id);
								cleanBuffer();
								deleteParticipant(dni, id);
								break;
							case '3':
								break;
							}
							break;
						case '3':
							r.modifyRunner(dni);
							break;
						case '4':
							r.verEstadisticas(dni);
							//TODO
							break;
						case '5':
							intentosRunner = 3;
							break;
						default:
							cout << "ERROR. La opcion elegida no es correcta."
								 << endl;
						}
					} while (opcionCorredor != '5');
				}
				else
				{
					cout << "Contraseña incorrecta." << endl;
				}
				if (intentosRunner != 3)
					intentosRunner++;
			}
			break;
		case '2':
			cout << "\nIntroduzca su nss: " << endl;
			cin >> str;
			nss = new char[strlen(str) + 1];
			strcpy(nss, str);
			cleanBuffer();
			if (foundEmployee(nss) == SQLITE_OK)
			{
				do
				{
					cout << "\nMENU TRABAJADOR" << endl;
					cout << "------------------" << endl;
					cout << "1.- Ver tu tarea." << endl;
					cout << "2.- Notificar baja." << endl;
					cout << "3.- Editar tus datos." << endl;
					cout << "4.- Solicitar cambio de tarea." << endl;
					cout << "5.- Introducir resultados de carreras." << endl;
					cout << "6.- Atrás." << endl;

					scanf("%c", &opcionWorker);
					cleanBuffer();
					switch (opcionWorker)
					{
					case '1':
						cout << "\nTarea" << endl;
						cout << "-----" << endl;
						showTask(nss);
						break;
					case '2':
						cout << "Introduzca una breve descripci�n del motivo de su baja: " << endl;
						getline(cin, s);
						strcpy(desc, s.c_str());
						cleanBuffer();
						sendNotification(nss, "BAJA", desc);
						break;
					case '3':
						employee.modifyEmployee(nss);
					case '4':
						cout << "Introduzca una breve descripci�n del motivo: " << endl;
						getline(cin, s);
						strcpy(desc, s.c_str());
						sendNotification(nss, "CAMBIO TAREA", desc);
						break;
					case '5':
						cout << "Introduzca el id de la carrera: " << endl;

						scanf("%i", &id);
						cleanBuffer();
						find = false;
						num = 0;
						if ((f = fopen("races.dat", "rb")) != NULL)
						{
							int num = fgetc(f);
							races = new Race[num];
							fread(races, sizeof(Race), num, f);
							find = true;
						}
						else
						{
							cout
								<< "No se ha encontrado el fichero de carreras."
								<< endl;
						}
						fclose(f);
						if (find)
						{
							for (int i = 0; i < num; i++)
							{
								if (races[i].getId() == id)
								{
									Participant *participants =
										races[i].getParticipants();
									for (int j = 0; j < races[i].getNP(); j++)
									{
										cout << "Corredor "
											 << participants[j].getName()
											 << ":" << endl;
										cout
											<< "Introduzca la posición en la que llego el corredor: "
											<< endl;

										int pos;
										scanf("%i", &pos);
										cleanBuffer();
										participants[j].setNumber(pos);
										cout
											<< "Introduzca el tiempo que hizo (hh:mm:ss): "
											<< endl;
										cin >> str;
										participants[j].setTime(str);
										cleanBuffer();
									}
								}
							}

							f = fopen("races.dat", "wb");
							fputc(num, f);
							fwrite(races, sizeof(Race), num, f);
							fclose(f);
							free(races);
						}
						break;
					case '6':
						intentosWorker = 3;
						break;
					default:
						cout << "ERROR. La opcion elegida no es correcta."
							 << endl;
					}
				} while (opcionWorker != '6' || intentosWorker != 3);
			}
			else
			{
				cout << "Contraseña incorrecta." << endl;
			}
			if (intentosWorker != 3)
				intentosWorker++;
			break;
		case '3':
			do
			{
				cout << "Introduzca la contraseña de administrador: " << endl;

				cin >> str;
				passAdmin = new char[strlen(str) + 1];
				strcpy(passAdmin, str);
				cleanBuffer();
				char *key = "alpharunners";
				if (strcmp(key, passAdmin) == 0)
				{
					checkNotifications();
					do
					{
						cout << "\nMENU ADMINISTRADOR" << endl;
						cout << "------------------" << endl;
						cout << "1.- Administrar carreras." << endl;
						cout << "2.- Administrar corredores." << endl;
						cout << "3.- Administrar trabajadores." << endl;
						cout << "4.- Atrás." << endl;

						scanf("%c", &opcionAdmin);
						cleanBuffer();
						switch (opcionAdmin)
						{
						case '1':
							do
							{
								cout << "\nADMINISTRACION DE CARRERAS" << endl;
								cout << "--------------------------" << endl;
								cout << "1.- Crear una carrera." << endl;
								cout << "2.- Modificar carrera." << endl;
								cout << "3.- Eliminar una carrera." << endl;
								cout << "4.- Añadir resultados de una carrera."
									 << endl;
								cout << "5.- Atrás." << endl;

								scanf("%c", &opcionAdmin);
								cleanBuffer();
								switch (opcionAdmin)
								{
								case '1':
									rc.createRace();
									break;
								case '2':
									cout << "Introduzca el id de la carrera: "
										 << endl;

									scanf("%i", &id);
									cleanBuffer();
									//modifyRace(id);
									break;
								case '3':
									cout << "Introduzca el id de la carrera: "
										 << endl;

									scanf("%i", &id);
									cleanBuffer();
									rc.deleteRace(id);
									break;
								case '4':
									cout << "Introduzca el id de la carrera: "
										 << endl;

									scanf("%i", &id);
									cleanBuffer();
									//introduceResults(id);
									break;
								case '5':
									break;
								default:
									cout
										<< "ERROR. La opcion elegida no es correcta."
										<< endl;
								}
							} while (opcionAdmin != '5');
							break;
						case '2':
							do
							{
								cout << "\nADMINISTRACION DE CORREDORES"
									 << endl;
								cout << "--------------------------" << endl;
								cout << "1.- Registrar un corredor." << endl;
								cout << "2.- Modificar un corredor." << endl;
								cout << "3.- Atrás." << endl;

								scanf("%c", &opcionAdmin);
								cleanBuffer();
								switch (opcionAdmin)
								{
								case '1':
									cout << "REGISTRO DE CORREDOR" << endl;
									cout << "--------------------" << endl;
									runner.getInformation();
									insertNewRunner(runner);
									break;
								case '2':
									cout
										<< "Introduzca el DNI del corredor del que quieres modificar sus datos: "
										<< endl;

									cin >> str;
									dni = new char[strlen(str) + 1];
									strcpy(dni, str);
									cleanBuffer();
									//modifyRunner(dni);
									break;
								case '3':
									break;
								default:
									cout
										<< "ERROR. La opcion elegida no es correcta."
										<< endl;
								}
							} while (opcionAdmin != '3');
							break;
						case '3':
							do
							{
								cout << "\nADMINISTRACION DE TRABAJADORES"
									 << endl;
								cout << "------------------------------"
									 << endl;
								cout << "1.- Dar de alta a un trabajador."
									 << endl;
								cout << "2.- Modificar datos de trabajador."
									 << endl;
								cout << "3.- Dar de baja a un trabajador."
									 << endl;
								cout << "4.- Atrás." << endl;

								scanf("%c", &opcionAdmin);
								cleanBuffer();
								switch (opcionAdmin)
								{
								case '1':
									cout << "REGISTRO DE EMPLEADO" << endl;
									cout << "--------------------" << endl;
									employee.getInformation();
									insertNewEmployee(employee);
									break;
								case '2':
									cout << "Introduzca el nss del trabajador:"
										 << endl;

									cin >> str;
									nss = new char[strlen(str) + 1];
									strcpy(nss, str);
									//modifyEmployeeA(nss);
									break;
								case '3':
									cout << "\nBAJA DE TRABAJADOR" << endl;
									cout << "------------------" << endl;
									cout << "Introduzca el nss del trabajador:"
										 << endl;

									cin >> str;
									nss = new char[strlen(str) + 1];
									strcpy(nss, str);
									cleanBuffer();

									num = 0;
									Employee *employees;

									if ((f = fopen("employees.dat", "rb")) != NULL)
									{
										num = fgetc(f);
										employees = new Employee[num];
										fread(employees, sizeof(Employee), num,
											  f);
										find = true;
									}
									else
									{
										cout
											<< "No se ha encontrado el fichero de empleados."
											<< endl;
										find = false;
									}
									fclose(f);

									if (find)
									{
										for (int i = 0; i < num; i++)
										{
											if (strcmp(employees[i].getNss(),
													   nss) == 0)
											{
												strcpy(employees[i].getState(),
													   "BAJA");
												cout
													<< "Se ha dado de baja correctamente al trabajador "
													<< employees[i].getName()
													<< "." << endl;
												find = true;
												break;
											}
											else
											{
												find = false;
											}
										}

										if (!find)
										{
											cout
												<< "No se ha podido encontrar al trabajador."
												<< endl;
										}

										f = fopen("employees.dat", "wb");
										fputc(num, f);
										fwrite(employees, sizeof(Employee), num,
											   f);
										fclose(f);
										free(employees);
									}

									break;
								case '4':
									break;
								default:
									cout
										<< "ERROR. La opcion elegida no es correcta."
										<< endl;
								}
							} while (opcionAdmin != '4');
							opcionAdmin = '3';
							break;
						case '4':
							break;
						default:
							cout << "ERROR. La opcion elegida no es correcta."
								 << endl;
						}
					} while (opcionAdmin != '4');
				}
				else
				{
					cout << "Contraseña erronea." << endl;
				}
				cout << "�Desea volver al menú inicial? S/N" << endl;

				scanf("%c", &back);
				cleanBuffer();
			} while (back != 'S' && back != 's');
			break;
		case '4':
			cout << "REGISTRO DE CORREDOR" << endl;
			cout << "--------------------" << endl;
			runner.getInformation();
			insertNewRunner(runner);
			break;
		case 'q':
			break;
		default:
			cout << "ERROR. La opcion elegida no es correcta." << endl;
		}
	} while (opcionIni != 'q');
	return 0;
}
