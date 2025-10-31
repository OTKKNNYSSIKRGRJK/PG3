#include<iostream>
#include<memory>
#include<vector>

namespace {
	class Animal {
	public:
		virtual void Move() = 0;
		virtual void Voice() = 0;

	public:
		Animal() = default;
		virtual ~Animal() = default;
	};

	class Dog : public Animal {
	public:
		virtual void Move() override { std::cout << "犬が走ってる\n"; }
		virtual void Voice() override { std::cout << "わんわん\n"; }

	public:
		Dog() = default;
		virtual ~Dog() = default;
	};

	class Cat : public Animal {
	public:
		virtual void Move() override { std::cout << "猫が屋根を歩いてる\n"; }
		virtual void Voice() override { std::cout << "にゃー\n"; }

	public:
		Cat() = default;
		virtual ~Cat() = default;
	};

	class Cow : public Animal {
	public:
		virtual void Move() override { std::cout << "牛が歩いてる\n"; }
		virtual void Voice() override { std::cout << "もー\n"; }

	public:
		Cow() = default;
		virtual ~Cow() = default;
	};
}

int main() {
	std::vector<std::unique_ptr<Animal>> animals{};
	animals.emplace_back(new Cat{});
	animals.emplace_back(new Dog{});
	animals.emplace_back(new Cow{});

	for (auto& animal : animals) {
		animal->Move();
		animal->Voice();
		std::cout << "\n";
	}

	return 0;
}