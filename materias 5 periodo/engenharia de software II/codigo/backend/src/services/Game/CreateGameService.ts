import { getCustomRepository } from "typeorm";
import { GamesRepositories } from "../../repositories/GamesRepositories";
import { hash } from "bcryptjs";

interface IRequestGame {
  name: string;
  genre: string;
  ageRestriction: number;
  price: number;
  platform: string;
  description: string;
  logo: string;
}

export class CreateGameService {
  async execute({
    name,
    genre,
    ageRestriction,
    price,
    platform,
    description,
    logo,
  }: IRequestGame) {
    if (!name) {
      throw new Error("Name can't be NULL");
    }

    if (!genre) {
      throw new Error("Genre can't be NULL");
    }

    if (!ageRestriction) {
      throw new Error("Age Restriction can't be NULL");
    }

    if (!price) {
      throw new Error("Price can't be NULL");
    }

    if (!platform) {
      throw new Error("Platform can't be NULL");
    }

    if (!description) {
      throw new Error("Description can't be NULL");
    }

    if (!logo) {
      throw new Error("Logo can't be NULL");
    }

    const gamesRepositories = getCustomRepository(GamesRepositories);

    const gameAlreadyExists = await gamesRepositories.findOne({ name });

    if (gameAlreadyExists) {
      throw new Error("Game Already Exists");
    }

    const game = gamesRepositories.create({
      name: name,
      genre: genre,
      ageRestriction: ageRestriction,
      price: price,
      platform: platform,
      description: description,
      logo: logo,
    });

    await gamesRepositories.save(game);

    return game;
  }
}
