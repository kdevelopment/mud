#include "stdafx.h"
#include "inventory.h"

MagicAbilityPrototype::MagicAbilityPrototype(const std::string &n, uint16_t baseDam, uint16_t basePurchase) : mName(n), mBaseDamage(baseDam), mBasePurchaseAmount(basePurchase) {}

void MagicAbilityPrototype::toString(std::string &s) const {
		char buf[1024] = { '\0' };
		sprintf_s(&buf[0], sizeof(buf), "Name: %s\nBaseDamage: %d\nBase Purchase Price: %d", mName.c_str(), mBaseDamage, mBasePurchaseAmount);
		s.append(&buf[0]);
	}
SwordAbilityPrototype::SwordAbilityPrototype(const std::string & n, uint16_t baseDam, uint16_t basePurchase) : mName(n), mBaseDamage(baseDam), mBasePurchaseAmount(basePurchase)
{
}
void SwordAbilityPrototype::toString(std::string &s) const {
	char buf[1024] = { '\0' };
	sprintf_s(&buf[0], sizeof(buf), "Name: %s\nBaseDamage: %d\nBase Purchase Price: %d", mName.c_str(), mBaseDamage, mBasePurchaseAmount);
	s.append(&buf[0]);
}
