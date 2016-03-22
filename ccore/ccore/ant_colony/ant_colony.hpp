/*
 * ant_colony.h
 *
 *  Created on: Mar 21, 2016
 *      Author: alex
 */

#pragma once

#include <memory>
#include <vector>
#include <initializer_list>
#include <cmath>
#include <unordered_map>
#include <cassert>

#include "city_distance.hpp"
#include "AntColonyAlgorithmParams.hpp"

namespace ant_colony
{


class AntColonyResult
{
public:
	void put_next_city(int city_num)
	{
		shortesPath.push_back(city_num);
	}

public:
	std::vector<int> shortesPath;
};


/***********************************************************************************************
* template <typename T> class Ant_colony
*                          - main class for Ant Colony Optimization
*
*
***********************************************************************************************/
template<typename T>
class Ant_colony
{

public:
	Ant_colony(const std::shared_ptr<city_distance::CityDistanceMatrix<T>>& init_distance
					, const std::shared_ptr<AntColonyAlgorithmParams>& init_params)
		: distance(init_distance)
		, params(init_params)
	{}

    decltype(auto) solve();

    decltype(auto) get_result() { return result; }

private:


public:

    std::shared_ptr<AntColonyResult> result;
	std::shared_ptr<city_distance::CityDistanceMatrix<T>> distance;
	std::shared_ptr<AntColonyAlgorithmParams> params;

};


}//namespace ant_colony
