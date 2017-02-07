Pod::Spec.new do |s|
  s.name             = 'HyprLoco'
  s.version          = '0.0.9'
  s.summary          = 'Integrate HyprLoco NORM location services into your app.'

  s.description      = <<-DESC
    The HyprLoco SDK allows your iOS application to easily communicate with the HyprLoco Order Information System (OIS).

    Visit [HyprLoco.com](http://HyprLoco.com) to learn how we can help your restaurant increase guest loyalty.

    Please email any questions about the HyprLoco iOS SDK to [support@HyprLoco.com](mailto:support@HyprLoco.com).
                       DESC

  s.platform         = :ios, '8.2'
  s.homepage         = 'http://github.com/hyprloco/hyprloco-sdk-ios'
  s.license          = { :type => 'MIT', :file => 'License.txt' }
  s.author           = { 'HyprLoco, Inc.' => 'support@HyprLoco.com' }
  s.source           = { :git => 'https://github.com/hyprloco/hyprloco-sdk-ios.git', :tag => s.version.to_s }
  s.documentation_url = 'http://hypr-dev-sdk.azurewebsites.net/iOS/'
  s.social_media_url = 'https://twitter.com/HyprLoco'
  s.frameworks = 'AudioToolbox', 'AVFoundation', 'CoreGraphics', 'CoreLocation', 'CoreMotion', 'Foundation', 'MapKit', 'QuartzCore', 'SystemConfiguration', 'UIKit', 'CoreData', 'Foundation'
  s.vendored_framework = 'HyprLoco.framework'
  s.source_files = 'HyprLoco.framework/**/*.h'
  s.resources = 'Resources/BDDataModel.momd'
  s.requires_arc = true
  s.preserve_paths  = 'HyprLoco.framework', 'BDDataModel.bundle'
  s.xcconfig = { 'OTHER_LDFLAGS' => '$(inherited) -ObjC', 'ENABLE_BITCODE' => 'NO' }
end
