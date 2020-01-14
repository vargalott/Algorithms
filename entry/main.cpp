// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

//#define __GARBAGE_EXTERN__
//#define __PATTERNS_INCLUDES__
#include "./pch.hpp"

// inside part that use rttr
#define __RTTR_TEST_OFF__
#include "..//Algorithms/garbage/templates.hpp"

int __cdecl main(void)
{
#ifndef __RTTR_TEST_OFF__

	RTTR_Test::DO_TEST();

#endif

#pragma region disabling when rttr use (just because)
#ifdef __RTTR_TEST_OFF__

	// templates
	std::size_t count = 0;
	AlmostReflectionTypeTraits::pod_reflection::detect_fields_count<AlmostReflectionTypeTraits::POD>(count);
	std::cout << "AlmostReflectionTypeTraits::POD fields count: " << count << "\n";	

	std::cout << "10! = " << TemplateMagic::factorial<10>::result << "\n";
	TemplateMagic::deep_switch::calc(1, 2);

	struct has_foo { inline void foo() const noexcept { std::cout << "foo\n"; } } foo;
	struct has_bar { inline void bar() const noexcept { std::cout << "bar\n"; } } bar;
	AlmostReflectionTypeTraits::call_foo_or_bar(foo);
	AlmostReflectionTypeTraits::call_foo_or_bar(bar);

#endif // __RTTR_TEST_OFF__
#pragma endregion

	return 0;
};

#define EMPTY_ENTRY_POINT
#ifndef EMPTY_ENTRY_POINT

int __cdecl main(void)
{
	return 0;
};

#endif // !EMPTY_ENTRY_POINT