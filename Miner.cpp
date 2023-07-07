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


/////////////////////////////////////////////////////////////////////////////////////////////////////////
// The given code represents a Miner class in the SPHINXMiner namespace, which is responsible for mining blocks by finding valid proof-of-work. 

  // The constructor initializes the Miner object with a default difficulty level of 4.
  // The mineBlock function is responsible for mining a new block. It takes the previous block's hash (previousHash) and the address to reward the miner (rewardAddress) as input. The function iteratively calculates the hash of the block data by appending the nonce value and using the SPHINXHash::swifftx_256 function from hash.hpp.
  // The proof-of-work is derived from the calculated hash, taking a substring of the hash with a length equal to the difficulty level (difficulty_). If the proof-of-work meets the requirement (e.g., starts with difficulty_ number of zeros), the miner is rewarded with an asset using the SPHINXAsset::AssetManager class. The mining process breaks when a valid proof-of-work is found.
  // After mining the block, a new Block object is created with the provided previousHash. The reward transaction, consisting of the rewardAddress and the proof-of-work, is added to the new block. The block's timestamp is set to the current time using std::time(nullptr). Finally, the mined block is returned.
  // The calculateProofOfWork function calculates the proof-of-work by finding a hash that satisfies the difficulty requirement. It takes the blockData (e.g., concatenated previous hash and reward address) and the desired difficulty as input. The function iteratively calculates the hash of the block data using SPHINXHash::swifftx_256 and checks if the generated proof-of-work matches the target requirement (e.g., a substring of difficulty number of zeros). If a valid proof-of-work is found, it is returned.
  // The startMining function is a placeholder that starts the proof-of-work process. It calls the POW function from the SPHINXPoW namespace. The specific implementation details of the POW function are not provided in the given code snippet.

// In summary, the Miner class encapsulates the logic for mining blocks by finding valid proof-of-work. It calculates the hash of block data, incrementing the nonce until a valid proof-of-work is found. The mined block is then constructed with the necessary information and returned. The code also includes a function for calculating proof-of-work separately and a placeholder function for starting the mining process. 
/////////////////////////////////////////////////////////////////////////////////////////////////////////


#include <chrono>
#include <cmath>
#include <iostream>
#include <vector>
#include <ctime>
#include <string>
#include <iostream>
#include "Miner.hpp"
#include "PoW.hpp"
#include "Hash.hpp"
#include "Block.hpp"
#include "Asset.hpp"
#include "Node.hpp"


namespace SPHINXMiner {

    Miner::Miner() : difficulty_(4), rewardHalvingInterval_(210000), reward_(50) {
        // Constructor implementation...
    }

    Block Miner::mineBlock(const std::string& previousHash, const std::string& rewardAddress) {
        // Mine a new block by finding a valid proof-of-work
        std::string blockData = previousHash + rewardAddress;
        int nonce = 0;

        while (true) {
            std::string hash = SPHINXHash::SPHINX_256(blockData + std::to_string(nonce)); // Use the SPHINX_256 function from Hash.hpp

            std::string proofOfWork = hash.substr(0, difficulty_);
            if (proofOfWork == std::string(difficulty_, '0')) {
                // Reward the miner with an asset
                SPHINXAsset::AssetManager assetManager;
                assetManager.issueSPX("Reward Asset", rewardAddress, reward_, rewardAddress); // Pass the reward amount as a parameter

                break;
            }

            // Increment the nonce to change the block data
            nonce++;
        }

        Block newBlock(previousHash);
        newBlock.addTransaction(rewardAddress + ":" + proofOfWork);
        newBlock.setTimestamp(std::time(nullptr));

        return newBlock;
    }

    std::string Miner::calculateProofOfWork(const std::string& blockData, int difficulty) {
        // Calculate the proof-of-work by finding a hash that satisfies the difficulty requirement
        std::string proofOfWork;
        std::string target(difficulty, '0');

        while (true) {
            std::string hash = SPHINXHash::SPHINX_256(blockData); // Use the swifftx_256 function from hash.hpp

            proofOfWork = hash.substr(0, difficulty);
            if (proofOfWork == target) {
                break;
            }

            // Increment the nonce to change the block data
            blockData += "nonce";
        }

        return proofOfWork;
    }

    void Miner::performMining() {
        SPHINXPoW::solveNonce(blockData, difficulty_); // Modify the parameters as needed

        int64_t totalBlocks = 50000000; // Total number of crypto assets to mine
        int64_t developerBlocks = totalBlocks * 0.3; // Number of crypto assets to be mined by developers

        int64_t minedBlocks = 0; // Counter for total mined crypto assets
        int64_t developerMinedBlocks = 0; // Counter for developer mined crypto assets

        bool developerMining = true; // Flag to indicate developer mining

        std::string blockData = ""; // Initialize blockData variable
        std::string rewardAddress = ""; // Initialize rewardAddress variable
        int64_t nonces = 1000000; // Define the number of nonces

        // Scenario 1: Developer Mining Phase
        while (developerMinedBlocks < developerBlocks) {
            for (int64_t nonce = 1; nonce < nonces; nonce++) {
                std::string hash = SPHINXHash::SPHINX_256(blockData + std::to_string(nonce)); // Use the swifftx_256 function from hash.hpp

                std::string proofOfWork = hash.substr(0, difficulty_);
                if (proofOfWork == std::string(difficulty_, '0')) {
                    // Reward the miner with an asset
                    SPHINXAsset::AssetManager assetManager;
                    assetManager.issueSPX("Reward Asset", rewardAddress, reward_); // Pass the reward amount as a parameter

                    minedBlocks++;
                    developerMinedBlocks++;

                    if (developerMinedBlocks >= developerBlocks) {
                        std::cout << "Developer mining phase completed. Transitioning to normal mining." << std::endl;
                        developerMining = false;
                    }

                    if (minedBlocks == totalBlocks) {
                        std::cout << "All crypto assets mined!" << std::endl;
                        return;
                    }

                    // Adjust the reward based on the block height
                    updateReward();

                    break;
                }

                // Increment the nonce to change the block data
                nonce++;
            }
        }

        // Scenario 2: Normal Mining Phase
        while (minedBlocks < totalBlocks) {
            for (int64_t nonce = 1; nonce < nonces; nonce++) {
                std::string hash = SPHINXHash::SPHINX_256(blockData + std::to_string(nonce)); // Use the swifftx_256 function from hash.hpp

                std::string proofOfWork = hash.substr(0, difficulty_);
                if (proofOfWork == std::string(difficulty_, '0')) {
                    // Reward the miner with an asset
                    SPHINXAsset::AssetManager assetManager;
                    assetManager.issueSPX("Reward Asset", rewardAddress, reward_); // Pass the reward amount as a parameter

                    minedBlocks++;

                    if (minedBlocks == totalBlocks) {
                        std::cout << "All crypto assets mined!" << std::endl;
                        return;
                    }

                    // Adjust the reward based on the block height
                    updateReward();

                    break;
                }

                // Increment the nonce to change the block data
                nonce++;
            }
        }
    }

    void Miner::updateReward() {
        // Check if the block height reaches a reward halving interval
        if ((blockHeight_ + 1) % rewardHalvingInterval_ == 0) {
            reward_ /= 2; // Halve the reward
        }
    }

} // namespace SPHINXMiner





