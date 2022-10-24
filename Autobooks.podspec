Pod::Spec.new do |s|
  s.name = 'Autobooks'
  s.version = '0.1.0'
  s.license = 'Apache2'
  s.summary = 'Autobooks SDK for iOS'
  s.homepage = 'https://github.com/autobooks/autobooks-ios'
  s.authors = { 'Autobooks' => 'helpdesk@autobooks.co' }
  s.source = { :git => 'https://github.com/autobooks/autobooks-ios.git', :tag => s.version }
  s.documentation_url = 'https://autobooks.github.io/autobooks-ios/documentation/autobooks'

  s.ios.deployment_target = '12.0'

  s.swift_versions = ['5']

  s.source_files = 'Sources/**/*.swift'
  s.resources = "Sources/Resources/*.xcassets"
end
