#include "utils.h"

namespace utils {

	double round(double in_raw, double in_precision)
	{
		double precision = (1.0 / in_precision);

		//for example: the 3.4899 in_raw value will be equal to 3.49 after this floor if the in_precision = 0.01
		in_raw = floor(in_raw * precision + 0.5) / precision;
		return in_raw;
	}

}