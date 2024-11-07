// @flow strict-local

import codegenNativeComponent from 'react-native/Libraries/Utilities/codegenNativeComponent';
import type { ViewProps, HostComponent } from 'react-native';
import type {
  WithDefault,
  DirectEventHandler,
  Int32,
} from 'react-native/Libraries/Types/CodegenTypes';

export type VoidEventData = Readonly<{}>;

export type StringEventData = Readonly<{
    text?: string;
  }>

export type ChangeEventData = Readonly<{
	target?: Int32;
	text?: string;
	eventCount?: Int32;
}>

export interface SearchBarNativeProps extends ViewProps {
    
    placeholder?: WithDefault<string, 'Search'>;
    text?: string;
    barStyle?: WithDefault<'default' | 'black', 'default'>;
    searchBarStyle?: WithDefault<'default' | 'prominent' | 'minimal', 'default'>;
    editable?: WithDefault<boolean, true>;
    cancelButtonText?: WithDefault<string, 'Cancel'>;
    showsCancelButton?: WithDefault<boolean, false>;
    hideBackground?: WithDefault<boolean, false>;
    enablesReturnKeyAutomatically?: WithDefault<boolean, true>;
    textFieldBackgroundColor?: string;
    tintColor?: string;
    barTintColor?: string;
    textColor?: string;
    returnKeyType?: string;
    keyboardType?: string;
    keyboardAppearance?: string;
    autoCapitalize?: string;
    autoCorrect?: WithDefault<boolean, false>;
    spellCheck?: WithDefault<boolean, false>;
    showsCancelButtonWhileEditing?: WithDefault<boolean, true>;
    onChange?: DirectEventHandler<ChangeEventData>;
    onChangeText?: DirectEventHandler<StringEventData>;
    onFocus?: DirectEventHandler<VoidEventData>;
    onBlur?: DirectEventHandler<VoidEventData>;
    onSearchButtonPress?: DirectEventHandler<StringEventData>;
    onCancelButtonPress?: DirectEventHandler<VoidEventData>;
  }

export default codegenNativeComponent<SearchBarNativeProps>(
  "RNCSearchBar"
) as HostComponent<SearchBarNativeProps>;