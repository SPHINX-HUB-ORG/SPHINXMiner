# SPHINXMiner

## Introduction

This repository is dedicated to the SPHINX blockchain project, an open-source post-quantum SPHINX blockchain designed to provide secure and scalable solutions in the post-quantum era. The project aims to develop a robust and decentralized network using a Proof of Work (PoW) consensus algorithm initiated by the community.

[SPHINX blockchain project](https://github.com/SPHINX-HUB-ORG/SPHINXPoW), an open-source post-quantum SPHINX blockchain designed to provide secure and scalable solutions in the post-quantum era. The project aims to develop a robust and decentralized network using a Proof of Work (PoW) consensus algorithm initiated by the community.

## Components

# SPHINXMiner

This repository contains code for the SPHINXMiner project, which is a mining module for the SPHINX blockchain. The SPHINXMiner aims to provide a Proof of Work (PoW) algorithm for mining blocks in the SPHINX blockchain.

## Function Explanation

### Miner::mineBlock

The `mineBlock` function is responsible for mining a new block by finding a valid proof-of-work. It takes the previous block's hash and the reward address as input parameters. The function iterates through nonce values until it finds a hash that meets the required difficulty level. Once a valid hash is found, the function creates a new block, adds the reward transaction, and sets the block's timestamp.

### Miner::calculateProofOfWork

The `calculateProofOfWork` function is used to calculate the proof-of-work for a given block data and difficulty level. It takes the block data and difficulty as input parameters. The function iterates through nonce values and calculates the hash of the block data. It checks if the calculated hash meets the difficulty requirement by comparing it with a target hash. Once a valid proof-of-work is found, the function returns it.

### Miner::performMining

The `performMining` function is responsible for the mining process. It includes two scenarios: the Developer Mining Phase and the Normal Mining Phase. In the Developer Mining Phase, a certain number of crypto assets are mined by developers with reduced difficulty. Once the developer mining goal is reached, the function transitions to the Normal Mining Phase where all miners participate with the regular difficulty. The function continues mining until all crypto assets are mined or the process is terminated.

### Miner::updateReward

The `updateReward` function is used to update the mining reward based on the block height. It checks if the block height reaches a reward halving interval. If the interval is reached, the function halves the reward amount.

## Getting Started

To get started with the SPHINXMiner project, follow these steps:

1. Clone the repository: `git clone https://github.com/your-username/SPHINXMiner.git`
2. Install the necessary dependencies.
3. Explore the codebase to understand the project structure and components.
4. Use the provided functions to mine blocks in the SPHINX blockchain.

## New File: [Filename]

Explain how the new file you uploaded to this repository is a part of the SPHINXMiner project and its purpose. Provide a brief overview of the file's contents and its relevance to the overall project.

## Getting Started

To get started with the SPHINX blockchain project:

1. Clone the repository: `git clone https://github.com/ChyKusuma/SPHINXMiner.git`
2. Install the necessary dependencies (provide a link to the installation guide if applicable).
3. Explore the codebase to understand the project structure and components.
4. Run the project or make modifications as needed.

## Contributing

We welcome contributions from the developer community to enhance the SPHINX blockchain project. If you are interested in contributing, please follow these guidelines:

1. Fork the repository on GitHub.
2. Create a new branch for your feature or bug fix: `git checkout -b feature/your-feature-name` or `git checkout -b bugfix/your-bug-fix`.
3. Make your modifications and ensure the code remains clean and readable.
4. Write tests to cover the changes you've made, if applicable.
5. Commit your changes: `git commit -m "Description of your changes"`.
6. Push the branch to your forked repository: `git push origin your-branch-name`.
7. Open a pull request against the main repository, describing your changes and the problem it solves.
8. Insert your information (i.e., name, email) in the authors space.

## License

This project is distributed under the [MIT License](link-to-license).

## Contact

If you have any questions, suggestions, or feedback regarding the SPHINX blockchain project, feel free to reach out to us at sphinxfounders@gmail.com.
