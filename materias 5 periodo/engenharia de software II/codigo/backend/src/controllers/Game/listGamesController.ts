import { ListGamesService } from "./../../services/Game/ListGamesService";
import { Request, Response } from "express";

export default {
  async handle(req: Request, res: Response) {
    const listGamesService = new ListGamesService();
    const games = await listGamesService.execute();
    res.send(games);
  },
};
