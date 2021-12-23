import { GamesRepositories } from "./../../repositories/GamesRepositories";
import { getCustomRepository } from "typeorm";

export class ListGamesService {
  async execute() {
    const gamesRepositories = getCustomRepository(GamesRepositories);

    const games = await gamesRepositories.find();

    return games;
  }
}
