import { Request, Response } from "express";
import { CreateRentService } from "../../services/Rent/CreateRentService";

export default {
  async handle(req: Request, res: Response) {
    const { user_id } = req;
    const { game_id } = req.body;

    const createRentService = new CreateRentService();
    const rent = await createRentService.execute({ user_id, game_id });

    res.send(rent);
  },
};
