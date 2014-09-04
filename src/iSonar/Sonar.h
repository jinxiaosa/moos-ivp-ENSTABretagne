/**
 * \file Sonar.h
 * \brief Classe Sonar
 * \author Team CISSAU - Veni Vidi Vici (ENSTA Bretagne)
 * \version 0.1
 * \date Jun 5th 2013
 *
 * Application MOOS récupérant les données liées au sonar
 *
 */

#ifndef Sonar_HEADER
#define Sonar_HEADER

#include "../common/constantes.h"
//#include "SonarDF.h"
#include "seanetmsg.h"

#include <fstream>

#include "MOOS/libMOOS/App/MOOSInstrument.h"
/*#ifdef _WIN32
	#include "MOOS/libMOOS/Utils/MOOSNTSerialPort.h"
#else
	#include "MOOS/libMOOS/Utils/MOOSLinuxSerialPort.h"
#endif
*/

//#include <opencv/cv.hpp>

class Sonar : public CMOOSInstrument
{
        //friend bool listen_sonar_messages_thread_func(void *pSonarObject);
    
	public:
		Sonar();
		bool initialiserPortSerie(std::string nom_port);
		~Sonar();

	protected:
		bool OnNewMail(MOOSMSG_LIST &NewMail);
		bool Iterate();
		bool OnConnectToServer();
		bool OnStartUp();
		void RegisterVariables();
                
               void ListenSonarMessages();
               
               bool SendMessage(const SeaNetMsg & msg) {/*msg.print_hex();printf("\n");*/return (m_Port.Write(msg.data().data(), (int)msg.data().size()) == (int)msg.data().size());}

	private: // Configuration variables
		std::string m_portName;
		SeaNetMsg_HeadCommand m_msgHeadCommand;


	private: // State variables
		unsigned int			m_iterations;
		double			        m_timewarp;
		//CMOOSLinuxSerialPort	m_moos_serial_port;
		//SonarDF*				m_cissonar;
                bool m_bNoParams;
                bool m_bSentCfg;
                
                bool m_bSonarReady;
                bool m_bPollSonar;
		                
                CMOOSThread m_serial_thread;
                
                //cv::Mat img, img_polar;
                std::ofstream log1;
                std::ofstream log2;

    
        static bool listen_sonar_messages_thread_func(void *pSonarObject) {
            Sonar* pSonar = static_cast<Sonar*> (pSonarObject);
            if (pSonar) {
                pSonar->ListenSonarMessages();
                return true;
            }
            else return false;
        }
};

#endif 
