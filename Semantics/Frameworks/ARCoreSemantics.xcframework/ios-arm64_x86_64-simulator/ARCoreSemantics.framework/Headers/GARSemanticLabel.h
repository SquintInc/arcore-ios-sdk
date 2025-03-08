/*
 * Copyright 2023 Google LLC. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0  = the "License");
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

/** @defgroup GARSemanticLabel */

/**
 * @ingroup GARSemanticLabel
 * Defines the labels the Scene Semantics API is able to detect and maps human-readable names to
 * per-pixel semantic labels. See
 * <a href="https://developers.google.com/ar/develop/ios/scene-semantics">the Scene Semantics
 * Developer Guide</a> for more information.
 */
typedef NS_ENUM(NSInteger, GARSemanticLabel) {
  /** Pixels with no semantic label available in the API output. */
  GARSemanticLabelUnlabeled = 0,
  /**
   * Pixels of the open sky, including clouds. Thin electrical wires in front of the sky are
   * included, but leaves/vegetation are not included.
   */
  GARSemanticLabelSky = 1,
  /**
   * Pixels of buildings, including houses, garages, etc. Includes all structures attached to the
   * building, such as signs, solar panels, scaffolding, etc.
   */
  GARSemanticLabelBuilding = 2,
  /**
   * Pixels of non-walkable vegetation, like trees and shrubs. In contrast, 'terrain' specifies
   * walkable vegetation, like grass.
   */
  GARSemanticLabelTree = 3,
  /** Pixels of drivable surfaces for vehicles, including paved, unpaved, dirt, driveways, etc. */
  GARSemanticLabelRoad = 4,
  /** Pixels of sidewalks for pedestrians and cyclists, including associated curbs. */
  GARSemanticLabelSidewalk = 5,
  /**
   * Pixels of walkable vegetation areas, including grass, soil, sand, etc. In contrast, 'tree'
   * specifies non-walkable vegetation, like trees and bushes.
   */
  GARSemanticLabelTerrain = 6,
  /**
   * Pixels of structures that are not buildings, including fences, guardrails, stand-alone walls,
   * tunnels, bridges, mountains, etc.
   */
  GARSemanticLabelStructure = 7,
  /**
   * Pixels of general temporary and permanent objects and obstacles, including mailboxes, fire
   * hydrants, poles, street lights, phone booths, bus stop enclosures, cones, parking meters, etc.
   */
  GARSemanticLabelObject = 8,
  /**
   * Pixels of vehicles, including cars, vans, buses, trucks, motorcycles, bicycles, trains, etc.
   */
  GARSemanticLabelVehicle = 9,
  /** Pixels of humans and animals. */
  GARSemanticLabelPerson = 10,
  /** Pixels of ground surfaces covered by water, including lakes, rivers, etc. */
  GARSemanticLabelWater = 11,
};
