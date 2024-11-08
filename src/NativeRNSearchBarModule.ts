import type { TurboModule } from 'react-native';
import { TurboModuleRegistry } from 'react-native';

export interface Spec extends TurboModule {
    focus(): void;
    blur(): void;
    unFocus(): void;
    clearText(): void;
}

export default TurboModuleRegistry.getEnforcing<Spec>("NativeRNSearchBarModule");
