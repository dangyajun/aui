//
// Created by alex2772 on 1/3/21.
//

#include "Cursor.h"


void ass::decl::Declaration<ACursor>::applyFor(AView* view) {
    view->setCursor(mInfo);
}