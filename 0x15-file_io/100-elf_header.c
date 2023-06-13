#include <elf.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
void print_elf(unsigned char *ident);
void print_magic(unsigned char *ident);
void print_header(Elf64_Ehdr *header);
/**
 * main - displays info contained in the ELF header at the
 * start of an ELF file
 * @argc: arg count
 * @argv: arg vector
 * Return: 0
 */
int main(int argc, char **argv)
{
	int file;
	Elf64_Ehdr header;
	int read_data;

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "Usage: %s <ELF-file>\n", argv[0]);
		exit(98);
	}
	file = open(argv[1], O_RDONLY);
	if (file == -1)
	{
		printf("Error: Not an ELF file\n");
		exit(98);
	}
	read_data = read(file, &header, sizeof(Elf64_Ehdr));
	if (read_data == -1)
	{
		printf("Error: Can't read the ELF header\n");
		exit(98);
	}
	print_elf(header.e_ident);
	print_header(&header);
	close(file);
	return (0);
}
/**
 * print_elf - checks whether the file is an ELF file or not
 * @ident: pointer to an array containing ELF magic numbers
 */
void print_elf(unsigned char *ident)
{
	int i;

	for (i = 0; i < 4; i++)
	{
		if (ident[i] != 127 && ident[i] != 'E' && ident[i] != 'L' && ident[i] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: not an ELF file\n");
			exit(98);
		}
	}
}
/**
 * print_magic - display magic
 * @ident: ptr to an array containing ELF magic numbers
 */
void print_magic(unsigned char *ident)
{
	int i;

	printf("Magic: ");
	for (i = 0; i < EI_NIDENT; i++)
	{
		printf("%02x ", ident[i]);
		if (i == EI_NIDENT - 1)
			printf("\n");
		printf(" ");
	}
}
/**
 * print_header - prints info contained in ELF header
 * @header: ptr to ELF header structure
 */
void print_header(Elf64_Ehdr *header)
{
	printf("ELF Header:\n");
	print_magic(header->e_ident);
	printf("Class: ");
	switch (header->e_ident[EI_CLASS])
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
			printf("Unknown class: %x\n", header->e_ident[EI_CLASS]);
			break;
	}
	printf("Data: ");
	switch (header->e_ident[EI_DATA])
	{
		case ELFDATANONE:
			printf("Invalid data encoding\n");
			break;
		case ELFDATA2LSB:
			printf("2's complement, little endian\n");
			break;
		case ELFDATA2MSB:
			printf("2's complement, big endian\n");
			break;
		default:
			printf("Unknown data encoding: %x\n", header->e_ident[EI_DATA]);
			break;
	}
	printf("Version: %d", header->e_ident[EI_VERSION]);
	switch (header->e_ident[EI_VERSION])
	{
		case EV_CURRENT:
			printf(" (current)\n");
			break;
		default:
			printf("\n");
			break;
	}
	printf("OS/ABI: ");
	switch (header->e_ident[EI_OSABI])
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
			printf("Unknown OS/ABI: %x\n", header->e_ident[EI_OSABI]);
			break;
	}
	printf("ABI Version: %d", header->e_ident[EI_ABIVERSION]);
	if (header->e_ident[EI_DATA] == ELFDATA2MSB)
		header->e_type >>= 8;
	printf("Type: ");
	switch (header->e_type)
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
			printf("Unknown file type: %x\n", header->e_type);
			break;
	}
	printf("Entry: ");
	if (header->e_ident[EI_DATA] == ELFDATA2MSB)
	{
		header->e_entry = ((header->e_entry << 8) & 0xFF00FF00) |
			((header->e_entry >> 8) & 0xFF00FF);
		header->e_entry = (header->e_entry << 16) | (header->e_entry >> 16);
	}
	if (header->e_ident[EI_DATA] == ELFCLASS32)
	{
		printf("%#x\n", (unsigned int)header->e_entry);
	}
	printf("%#lx\n", header->e_entry);
}
