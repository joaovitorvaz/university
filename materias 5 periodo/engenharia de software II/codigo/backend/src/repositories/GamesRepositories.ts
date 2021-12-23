import { EntityRepository, Repository } from "typeorm";
import { Game } from "../entities/Game";

@EntityRepository(Game)
export class GamesRepositories extends Repository<Game> {}