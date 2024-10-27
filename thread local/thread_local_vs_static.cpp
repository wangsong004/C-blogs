#include <iostream>
#include <map>

int main() {
	// 创建一个 std::multimap，键和值都为 int 类型
	std::multimap<int, int> mm;

	// 插入一些键值对
	mm.insert({ 1, 10 });
	mm.insert({ 2, 20 });
	mm.insert({ 2, 25 }); // 插入具有相同键的元素
	mm.insert({ 3, 30 });
	mm.insert({ 3, 35 }); // 插入具有相同键的元素
	mm.insert({ 3, 40 }); // 插入具有相同键的元素

	// 遍历并输出所有键值对
	std::cout << "All elements in the multimap:" << std::endl;
	for (const auto& pair : mm) {
		std::cout << "Key: " << pair.first << ", Value: " << pair.second << std::endl;
	}

	// 查找所有键为 2 的元素
	std::cout << "\nElements with key 2:" << std::endl;
	auto range = mm.equal_range(2);
	for (auto it = range.first; it != range.second; ++it) {
		std::cout << "Key: " << it->first << ", Value: " << it->second << std::endl;
	}

	// 查找所有键为 3 的元素
	std::cout << "\nElements with key 3:" << std::endl;
	range = mm.equal_range(3);
	for (auto it = range.first; it != range.second; ++it) {
		std::cout << "Key: " << it->first << ", Value: " << it->second << std::endl;
	}

	return 0;
}
