import { getCustomRepository } from "typeorm";
import { GamesRepositories } from "../../repositories/GamesRepositories";

export class ListGameService {
  async execute(id: string) {
    const gamesRepositories = getCustomRepository(GamesRepositories);

    const game = await gamesRepositories.findOne(id);

    if (game) {
      throw new Error("Game doesn't exist.");
    }

    return game;
  }
}
