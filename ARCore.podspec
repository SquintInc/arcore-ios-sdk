Pod::Spec.new do |s|
    s.name              = 'ARCore'
    s.version           = '1.47.1'
    s.summary           = 'Custom ARCore SDK with updated nanopb dependency.'
    s.homepage          = 'https://github.com/SquintInc/arcore-ios-sdk'
    s.license           = {
      :type => 'Copyright',
      :file => 'LICENSE'
    }
    s.author            = {
      'Google, Inc.' => 'google-ar-sdk@google.com'
    }
    s.source            = {
      :git => 'https://github.com/SquintInc/arcore-ios-sdk.git'
    }
    s.platform          = :ios, '13.0'
    s.swift_version     = "5.9"
    s.preserve_paths    = ["CHANGELOG", "README.md", "LICENSE", "Package.swift"]
    s.cocoapods_version = ">= 1.12.0"
    s.default_subspec   = 'Base'
    s.pod_target_xcconfig = {
      'ENABLE_BITCODE' => 'NO',
      'EXCLUDED_ARCHS[sdk=iphoneos*]' => 'armv7',
      'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'i386'
    }
    s.static_framework = true
  
    s.subspec 'Base' do |base|
      base.source_files = 'Base/Sources/**/*.{h,m}'
      base.vendored_frameworks = 'Base/Frameworks/ARCoreBase.xcframework'
      base.frameworks = ['CoreTelephony', 'Foundation', 'SystemConfiguration', 'Security', 'UIKit']
      base.libraries = ['c++', 'z']
      base.preserve_paths = ['Base/dummy.m', 'Base/Sources/ARCore/module.modulemap']
      base.dependency 'nanopb', '~> 3.30910'
      base.dependency 'GoogleDataTransport', '~> 10.1.0'
    end
  
    s.subspec 'CloudAnchors' do |cloud|
      cloud.source_files = 'CloudAnchors/Sources/**/*.{h,m}'
      cloud.vendored_frameworks = 'CloudAnchors/Frameworks/ARCoreCloudAnchors.xcframework'
      cloud.frameworks = ['ARKit', 'CoreFoundation', 'CoreGraphics', 'CoreImage', 'CoreMotion', 'CoreVideo', 'CoreTelephony', 'Foundation', 'ImageIO', 'Security', 'SystemConfiguration', 'UIKit']
      cloud.libraries = ['c++', 'z', 'sqlite3', 'm']
      cloud.preserve_paths = 'CloudAnchors/dummy.m'
      cloud.dependency 'ARCore/GARSession', '~> 1.47.0'
      cloud.dependency 'ARCore/Base', '~> 1.47.0'
      cloud.dependency 'ARCore/TFShared', '~> 1.47.0'
      cloud.dependency 'ARCore/GARSession', '~> 1.47.0'
      cloud.dependency 'ARCore/Base', '~> 1.47.0'
      cloud.dependency 'GTMSessionFetcher/Core', '>= 3.4', '< 4.1.0'
      cloud.dependency 'nanopb', '~> 3.30910'
    end
  
    s.subspec 'Geospatial' do |geo|
      geo.source_files = 'Geospatial/Sources/**/*.{h,m}'
      geo.vendored_frameworks = 'Geospatial/Frameworks/ARCoreGeospatial.xcframework'
      geo.frameworks = ['ARKit', 'AVFoundation', 'CoreFoundation', 'CoreGraphics', 'CoreImage', 'CoreLocation', 'CoreMedia', 'CoreMotion', 'CoreTelephony', 'CoreVideo', 'Foundation', 'ImageIO', 'SceneKit', 'Security', 'SystemConfiguration', 'UIKit']
      geo.libraries = ['c++', 'z', 'sqlite3', 'dl', 'm']
      geo.preserve_paths = 'Geospatial/dummy.m'
      geo.dependency 'ARCore/Base', '~> 1.47.0'
      geo.dependency 'ARCore/TFShared', '~> 1.47.0'
      geo.dependency 'ARCore/GARSession', '~> 1.47.0'
    end
  
    s.subspec 'GARSession' do |gar|
      gar.source_files = 'GARSession/Sources/**/*.{h,m}'
      gar.vendored_frameworks = 'GARSession/Frameworks/ARCoreGARSession.xcframework'
      gar.frameworks = ['ARKit', 'CoreFoundation', 'CoreGraphics', 'CoreImage', 'CoreMotion', 'CoreTelephony', 'CoreVideo', 'Foundation', 'ImageIO', 'Security', 'SystemConfiguration', 'UIKit']
      gar.libraries = ['c++', 'z', 'sqlite3']
      gar.preserve_paths = 'GARSession/dummy.m'
      gar.resource_bundles = {
        'ARCoreResources' => 'GARSession/Resources/ARCoreResources/**'
      }
      gar.dependency 'ARCore/Base', '~> 1.47.0'
      gar.dependency 'Firebase/RemoteConfig', '~> 11.2'
      gar.dependency 'nanopb', '~> 3.30910'
  
    end
  
    s.subspec 'AugmentedFaces' do |faces|
      faces.source_files = 'AugmentedFaces/Sources/**/*.{h,m}'
      faces.vendored_frameworks = 'AugmentedFaces/Frameworks/ARCoreAugmentedFaces.xcframework'
      faces.frameworks = ['Accelerate', 'AVFoundation', 'CoreFoundation', 'CoreGraphics', 'CoreMedia', 'CoreTelephony', 'CoreVideo', 'Foundation', 'GLKit', 'ImageIO', 'Metal', 'MobileCoreServices', 'OpenGLES', 'QuartzCore', 'Security', 'SystemConfiguration', 'UIKit']
      faces.libraries = ['z', 'c++', 'dl', 'm']
      faces.preserve_paths = 'AugmentedFaces/dummy.m'
      faces.resource_bundles = {
        'ARCoreFaceResources' => 'AugmentedFaces/Resources/ARCoreFaceResources/**'
      }
      faces.dependency 'ARCore/Base', '~> 1.47.0'
      faces.dependency 'ARCore/TFShared', '~> 1.47.0'
      faces.dependency 'nanopb', '~> 3.30910'
    end
  
    s.subspec 'Semantics' do |semantics|
      semantics.source_files = 'Semantics/Sources/**/*.{h,m}'
      semantics.vendored_frameworks = 'Semantics/Frameworks/ARCoreSemantics.xcframework'
      semantics.frameworks = ['Accelerate', 'ARKit', 'CoreVideo', 'Foundation']
      semantics.libraries = ['z', 'c++', 'dl', 'm']
      semantics.preserve_paths = 'Semantics/dummy.m'
      semantics.resource_bundles = {
        'ARCoreCoreMLSemanticsResources' => 'Semantics/Resources/ARCoreCoreMLSemanticsResources/**'
      }
      semantics.dependency 'ARCore/Base', '~> 1.47.0'
      semantics.dependency 'ARCore/TFShared', '~> 1.47.0'
      semantics.dependency 'ARCore/GARSession', '~> 1.47.0'
    end
  
    s.subspec 'TFShared' do |tf|
      tf.source_files = 'TFShared/Sources/**/*.{h,m}'
      tf.vendored_frameworks = 'TFShared/Frameworks/ARCoreTFShared.xcframework'
      tf.frameworks = ['Accelerate']
      tf.libraries = ['c++', 'z']
      tf.preserve_paths = 'TFShared/dummy.m'
      tf.dependency 'ARCore/Base', '~> 1.47.0'
    end
  end