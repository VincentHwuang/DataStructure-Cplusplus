/*
 * filename:utils.h
 * created at:2017-08-18
 * author:VincentHwuang
 */

#ifndef UTILS_H
#define UTILS_H

namespace Utility
{
template<typename T> inline 
T Max(T a,T b)
{
	return ((a)>(b)? (a):(b));
}

template<typename T> inline 
T Min(T a,T b)
{
	return ((a)>(b)? (b):(a));
}

}






#endif
