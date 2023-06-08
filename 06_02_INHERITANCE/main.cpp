#include <iostream>

class IElectronics {
public:
	virtual void ShowSpec() const = 0;
	virtual ~IElectronics() = default;
};

class Appliances: public IElectronics {
private:
	unsigned short _weight;
public:
	Appliances(const unsigned short weight) : _weight{ weight } {}
	void ShowSpec() const override {
		std::cout << "Weight: " << _weight << std::endl;
	}
};

class Device: public IElectronics {
private:
	unsigned short _batteryLife;
public:
	Device(const unsigned short batteryLife) :
		_batteryLife{ batteryLife } {}
	void ShowSpec() const override {
		std::cout << "Battery life: " << _batteryLife << std::endl;
	}
};

class Player : public Device {
private:
	unsigned short _totalTracks;
public:
	Player(const unsigned short batteryLife,
		const unsigned short totalTracks) :
		Device(batteryLife),
		_totalTracks{ totalTracks } {}
	void ShowSpec() const override {
		Device::ShowSpec();
		ShowTotalTracks();
	}
	void ShowTotalTracks() const {
		std::cout << "Total tracks: " << _totalTracks << std::endl;
	}
};

int main() {
	Player player{ 36, 100 };
	Device device{ 24 };
	Device *device_ptr = &device;
	Device *player_ptr = &player;
	device_ptr->ShowSpec();
	player_ptr->ShowSpec();

	return 0;
}