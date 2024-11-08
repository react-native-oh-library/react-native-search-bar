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
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

import type { RNPackageContext, UITurboModule, UITurboModuleContext } from '@rnoh/react-native-openharmony/ts';
import { RNPackage, UITurboModuleFactory } from '@rnoh/react-native-openharmony/ts';
import { RNSearchBarModule } from './RNSearchBarModule';
import { TM } from "./namespace/ts"

class SearchBarPackageTurboModulesFactory extends UITurboModuleFactory {
  createTurboModule(name: string): UITurboModule | null {
    if (name === TM.RNSearchBarModule.NAME) {
      return new RNSearchBarModule(this.ctx);
    }
    return null;
  }

  hasTurboModule(name: string): boolean {
    return name === TM.RNSearchBarModule.NAME;
  }
}

export class SearchBarPackage extends RNPackage {
  createTurboModulesFactory(ctx: UITurboModuleContext): UITurboModuleFactory {
    return new SearchBarPackageTurboModulesFactory(ctx);
  }
}
