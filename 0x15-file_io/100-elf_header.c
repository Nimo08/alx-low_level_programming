#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <elf.h>
void print_magic(const unsigned char *magic);
void print_class(unsigned char class);
void print_data(unsigned char data);
void print_version(unsigned char version);
void print_osabi(unsigned char osabi);
void print_abi_version(unsigned char abi_version);
void print_type(unsigned short type);
void print_entry(unsigned long entry);
/**
 * main - displays info contained in the ELF header at the
 * start of an ELF file
 * @argc: arg count
 * @argv: arg vector
 * Return: 0
 */
int main(int argc, char **argv)
{
	FILE *file_ptr;
	char *elf_filename;
	Elf32_Ehdr header;

	elf_filename = NULL;
	if (argc != 2)
	{
		printf("Usage: elf_header elf_filename\n");
		exit(98);
	}
	elf_filename = argv[1];
	file_ptr = fopen(elf_filename, "rb");
	if (file_ptr == NULL)
	{
		printf("Error: Not an ELF file\n");
		exit(98);
	}
	if (fread(&header, sizeof(header), 1, file_ptr) != 1)
	{
		printf("Error: Can't read the ELF header\n");
		fclose(file_ptr);
		exit(98);
	}
	print_magic(header.e_ident);
	print_class(header.e_ident[EI_CLASS]);
	print_data(header.e_ident[EI_DATA]);
	print_version(header.e_ident[EI_VERSION]);
	print_osabi(header.e_ident[EI_OSABI]);
	print_abi_version(header.e_ident[EI_ABIVERSION]);
	print_type(header.e_type);
	print_entry(header.e_entry);
	fclose(file_ptr);
	return (0);
}
/**
 * print_magic - display magic
 * @magic: unsigned char
 */
void print_magic(const unsigned char *magic)
{
	int i;

	printf("Magic: ");
	for (i = 0; i < EI_NIDENT; i++)
	{
		printf("%02x ", magic[i]);
	}
	printf("\n");
}
/**
 * print_class - display class
 * @class: unsigned char
 */
void print_class(unsigned char class)
{
	printf("Class: ");
	switch (class)
	{
		case ELFCLASSNONE:
			printf("Invalid class\n");
			break;
		case ELFCLASS32:
			printf("ELF32\n");
			break;
		case ELFCLASS64:
			printf("ELF64\n");
			break;
		default:
			printf("Unknown class\n");
			break;
	}
}
/**
 * print_data - display data
 * @data: unsigned char
 */
void print_data(unsigned char data)
{
	printf("Data: ");
	switch (data)
	{
		case ELFDATANONE:
			printf("Invalid data encodinf\n");
			break;
		case ELFDATA2LSB:
			printf("2's complement, little endian\n");
			break;
		case ELFDATA2MSB:
			printf("2's complement, big endian\n");
			break;
		default:
			printf("Unknown data encoding\n");
			break;
	}
}
/**
 * print_version - display version
 * @version: unsigned char
 */
void print_version(unsigned char version)
{
	printf("Version: %d\n", version);
}
/**
 * print_osabi - display osabi
 * @osabi: unsigned char
 */
void print_osabi(unsigned char osabi)
{
	printf("OS/ABI: ");
	switch (osabi)
	{
		case ELFOSABI_SYSV:
			printf("UNIX System V ABI\n");
			break;
		case ELFOSABI_HPUX:
			printf("HP-UX ABI\n");
			break;
		case ELFOSABI_NETBSD:
			printf("NetBSD ABI\n");
			break;
		case ELFOSABI_LINUX:
			printf("Linux ABI\n");
			break;
		case ELFOSABI_SOLARIS:
			printf("Solaris ABI\n");
			break;
		case ELFOSABI_IRIX:
			printf("IRIX ABI\n");
			break;
		case ELFOSABI_FREEBSD:
			printf("FreeBSD ABI\n");
			break;
		case ELFOSABI_TRU64:
			printf("TRU64 UNIX ABI\n");
			break;
		case ELFOSABI_ARM:
			printf("ARM architecture ABI\n");
			break;
		case ELFOSABI_STANDALONE:
			printf("Standalone (embedded) ABI\n");
			break;
		default:
			printf("Unknown OS/ABI\n");
			break;
	}
}
/**
 * print_abi_version - display abi version
 * @abi_version: unsigned char
 */
void print_abi_version(unsigned char abi_version)
{
	printf("ABI Version: %d\n", abi_version);
}
/**
 * print_type - display type
 * @type: unsigned short
 */
void print_type(unsigned short type)
{
	printf("Type: ");
	switch (type)
	{
		case ET_NONE:
			printf("No file type\n");
			break;
		case ET_REL:
			printf("Relocatable file\n");
			break;
		case ET_EXEC:
			printf("Executable file\n");
			break;
		case ET_DYN:
			printf("Shared object file\n");
			break;
		case ET_CORE:
			printf("Core file\n");
			break;
		default:
			printf("Unknown file type\n");
			break;
	}
}
/**
 * print_entry - display entry
 * @entry: unsigned long
 */
void print_entry(unsigned long entry)
{
	printf("Entry point address: 0x%lx\n", entry);
}
