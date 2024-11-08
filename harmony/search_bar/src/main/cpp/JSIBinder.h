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

#include "RNOHCorePackage/ComponentBinders/ViewComponentJSIBinder.h"

namespace rnoh {

class SearchBarJSIBinder : public ViewComponentJSIBinder {
    facebook::jsi::Object createNativeProps(facebook::jsi::Runtime &rt) override {
        auto object = ViewComponentJSIBinder::createNativeProps(rt);
        object.setProperty(rt, "placeholder", true);
        object.setProperty(rt, "textColor", true);
        object.setProperty(rt, "barTintColor", true);
        object.setProperty(rt, "tintColor", true);
        object.setProperty(rt, "text", true);
        object.setProperty(rt, "barStyle", true);
        object.setProperty(rt, "searchBarStyle", true);
        object.setProperty(rt, "returnKeyType", true);
        object.setProperty(rt, "keyboardType", true);
        object.setProperty(rt, "keyboardAppearance", true);
        object.setProperty(rt, "autoCapitalize", true);
        object.setProperty(rt, "editable", true);
        object.setProperty(rt, "cancelButtonText", true);
        object.setProperty(rt, "showsCancelButton", true);
        object.setProperty(rt, "hideBackground", true);
        object.setProperty(rt, "enablesReturnKeyAutomatically", true);
        object.setProperty(rt, "textFieldBackgroundColor", true);
        object.setProperty(rt, "autoCorrect", true);
        object.setProperty(rt, "spellCheck", true);
        object.setProperty(rt, "showsCancelButtonWhileEditing", true);
        return object;
    }

    facebook::jsi::Object createDirectEventTypes(facebook::jsi::Runtime &rt) override {
        facebook::jsi::Object events(rt);
        events.setProperty(rt, "topChange", createDirectEvent(rt, "onChange"));
        events.setProperty(rt, "topChangeText", createDirectEvent(rt, "onChangeText"));
        events.setProperty(rt, "topFocuss", createDirectEvent(rt, "onFocus"));
        events.setProperty(rt, "topBlurr", createDirectEvent(rt, "onBlur"));
        events.setProperty(rt, "topSearchButtonPress", createDirectEvent(rt, "onSearchButtonPress"));
        events.setProperty(rt, "topCancelButtonPress", createDirectEvent(rt, "onCancelButtonPress"));
        return events;
    }
};
} // namespace rnoh