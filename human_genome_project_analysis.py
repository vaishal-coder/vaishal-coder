from Bio.Seq import Seq
from Bio.SeqUtils import GC

# Create a DNA sequence
dna_seq = Seq("ATGGCCATTGTAATGGGCCGCTGAAAGGGTGCCCGATAG")

# Calculate GC content
gc_content = GC(dna_seq)

# Reverse complement of the sequence
rev_comp_seq = dna_seq.reverse_complement()

# Transcribe to mRNA
mRNA_seq = dna_seq.transcribe()

print(f"Original DNA Sequence: {dna_seq}")
print(f"GC Content: {gc_content}%")
print(f"Reverse Complement: {rev_comp_seq}")
print(f"mRNA Sequence: {mRNA_seq}")
