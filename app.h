#ifndef NES_APP_H
#define NES_APP_H

#include <escher.h>
#include "nes_controller.h"

class AppsContainer;

namespace NES {

class App : public ::App {
public:
  class Descriptor : public ::App::Descriptor {
  public:
    I18n::Message name() override;
    I18n::Message upperName() override;
    const Image * icon() override;
  };
  class Snapshot : public ::App::Snapshot {
  public:
    Snapshot();
    App * unpack(Container * container) override;
    Descriptor * descriptor() override;
  };
  virtual void didBecomeActive(Window * window);
  virtual void willBecomeInactive();
  void * getHeap() { return this->m_nesHeap; };
private:
  App(Container * container, Snapshot * snapshot);
  NesController m_nesController;
  AppsContainer * m_appsContainer;
  static constexpr int k_nesHeapSize = 1<<16;
  char m_nesHeap[k_nesHeapSize];
};

}

#endif
