#ifndef BgfxAdapter_hpp
#define BgfxAdapter_hpp

#include <CompositorServices/CompositorServices.h>

class BgfxAdapter {
private:
  bool m_initialized = false;
  cp_layer_renderer_t m_layerRenderer = NULL;
  
public:
  BgfxAdapter(cp_layer_renderer_t layerRenderer) : m_layerRenderer(layerRenderer) {
  }
  
  ~BgfxAdapter() {
    shutdown();
  }
  
  bool initialize(void);
  void shutdown(void);
  void render(void);
};

#endif /* BgfxAdapter_hpp */

