#include <memory>
#include "utils.h"

class MemoryLeakItem {
  public:
    int value;

    MemoryLeakItem(int v) {
      this->value = v;
    }
};


class InstanceMemoryLeak {
  public:
    std::unique_ptr<MemoryLeakItem> item1;
    MemoryLeakItem* item2;

    InstanceMemoryLeak(
      std::unique_ptr<MemoryLeakItem> _item1,
      MemoryLeakItem* _item2
    ) :
      item1(std::move(_item1)),
      item2(_item2)
    {}

    ~InstanceMemoryLeak() {
      delete item2;
    }
    InstanceMemoryLeak(const InstanceMemoryLeak&) = delete;
    InstanceMemoryLeak& operator=(const InstanceMemoryLeak&) = delete;
};

class StaticMemoryLeak {
  public:
    static std::unique_ptr<MemoryLeakItem> item1;
    static MemoryLeakItem* item2;

    static auto initialize() -> void;
    static auto teardown() -> void;
};

std::unique_ptr<MemoryLeakItem> StaticMemoryLeak::item1;
MemoryLeakItem* StaticMemoryLeak::item2 = nullptr;


auto StaticMemoryLeak::initialize() -> void {
  auto _item1 = std::make_unique<MemoryLeakItem>(1);
  auto _item2 = new MemoryLeakItem(2);

  StaticMemoryLeak::item1 = std::move(_item1);
  StaticMemoryLeak::item2 = _item2;
}

auto test_memory_leak_raw_pointer() -> void {
  // int *node;
  // node = (int *) malloc(8);
  // char *login = new char(50);
}

auto test_memory_leak_with_instance_class() -> void {
  auto item1 = std::make_unique<MemoryLeakItem>(1);
  auto item2 = new MemoryLeakItem(2);

  auto ml = new InstanceMemoryLeak(std::move(item1), item2);

  delete ml;
  item2 = nullptr;
}

auto test_memory_leak_with_static_class() -> void {
  StaticMemoryLeak::initialize();
}


auto test_memory_leak() -> void {
  print_test_header("test_memory_leak");
  test_memory_leak_raw_pointer();
  test_memory_leak_with_instance_class();
  print_test_footer("test_memory_leak");
}
