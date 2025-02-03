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

#import <CoreVideo/CoreVideo.h>
#import <Foundation/Foundation.h>

#import <ARCoreGARSession/GARFrame.h>
#import <ARCoreSemantics/GARSemanticLabel.h>

NS_ASSUME_NONNULL_BEGIN

/** Category adding Semantics functionality to `GARFrame`. */
@interface GARFrame (Semantics)

/**
 * The latest semantic image for the `GARFrame` as a
 * <a href="https://developer.apple.com/documentation/corevideo/cvpixelbuffer">`CVPixelBuffer`</a>.
 * Each pixel in the image is an 8-bit integer representing a semantic class label: see
 * `#GARSemanticLabel` for a list of pixel labels and
 * <a href="https://developers.google.com/ar/develop/ios/scene-semantics">the Scene Semantics
 * Developer Guide</a> for more information.
 *
 * `GARFrame` retains the semantic `CVPixelBuffer`. Holding references to `GARFrame`s will
 * eventually exhaust resources.
 *
 * `GARFrame.semanticImage` will be nil if `GARSessionConfiguration` does not have
 * `#GARSemanticModeEnabled` set. Use `GARSession#isSemanticModeSupported:` to check for support for
 * the Scene Semantics API.
 *
 * `GARFrame.semanticImage` may be nil for the first few frames after initializing semantics, or if
 * memory is exhausted due to retaining old `GARFrame`s.
 */
@property(nullable, readonly) CVPixelBufferRef semanticImage CF_RETURNS_NOT_RETAINED;

/**
 * The latest semantic confidence image for the `GARFrame` as a
 * <a href="https://developer.apple.com/documentation/corevideo/cvpixelbuffer">`CVPixelBuffer`</a>.
 * Each pixel is an 8-bit integer representing the confidence of the semantic label, with 0
 * representing the lowest confidence and 255 representing the highest confidence.
 *
 * `GARFrame` retains the semantic `CVPixelBuffer`. Holding references to `GARFrame`s will
 * eventually exhaust resources.
 *
 * `GARFrame.semanticConfidenceImage` will be nil if `GARSessionConfiguration` does not have
 * `#GARSemanticModeEnabled` set. Use `GARSession#isSemanticModeSupported:` to check for support for
 * the Scene Semantics API.
 *
 * `GARFrame.semanticConfidenceImage` may be nil for the first few frames after initializing
 * semantics, or if memory is exhausted due to retaining old `GARFrame`s.
 */
@property(nullable, readonly) CVPixelBufferRef semanticConfidenceImage CF_RETURNS_NOT_RETAINED;

/**
 * Retrieves the fraction of the most recent semantics frame that are @p queryLabel.
 * Queries the semantic image provided by `GARFrame.semanticImage` for pixels labeled by @p
 * queryLabel. This call is more efficient than retrieving the `CVPixelBuffer` and performing a
 * pixel-wise search for the detected labels.
 *
 * If `GARFrame.semanticImage` is nil, `GARFrame#fractionForSemanticLabel:` will return 0.0.
 *
 * @param queryLabel the label to search for in the semantic image. See `#GARSemanticLabel` for
 * options.
 * @return The fraction of the semantic image with the given `queryLabel`.
 */
- (float)fractionForSemanticLabel:(GARSemanticLabel)queryLabel;

@end
NS_ASSUME_NONNULL_END