import { instanceToPlain } from "class-transformer";
import { Request, Response } from "express";
import { AuthenticateUserService } from "../../services/User/AuthenticateUserService";
import { CreateUserService } from "../../services/User/CreateUserService";

export default {
  async handle(req: Request, res: Response) {
    const { email, password, name, birthDate, cpf, phone } = req.body;

    const createUserService = new CreateUserService();

    const user = await createUserService.execute({
      email,
      password,
      name,
      birthDate,
      cpf,
      phone,
    });

    const authenticateUserService = new AuthenticateUserService();

    const token = await authenticateUserService.execute(email, password);

    const data = instanceToPlain(user);
    return res.status(201).send({ ...data, token });
  },
};
