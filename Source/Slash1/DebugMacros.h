#pragma once

#include "DrawDebugHelpers.h"

//macros to avoid retyping same debug sphere props
#define DRAW_SPHERE(Location) if(GetWorld()) DrawDebugSphere(GetWorld(),Location,25.f,12,FColor::Red, true)
#define DRAW_SPHERE_1FRAME(Location) if(GetWorld()) DrawDebugSphere(GetWorld(),Location,25.f,12,FColor::Red, false, -1.f)	//-1.f means it's 'lifetime' is a single frame only
#define DRAW_LINE(Start,End) if(GetWorld()) DrawDebugLine(GetWorld(), Start, End, FColor::Red, true, -1.f, 0, 1.f)
#define DRAW_LINE_1FRAME(Start,End) if(GetWorld()) DrawDebugLine(GetWorld(),Start,End,FColor::Red, false, -1.f)
#define DRAW_POINT(Location) if(GetWorld()) DrawDebugPoint(GetWorld(), Location, 15.f, FColor::Red, true)
#define DRAW_POINT_1FRAME(Location) if(GetWorld()) DrawDebugPoint(GetWorld(),Location,15.f,FColor::Red, false, -1.f)
#define DRAW_VECTOR(Start,End) if(GetWorld()) \
		{\
			DrawDebugLine(World, Start, End, FColor::Red, true, -1.f, 0, 1.f);\
			DrawDebugPoint(World, End, 15.f, FColor::Red, true);\
		}
#define DRAW_VECTOR_1FRAME(Start,End) if(GetWorld()) \
		{\
			DrawDebugLine(GetWorld(), Start, End, FColor::Red, false, -1.f, 0, 1.f);\
			DrawDebugPoint(GetWorld(), End, 15.f, FColor::Red, false, -1.f);\
		}