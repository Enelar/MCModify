#include "../include/NamedBinaryTag.hpp"

namespace NBT
{
	Tag::End const Tag::End::END;
	Tag::ID_t const Tag::End::ID = 0;
	Tag::ID_t const Tag::Byte::ID = 1;
	Tag::ID_t const Tag::Short::ID = 2;
	Tag::ID_t const Tag::Int::ID = 3;
	Tag::ID_t const Tag::Long::ID = 4;
	Tag::ID_t const Tag::Float::ID = 5;
	Tag::ID_t const Tag::Double::ID = 6;
	Tag::ID_t const Tag::ByteArray::ID = 7;
	Tag::ID_t const Tag::String::ID = 8;
	Tag::ID_t const Tag::List::ID = 9;
	Tag::ID_t const Tag::Compound::ID = 10;
	Tag::ID_t const Tag::IntArray::ID = 11;
	std::map<Tag::ID_t, std::function<std::unique_ptr<Tag> (Tag::Name_t const &name, std::istream &)>> const Tag::readers
	{
		{ Byte::ID, [](Name_t const &name, std::istream &is) -> std::unique_ptr<Tag>
			{
				return std::unique_ptr<Tag>(new Tag::Byte(name, is));
			}
		},
		{ Short::ID, [](Name_t const &name, std::istream &is) -> std::unique_ptr<Tag>
			{
				return std::unique_ptr<Tag>(new Tag::Short(name, is));
			}
		},
		{ Int::ID, [](Name_t const &name, std::istream &is) -> std::unique_ptr<Tag>
			{
				return std::unique_ptr<Tag>(new Tag::Int(name, is));
			}
		},
		{ Long::ID, [](Name_t const &name, std::istream &is) -> std::unique_ptr<Tag>
			{
				return std::unique_ptr<Tag>(new Tag::Long(name, is));
			}
		},
		{ Float::ID, [](Name_t const &name, std::istream &is) -> std::unique_ptr<Tag>
			{
				return std::unique_ptr<Tag>(new Tag::Float(name, is));
			}
		},
		{ Double::ID, [](Name_t const &name, std::istream &is) -> std::unique_ptr<Tag>
			{
				return std::unique_ptr<Tag>(new Tag::Double(name, is));
			}
		},
		{ ByteArray::ID, [](Name_t const &name, std::istream &is) -> std::unique_ptr<Tag>
			{
				return std::unique_ptr<Tag>(new Tag::ByteArray(name, is));
			}
		},
		{ String::ID, [](Name_t const &name, std::istream &is) -> std::unique_ptr<Tag>
			{
				return std::unique_ptr<Tag>(new Tag::String(name, is));
			}
		},
		{ List::ID, [](Name_t const &name, std::istream &is) -> std::unique_ptr<Tag>
			{
				Tag::ID_t type { Tag::Byte(u8"", is).v};
				return std::unique_ptr<Tag>(new Tag::List(name, type, is));
			}
		},
		{ Compound::ID, [](Name_t const &name, std::istream &is) -> std::unique_ptr<Tag>
			{
				return std::unique_ptr<Tag>(new Tag::Compound(name, is));
			}
		},
		{ IntArray::ID, [](Name_t const &name, std::istream &is) -> std::unique_ptr<Tag>
			{
				return std::unique_ptr<Tag>(new Tag::IntArray(name, is));
			}
		}
	};
}
