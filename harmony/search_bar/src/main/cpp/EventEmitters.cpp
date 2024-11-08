
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

#include "EventEmitters.h"

namespace facebook {
namespace react {

void RNCSearchBarEventEmitter::onChange(OnChange event) const {
  dispatchEvent("change", [event=std::move(event)](jsi::Runtime &runtime) {
    auto payload = jsi::Object(runtime);
    payload.setProperty(runtime, "target", event.target);
    payload.setProperty(runtime, "text", event.text);
    payload.setProperty(runtime, "eventCount", event.eventCount);
    return payload;
  });
}

void RNCSearchBarEventEmitter::onChangeText(StringResult event) const {
  dispatchEvent("changeText", [event=std::move(event)](jsi::Runtime &runtime) {
    auto payload = jsi::Object(runtime);
    payload.setProperty(runtime, "text", event.text);
    return payload;
  });
}

void RNCSearchBarEventEmitter::onSearchButtonPress(StringResult event) const {
  dispatchEvent("searchButtonPress", [event=std::move(event)](jsi::Runtime &runtime) {
    auto payload = jsi::Object(runtime);
    payload.setProperty(runtime, "text", event.text);
    return payload;
  });
}

void RNCSearchBarEventEmitter::onFocus(OnFocus event) const {
  dispatchEvent("focus", [event=std::move(event)](jsi::Runtime &runtime) {
    auto payload = jsi::Object(runtime);
    return payload;
  });
}

void RNCSearchBarEventEmitter::onBlur(OnBlur event) const {
  dispatchEvent("blur", [event=std::move(event)](jsi::Runtime &runtime) {
    auto payload = jsi::Object(runtime);
    return payload;
  });
}

void RNCSearchBarEventEmitter::onCancelButtonPress(OnCancelButtonPress event) const {
  dispatchEvent("cancelButtonPress", [event=std::move(event)](jsi::Runtime &runtime) {
    auto payload = jsi::Object(runtime);
    return payload;
  });
}

} // namespace react
} // namespace facebook