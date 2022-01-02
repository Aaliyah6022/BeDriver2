#include <ntdef.h>
#include <ntifs.h>
#include <ntddk.h>

extern "C" NTSTATUS NTAPI MmCopyVirtualMemory
(
	PEPROCESS SourceProcess,
	PVOID SourceAddress,
	PEPROCESS TargetProcess,
	PVOID TargetAddress,
	SIZE_T BufferSize,
	KPROCESSOR_MODE PreviousMode,
	PSIZE_T ReturnSize
);

NTSTATUS KernelRead(PEPROCESS process, void* address, void* buffer, size_t size)
{
	size_t bytes = 0;
	auto status = MmCopyVirtualMemory(process, address, IoGetCurrentProcess(), buffer, size, KernelMode, &bytes);
	if (!NT_SUCCESS(status) || !bytes)
		return STATUS_INVALID_ADDRESS;

	return status;
}

NTSTATUS KernelWrite(PEPROCESS process, void* address, void* buffer, size_t size)
{
	size_t bytes = 0;
	auto status = MmCopyVirtualMemory(IoGetCurrentProcess(), buffer, process, address, size, KernelMode, &bytes);
	if (!NT_SUCCESS(status) || !bytes)
		return STATUS_INVALID_ADDRESS;

	return status;
}

void UnloadRoutine(PDRIVER_OBJECT DriverObject)
{
	UNREFERENCED_PARAMETER(DriverObject);

	DbgPrintEx(0, 0, "Unload routine called.\n");
}

extern "C" NTSTATUS DriverEntry(PDRIVER_OBJECT DriverObject, PUNICODE_STRING RegistryPath)
{
	UNREFERENCED_PARAMETER(RegistryPath);

	DriverObject->DriverUnload = UnloadRoutine;

	DbgPrintEx(0, 0, "Driver Loaded!\n");
	return STATUS_SUCCESS;
}