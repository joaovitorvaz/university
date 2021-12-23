import { EntityRepository, Repository } from "typeorm";
import { Rent } from "../entities/Rent";

@EntityRepository(Rent)
export class RentsRepositories extends Repository<Rent> {}
