import { Request, Response } from "express";
import { ListGameService } from "../../services/Game/ListGameService";

export default {
  async handle(req: Request, res: Response) {
    const { game_id } = req.body;

    const listGameService = new ListGameService();

    const game = await listGameService.execute(game_id);

    res.send(game);
  },
};
