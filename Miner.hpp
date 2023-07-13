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



#ifndef MINER_HPP
#define MINER_HPP

#include <string>
#include "Block.hpp"

namespace SPHINXMiner {

    class Miner {
    public:
        Miner();
        Block mineBlock(const std::string& previousHash, const std::string& rewardAddress);
        void performMining();

    private:
        int difficulty_;
        int rewardHalvingInterval_;
        int reward_;

        std::string calculateProofOfWork(const std::string& blockData, int difficulty);
        void updateReward();
    };

} // namespace SPHINXMiner

#endif // MINER_HPP
