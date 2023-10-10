// Copyright (c) 2023 Damian Nowakowski. All rights reserved.

#pragma once

#ifdef __cpp_impl_coroutine

#include <coroutine>

struct FECFCoroutinePromise;
using FECFCoroutineHandle = std::coroutine_handle<FECFCoroutinePromise>;

struct FECFCoroutine : FECFCoroutineHandle
{
	using promise_type = ::FECFCoroutinePromise;
};

struct FECFCoroutinePromise
{
	FECFCoroutine get_return_object() { return { FECFCoroutine::from_promise(*this) }; }
	std::suspend_never initial_suspend() { return {}; }
	std::suspend_never final_suspend() noexcept { return {}; }
	void return_void() {}
	void unhandled_exception() {}
};

#else

struct FECFCoroutine
{};

struct FECFCoroutineHandle
{};

#endif