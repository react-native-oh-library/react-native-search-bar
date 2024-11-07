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

#include <jsi/jsi.h>
#include <react/renderer/components/view/ViewProps.h>
#include <react/renderer/core/PropsParserContext.h>

namespace facebook {
namespace react {

class JSI_EXPORT RNCSearchBarProps final : public ViewProps {
 public:
  RNCSearchBarProps() = default;
  RNCSearchBarProps(const PropsParserContext& context, const RNCSearchBarProps &sourceProps, const RawProps &rawProps);

#pragma mark - Props
  std::string placeholder{"Search"};
  std::string textColor{};
  std::string barTintColor{};
  std::string tintColor{};
  std::string text{};
  std::string returnKeyType{};
  std::string keyboardType{};
  std::string keyboardAppearance{};
  std::string autoCapitalize{};
  std::string barStyle{"default"};
  std::string searchBarStyle{"default"};
  std::string cancelButtonText{"Cancel"};
  std::string textFieldBackgroundColor{};
  bool editable{true};
  bool enablesReturnKeyAutomatically{true};
  bool showsCancelButtonWhileEditing{true};
  bool showsCancelButton{false};
  bool hideBackground{false};
  bool autoCorrect{false};
  bool spellCheck{false};
};

} // namespace react
} // namespace facebook