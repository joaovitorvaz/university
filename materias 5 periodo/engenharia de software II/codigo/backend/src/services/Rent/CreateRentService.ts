import { getCustomRepository } from "typeorm";
import { RentsRepositories } from "../../repositories/RentsRepositories";

interface ICreateRentService {
  user_id: string;
  game_id: string;
}

export class CreateRentService {
  async execute({ game_id, user_id }: ICreateRentService) {
    const restsReposiories = getCustomRepository(RentsRepositories);

    const rentAlreadyExists = await restsReposiories.find({
      user_id,
      game_id,
    });

    const lastRent = rentAlreadyExists.pop();

    if (lastRent && lastRent.expired_at > new Date()) {
      throw Error("Rent already exists.");
    }

    const rent = restsReposiories.create({
      game_id,
      user_id,
    });

    await restsReposiories.save(rent);

    return rent;
  }
}
