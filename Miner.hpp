/*
 *  Copyright (c) (2023) SPHINX_ORG
 *  Authors:
 *    - (C kusuma) <thekoesoemo@gmail.com>
 *      GitHub: (https://github.com/chykusuma)
 *  Contributors:
 *    - (Contributor 1) <email1@example.com>
 *      Github: (https://github.com/yourgit)
 *    - (Contributor 2) <email2@example.com>
 *      Github: (https://github.com/yourgit)
 */



#ifndef SPHINXMINER_HPP
#define SPHINXMINER_HPP

#pragma once

#include <string>
#include "Block.hpp"


namespace SPHINXMiner {

    class Miner {
    private:
        int difficulty_;
        int rewardHalvingInterval_;
        int reward_;
        int blockHeight_;

    public:
        Miner();

        struct Block {
            std::string previousHash;
            std::string data;
            std::string proofOfWork;
            std::time_t timestamp;
        };

        Block mineBlock(const std::string& previousHash, const std::string& rewardAddress);

        std::string calculateProofOfWork(const std::string& blockData, int difficulty);

        void startMining();

    private:
        void updateReward();
    };

} // namespace SPHINXMiner

#endif // SPHINX_MINER_HPP

