//
// Created by alex2 on 28.09.2020.
//

#include "ADividerView.h"

ADividerView::ADividerView() {
    AVIEW_CSS;
}

bool ADividerView::consumesClick(const glm::ivec2& pos) {
    return false;
}

ADividerView::~ADividerView() = default;