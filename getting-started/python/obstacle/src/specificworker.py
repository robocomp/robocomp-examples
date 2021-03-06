#
# Copyright (C) 2019 by YOUR NAME HERE
#
#    This file is part of RoboComp
#
#    RoboComp is free software: you can redistribute it and/or modify
#    it under the terms of the GNU General Public License as published by
#    the Free Software Foundation, either version 3 of the License, or
#    (at your option) any later version.
#
#    RoboComp is distributed in the hope that it will be useful,
#    but WITHOUT ANY WARRANTY; without even the implied warranty of
#    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#    GNU General Public License for more details.
#
#    You should have received a copy of the GNU General Public License
#    along with RoboComp.  If not, see <http://www.gnu.org/licenses/>.
#

import sys, os, traceback, time

from PySide import QtGui, QtCore
from genericworker import *

class SpecificWorker(GenericWorker):
	def __init__(self, proxy_map):
		super(SpecificWorker, self).__init__(proxy_map)
		self.timer.timeout.connect(self.compute)
		self.Period = 2000
		self.timer.start(self.Period)

	def setParams(self, params):
		#try:
		#	self.innermodel = InnerModel(params["InnerModelPath"])
		#except:
		#	traceback.print_exc()
		#	print "Error reading config params"
		return True

	@QtCore.Slot()
	def compute(self):
		print 'SpecificWorker.compute...'
		rot = 0.7
		try:
			ldata = []
			d = []
			ldata = self.laser_proxy.getLaserData();
			for i in range(0,len(ldata)):
				dis = ldata[i]
				y = dis.dist
				d.append(y)
			d.sort()
			distance = d[0]
			print distance
			if distance < 400:
				self.differentialrobot_proxy.setSpeedBase(0, rot)
				time.sleep(1)
				rot = rot+ 0.5
				if rot > 3:
					rot = 1
				self.differentialrobot_proxy.setSpeedBase(70, 0)
				time.sleep(1)
			else:
				self.differentialrobot_proxy.setSpeedBase(100, 0)
				time.sleep(1)
		except Ice.Exception, e:
			traceback.print_exc()
			print e
		return True

