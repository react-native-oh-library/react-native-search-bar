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
import {
  Descriptor,
  ComponentBuilderContext,
  ViewBaseProps,
  RNViewBase,
  RNComponentContext,
} from '@rnoh/react-native-openharmony'
import eventBus from './eventBus';

const TAG: string = "[RNOH] RNCSearchBar"

export interface RNCSearchBarProps extends ViewBaseProps {
  // 占位符 
  placeholder: string;

  // 输入的文字颜色 
  textColor: string;

  // search-bar父布局的背景颜色 
  barTintColor: string;

  // 文本选中背景色&光标颜色&取消按钮文本颜色 
  tintColor: string;

  // 输入的文字内容 
  text: string;

  // 输入框的背景色 
  textFieldBackgroundColor: string;

  // returnKeyType?: ReturnKeyType | ReturnKeyTypeIOS; 
  returnKeyType: string;

  // 要显示的键盘类型 KeyboardType | KeyboardTypeIOS;
  keyboardType: string;

  // 仅仅在搜索框获取焦点的时候显示取消按钮，默认开启 true 
  showsCancelButtonWhileEditing: boolean;

  // 是否隐藏search-bar父布局背景色 
  hideBackground: boolean;

  // search-bar的风格  'default' | 'black' 
  barStyle: string;

  // 是否允许用户获取焦点 
  editable: boolean;

  // 是否显示取消按钮 默认 false 
  showsCancelButton: boolean;

  // search-bar的样式  'default' | 'prominent' | 'minimal'
  searchBarStyle: string;

  // 取消按钮的文字
  cancelButtonText: string;

  // ===========================================================================

  // 键盘的主题风格 'default' | 'dark' | 'light'  （不支持）
  keyboardAppearance: string;

  //当输入时，是否自动启用键盘的返回键  （不支持）
  enablesReturnKeyAutomatically: boolean;

  // 是否开启错误单词自动更正功能 默认不开启 （不支持）
  autoCorrect: boolean;

  // 如果输入了错误的单词，是否显示红色下划线 默认不显示 （不支持）
  spellCheck: boolean;

  // 自动大写 'none' 不大写| 'sentences'句子 | 'words'词 | 'characters'人物（不支持）
  autoCapitalize: string;

}

export type SearchBarDescriptor = Descriptor<"RNCSearchBar", RNCSearchBarProps>

@Component
export struct RNCSearchBar {
  public static readonly NAME = "RNCSearchBar";
  ctx!: RNComponentContext
  tag: number = 0
  @BuilderParam buildCustomComponent: (componentBuilderContext: ComponentBuilderContext) => void
  @State descriptor: SearchBarDescriptor = {} as SearchBarDescriptor
  private unregisterDescriptorChangesListener?: () => void = undefined
  @State isFocus: boolean = false;
  @State isFocusable: boolean = true;
  @State text: string = "";
  @State changeCount: number = 0;
  private props: RNCSearchBarProps = {} as RNCSearchBarProps;

  aboutToAppear() {
    this.descriptor = this.ctx.descriptorRegistry.getDescriptor<SearchBarDescriptor>(this.tag)
    this.unregisterDescriptorChangesListener = this.ctx.descriptorRegistry.subscribeToDescriptorChanges(this.tag,
      (newDescriptor) => {
        this.descriptor = (newDescriptor as SearchBarDescriptor)
      }
    )
    this.props = this.descriptor.props;
    this.text = this.props.text;
    this.isFocusable = this.props.editable;

    console.log("ETS------------> props: " + JSON.stringify(this.descriptor.props))

    eventBus.on('focusForTurboModule', () => {
      this.getUIContext().getFocusController().requestFocus("search");
    });

    eventBus.on('blurForTurboModule', () => {
      this.getUIContext().getFocusController().clearFocus();
    });

    eventBus.on('unFocusForTurboModule', () => {
      this.getUIContext().getFocusController().clearFocus();
    });

    eventBus.on('clearTextForTurboModule', () => {
      this.text = "";
    });
  }

  aboutToDisappear() {
    this.unregisterDescriptorChangesListener?.()

    eventBus.off('focusForTurboModule', () => {

    });

    eventBus.off('blurForTurboModule', () => {

    });

    eventBus.off('unFocusForTurboModule', () => {

    });

    eventBus.off('clearTextForTurboModule', () => {

    });
  }

  onChange(value: string, count: number) {
    this.ctx.rnInstance.emitComponentEvent(
      this.descriptor.tag,
      RNCSearchBar.NAME,
      {
        type: "onChange",
        text: value,
        target: this.tag,
        eventCount: count,
      }
    );
  }

  onChangeText(value: string) {
    this.ctx.rnInstance.emitComponentEvent(
      this.descriptor.tag,
      RNCSearchBar.NAME,
      {
        type: "onChangeText",
        text: value,
      }
    );
  }

  onFocusSearch() {
    this.isFocus = true;
    this.ctx.rnInstance.emitComponentEvent(
      this.descriptor.tag,
      RNCSearchBar.NAME,
      {
        type: "onFocus"
      }
    );
  }

  onBlurSearch() {
    this.isFocus = false;
    this.ctx.rnInstance.emitComponentEvent(
      this.descriptor.tag,
      RNCSearchBar.NAME,
      {
        type: "onBlur"
      }
    );
  }

  onSearchButtonPress(value: string) {
    this.text = value;
    this.ctx.rnInstance.emitComponentEvent(
      this.descriptor.tag,
      RNCSearchBar.NAME,
      {
        type: "onSearchButtonPress",
        text: value
      }
    );
  }

  onCancelButtonPress() {
    this.ctx.rnInstance.emitComponentEvent(
      this.descriptor.tag,
      RNCSearchBar.NAME,
      {
        type: "onCancelButtonPress",
      }
    );
  }

  /**
   * 主要设置取消按钮，重复设置多个相关取消按钮显示的情况时，会被最后的覆盖
   * @returns
   */
  getShowCancelButton(): CancelButtonStyle {
    let cancle: CancelButtonStyle = CancelButtonStyle.INVISIBLE;

    if (this.props.showsCancelButton) {
      cancle = CancelButtonStyle.INVISIBLE;
    } else {
      cancle = CancelButtonStyle.INVISIBLE;
    }

    // 输入框获取焦点并且设置了仅仅当获取焦点的时候同时编辑的时候显示取消按钮
    if (this.isFocus && this.props.showsCancelButtonWhileEditing) {
      cancle = CancelButtonStyle.INVISIBLE;
    }
    return cancle;
  }

  getShowCancelButton2(): Visibility {
    let cancle: Visibility = Visibility.None;

    if (this.props.showsCancelButton) {
      cancle = Visibility.Visible;
    } else {
      cancle = Visibility.None;
    }

    // 输入框获取焦点并且设置了仅仅当获取焦点的时候同时编辑的时候显示取消按钮
    if (this.isFocus && this.props.showsCancelButtonWhileEditing) {
      cancle = Visibility.Visible;
    }
    return cancle;
  }

  getSearchBgColor(): string | null {
    let color: string = "";
    if (this.props.barStyle.length > 0 && this.props.barStyle === "default") {
      color = "#E8E8E8"
    } else if (this.props.barStyle.length > 0 && this.props.barStyle === "black") {
      color = Color.Black.toString();
    }

    if (this.props.textFieldBackgroundColor) {
      color = this.props.textFieldBackgroundColor;
    }
    return color.length > 0 ? color : "#E8E8E8";
  }

  getRootViewBgColor(): string | null {
    let color: string = "";


    // 先判断barStyle属性的设置情况。
    if (this.props.barStyle.length > 0 && this.props.barStyle === "default") {
      // 如果barStyle是默认，接着判断searchBarStyle属性的设置情况
      if (this.props.searchBarStyle.length > 0 && this.props.searchBarStyle === "default") {
        color = Color.White.toString();
      } else if (this.props.searchBarStyle.length > 0 && this.props.searchBarStyle === "prominent") {
        color = Color.White.toString();
      } else if (this.props.searchBarStyle.length > 0 && this.props.searchBarStyle === "minimal") {
        color = Color.Transparent.toString();
      } else {
        color = Color.White.toString();
      }
    } else if (this.props.barStyle.length > 0 && this.props.barStyle === "black") {
      color = "#363636";
    }

    // 第三步：再判断barTintColor属性的设置情况，如果设置了，会覆盖第一和第二步的设置。
    if (this.props.barTintColor) {
      color = this.props.barTintColor;
    }
    return color.length > 0 ? color : Color.Transparent.toString();
  }

  getEnterKeyType(): EnterKeyType {
    switch (this.props.returnKeyType) {
      case "Go":
        return EnterKeyType.Go;
      case "Send":
        return EnterKeyType.Send;
      case "Next":
        return EnterKeyType.Next;
      case "Done":
        return EnterKeyType.Done;
      default:
        return EnterKeyType.Search;
    }
  }

  getInputType(): SearchType {
    switch (this.props.keyboardType) {
      case "phone-pad":
        return SearchType.PHONE_NUMBER;
      case "email-address":
        return SearchType.EMAIL;
      case "number-pad":
      case "numeric":
        return SearchType.NUMBER;
      case "url":
        return SearchType.URL;
      default:
        return SearchType.NORMAL;
    }
  }

  getCancelButtonColor(): string {
    let color: string = "";

    if (this.props.tintColor.length > 0) {
      color = this.props.tintColor;
    } else {
      // 默认显示取消按钮时，取消按钮的默认颜色为灰色
      color = Color.Grey.toString();
      // 当获取焦点的时候取消按钮的默认颜色为蓝色
      if (this.isFocus) {
        color = Color.Blue.toString();
      }
    }

    return color;
  }

  build() {
    RNViewBase({ ctx: this.ctx, tag: this.tag }) {
      Row() {
        Search({ placeholder: this.props.placeholder, value: this.text })
          .layoutWeight(1)
          .fontColor(this.props.textColor)
          .placeholderColor(Color.Grey)
          .searchIcon({ color: Color.Grey })
          .backgroundColor(this.getSearchBgColor())
          .selectedBackgroundColor(this.props.tintColor)
          .caretStyle({ color: this.props.tintColor })
          .cancelButton({ style: this.getShowCancelButton(), icon: { color: this.getCancelButtonColor() } })
          .enterKeyType(this.getEnterKeyType())
          .type(this.getInputType())
          .focusable(this.isFocusable)
          .onChange((value) => {
            this.text = value;
            this.changeCount = this.changeCount + 1;
            this.onChange(value, this.changeCount)
            this.onChangeText(value)
            if (value.length == 0) {
              this.onCancelButtonPress();
            }
          })
          .onFocus(() => {
            this.onFocusSearch()
          })
          .onBlur(() => {
            this.onBlurSearch()
          })
          .onSubmit((value) => {
            this.onSearchButtonPress(value)
          })
          .onDidDelete((info: DeleteValue) => {
            this.onCancelButtonPress();
          })
          .id("search")
        Text(this.props.cancelButtonText)
          .padding({ left: 10 })
          .fontColor(this.getCancelButtonColor())
          .visibility(this.getShowCancelButton2())
          .onClick((e) => {
            this.text = "";
          })
      }
      .width('100%')
      .padding({ right: 10, left: 10 })
      .justifyContent(FlexAlign.Center)
      .backgroundColor(this.props.hideBackground ? Color.Transparent.toString() : this.getRootViewBgColor())
    }
  }
}