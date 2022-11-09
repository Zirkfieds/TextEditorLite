#include "advancedFunctions.h"

//THE FILE FOR STATISTICS FEATURE, DISPLAYING STATISTICS OF THE CURRENT FILE


statistics::statistics() {

    statisticsData = new long int[typeCount];

    for (int i = 0; i < typeCount; i++) {
        statisticsData[i] = -1;
    }

}
