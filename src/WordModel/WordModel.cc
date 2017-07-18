#include "wordmodel.ih"
#include <random>
#include <memory>

#include <iostream>
using namespace std;

namespace Word2Vec
{
    WordModel::WordModel(Parameters params)
    :
        d_params(params)
    {
        //d_params.table = nullptr;
        //d_params.syn0 = new real[d_params.layer1_size * d_params.vocabulary->size()];
        //d_params.syn1 = d_params.hs ? new real[d_params.layer1_size * d_params.vocabulary->size()]() : nullptr;
        //d_params.syn1neg = d_params.negative > 0 ? new real[d_params.layer1_size * d_params.vocabulary->size()]() : nullptr;
        size_t units = d_params.layer1_size * d_params.vocabulary->size();
        d_params.syn0 = make_shared<std::vector<real> >(units, 0);
        if (d_params.hs)
            d_params.syn1 = make_shared<std::vector<real> >(units, 0);
        if (d_params.negative > 0)
            d_params.syn1neg = make_shared<std::vector<real> >(units, 0);

        random_device r;
        mt19937 generator(r());
        real extent = 0.5 / d_params.layer1_size;
        uniform_real_distribution<> distribution(-extent, extent);
        for (size_t b = 0; b < d_params.layer1_size; ++b)
            for (size_t a = 0; a < d_params.vocabulary->size(); ++a)
                (*d_params.syn0)[a * d_params.layer1_size + b] = distribution(generator);

        d_params.vocabulary->createBinaryTree();

        //d_params.expTable = new real[d_params.exp_table_size + 1];
        d_params.expTable = make_shared<vector<real> >(d_params.exp_table_size + 1);
        vector<real> &expTable(*d_params.expTable);
        for (size_t i = 0; i < d_params.exp_table_size; ++i) 
        {
            expTable[i] = exp((i / (real)d_params.exp_table_size * 2 - 1) * d_params.max_exp); // Precompute the exp() table
            expTable[i] = expTable[i] / (expTable[i] + 1);               // Precompute f(x) = x / (x + 1)
        }
    }
}
