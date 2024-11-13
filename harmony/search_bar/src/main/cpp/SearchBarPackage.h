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

#include "EventEmiRequestHandler.h"
#include "RNOH/Package.h"
#include "ComponentDescriptors.h"
#include "JSIBinder.h"
#include "NapiBinder.h"

using namespace rnoh;
using namespace facebook;

namespace rnoh {

class SearchBarPackage : public Package {
public:
    SearchBarPackage(Package::Context ctx): Package(ctx) {}

    std::vector<facebook::react::ComponentDescriptorProvider> createComponentDescriptorProviders() override {
        return {facebook::react::concreteComponentDescriptorProvider<facebook::react::RNCSearchBarComponentDescriptor>()};
    }

    ComponentNapiBinderByString createComponentNapiBinderByName() override {
        return {{"RNCSearchBar", std::make_shared<SearchBarNapiBinder>()}};
    }

    ComponentJSIBinderByString createComponentJSIBinderByName() override {
        return {{"RNCSearchBar", std::make_shared<SearchBarJSIBinder>()}};
    }
    
    EventEmitRequestHandlers createEventEmitRequestHandlers() override {
        return {std::make_shared<SearchBarEventEmitRequestHandler>()};
    }
    
};
} // namespace rnoh