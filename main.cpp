#include<iostream>

namespace {
	class Enemy {
	private:
		void Approach();
		void Shoot();
		void Escape();

	public:
		void Update();

		Enemy();

	private:
		using Phase = void(Enemy::*)();
		Phase CurrentPhase_{ nullptr };
	};

	void Enemy::Update() {
		(this->*CurrentPhase_)();
	}

	void Enemy::Approach() {
		std::cout << "接近\n";
		CurrentPhase_ = &Enemy::Shoot;
	}

	void Enemy::Shoot() {
		std::cout << "射撃\n";
		CurrentPhase_ = &Enemy::Escape;
	}

	void Enemy::Escape() {
		std::cout << "離脱\n";
	}

	Enemy::Enemy() {
		CurrentPhase_ = &Enemy::Approach;
	}
}

int main() {
	Enemy enemy{};
	enemy.Update();
	enemy.Update();
	enemy.Update();

	return 0;
}