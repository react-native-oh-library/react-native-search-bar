import React from 'react';
import PropTypes from 'prop-types';

import NativeRNSearchBarModule from './NativeRNSearchBarModule';
import RNCSearchBar from './RNCSearchBarNativeComponent';

class SearchBar extends React.PureComponent {
  static propTypes = {
    placeholder: PropTypes.string,
    text: PropTypes.string,
    barTintColor: PropTypes.string,
    tintColor: PropTypes.string,
    textColor: PropTypes.string,
    textFieldBackgroundColor: PropTypes.string,
    cancelButtonText: PropTypes.string,
    showsCancelButton: PropTypes.bool,
    onChange: PropTypes.func,
    onChangeText: PropTypes.func,
    onFocus: PropTypes.func,
    onBlur: PropTypes.func,
    onSearchButtonPress: PropTypes.func,
    onCancelButtonPress: PropTypes.func,
    enablesReturnKeyAutomatically: PropTypes.bool,
    hideBackground: PropTypes.bool,
    keyboardType: PropTypes.oneOf([
      // Cross-platform
      'default',
      'email-address',
      'numeric',
      'phone-pad',
      // iOS-only
      'ascii-capable',
      'numbers-and-punctuation',
      'url',
      'number-pad',
      'name-phone-pad',
      'decimal-pad',
      'twitter',
      'web-search',
    ]),
    keyboardAppearance: PropTypes.oneOf(['default', 'light', 'dark']),
    autoCapitalize: PropTypes.oneOf([
      'none',
      'words',
      'sentences',
      'characters',
    ]),
    autoCorrect: PropTypes.bool,
    spellCheck: PropTypes.bool,
    barStyle: PropTypes.oneOf(['default', 'black']),
    searchBarStyle: PropTypes.oneOf(['default', 'prominent', 'minimal']),
    editable: PropTypes.bool,
    returnKeyType: PropTypes.string,
    showsCancelButtonWhileEditing: PropTypes.bool,
  };

  static defaultProps = {
    text: '',
    placeholder: 'Search',
    barStyle: 'default',
    searchBarStyle: 'default',
    editable: true,
    cancelButtonText: 'Cancel',
    showsCancelButton: false,
    hideBackground: false,
    enablesReturnKeyAutomatically: true,
    textFieldBackgroundColor: null,
    tintColor: null,
    barTintColor: null,
    textColor: null,
    returnKeyType: 'search',
    keyboardType: 'default',
    keyboardAppearance: 'default',
    autoCapitalize: 'sentences',
    autoCorrect: false,
    spellCheck: false,
    showsCancelButtonWhileEditing: true,
    onChange: () => null,
    onChangeText: () => null,
    onFocus: () => null,
    onBlur: () => null,
    onSearchButtonPress: () => null,
    onCancelButtonPress: () => null,
  };

  onChangeText = e => {
    if(this.props.onChangeText){
		this.props.onChangeText(e.nativeEvent.text);
	}
  };

  onSearchButtonPress = e => {
    this.props.onSearchButtonPress(e.nativeEvent.text);
  };

  onFocus = () => {
    this.props.onFocus();
  };

  onCancelButtonPress = () => {
    this.props.onChangeText('');
    this.props.onCancelButtonPress();
  };

  onBlur = () => {
    this.props.onBlur();
  };

  blur() {
    return NativeRNSearchBarModule.blur();
  }

  focus() {
    return NativeRNSearchBarModule.focus();
  }

  clearText() {
    return NativeRNSearchBarModule.clearText();
  }

  unFocus() {
    return NativeRNSearchBarModule.unFocus();
  }

  render() {
    return (
      <RNCSearchBar
        style={{ height: 55 }}
        {...this.props}
		onChangeText={this.onChangeText}
        onPress={this.onPress}
        onFocus={this.onFocus}
        onBlur={this.onBlur}
        onSearchButtonPress={this.onSearchButtonPress}
        onCancelButtonPress={this.onCancelButtonPress}
      />
    );
  }
}

export default SearchBar;