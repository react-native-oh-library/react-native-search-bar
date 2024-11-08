/**
 * MIT License
 * 
 * Copyright (C) 2024 Huawei Device Co., Ltd.
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * Ï
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANT KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
#pragma once
#include "EventEmitters.h"
#include "RNOH/ArkJS.h"
#include "RNOH/EventEmitRequestHandler.h"

using namespace facebook;
namespace rnoh {

    enum SearchBarEventType {
        CHANGE,
        CHANGE_TEXT,
        FOCUS,
        BLUR,
        SEARCH_BUTTON_PRESS,
        CANCEL_BUTTON_PRESS,
    };

    SearchBarEventType getSearchBarEventType(ArkJS &arkJs, napi_value eventObject) {
        auto eventType = arkJs.getString(arkJs.getObjectProperty(eventObject, "type"));
        if (eventType == "onChange") {
            return SearchBarEventType::CHANGE;
        } else if (eventType == "onChangeText") {
            return SearchBarEventType::CHANGE_TEXT;
        } else if (eventType == "onFocus") {
            return SearchBarEventType::FOCUS;
        } else if (eventType == "onBlur") {
            return SearchBarEventType::BLUR;
        } else if (eventType == "onSearchButtonPress") {
            return SearchBarEventType::SEARCH_BUTTON_PRESS;
        } else if (eventType == "onCancelButtonPress") {
            return SearchBarEventType::CANCEL_BUTTON_PRESS;
        } else {
            throw std::runtime_error("Unknown Checkbox event type");
        }
    }

    class SearchBarEventEmitRequestHandler : public EventEmitRequestHandler {
    public:
        void handleEvent(EventEmitRequestHandler::Context const &ctx) override {
            if (ctx.eventName != "RNCSearchBar") {
                return;
            }
            ArkJS arkJs(ctx.env);
            auto eventEmitter = ctx.shadowViewRegistry->getEventEmitter<react::RNCSearchBarEventEmitter>(ctx.tag);
            if (eventEmitter == nullptr) {
                return;
            }
            auto eventType = getSearchBarEventType(arkJs, ctx.payload);
            switch (eventType) {
                case SearchBarEventType::CHANGE: {
                    int32_t target = arkJs.getInteger(arkJs.getObjectProperty(ctx.payload, "target"));
                    std::string text = arkJs.getString(arkJs.getObjectProperty(ctx.payload, "text"));
                    int32_t eventCount = arkJs.getInteger(arkJs.getObjectProperty(ctx.payload, "eventCount"));
                    react::RNCSearchBarEventEmitter::OnChange event = {target,text, eventCount};
                    eventEmitter->onChange(event);
                    break;
                }
            case SearchBarEventType::CHANGE_TEXT: {
                    std::string value = arkJs.getString(arkJs.getObjectProperty(ctx.payload, "text"));
                    react::RNCSearchBarEventEmitter::StringResult event = {value};
                    eventEmitter->onChangeText(event);
                    break;
                }
            case SearchBarEventType::FOCUS: {
                    react::RNCSearchBarEventEmitter::OnFocus event{};
                    eventEmitter->onFocus(event);
                    break;
                }
            case SearchBarEventType::BLUR: {
                    react::RNCSearchBarEventEmitter::OnBlur event{};
                    eventEmitter->onBlur(event);
                    break;
                }
            case SearchBarEventType::SEARCH_BUTTON_PRESS: {
                    std::string value = arkJs.getString(arkJs.getObjectProperty(ctx.payload, "text"));
                    react::RNCSearchBarEventEmitter::StringResult event = {value};
                    eventEmitter->onSearchButtonPress(event);
                    break;
                }
            case SearchBarEventType::CANCEL_BUTTON_PRESS: {
                    react::RNCSearchBarEventEmitter::OnCancelButtonPress event{};
                    eventEmitter->onCancelButtonPress(event);
                    break;
                }
                default:
                    break;
            }
        };
    };
} // namespace rnoh