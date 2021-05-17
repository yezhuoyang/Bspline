#pragma once


#include <Eigen/Core>
#include <vector>
#include <map>


using namespace std;
using namespace Eigen;

class BSplineCurve
{
   public:
       typedef std::pair<int, double> Parameter;

       BSplineCurve(double interal=0.001):interal_(interal){

       }

       ~BSplineCurve(){
           clear();
       }

       size_t nb_control() const {return controls_.size();}

       /*
        * Compute the x,y position of current parameter
        */
       Vector2d getPos(const Parameter& para) const;


       /*
        * Compute the first differential
        */
       Vector2d getFirstDiff(const Parameter& para) const;


       /*
        * Compute the second differential
        */
       Vector2d getSecondDiff(const Parameter& para) const;

       /*
        * Compute the curvature of a given point
        */
       double getCurvature(const Parameter& para) const;


       /*
        * Compute the unit tangent vector
        */
       Vector2d getTangent(const Parameter &para) const;

       /*
        * Compute the unit Normal vector
        */
       Vector2d getNormal(const Parameter &para) const;


       /*
        * Compute the Curvature centor
        */
       Vector2d getCurvCenter(const Parameter &para) const;


       /*
        * Compute the foot print
        */
       double findFootPrint(const vector<Vector2d>& givepoints,vector<Parameter>& footPrints) const;


       /*
        * find the coff vector
        */
       VectorXd getCoffe(const Parameter&para) const ;

       /*
        * set the control points and compute a uniform spatial partition of the data points
        */
        void setNewControl(const vector<Vector2d>& controlPs);

        /*
         * Check if two points are on the same side
         */
        bool checkSameSide(Vector2d p1,Vector2d p2,Vector2d neip);


        MatrixXd getSIntegralSq();

        MatrixXd getFIntegralSq();

        const vector<Vector2d>& getControls() const{return controls_;}

        const vector<Vector2d>& getSamples() const{return positions_;}




   private:

    void clear(){
        controls_.clear();
        positions_.clear();
    }

    Parameter getPara(int index) const;


    bool checkInside(Vector2d p);

    /*
     * Test if a point is Left|On|Right of an infinite line
     */
    int isLeft(Vector2d p0,Vector2d p1, Vector2d p2);


private:

    double interal_;
    std::vector<Vector2d> controls_;
    std::vector<Vector2d> positions_;




};

