class Material
{
public:
	// Принимает на вход величину деформации.
	// Возвращает величину напряжения, посчитанную с учётом реологии материала.
	virtual float getStress(float strain) = 0;
};
class ElasticMaterial : public Material {
public:
	float emod;
	ElasticMaterial(float elasticModulus){
		this->emod = elasticModulus;
	};
	float getStress(float strain) {
		return (this->emod * strain);
	};
};
class PlasticMaterial : public Material {
public:
	float emod;
	float sLim;
	PlasticMaterial(float elasticModulus, float strainLimit) {
		this->sLim = strainLimit;
		this->emod = elasticModulus;
	};
	float getStress(float strain) {
		if (strain >= sLim) {
			return this->sLim * this->emod;
		}
		return strain * this->emod;
	};
};