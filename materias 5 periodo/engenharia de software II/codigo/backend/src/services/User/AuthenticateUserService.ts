import { compare } from "bcryptjs";
import { sign } from "jsonwebtoken";
import { getCustomRepository } from "typeorm";
import { UsersRepositories } from "../../repositories/UsersRepositories";
require("dotenv").config();

export class AuthenticateUserService {
  async execute(email: string, password: string) {
    const usersRepositories = getCustomRepository(UsersRepositories);

    const user = await usersRepositories.findOne({ email });

    if (!user) {
      throw new Error("Email/Password Incorrect");
    }

    const passwordMatch = await compare(password, user.password);

    if (!passwordMatch) {
      throw new Error("Email/Password Incorrect");
    }

    const token = sign({ email }, process.env.JWT_TOKEN, {
      subject: user.id,
      expiresIn: "1d",
    });

    return token;
  }
}
