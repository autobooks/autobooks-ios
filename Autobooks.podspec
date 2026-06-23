Pod::Spec.new do |s|
  s.name = 'Autobooks'
  s.version = '2.4.0'
  s.license = 'Apache2'
  s.summary = 'Autobooks SDK for iOS'
  s.homepage = 'https://github.com/autobooks/autobooks-ios'
  s.authors = { 'Autobooks' => 'developer@autobooks.co' }
  s.source = { :git => 'https://github.com/autobooks/autobooks-ios.git', :tag => s.version }
  s.documentation_url = 'https://github.com/autobooks/autobooks-ios'

  s.ios.deployment_target = '16.0'

  s.swift_versions = ['5']
  
  s.vendored_frameworks = ['Frameworks/Autobooks.xcframework', 'Frameworks/triPOSMobileSDK.xcframework']

  # No EXCLUDED_ARCHS: as of 2.4.0 every vendored slice (Autobooks, triPOS, Kount) ships a
  # native arm64 iOS Simulator slice, matching the project (which removed EXCLUDED_ARCHS in 2.3.6).
  # Excluding arm64 here would needlessly force Apple-silicon consumers into x86_64/Rosetta builds.
end
