import { ListUsersService } from "./../../services/User/ListUsersService";
import { Request, Response } from "express";

export default {
  async handle(req: Request, res: Response) {
    const listUsersService = new ListUsersService();
    const users = await listUsersService.execute();

    res.send(users);
  },
};
