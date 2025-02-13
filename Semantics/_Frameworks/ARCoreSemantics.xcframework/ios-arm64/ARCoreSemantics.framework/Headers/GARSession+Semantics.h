/*
 * Copyright 2023 Google LLC. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#import <Foundation/Foundation.h>

#import <ARCoreGARSession/GARSession.h>
#import <ARCoreSemantics/GARSemanticMode.h>

/** Category adding Scene Semantics functionality to `GARSession`. */
@interface GARSession (Semantics)

/**
 * Determines whether the given `#GARSemanticMode` is supported on the current device and OS
 * version. If this returns `NO`, then using `GARSession#setConfiguration:error:` with the given
 * semantic mode will fail with the error code `#GARSessionErrorCodeConfigurationNotSupported`. A
 * device may be incompatible with a given mode due to insufficient sensor capabilities or compute
 * performance.
 *
 * @param semanticMode The Scene Semantics mode.
 * @return `YES` if the @p semanticMode is supported, `NO` otherwise.
 */
- (BOOL)isSemanticModeSupported:(GARSemanticMode)semanticMode;

@end
