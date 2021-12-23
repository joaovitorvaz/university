import { Request, Response } from "express";
import { CreateGameService } from "../../services/Game/CreateGameService";

export default {
  async handle(req: Request, res: Response) {
    const { name, genre, ageRestriction, price, platform, description, logo } =
      req.body;

    const createGameService = new CreateGameService();

    const game = await createGameService.execute({
      name,
      genre,
      ageRestriction,
      price,
      platform,
      description,
      logo,
    });

    return res.status(201).send({ ...game });
  },
};
