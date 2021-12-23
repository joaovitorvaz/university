import { getCustomRepository } from "typeorm";
import { UsersRepositories } from "../../repositories/UsersRepositories";

export class DeleteUserService {
  async execute(id: string) {
    const usersRepositories = getCustomRepository(UsersRepositories);

    const result = await usersRepositories.delete({ id });

    return result;
  }
}
