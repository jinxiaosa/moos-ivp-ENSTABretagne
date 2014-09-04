/**
 * \file WallFollowing.h
 * \brief Classe WallFollowing
 * \author Team CISSAU - Veni Vidi Vici (ENSTA Bretagne)
 * \version 0.1
 * \date Jun 25th 2013
 *
 * Application MOOS de suivi de mur
 *
 */

#ifndef WallFollowing_HEADER
#define WallFollowing_HEADER

#include <map>
#include <list>
#include <utility>
#include <opencv/cv.h>
#include <opencv2/highgui/highgui.hpp>
#include "../common/constantes.h"
#include "MOOS/libMOOS/App/MOOSApp.h"

#define LARGEUR_MAPPING		400
#define HAUTEUR_MAPPING		400

using namespace cv;
using namespace std;

class WallFollowing : public CMOOSApp
{
	public:
		WallFollowing();
		~WallFollowing();

	protected:
		bool OnNewMail(MOOSMSG_LIST &NewMail);
		bool Iterate();
		bool OnConnectToServer();
		bool OnStartUp();
		void RegisterVariables();
		
		void computeAndSendCommands(double angle, double distance);

	private: // Configuration variables

	private: // State variables
		unsigned int	m_iterations;
		double			m_timewarp;
		Mat				m_map;
		float 			m_angle_precedent;
		int				m_nb_data;
		list<pair<float,float> > 	m_obstacles;
		
		bool m_regulate;
		double m_current_heading, m_last_heading;
};

#endif 