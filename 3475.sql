# Write your MySQL query statement below
SELECT *,
  CASE
    WHEN SUBSTRING(dna_sequence, 1, 3) = 'ATG' THEN 1
    ELSE 0
  END AS has_start,

  CASE
    WHEN SUBSTRING(dna_sequence, length(dna_sequence)-2, 3) = 'TAA' THEN 1
    WHEN SUBSTRING(dna_sequence, length(dna_sequence)-2, 3) = 'TAG' THEN 1
    WHEN SUBSTRING(dna_sequence, length(dna_sequence)-2, 3) = 'TGA' THEN 1
    ELSE 0
  END AS has_stop,

  CASE
    WHEN dna_sequence LIKE '%ATAT%' THEN 1
    ELSE 0
  END AS has_atat,

  CASE
    WHEN dna_sequence LIKE '%GGG%' THEN 1
    ELSE 0
  END AS has_ggg

  FROM Samples
