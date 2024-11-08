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

#include <react/renderer/core/PropsParserContext.h>
#include <react/renderer/core/propsConversions.h>
#include "Props.h"

namespace facebook {
namespace react {

    RNCSearchBarProps::RNCSearchBarProps(const PropsParserContext &context, const RNCSearchBarProps &sourceProps,
                                       const RawProps &rawProps): ViewProps(context, sourceProps, rawProps),
            placeholder(convertRawProp(context, rawProps, "placeholder", sourceProps.placeholder, {})),
            textColor(convertRawProp(context, rawProps, "textColor", sourceProps.textColor, {})),
            barTintColor(convertRawProp(context, rawProps, "barTintColor", sourceProps.barTintColor, {})),
            tintColor(convertRawProp(context, rawProps, "tintColor", sourceProps.tintColor, {})),
            text(convertRawProp(context, rawProps, "text", sourceProps.text, {})),
            barStyle(convertRawProp(context, rawProps, "barStyle", sourceProps.barStyle, {})),
            searchBarStyle(convertRawProp(context, rawProps, "searchBarStyle", sourceProps.searchBarStyle, {})),
            returnKeyType(convertRawProp(context, rawProps, "returnKeyType", sourceProps.returnKeyType, {})),
            keyboardType(convertRawProp(context, rawProps, "keyboardType", sourceProps.keyboardType, {})),
            keyboardAppearance(convertRawProp(context, rawProps, "keyboardAppearance", sourceProps.keyboardAppearance, {})),
            autoCapitalize(convertRawProp(context, rawProps, "autoCapitalize", sourceProps.autoCapitalize, {})),
            editable(convertRawProp(context, rawProps, "editable", sourceProps.editable, {})),
            cancelButtonText(convertRawProp(context, rawProps, "cancelButtonText", sourceProps.cancelButtonText, {})),
            showsCancelButton(convertRawProp(context, rawProps, "showsCancelButton", sourceProps.showsCancelButton, {})),
            hideBackground(convertRawProp(context, rawProps, "hideBackground", sourceProps.hideBackground, {})),
            autoCorrect(convertRawProp(context, rawProps, "autoCorrect", sourceProps.autoCorrect, {})),
            spellCheck(convertRawProp(context, rawProps, "spellCheck", sourceProps.spellCheck, {})),
            showsCancelButtonWhileEditing(convertRawProp(context, rawProps, "showsCancelButtonWhileEditing", sourceProps.showsCancelButtonWhileEditing, {})),
            enablesReturnKeyAutomatically(convertRawProp(context, rawProps, "enablesReturnKeyAutomatically", sourceProps.enablesReturnKeyAutomatically, {})),
            textFieldBackgroundColor(convertRawProp(context, rawProps, "textFieldBackgroundColor", sourceProps.textFieldBackgroundColor, {}))
    {}

} // namespace react
} // namespace facebook