#ifndef MUD_INVENTORY_H_
#pragma once
#define MUD_INVENTORY_H_

#include <vector>
#include <memory>

class MagicAbilityPrototype {
public:
	MagicAbilityPrototype(const std::string &n, uint16_t baseDam, uint16_t basePurchase);
	const std::string &getName() const { return mName; }
	const uint16_t getBaseDamage() const { return mBaseDamage; }
	const uint16_t getBasePurchaseAmount() const { return mBasePurchaseAmount; }
	void toString(std::string &s) const;
private:
	std::string mName;
	int	mBaseDamage;
	int	mBasePurchaseAmount;
};

class SwordAbilityPrototype {
public:
	SwordAbilityPrototype(const std::string &n, uint16_t baseDam, uint16_t basePurchase);
	const std::string &getName() const { return mName; }
	const uint16_t getBaseDamage() const { return mBaseDamage; }
	const uint16_t getBasePurchaseAmount() const { return mBasePurchaseAmount; }
	void toString(std::string &s) const;
private:
	std::string mName;
	int	mBaseDamage;
	int	mBasePurchaseAmount;
};

class BaseInventoryFolder {
public:
	enum FOLDER_TYPE {
		MAGIC_ABILITY
		, SWORD_ABILITY
		, BOW_ABILITY
		, ITEMS
	};
public:
	BaseInventoryFolder(const FOLDER_TYPE &ft) : mType(ft) {}
	virtual ~BaseInventoryFolder() {}
	const FOLDER_TYPE &getFolderType() const { return mType; }
protected:
	FOLDER_TYPE mType;
};

class MagicAbilityInstance {
public:
	MagicAbilityInstance(const MagicAbilityPrototype *map) : mMagicAbilityProto(map), ExtraDamageFromEnchantment(0) {}
	~MagicAbilityInstance() {}
	const char *getName() const { return getPrototype()->getName().c_str(); }
	const MagicAbilityPrototype *getPrototype() const { return mMagicAbilityProto; }
	int getDamange() const { return getPrototype()->getBaseDamage() + ExtraDamageFromEnchantment; }
	void toString(std::string &s) const {
		getPrototype()->toString(s);
		char buf[1024] = { '\0' };
		sprintf_s(&buf[0], sizeof(buf), "%s\nExtraDamage: %d", s.c_str(), ExtraDamageFromEnchantment);
		s = &buf[0];
	}
private:
	const MagicAbilityPrototype *mMagicAbilityProto;
	int ExtraDamageFromEnchantment;
};
class SwordAbilityInstance {
public:
	SwordAbilityInstance(const SwordAbilityPrototype *sap) : mSwordAbilityProto(sap), ExtraDamageFromEnchantment(0) {}
	~SwordAbilityInstance() {}
 	const SwordAbilityPrototype * getPrototype() const { return mSwordAbilityProto; }
	const char *getName() const { return getPrototype()->getName().c_str(); }
	int getDamange() const { return getPrototype()->getBaseDamage() + ExtraDamageFromEnchantment; }
	void toString(std::string &s) const {
		getPrototype()->toString(s);
		char buf[1024] = { '\0' };
		sprintf_s(&buf[0], sizeof(buf), "%s\nExtraDamage: %d", s.c_str(), ExtraDamageFromEnchantment);
		s = &buf[0];
	}
private:
	const SwordAbilityPrototype *mSwordAbilityProto;
	int ExtraDamageFromEnchantment;
};

class MagicAbilityFolder : public BaseInventoryFolder  {
public:
	static const FOLDER_TYPE TYPE = MAGIC_ABILITY;
	typedef std::vector<std::shared_ptr<MagicAbilityInstance>> MAGIC_ABILITY_FOLDER_TYPE;
	typedef MAGIC_ABILITY_FOLDER_TYPE::iterator MAGIC_ABILITY_FOLDER_TYPE_IT;
public:
	MagicAbilityFolder(const std::string &name) : BaseInventoryFolder(MAGIC_ABILITY), mFolder(), mName(name) {}
	virtual ~MagicAbilityFolder() {}
	void addMagicAbility(const std::shared_ptr<MagicAbilityInstance> &ma) {
		mFolder.push_back(ma);
	}
	void toString(std::string &foldInfo) {
		MAGIC_ABILITY_FOLDER_TYPE_IT it = mFolder.begin();
		for (; it != mFolder.end(); ++it) {
			(*it)->toString(foldInfo);
			foldInfo.append("\n");
		}
	}
	void toInterfaceString(std::string &interfaceStr) {
		MAGIC_ABILITY_FOLDER_TYPE_IT it = mFolder.begin();
		for (int i=0; it != mFolder.end(); ++it,i++) {
			char buffer[128] = { '\0' };
			snprintf(&buffer[0], sizeof(buffer), "%d: %s\n", i, (*it)->getName());
			interfaceStr.append(&buffer[0]);
		}
	}
protected:
	MAGIC_ABILITY_FOLDER_TYPE mFolder;
	std::string mName;
};
class SwordAbilityFolder : public BaseInventoryFolder {
public:
	static const FOLDER_TYPE TYPE = SWORD_ABILITY;
	typedef std::vector<std::shared_ptr<SwordAbilityInstance>> SWORD_ABILITY_FOLDER_TYPE;
	typedef SWORD_ABILITY_FOLDER_TYPE::iterator SWORD_ABILITY_FOLDER_TYPE_IT;
public:
	SwordAbilityFolder(const std::string &name) : BaseInventoryFolder(SWORD_ABILITY), mFolder(), mName(name) {}
	virtual ~SwordAbilityFolder() {}
	void addSwordAbility(const std::shared_ptr<SwordAbilityInstance> &sa) {
		mFolder.push_back(sa);
	}
	void toInterfaceString(std::string &interfaceStr) {
		SWORD_ABILITY_FOLDER_TYPE_IT it = mFolder.begin();
		for (int i = 0; it != mFolder.end(); ++it, i++) {
			char buffer[128] = { '\0' };
			snprintf(&buffer[0], sizeof(buffer), "%d: %s\n", i, (*it)->getName());
			interfaceStr.append(&buffer[0]);
		}
	}
protected:
	SWORD_ABILITY_FOLDER_TYPE mFolder;
	std::string mName;
};
class Inventory {
public:
	typedef std::vector<std::shared_ptr<BaseInventoryFolder>> INV_FOLDER_TYPE;
	typedef INV_FOLDER_TYPE::iterator INV_FOLDER_TYPE_IT;
public:
	void addFolder(BaseInventoryFolder *bif) {
		mFolders.push_back(std::shared_ptr<BaseInventoryFolder>(bif));
	}
	template<typename T>
	std::shared_ptr<T> getFolderByType(T *) {
		INV_FOLDER_TYPE_IT it = mFolders.begin();
		for (; it != mFolders.end(); ++it) {
			if ((*it)->getFolderType() == T::TYPE) {
				return std::shared_ptr<T>((T*)(*it).get());
			}
		}
		return std::shared_ptr<T>(0);
	}
	/*
	template<typename T>
	std::shared_ptr<T> getFolderByType(const BaseInventoryFolder::FOLDER_TYPE &ft) {
		INV_FOLDER_TYPE_IT it = mFolders.begin();
		for (; it != mFolders.end(); ++it) {
			if ((*it)->getFolderType() == ft) {
				return std::shared_ptr<T>((T*)(*it).get());
			}
		}
		return std::shared_ptr<T>(0);
	}
	*/
protected:
	INV_FOLDER_TYPE mFolders;
};

#endif
