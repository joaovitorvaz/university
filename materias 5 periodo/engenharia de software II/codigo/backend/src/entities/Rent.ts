import {
  Column,
  CreateDateColumn,
  Entity,
  JoinColumn,
  ManyToOne,
  PrimaryColumn,
} from "typeorm";
import { v4 as uuid } from "uuid";
import { Game } from "./Game";
import { User } from "./User";

@Entity("rents")
export class Rent {
  @PrimaryColumn()
  readonly id: string;

  @Column()
  user_id: string;

  @ManyToOne((type) => User, (user) => user.rents)
  @JoinColumn({ name: "user_id" })
  user: User;

  @Column()
  game_id: string;

  @ManyToOne((type) => Game)
  @JoinColumn({ name: "game_id" })
  game: Game;

  @CreateDateColumn()
  created_at: Date;

  @Column()
  expired_at: Date;

  constructor() {
    if (!this.id) {
      this.id = uuid();
      let date = new Date();
      date.setDate(date.getDate() + 7);
      this.expired_at = date;
    }
  }
}
