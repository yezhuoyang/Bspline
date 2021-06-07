#include <Eigen/LU>
class lez_fitting{
	public:
	vector<Vector2d>controls,positions;
	vector<Vector2d>getControls(){
		return controls;
	}
	vector<Vector2d>getSamples(){
		return positions;
	}
	double dis(Vector2d o){
		return sqrt(max(0.,o.x()*o.x()+o.y()*o.y()));
	}
	double cal(double a,double b,double c){
		if(abs(a)<1e-9)return c/-b;
		double x=(-b+sqrt(b*b-4*a*c))/(2*a);
		return x;
	}
	double N(vector<double>&t,int i,double x,int p){
		if(x<t[i]||x>=t[i+p+1])return 0;
		if(p==0)return 1;
		return(x-t[i])/(max(1e-9,t[i+p]-t[i]))*N(t,i,x,p-1)+(t[i+p+1]-x)/(max(1e-9,t[i+p+1]-t[i+1]))*N(t,i+1,x,p-1);
	}
	lez_fitting(const vector<Vector2d>&points,int controlNum){
		int p=3;//order-3 B-spline
		vector<double>para;//initial parameters
		para.push_back(0);
		double sum=0;
		for(int i=1;i<points.size();i++){
			sum+=dis(points[i]-points[i-1]);
			para.push_back(sum);
		}
		for(int i=0;i<para.size();i++)
			para[i]/=sum;
		vector<Vector2d>deriv=points;//derivations
		vector<double>f;//feature function
		vector<double>t;//parameters
		for(int i=1;i<=p;i++){
			for(int j=0;j+1<deriv.size();j++){
				deriv[j]=(deriv[j+1]-deriv[j])/(para[j+1]-para[j]);
				para[j]=0.5*(para[j]+para[j+1]);
			}
			deriv.pop_back();
			para.pop_back();
		}
		for(int i=0;i<deriv.size();i++){
			f.push_back(pow(dis(deriv[i]),1./p));
			printf("%f ",f[i]);
		}
		printf("\n");
		
		sum=0;
		double ita=1e-6;
		for(int i=0;i+1<f.size();i++)
			sum+=0.5*(f[i]+f[i+1]+ita)*(para[i+1]-para[i]);
		sum/=controlNum-p;
		double cur=0;
		for(int i=1;i<=p+1;i++)
			t.push_back(0);
		for(int i=0,j=1;i+1<f.size();i++){
			while(j<controlNum-p&&j*sum<cur+0.5*(f[i]+f[i+1]+ita)*(para[i+1]-para[i])){
				t.push_back(para[i]+cal(0.5*(f[i+1]-f[i])/(para[i+1]-para[i]),f[i]+0.5*ita,-j*sum+cur));
				printf("%f!!!",t[t.size()-1]);
				j++;
			}
			cur+=0.5*(f[i]+f[i+1]+ita)*(para[i+1]-para[i]);
		}
		for(int i=0;i<t.size();i++)
			t[i]/=para[para.size()-1];
		for(int i=1;i<=p+1;i++)
			t.push_back(1+1e-9);
		
		sum=0;
		para.clear();
		para.push_back(0);
		for(int i=1;i<points.size();i++){
			sum+=dis(points[i]-points[i-1]);
			para.push_back(sum);
		}
		for(int i=0;i<para.size();i++)
			para[i]/=sum;
		for(int i=0;i<t.size();i++)
			printf("%f ",t[i]);
		printf("\n");
		for(int i=0;i<para.size();i++)
			printf("%f ",para[i]);
		printf("\n");
		MatrixXd A(controlNum,para.size());
		for(int i=0;i<controlNum;i++)
			for(int j=0;j<para.size();j++){
				A(i,j)=N(t,i,para[j],p);
			}
			
		vector<Vector2d>Q;
		for(int i=0;i<controlNum;i++){
			Vector2d o;
			o.x()=o.y()=0;
			for(int j=0;j<para.size();j++)
				o=o+A(i,j)*points[j];
			Q.push_back(o);
		}
//		for(int i=0;i<controlNum;i++,printf("\n"))
//			for(int j=0;j<para.size();j++)
//				printf("%f ",A(i,j));
		A=A*A.transpose();
//		for(int i=0;i<A.rows();i++,printf("\n"))
//			for(int j=0;j<A.cols();j++)
//				printf("%f ",A(i,j));
		A=A.inverse();
//		for(int i=0;i<controlNum;i++,printf("\n"))
//			for(int j=0;j<controlNum;j++)
//				printf("%f ",A(i,j));
		for(int i=0;i<controlNum;i++){
			Vector2d o;
			o.x()=o.y()=0;
			for(int j=0;j<controlNum;j++)
				o=o+A(i,j)*Q[j];
			controls.push_back(o);
		}
		for(double i=0;i<=1;i+=1e-3){
			Vector2d o;
			o.x()=o.y()=0;
			for(int j=0;j<controlNum;j++)
				o=o+N(t,j,i,p)*controls[j];
			positions.push_back(o);
		}
	}
};
