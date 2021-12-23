import { Request, Response } from "express";
import { UpdateUserService } from "../../services/User/UpdateUserService";

export default {
  async handle(req: Request, res: Response) {
    const { email, password, birthDate, phone, name, cpf } = req.body;
    const { user_id } = req;

    const updateUserService = new UpdateUserService();

    const user = await updateUserService.execute({
      id: user_id,
      name,
      email,
      password,
      phone,
      birthDate,
      cpf,
    });

    res.json({ message: "Success Updated" });
  },
};
