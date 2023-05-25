#include <memory>
#include "utils.h"

class MemoryLeakItem {
  public:
    int value;

    MemoryLeakItem(int v) {
      this->value = v;
    }
};

class MemoryLeak {
  public:
    std::unique_ptr<MemoryLeakItem> item1;
    MemoryLeakItem* item2;

    MemoryLeak(
      std::unique_ptr<MemoryLeakItem> _item1,
      MemoryLeakItem* _item2
    ) :
      item1(std::move(_item1)),
      item2(_item2)
    {}

    ~MemoryLeak() {
      delete item2;
    }
    MemoryLeak(const MemoryLeak&) = delete;
    MemoryLeak& operator=(const MemoryLeak&) = delete;
};

auto test_memory_leak_raw_pointer() -> void {
  int *node;
  node = (int *) malloc(8);
  char *login = new char(50);
}

auto test_memory_leak_with_instance_class() -> void {
  auto item1 = std::make_unique<MemoryLeakItem>(1);
  auto item2 = new MemoryLeakItem(2);

  auto ml = new MemoryLeak(std::move(item1), item2);

  delete ml;
  item2 = nullptr;
}


auto test_memory_leak() -> void {
  print_test_header("test_memory_leak");
  // test_memory_leak_raw_pointer();
  test_memory_leak_with_instance_class();
  print_test_footer("test_memory_leak");
}
