import { Request, Response } from "express";
import { DeleteUserService } from "../../services/User/DeleteUserService";

export default {
  async handle(req: Request, res: Response) {
    const { user_id } = req;

    const deleteUserService = new DeleteUserService();

    const result = await deleteUserService.execute(user_id);

    return res.send({ message: "User deleted" });
  },
};
