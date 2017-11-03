/**
\author Jeanpetit Florent
*/

#ifndef NEURON_HPP	
#define NEURON_HPP
#include <iostream>
#include <cmath>
#include <vector>
#include <fstream>
#include <cassert>
#include <random>


using namespace std;

class Neuron
{
	private:

double membrane_pot_;
int nb_spikes_;
vector <double> spikes_time_;
vector <double> time_buffer_;
int delay_= 15;	
int internal_time_;
//true if exitatory
//false if inhibitory
bool E_;
double J_ = 0.1;

vector <int> connections_;

	 double C_ =(40.0); 
	 double tau_ =(20.0);
	 double tau_ref_ =(2.0);
	 double Vreset_ =(0.0);
	 double Vthreshold_ =(20.0);
	 double h_ =(0.1);
	 double R_ =(20.0);

	
	public:
	
//CONSTRUCTORS	
Neuron ();

// GETTERS	

/**
	 @return double // return step time = 0.1 ms 
	 */
double getH() const;
/**
	 @return double //  return membrane potential of the neuron
	 */
double getMembpot() const ;

/**
	 @return int // return number of spikes occured 
	 */
int getNbSpikes() const;
/**
	 @return int // return the intetnal time of the neuron
	 */
int getInternalTime() const;
/**
	 @return int //  return the delay
	 */
int getDelay() const;	
/**
	 @return bool //  return myes if the neuron is an exitatory neuron,
	  no if not
	 */
bool getEx();
/**
	 @return double //  return J
	 */
double getJ();
/**
	 @return vector<double> //  return a table of time
	 when spikes occured for this neuron
	 */
vector<double> getSpikesTime();
/**
	 @return double //  return the time of the last spikes that occured
	 */
double getLastTimeSpike();

vector<int> getConnections();
//SETTERS
/**
	 @return void //  set membrane potential
	 @param double
	 */
void setMembPot(double m);
/**
	 @return void //  set the number of spikes
	 @param int
	 */
void setNbSpikes (int nbs);
/**
	 @return double //  set the boolean E:
	  true for exitatory neuron and false for inhibitory neuron
	  @param boolean
	 */
void setEx(bool alpha);



//methods used in update, to determine and set potential
/**
	 @return bool //  return yes if Vthreshold is reached
	 */	
bool ifPotMaxReached();
/**
	 @return void // if Vthreshold is reached
	 */
void PotMaxReached();
/**
	 set the new potential with the buffer, the background noise,
	 the external current
	 @return void // set membrane potential each time
	 @param external current I
	 */
void SetPot(double I, int pois);
/**
	 @return void // if Vthreshold is reached,
	 set the membrane potential to 0=Vreset
	 */
void SetNewPot();
/**
	 @return bool // return true if the neuron is not in refractory time,
	 false if not
	 */
bool Refractory();


void connect(int i);

//update neuron's potential state
/**
	 update potential each step time,
	 in function of the refractory time, 
	 @return bool // return true if the neuron spikes
	 @param external current I
	 */
bool update (double const& I, int pois);
	
//update buffer
/**
	insert a new value in the buffer 
	 @return void //
	 @param int buffer's position, double value
	 */
void updatebuffer (int pos, double value);

//DESTRUCTOR
//~Neuron();	
};


#endif
