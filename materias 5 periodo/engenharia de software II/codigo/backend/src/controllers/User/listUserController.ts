import { Request, Response } from "express";
import { ListUserService } from "../../services/User/ListUserService";

export default {
  async handle(req: Request, res: Response) {
    const { user_id } = req;

    const listUserService = new ListUserService();

    const user = await listUserService.execute(user_id);

    res.send(user);
  },
};
