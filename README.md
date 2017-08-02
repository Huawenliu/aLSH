# 位置敏感哈希LSH应用用计算向量最大内积和

---

> **Locality Sensitive Hashing:** 位置敏感哈希

---

## 简介：

位置敏感哈希可以快速计算向量之间相似度（aNN问题）。与一般用于替代场景的线性扫描机树形相似性搜索算法比较而言，局部敏感哈希具备亚线性的计算时耗；
尤其在高维度向量计算中，位置敏感哈希具备性能上的优点；与此相反，应用位置敏感哈希是有一定程度的精度损失，
在一定程度上可以根据候选数据来选取哈希参数，有利于减少损失。

---

## Reference:

- LSH:
[Locality-Sensitive Hashing Scheme Based on p-Stable Distributions](http://www.cs.princeton.edu/courses/archive/spr05/cos598E/bib/p253-datar.pdf)

- L2-ALSH:
[Asymmetric LSH (ALSH) for Sublinear Time Maximum Inner Product Search (MIPS)](https://papers.nips.cc/paper/5329-asymmetric-lsh-alsh-for-sublinear-time-maximum-inner-product-search-mips.pdf)

- Sign-ALSH(Cosine):
[Improved Asymmetric Locality Sensitive Hashing (ALSH) for Maximum Inner Product Search (MIPS)](http://auai.org/uai2015/proceedings/papers/96.pdf)

- Simple-ALSH(Cosine):
[On Symmetric and Asymmetric LSHs for Inner Product Search](https://arxiv.org/abs/1410.5518)

---
