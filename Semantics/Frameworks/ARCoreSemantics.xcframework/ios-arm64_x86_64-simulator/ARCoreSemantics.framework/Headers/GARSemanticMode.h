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

/** @defgroup GARSemanticMode */

/**
 * @ingroup GARSemanticMode
 * Describes the behavior of the Scene Semantics API.
 * Scene Semantics uses a machine learning model to label each pixel from the camera feed with a
 * `#GARSemanticLabel`. See
 * <a href="https://developers.google.com/ar/develop/ios/scene-semantics">the Scene Semantics
 * Developer Guide</a> for more information.
 *
 * The Scene Semantics API is currently able to distinguish between outdoor labels specified by
 * `#GARSemanticLabel`. Usage indoors is currently unsupported and may yield unreliable results.
 * Some ARCore supported devices do not support the Scene Semantics API. Use
 * `GARSession#isSemanticModeSupported:` to query for support for Scene Semantics. Affected devices
 * are also indicated on the <a href="https://developers.google.com/ar/devices">ARCore supported
 * devices page</a>.
 *
 * The default value is `#GARSemanticModeDisabled`. Use `GARSessionConfiguration#semanticMode`
 * and `GARSession#setConfiguration:error:`to set the desired mode.
 */
typedef NS_ENUM(NSInteger, GARSemanticMode) {
  /**
   * The Scene Semantics API is not enabled. Calls to `GARFrame#acquireSemanticImage:`,
   * `GARFrame#acquireSemanticConfidenceImage:`, and
   * `GARFrame#fractionForSemanticLabel:error:` will not return valid results.
   *
   * This is the default mode.
   */
  GARSemanticModeDisabled = 0,

  /**
   * The Scene Semantics API is enabled. Calls to `GARFrame#acquireSemanticImage:`,
   * `GARFrame#acquireSemanticConfidenceImage:`, and
   * `GARFrame#fractionForSemanticLabel:error:` will return valid results.
   *
   *  Use `GARSessionConfiguration#semanticMode` and `GARSession#setConfiguration:error:`to set the
   * desired mode.
   */
  GARSemanticModeEnabled = 1,
};
