/*
 *    Copyright (C)2018 by YOUR NAME HERE
 *
 *    This file is part of RoboComp
 *
 *    RoboComp is free software: you can redistribute it and/or modify
 *    it under the terms of the GNU General Public License as published by
 *    the Free Software Foundation, either version 3 of the License, or
 *    (at your option) any later version.
 *
 *    RoboComp is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU General Public License for more details.
 *
 *    You should have received a copy of the GNU General Public License
 *    along with RoboComp.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "specificworker.h"

/**
* \brief Default constructor
*/
SpecificWorker::SpecificWorker(MapPrx& mprx) : GenericWorker(mprx)
{

}

/**
* \brief Default destructor
*/
SpecificWorker::~SpecificWorker()
{

}

bool SpecificWorker::setParams(RoboCompCommonBehavior::ParameterList params)
{
//       THE FOLLOWING IS JUST AN EXAMPLE
//	To use innerModelPath parameter you should uncomment specificmonitor.cpp readConfig method content
//	try
//	{
//		RoboCompCommonBehavior::Parameter par = params.at("InnerModelPath");
//		std::string innermodel_path = par.value;
//		innerModel = new InnerModel(innermodel_path);
//	}
//	catch(std::exception e) { qFatal("Error reading config params"); }




	timer.start(Period);


	return true;
}

void SpecificWorker::compute( )
{
	int num;
	char input[0];
	std::cout << " Enter \n 1: forward \n 3: left \n 2: backward \n 4: right" << endl;
	std::cin >> input;
	istringstream ( input ) >> num;

	if (num == 1 )
	{
		differentialrobot_proxy->setSpeedBase(300, 0); 
  		usleep(750000);
		differentialrobot_proxy->setSpeedBase(0, 0); 
  		usleep(500000);
	}
	if (num == 2)
	{
		differentialrobot_proxy->setSpeedBase(-300, 0); 
  		usleep(750000);
		differentialrobot_proxy->setSpeedBase(0, 0); 
  		usleep(500000);
	}
	if (num == 3)
	{
		differentialrobot_proxy->setSpeedBase(5, 1.5707); 
  		usleep(1000000);
		differentialrobot_proxy->setSpeedBase(0, 0); 
  		usleep(500000);
	}
	if (num == 4)
	{
		differentialrobot_proxy->setSpeedBase(5, -1.5707); 
  		usleep(1000000);
		differentialrobot_proxy->setSpeedBase(0, 0); 
  		usleep(500000);
	}
	else
	{
		std::cout << "invalid entry" << endl;
	}


}


