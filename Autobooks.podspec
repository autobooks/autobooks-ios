Pod::Spec.new do |s|
  s.name = 'Autobooks'
  s.version = '1.10.2'
  s.license = 'Apache2'
  s.summary = 'Autobooks SDK for iOS'
  s.homepage = 'https://github.com/autobooks/autobooks-ios'
  s.authors = { 'Autobooks' => 'developer@autobooks.co' }
  s.source = { :git => 'https://github.com/autobooks/autobooks-ios.git', :tag => s.version }
  s.documentation_url = 'https://github.com/autobooks/autobooks-ios'

  s.ios.deployment_target = '14.0'

  s.swift_versions = ['5']
  
  s.vendored_frameworks = ['Frameworks/Autobooks.xcframework', 'Frameworks/triPOSMobileSDK.xcframework']

  s.pod_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }
  s.user_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }
end
