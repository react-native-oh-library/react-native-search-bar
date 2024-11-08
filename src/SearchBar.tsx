import type { SearchBarNativeProps } from './RNCSearchBarNativeComponent';
import React from 'react';
import RNCSearchBar from './RNCSearchBarNativeComponent';
import NativeRNSearchBarModule from './NativeRNSearchBarModule';

type SearchBarProps = SearchBarNativeProps;


export class SearchBar extends React.Component<SearchBarProps> {

  /**
   * js 接口 
   * focus
   */
  focus = () => {
	 NativeRNSearchBarModule.focus();
  };
  
  /**
   * js 接口 
   * blur
   */
  blur = () => {
	 NativeRNSearchBarModule.blur();
  };
  
  /**
   * js 接口 
   * unFocus
   */
  unFocus = () => {
	 NativeRNSearchBarModule.unFocus();
  };
  
   /**
   * js 接口 
   * clearText
   */
  clearText = () => {
	 NativeRNSearchBarModule.clearText();
  };
  
  onSearchButtonPress = e => {
	  if(this.props.onSearchButtonPress){
		this.props.onSearchButtonPress(e.nativeEvent.text);
	  }
    
  };
  
  onChangeText = e => {
	if(this.props.onChangeText){
		this.props.onChangeText(e.nativeEvent.text);
	}
  };


  render() {
   
	return (
		<RNCSearchBar
			{...this.props}
			onSearchButtonPress={this.onSearchButtonPress}
			onChangeText={this.onChangeText}
		/>
	);
  }
}

export default SearchBar;