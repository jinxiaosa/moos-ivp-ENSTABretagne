/**
 * \file Camera.h
 * \brief Classe Camera
 * \author Team CISSAU - Veni Vidi Vici (ENSTA Bretagne)
 * \version 0.1
 * \date Jun 5th 2013
 *
 * Application MOOS récupérant les données de la caméra orientée vers l'avant
 *
 */

#ifndef Camera_HEADER
#define Camera_HEADER

/*<<<<<<< HEAD
// yangrui find problem here
#include <cv.h> //available only for opencv3
#include <highgui.h>
=======*/
#include <opencv/cv.h>
#include <opencv2/highgui/highgui.hpp>
//>>>>>>> upstream_vinc/master

#include "../common/constantes.h"
#include "MOOS/libMOOS/App/MOOSApp.h"

#include "videograbv4l2.h"

using namespace std;
using namespace cv;

class Camera : public CMOOSApp
{
	public:
		Camera();
		~Camera();

	protected:
		bool OnNewMail(MOOSMSG_LIST &NewMail);
		bool Iterate();
		bool OnConnectToServer();
		bool OnStartUp();
		void RegisterVariables();

	private: // Configuration variables

	private: // State variables
		string			m_image_name, m_display_name;
		unsigned int	m_iterations;
		double			m_timewarp;
		bool			m_server;
		//VideoCapture	m_vc;
		VideoGrabV4L2	m_vc_v4l2;
		bool			m_affichage_image, m_inverser_image;
};

#endif 
