/**
 * \file Modem.h
 * \brief Classe Modem
 * \author Team CISSAU - Veni Vidi Vici (ENSTA Bretagne)
 * \version 0.1
 * \date Jun 5th 2013
 *
 * Application MOOS permettant le dialogue entre les AUV par modem
 *
 */

#ifndef Modem_HEADER
#define Modem_HEADER

#include <vector>
#include "../common/constantes.h"
#include "MOOS/libMOOS/App/MOOSApp.h"

using namespace std;

class Modem : public CMOOSApp
{
	public:
		Modem();
		~Modem();

	protected:
		bool OnNewMail(MOOSMSG_LIST &NewMail);
		bool Iterate();
		bool OnConnectToServer();
		bool OnStartUp();
		void RegisterVariables();
		bool envoyerMessage(char* message);
		bool attendreConfirmationBonneReception();

	private: // Configuration variables

	private: // State variables
		unsigned int	m_iterations;
		double			m_timewarp;
		vector<string>	m_listeVariablesSuivies;
		bool			m_anomalie_detectee;
		double 			m_position_x_anomalie;
		double 			m_position_y_anomalie;
		double 			m_position_z_anomalie;
		bool 			m_position_x_anomalie_recue;
		bool 			m_position_y_anomalie_recue;
		bool 			m_position_z_anomalie_recue;
};

#endif 