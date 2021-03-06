libword2vec
========

This is a C++ port of the repository at https://github.com/dav/word2vec, previously copied from https://code.google.com/p/word2vec/

The port is based on the modifications in the repository at https://github.com/adamwulf/word2vec

Goal is to make a more encapsulated library to programmatically train word vectors and extract word distances, for use in other systems.

Training using skip and cbow works, and outperforms the C-variant by 25% to 50% on preliminary tests.

Original text
============
[I've copied it](https://github.com/dav/word2vec)to a github project so I can apply and track community patches for my needs (starting with capability for Mac OS X compilation).

Tools for computing distributed represention of words (and Grams) included from the [cedias](https://github.com/cedias/word2vec) repo.

- ***makefile and some source has been modified for Mac OS X compilation*** See https://code.google.com/p/word2vec/issues/detail?id=1#c5
- ***memory patch for word2vec has been applied*** See https://code.google.com/p/word2vec/issues/detail?id=2
- Project file layout altered

There seems to be a segfault in the compute-accuracy utility.

To get started: 
    
    cd scripts && ./demo-word.sh

------------------------------------------------------

This tool provides an efficient implementation of the continuous bag-of-words and skip-gram architectures for computing vector representations of words. These representations can be subsequently used in many natural language processing applications and for further research. 

Tools for computing distributed representation of words
------------------------------------------------------

We provide an implementation of the Continuous Bag-of-Words (CBOW) and the Skip-gram model (SG), as well as several demo scripts.

Given a text corpus, the word2vec tool learns a vector for every word in the vocabulary using the Continuous
Bag-of-Words or the Skip-Gram neural network architectures. The user should to specify the following:
 - desired vector dimensionality
 - the size of the context window for either the Skip-Gram or the Continuous Bag-of-Words model
 - training algorithm: hierarchical softmax and / or negative sampling
 - threshold for downsampling the frequent words 
 - number of threads to use
 - the format of the output word vector file (text or binary)

Usually, the other hyper-parameters such as the learning rate do not need to be tuned for different training sets. 

The script demo-word.sh downloads a small (100MB) text corpus from the web, and trains a small word vector model. After the training
is finished, the user can interactively explore the similarity of the words.

More information about the scripts is provided at https://code.google.com/p/word2vec/

