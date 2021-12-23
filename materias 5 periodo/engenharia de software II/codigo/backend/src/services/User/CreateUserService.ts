import { getCustomRepository } from "typeorm";
import { UsersRepositories } from "../../repositories/UsersRepositories";
import { hash } from "bcryptjs";

interface IRequestUser {
  email: string;
  password: string;
  name: string;
  cpf: string;
  birthDate: Date;
  phone: string;
}

export class CreateUserService {
  async execute({
    email,
    password,
    birthDate,
    cpf,
    name,
    phone,
  }: IRequestUser) {
    if (!email) {
      throw new Error("Email Invalid");
    }

    if (!password) {
      throw new Error("Password Invalid");
    }

    if (!birthDate) {
      throw new Error("Birth Date Invalid");
    }

    if (!cpf) {
      throw new Error("Cpf Invalid");
    }

    if (!name) {
      throw new Error("Name Invalid");
    }

    if (!phone) {
      throw new Error("Cellphone Invalid");
    }

    const usersRepositories = getCustomRepository(UsersRepositories);

    const userAlreadyExistsByEmail = await usersRepositories.findOne({ email });
    const userAlreadyExistsByCpf = await usersRepositories.findOne({ cpf });

    if (userAlreadyExistsByEmail || userAlreadyExistsByCpf) {
      throw new Error("User Already Exists");
    }

    const passwordHash = await hash(password, 8);

    const user = usersRepositories.create({
      name: name,
      email: email,
      password: passwordHash,
      birthDate: birthDate,
      cpf: cpf,
      phone: phone,
      isAdmin: false,
    });

    await usersRepositories.save(user);

    return user;
  }
}
