import SwiftUI
import CompositorServices

// Default configuration
struct ContentStageConfiguration: CompositorLayerConfiguration {
  func makeConfiguration(capabilities: LayerRenderer.Capabilities, configuration: inout LayerRenderer.Configuration) {
	  let supportsFoveation = capabilities.supportsFoveation
	  let supportedLayouts = capabilities.supportedLayouts(options: supportsFoveation ? [.foveationEnabled] : [])
	  
	  // The device supports the `dedicated` and `layered` layouts.
	  // The simulator supports the `dedicated` and `shared` layouts.
	  configuration.layout = supportedLayouts.contains(.layered) ? .layered : .dedicated
	  configuration.isFoveationEnabled = supportsFoveation
	  configuration.colorFormat = .rgba16Float
	  configuration.depthFormat = .depth32Float
  }
}

@main
struct ExampleApp: App {
	var body: some Scene {
		ImmersiveSpace {
			CompositorLayer(configuration: ContentStageConfiguration()) { layerRenderer in
				let renderThread = Thread {
					var engine = BgfxAdapter(layerRenderer)
					engine.renderLoop()
				}
				renderThread.name = "Render Thread"
				renderThread.start()
			}
		}
	}
}
